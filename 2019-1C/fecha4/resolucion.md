**1) ¿Qué es una macro de C? Enumere buenas prácticas para su definición.**   
ej 6 primera fecha

**2) Describa el proceso de transformación de código fuente a un ejecutable. Precise las etapas y las tareas desarrolladas en cada una de ellas.**
respuesta en segunda o primera fecha

**3) Explique breve y concretamente qué es f:**  
```
char (*f) (int *, char[3]);
```

f es un puntero a una funcion que devuelve un tipo de dato char. Recibe por parametro un puntero a un tipo de dato int y un arreglo de tipo char de tres elementos.  

**4) Escribir un programa ISO C que procese el archivo “nros_2bytes_bigendian.dat” sobre sí mismo, eliminando los número múltiplos de 7.**  

resuelto parecido pero con multiplos de 3.

**5) Implemente una función C++ denominada DobleSegunda que reciba dos listas de elementos y devuelva una nueva lista duplicando los elementos de la primera si están en la segunda:**  
```
std::list<T> DobleSegunda(std::list<T> a,std::list<T> b);
```

resuelto parecido fecha 2 2C2019 (agregando los que no estan en la otra).  

**6) Escriba un programa que reciba por línea de comandos un Puerto y una IP. El programa debe aceptar una unica conexión e imprimir en stdout todo lo recibido. Al recibir el texto ‘FIN’ debe finalizar el programa sin imprimir dicho texto.**  

resuelto.

**7) Escriba el .H de una biblioteca de funciones ISO C para números complejos. Incluya, al menos, 4 funciones.**  

En archivo complejo.h

**8) Explique qué es cada uno de los siguientes, haciendo referencia a su inicialización, su comportamiento y el area de memoria donde residen:**
**a) Una variable global static**: Esta variable sera global en el modulo declarado pero no podra ser accedida por otros modulos. Las inicializa el compilador y se almacenan en el data segment. El scope es local al archivo donde fue declarado.  
**b) Una variable local static**: Es una variable local que tiene un scope local. Estas variables son inicializadas por el compilador. Residen en el data segment. Es una variable local a una función, pero por ser static su valor se mantiene entre llamadas a esta función.  
**c) Un atributo de clase static.**: Es un atributo que pertenece a la clase y no a un objeto en particular. El scope es global y el lifetime es mientras dure la ejecucion del programa.  

**9) ¿Cómo se logra que 2 threads accedan (lectura/escritura) a un mismo recurso compartido sin que se generen problemas de consistencia? Ejemplifique.**  

Lo que se hace para lograr esto es proteger el recurso compartido junto con una exclusion mutua (mutex). Cuando un hilo accede al recurso, se realiza un lock de dicho mutex, que es unico para ese recurso, de manera que si ocurriera un context switch, si otro hilo quiere acceder para modificarlo no podra ya que estara lockeado. Una vez que se haya realizado el unlock correspondiente, ahi puede acceder el otro hilo. Ejemplo:  


```
int contador = 0;
std::mutex m;

void incrementarContador(){
  m.lock();
  contador++;
  m.unlock();
}
int main(){
  std::thread thread1(incrementarContador);
  std::thread thread2(incrementarContador);

  thread1.join();
  thread2.join();
  return 0;
}

}
```

**10) Indique la salida del siguiente programa:**
```
class A{
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
  B b;
  return 0;
}
```
La salida del programa sera:
```
A()
B()
~B()
~A()
```
