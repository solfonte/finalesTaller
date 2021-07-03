1) Escriba un programa (desde la inicialización hasta la liberación de los recursos) que reciba paquetes de la forma nnn+nn+....+nnnn= (numeros separados por +, seguidos de =) e imprima el resultado de la suma de cada paquete por pantalla. Al recibir un paquete vacío (“=”) debe cerrarse ordenadamente. No considere errores. .



2) Explique breve y concretamente qué es f:
```
int (*f) (short *, char[4]);
```


3) Analice el siguiente código y determine lo que se imprime (valor de Pi)
```
main(){
int *Pi=1000;
Pi++;
printf(“Pi apunta a la dirección: %l”, (long)Pi);
}
```



4) ¿Qué es un functor? ¿Qué ventaja ofrece frente a una función convencional? Ejemplifique.

**respuesta en final de 1C**

5) ¿Cómo se logra que 2 threads accedan (lectura/escritura) a un mismo recurso compartido
sin que se generen problemas de consistencia? Ejemplifique.

**respuesta en otro final del 1C**

6) Describa el concepto de loop de eventos (events loop) utilizado en programación orientada
a eventos y, en particular, en entornos de interfaz gráfica (GUIs).

**respuesta en final del 1C**

7) Considere la estructura struct ejemplo { int a; char b;}. ¿Es verdad que sizeof (ejemplo)=sizeof(a) +sizeof(b)? Justifique.


8) ¿En qué consiste el patrón de diseño RAII? Ejemplifique.


9) Escribir un programa ISO C que procese el archivo de enteros de 2 bytes bigendian cuyo nombre es recibido como parámetro. El procesamiento consiste en eliminar los número múltiplos de 3, trabajando sobre el mismo archivo (sin archivos intermedios ni en memoria).


10) Implemente una función C++ denominada DobleSiNo que reciba dos listas de elementos y
devuelva una nueva lista duplicando los elementos de la primera que no están en la
segunda:
std::list<T> DobleSiNo(std::list<T> a,std::list<T> b);
