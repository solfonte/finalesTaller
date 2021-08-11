**1) Escriba un programa (desde la inicialización hasta la liberación de los recursos) que reciba paquetes de la forma nnn+nn+....+nnnn= (numeros separados por +, seguidos de =) e imprima el resultado de la suma de cada paquete por pantalla. Al recibir un paquete vacío (“=”) debe cerrarse ordenadamente. No considere errores.**  

resuelto en ejercicio1.c

**2) Explique breve y concretamente qué es f:**  
```
int (*f) (short *, char[4]);
```

f es un puntero a una funcion. Esta recibe a su vez un puntero a un entero de 2 bytes y un vector de tipo char de 4 elementos.  

**3) Analice el siguiente código y determine lo que se imprime (valor de Pi)**  

```c
main(){
int *Pi=1000;
Pi++;
printf(“Pi apunta a la dirección: %l”, (long)Pi);
}
```  

En este codigo se define un puntero a un entero y se inicializa con el valor 1000. Esto significa que el puntero apunta a la direccion 1000 de memoria. Cuando se incrementa el puntero haciendo Pi++, se incrementa la direccion de memoria. Como este es un puntero a un entero, la direccion se incrementa en cuatro direcciones de memoria, ya que un entero tiene un tamanio de 4 bytes (en una arquitectura de 32 bits), con lo cual su representacion ocupara 4 direcciones de memoria. El resultado sera 1000 + 100 = 1100 ya que 100 = 4 en binario. Lo que se imprime por pantalla es: ``` Pi apunta a la direccion: 12```

**4) ¿Qué es un functor? ¿Qué ventaja ofrece frente a una función convencional? Ejemplifique.**  

respuesta en final de 1C

**5) ¿Cómo se logra que 2 threads accedan (lectura/escritura) a un mismo recurso compartido sin que se generen problemas de consistencia? Ejemplifique.**    

respuesta en otro final del 1C

**6) Describa el concepto de loop de eventos (events loop) utilizado en programación orientada a eventos y, en particular, en entornos de interfaz gráfica (GUIs).**  

respuesta en final del 1C

**7) Considere la estructura struct ejemplo { int a; char b;}. ¿Es verdad que sizeof (ejemplo)=sizeof(a) +sizeof(b)? Justifique.**  

Esto no es verdad ya que la memoria de cada campo del struct se aloca en direcciones múltiplos de 4 (en una arquitectura de 32 bits) en direcciones de memoria contiguas, por lo cual se puede llegar a "desperdiciar" locaciones en la memoria si los elementos ocupan menos de un múltiplo de 4. size(int) devolvera 4 (suponiendo una arquitectura de 32 bits) y sizeof(char) devolvera 1. size(a) + size(b) = 5 pero sizeof(ejemplo) = 8.

**8) ¿En qué consiste el patrón de diseño RAII? Ejemplifique.**   

Este patron de diseño es un patron utilizado para el manejo de recursos y consiste en reservar recursos para el objeto en el constructor y liberarlos en el destructor. Luego, para liberar los objetos, se hace en el orden inverso al cual fueron instanciados. Esto nos ayuda a dejar de tener leaks. Por ejemplo:

```c
Class Lista{
  int* l;
  public:
    Lista(int cantidadElementos){
      l = (int)malloc(sizeof(int) * cantidadElementos);
    }
    ~Lista(){
      free(l);
    }
}
```


**9) Escribir un programa ISO C que procese el archivo de enteros de 2 bytes bigendian cuyo nombre es recibido como parámetro. El procesamiento consiste en eliminar los número múltiplos de 3, trabajando sobre el mismo archivo (sin archivos intermedios ni en memoria).**  

ejercicio9.c

**10) Implemente una función C++ denominada DobleSiNo que reciba dos listas de elementos y devuelva una nueva lista duplicando los elementos de la primera que no están en la segunda:**  
```
std::list<T> DobleSiNo(std::list<T> a,std::list<T> b);
```  
Resuelto.
