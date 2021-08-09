**1) ¿Qué diferencia existe entre un constructor por copia y uno por movimiento? Ejemplifique.**

(resuelto en otro final).

**2) Escriba una rutina que dibuje un rombo azul del tamaño de la pantalla.**

ejercicio.c

**3) Escribir un programa ISO C MULTIPLATAFORMA que procese el archivo “bigEndian.dat” sobre sí mismo, leyendo nros. de 4 bytes Big-Endian y triplicando los impares.**

resuelto parecido en final fecha 1 2019 2C. Cambia:  
* en lugar de usar ```uint16_t``` se usa ```uint32_t```.
* en lugar de chequear ``` num % 3 == 0```, se debe verificar ```num % 2 == 1```.

**4) ¿Qué es un Deadlock? Ejemplifique.**

Un deadlock es un lock que fue realizado por un hilo que nunca puede ser liberado. Por ejemplo:

```c
class Acumulador{
	std::mutex m;
	int acumulador = 0;
	void acumular(int& numero){
		m.lock();
		this->acumulador += numero;
	}
}
```
Al llamar a la funcion acumular de acumulador, lo que ocurrira es que el hilo que la ejecute realizara un lock pero nunca un unlock, con lo cual ningun otro thread podra acceder a la ejecucion de dicha funcion.

**5) Escriba un programa que reciba por línea de comandos un Puerto y una IP. El programa debe conectarse y quedar en escucha de paquetes con la forma “d..d+d..d+...=”. El programa debe imprimir en stdout cada suma hasta que la misma sea 0 (cero). En ese caso debe finalizar ordenadamente.**

resuelto en ejercicio5.cpp

**6) Describa con exactitud las siguientes declaraciones/definiciones globales:**
		**- char *(*A)();**: A es la declaracion de un puntero a una funcion que no recibe parametros y devuelve un puntero a un dato de tipo char.
		**- static int *(*C)[5];**: la declaracion de un puntero a un arreglo de punteros a int, de scope local al modulo declarado por haber sido declarado con static, y reside en el data segment.
		**- short *B(){return NULL;}**: la definicion de una funcion B que devuelve un puntero a un short. Reside en el code segment y es de visibilidad global.

**7) Declare una clase a elección considerando:**
		**- Atributos que son necesarios**  
		**- Accesibilidad a la Clase**  
		**- Incluir los operadores -, ++ (post-incremento), --(pre-incremento), >> (impresión), << (carga desde consola), float**  

(resuelto parecido en fechas anteriores).

**8) Implemente una función C++ denominada SoloMuliplos que reciba una lista de elementos numéricos y un elemnto numérico x. La función debe devolver una nueva lista con los elementos de la primera que sean múltiplos de x:**
```
std::list<T> SoloMultiplos(std::list<T> a,T x);
```
resuelto en ejercicio8.cpp  

**9) ¿Se puede evitar que un objeto de una clase sea copiado?¿y clonado?. En caso afirmativo explique cómo puede hacerse. En caso negativo explique por qué no se puede.**

Se puede evitar que un objeto sea copiado. Lo que debemos hacer es eliminar su constructor copia y el operador asignacion por copia. Ademas podemos evitar que sea clonado, definiendo su constructor por movimiento. Asi, si se intentara clonar, en lugar de haber dos objetos siendo "duenios" de los mismos recursos, los recursos de uno se transfieren al otro.  

**10) ¿Qué es un thread?¿Qué recursos comparte con otros threads del mismo proceso?¿Cuales son exclusivos (no compartidos)?**  

Un thread es una ejecucion de un bloque de codigo. Cuando tenemos multiples hilos, estos bloques de codigo se ejecutan de manera concurrente. Los recursos que se comparten por los hilos de un mismo programa son el code segment, el data segment, el heap y los file descriptors. Los exclusivos son los registros y el stack.  
