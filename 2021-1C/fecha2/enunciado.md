**1) Escriba un programa que reciba por línea de comandos un Puerto y una IP. El programa debe establecer una unica conexión, y enviar todo el texto ingresado por stdin. Cuando se ingrese el texto ‘FIN’ debe finalizar el programa sin enviar dicho texto.**

resuelto en ejercicio1.cpp

**2) ¿Qué es una Condition Variable? Ejemplifique mediante código.**

Una condition variable es una variable utilizada por un thread para esperar un evento generado por otro thread o el tiempo. Por ejemplo:

```
std::condition_variable cv;
std::mutex cv_m;
int i = 1;

void waits(){
    std::unique_lock<std::mutex> lk(cv_m);
    cv.wait(lk, []{return i == 1;});
}
```
Cuando se cumpla la condicion de que i == 1, la condition variable se desbloquea.

**3) Escribir un programa ISO C MULTIPLATAFORMA que procese el archivo “valores.txt” sobre sí mismo. El procesamiento consiste en leer números separados por 1 espacio que se encuentran en base 3 y escribirlos en 4 símbolos base hexadecimales, también separados por 1 espacio.**

resuelto en ejercicio3.c

**4) Implemente un programa de 2 threads (producer-consumer) que genere e imprima los números del 100 al 1.**

resuelto en ejercicio4.cpp

**5) Implemente una función C++ denominada PurgarMapa que reciba un mapa (clave-valor) por referencia y le quite los elementos cuyos valores están repetidos.**

ejercicio5.cpp *no anda*

**6) Explique y ejemplifique el uso de la directiva de precompilación #include**

El uso de esta directiva es la de incluir archivos de encabezados/ librerias. La utilizamos para
poder incluir archivos donde se encuentren las referencias a funciones, variables,constantes,
estructuras o clases que utilicemos en el modulo donde las incluimos, cuyas definiciones se
encuentran en el encabezado que incluimos con #include. Por ejemplo:
```c
#include <stdio.h>
#include “complejo.h”
```
*cheqeuar cuando me corrija*
**7) Explique qué es cada uno de los siguientes, haciendo referencia a su inicialización, su comportamiento y el area de memoria donde residen:**
**a) Una variable global static**
**b) Una variable local static**
**c) Un atributo de clase static.**

en otro final

**8) ¿Qué es un template? Ejemplifique**

Un template es una plantilla para generar clases. Nos permite implementar el codigo de una
clase, para luego especificar un tipo de dato que reemplazara al template. Por ejemplo:
```
Template <class T>
class list{
  private:
    std::list<T> data;
  public:
    void addData(T& data){
      this->data.push_back(data);
  }
};
```
Luego podemos especificar el tipo:
```
int main(){
  list<int> numeros;
  return 0;
}
```
El compilador luego procesa el codigo del template, reemplazando por el tipo de dato que
especificamos.
*chequear cuando me corrija*

**9) Indique la salida del siguiente programa:**
```
class A {
  A(){
    cout << “A()” << endl;
  }
  ~A(){
      cout << “~A()” << endl;
  }
}
class B : public A {
  B(){
    cout << “B()” << endl;
  }
  ~B(){
    cout << “~B()” << endl;
  }
}
int main () {
  B b; return 0;
}
```
en otro final

**10) Escriba una rutina que dibuje un rombo verde centrado y de 1⁄4 del alto de la ventana.**

ejercicio10.c
