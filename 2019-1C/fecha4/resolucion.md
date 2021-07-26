**1) ¿Qué es una macro de C? Enumere buenas prácticas para su definición.**   
ej 6 primera fecha

**2) Describa el proceso de transformación de código fuente a un ejecutable. Precise las etapas y las tareas desarrolladas en cada una de ellas.**
respuesta en segunda o primera fecha

**3) Explique breve y concretamente qué es f:**  
```
char (*f) (int *, char[3]);
```

f es la declaracion de un puntero a una funcion que devuelve un tipo de dato char. Recibe por parametro un puntero a un tipo de dato int y un arreglo de tipo char de tres elementos.  

**4) Escribir un programa ISO C que procese el archivo “nros_2bytes_bigendian.dat” sobre sí mismo, eliminando los número múltiplos de 7.**  

*falta (archivo binario o de texto?)*

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
**a) Una variable global static**:
**b) Una variable local static**
**c) Un atributo de clase static.**

  a- Esta variable sera global en el modulo declarado pero no podra ser accedida por otros modulos. Las inicializa el compilador y se almacenan en el data segment. El scope es local al archivo donde fue declarado.
  b- Es una variable local que tiene un scope local. Estas variables son inicializadas por el compilador. Residen en el data segment. Es una variable local a una función, pero por ser static su valor se mantiene entre llamadas a esta función.
  c- Es un atributo que pertenece a la clase y no a un objeto en particular. *falta scope y lifetime*

**9) ¿Cómo se logra que 2 threads accedan (lectura/escritura) a un mismo recurso compartido sin que se generen problemas de consistencia? Ejemplifique.**  
Lo que se hace para lograr esto es hacer una clase protegida, donde se encapsula el recurso compartido junto con su mutex correspondiente. Cuando un hilo accede al recurso, se realiza un lock de dicho mutex, que es unico para ese recurso, de manera que cuando un hilo acceda a el, si otro hilo quiere acceder no podra ya que estara lockeado. Una vez que se haya realizado el unlock correspondiente, ahi puede acceder el otro hilo. Ejemplo:  
Definimos las clase que contiene el recurso que sera protegido. Para el caso del ejemplo, es una lista protegida de enteros.

```
Class listaProtegida{
  std::list<int> lista;
  std::mutex m;

  public:
  void agregarSiNoFueAgregado(int x){
    m.lock();

    if (!lista.has(x)){
      lista.add(x)
    }

    m.unlock();
  }

}
```
Cuando un hilo invoca a un metodo se realiza el correspondiente lock para asegurar que no se realice un context switch que pueda agregar el elemento que se quiera agregar mediante otro hilo. Asi, nos aseguramos que si no lo encontramos en la lista es porque efectivamente no fue agregado.  

**10) Indique la salida del siguiente programa:**
**class A { A(){cout << “A()” << endl;}**       
**~A(){ cout << “~A()” << endl;} }**  
**class B : public A { B(){cout << “B()” << endl;}**       
**~B(){ cout << “~B()” << endl;} }**  
**int main () { B b; return 0;}**  

La salida del programa sera:
```
A()
B()
~B()
~A()
```
