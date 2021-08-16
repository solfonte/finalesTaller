# Finales de taller de programacion 75.42
Resueltos de finales del curso Veiga.

# Lenguaje C y C++

## Memoria

* El tamaño en bytes de los tipos depende de la arquitectura y del compilador.
* El compilador puede guardar las variables en posiciones de memoria múltiplos de 4 (depende de la arquitectura y de los flags de compilación): variables alineadas son accedidas más rápidamente que las desalineadas. Como contra, la alineación despedicia espacio (padding) hay un tradeoff entre velocidad y espacio.
* El tamaño de un puntero no depende de a que tipo apunta. Todos los punteros ocupan el mismo tamaño (que depende de la arquitectura).
* El padding se hace mas notorio en las estructuras: el acceso a cada atributo es rápido pero hay memoria desperdiciada.
* Endiannes: se vuelve relevante en el momento que queremos interpretar un int como una tira de bytes (char*) o viceversa. Se puede cambiar el endianess de una variable short int y int del endianess nativo o "del host" a big endian o "el endianess de la red" y viceversa:
```
#include <arpa/inet.h>.
```

  - Host to Network
  ```
    uint16_t htons(uint16_t hostshort);
    uint32_t htonl(uint32_t hostlong);
  ```
  - Network to Host
  ```
  uint16_t ntohs(uint16_t netshort);
  uint32_t ntohl(uint32_t netlong);
  ```

* Segmentos de memoria:
**Code segment**: de solo lectura y ejecutable, a donde va el código y las constantes.
**Data segment**: variables creadas al inicio del programa y son válidas hasta que este termina; pueden ser de acceso global o local.
**Stack**: variables creadas al inicio de una llamada a una función y destruidas automáticamente cuando esta llamada termina.
**Heap**: variables cuya duración esta controlada por el programador (run-time).

* Duración (lifetime): tiempo desde que a la variable se le reserva memoria hasta que esta es liberada. Determinado por el segmento de memoria que se usa.
* Visibilidad (scope): Cuando una variable se la puede acceder y cuando esta oculta.  

Algunos ejemplos son:
```c
int g = 1; // Data segment; scope global
static int l = 1; // Data segment; scope local (este file)
extern char e; // No asigna memoria (es un nombre)
```

```c
void Fa() { } // Code segment; scope global
static void Fb() { } // Code segment; scope local (este file)
void Fc(); // No asigna memoria (es un nombre)
```

El siguiente codigo falla. Como el puntero "a" apunta al Code Segment y este es de solo lectura, tratar de modificarlo termina en un Segmentation Fault

```c
void f() {
  char *a = "ABC"; // c en el Stack; apunta al Code Segment
  char b[] = "ABC"; // es un array con su todo en el Stack

  b[0] = ’X’;
  a[0] = ’X’; // segmentation fault
  }
```  

Diferencia entre una definicion y una declaracion:  
* declaracion: informarle al compilador que algo existe pero que no reserve recursos. Despues el linker va a referenciar las cosas.  
* definicion: definicion es declaracion pero ademas implica una reserva de recursos.  

## Compilacion

https://wiki.cs.famaf.unc.edu.ar/lib/exe/fetch.php?media=algo1:curso-c.pdf

## Clases en c++

* Con los constructores (si estan bien escritos) no se puede usar un objeto sin inicializar.
* Con los destructores (si estan bien escritos, se usa RAII y usamos el stack) no vamos a tener leaks.
* Los destructores se llaman automáticamente cuando el objeto se va de scope.
* Todos los objetos tienen un destructor.
* Las clases abstractas son las que tienen un método virtual puro.
* **object slicing**: si tengo una clase Base y una clase Derivada que hereda de base, si tengo:
```c
  Derivada d;
  Base b;
  b = d;
  ```
b se va a quedar con la parte de Base de d, no es que b va a ser de tipo Derivada.


Links:
  * https://taller-de-programacion.github.io/blog/2010/08/21/Constructor-de-copia-Orden.html

### RAII

La idea es simple, si hay un recurso (memoria en el heap, un archivo, un socket) hay que encapsular el recurso en un objeto de C++ cuyo constructor lo adquiera e inicialize y cuyo destructor lo libere.    

Al instanciarse los objetos RAII en el stack, sus constructores adquieren los recursos automáticamente. Al irse de scope cada objeto se les invoca su destructor automáticamente y por ende  liberan sus recursos sin necesidad de hacerlo explícitamente.    

El código C++ se simplifica y se hace más robusto a errores de programación: RAII + Stack es uno de los conceptos claves en C++.

# Sockets (TCP)
* Servicio: port  
* ip: host  
* La función *getaddrinfo* resuelve los nombres simbolicos de *host* y *servicio* nombres a sus correspondientes IPs y puertos.  

Podemos probar el cliente y el server ingresando lo siguiente en la terminal:  
nc -l -p <port> para server  
nc localhost <port> para cliente  

**Servidor**
```c
memset(&hints, 0, sizeof(struct addrinfo));
hints.ai_family = AF_INET; /* IPv4 */
hints.ai_socktype = SOCK_STREAM; /* TCP */
hints.ai_flags = AI_PASSIVE;

status = getaddrinfo(0 /* ANY */, "http", &hints, &results);
freeaddrinfo(results);
```
Las funciones que realiza son:  
* inicializar un socket: crear un file descriptor al igual que cuando abrimos un archivo
* bind: establece a que interface, IP y puerto se quiere asociar ese socket. La dirección usada en la función bind son el resultado de la función getaddrinfo.  
* listen: listen define cuantas conexiones en espera pueden esperar hasta ser aceptadas. No limita cuantas conexiones totales puede haber.  
* accept: el servidor acepta las conexiones de alguien que quiere conectarse. Esta funcion es bloqueante. Cuando acepta una conexión, la función accept se desbloquea y retorna un nuevo socket que representa a la
nueva conexión.  
* cerrar un socket.  
* Ademas tiene dos sockets: aceptador y peer. El primero acepta las conexiones y el segundo es unico para comunicarse con cada cliente conectado.  

**Cliente**

```c
memset(&hints, 0, sizeof(struct addrinfo));
hints.ai_family = AF_INET; /* IPv4 */
hints.ai_socktype = SOCK_STREAM; /* TCP */
hints.ai_flags = 0;

status = getaddrinfo("fi.uba.ar", "http", &hints, &results);
freeaddrinfo(results);
```
Las funciones que realiza son:  
* inicializar un socket  
* connect: para conectar el socket con el servidor. Es bloqueante.  
* cerrar un socket  

Para cerrar una conexion, se hace *shutdown* y *close*. Tipos de shut down:  
  - envio: SHUT_WR  
  - recepción: SHUT_RD  
  - ambos: SHUT_RDWR  

# Archivos

Para abrir un archivo:
```c
FILE *fopen(const char *path, const char *modo);
```
Para cerrarlo:
```c
int fclose(FILE *stream);
```
Modos de aperura de archivos:
* "r": lectura. El archivo debe existir.  
* "w": Escritura (crea el archivos si no existe; sobreescribe uno existente).  
* "a": Append (crea el archivo si no existe. Si existe continúa al final).  
* "r+": Lectura y escritura, empieza al principio. El archivo debe existir.  
* "w+": Lectura y escritura (sobreescribe el archivo si existe).  
* "a+": Lectura y escritura (hace append si existe el archivo).  
Para archivos binarios:
* "b": Para lectura escritura de archivos binarios (usar con alguno de los anteriores).  
* "t": Para lectura escritura de archivos en modo texto.  

Mas funciones:  
```c
int fgetc(FILE *stream);
int fputc(int char, FILE *stream):
char *fgets(char *str, int n, FILE *stream):
int fputs(const char *str, FILE *stream):
size_t fread(void *ptr, size_t tam_elemento, size_t cant_elem, FILE *stream);
size_t fwrite(const void *ptr, size_t tam_elemento, size_t cant_elem, FILE *stream):
int fseek(FILE *stream, long int offset, int desde):
  ○ SEEK_SET: Inicio
  ○ SEEK_CUR: Posición actual
  ○ SEEK_END: Fin
void rewind(FILE *stream):
long int ftell(FILE *stream);
int fclose(FILE *stream);
int feof(FILE *stream);
ftruncate(FILE *stream, long int offset);
```
https://wiki.cs.famaf.unc.edu.ar/lib/exe/fetch.php?media=algo1:curso-c.pdf

# Threads

En C++11 podemos ejecutar una función en su propio hilo con td::thread. Luego, debemos esperar a que los hilos terminen sincronizando las ejecuciones con join.  
**Race condition**: se debe al acceso no-atómico de lecto/escritura de un recurso compartido.
Si el recurso compartido es inmutable o solamente se accede a él para operaciones de lectura, no existe la posibilidad de tal error. Para evitar la race condition debemos hacer que los hilos se coordinen entre sí para evitar que accedan al objeto compartido a la vez.  
Un mutex es un objeto que nos permitirá forzar la ejecución de un código de forma exclusiva por un hilo a la vez. En C++ std::mutex.  
Para hacer un lock de un mutex podemos usar un lock raii:  
```c
#include <utility>
#include <mutex>
std::mutex mutex;
std::lock_guard<std::mutex> lck(this->mutex);
```
Evita problemas de dead lock (cuando no se libera el mutex).   

### Condition variables
Usamos std::unique_lock<std::mutex> que nos da la posibilidad de desbloquear el mtex, a diferencia de lock_guard.
```c
#include <condition_variable>
```
# Sobrecarga de operadores

Asignacion por copia
```
T& operator=(const T& other);
```

Asignacion por movimiento

```
T& operator=(T&& other);
```

Operador Call

```
void operator()() const;
//o con parametros
double operator()(double x) const;
```

Pre y post incremento
```
class Complex {
  Complex& operator++() { //Pre-Incremento
    ++re;
    return *this;
  }
  Complex operator++(int) { //Post-Incremento
    Complex copy(*this);
    ++re;
    return copy;
  }
};
```
Operadores de comparacion
```
bool operator==(const Complex& other) const{
  return this->re == other.re && this->im == other.im;
}
```
# UI

Para compilar los ejercicios de gui:  
```
gcc `sdl2-config --cflags` -std=c11 NOMBRE_DEL_ARCHIVO_C -lSDL2 -lSDL2_gfx -o gfx
```
Para correrlo:
```
./gfx
```

Para ver como formar los colores en RGB: https://es.wikipedia.org/wiki/RGB#:~:text=La%20ausencia%20de%20color%2C%20es,magenta%20(255%2C0%2C255)

Referencias:
Diapositivas del curso Veiga.  
https://ccia.ugr.es/~jfv/ed1/c/cdrom/cap2/cap25.htm  
https://wiki.cs.famaf.unc.edu.ar/lib/exe/fetch.php?media=algo1:curso-c.pdf
