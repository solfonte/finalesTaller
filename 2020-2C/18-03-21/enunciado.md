**1) Escriba un programa (desde la inicialización hasta la liberación de los recursos) que escuche el puerto 120 y reciba paquetes de la forma: 		[CHAR_LIM]xxxxx.xxxxxxx[CHAR_LIM]**
**donde [CHAR_LIM] puede ser cualquier caracter ASCII**
**Al completar la recepción del paquete deberá imprimir el caracter con más apariciones del mismo (sin considerar [CHAR_LIM]). Al recibir un paquete vacío ([CHAR_LIM][CHAR_LIM]) debe cerrarse ordenadamente. No considere errores.**

resuelto en ejercicio1.cpp

**2) ¿Qué función se utiliza para lanzar hilos?¿Qué parámetros tiene y para qué sirven? Ejemplifique.**

En c++11 podemos ejecutar una funcion en su propio hilo con std::thread. Los parametros que deben pasarse son la funcion y los parametros que recibe esa funcion. Por ejemplo, tenemos la  siguiente funcion:

```c
void f(int numero);
```
Al lanzar el thread, lo hacemos de la siguiente manera por ejemplo:

```c
std::thread(f,1);
```

**3) ¿Qué finalidad tiene la palabra virtual antepuesta a un método? Ejemplifique.**

La finalidad es la declaracion de funciones que pueden ser redefinidas por clases derivadas a una clase. Asi, podemos aplicar polimorfismo. Por ejemplo:
```c
class Base {
	public:
		virtual void metodo() {
			std::cout << "Base\n";
		}
};

class Derivada: public Base {
	public:
		virtual void metodo() {
			std::cout << "Derivada\n";
		}
};
```

**4) Implemente una función C++ denominada DUPLICAR que reciba dos listas de elementos y devuelva una nueva lista duplicando los elementos de la primera que están en la segunda:**
		**std::list<T> Duplicar(std::list<T> a,std::list<T> b);**

(resuelto parecido)

**5) Declare una clase a elección considerando:**
		**- Atributos que son necesarios**
		**- Accesibilidad a la Clase**
		**- Incluir los operadores *, --(pre-decremento), ++(post-incremento), << (impresión), >>(carga desde consola), functor**

(resuelto en otro final)

**6) Explique qué es (a), (b), (c) y (d), haciendo referencia a su valor y momento de inicialización, su comportamiento y el area de memoria donde residen:**

```c
extern int *a[25];
int b()
{
static float c;
char d=70;
return c+(float) d;
}
```

(a) es la declaracion de un puntero a un arreglo de 25 elementos de tipo int. Como esta declarado con la palabra extern, esto indica que es una variable definida en otro modulo. No se asigna memoria para esta declaracion, es un nombre y se inicializa en el modulo donde se definio.   
(b) es la definicion de una funcion que no recibe parametros. Reside en el code segment y tiene un scope global.
(c) es la declaracion de una variable de tipo float. Como esta declarada con la palabra static, tiene un scope local al modulo donde se la declara y reside en el data segment. Se inicializa una vez al iniciarse la ejecucion del programa y se inicializa en cero ya que se inicializan con este valor las variables estaticas que no se les asigno un valor al compilarse el programa.  
(d) es la definicion de una variable de tipo char. Reside en el stack y tiene un scope local a esta funcion. Se inicializa al ejecutarse la linea donde se la define ya que se le asigno un valor con =.  

**7) Escriba una rutina que dibuje un rombo verde que ocupe toda la ventana.**

resuelto parecido en el final del 25-03-21.

**8) ¿Qué diferencia existe entre un constructor por copia y uno por movimiento? Ejemplifique.**

(resuelto en otros finales).

**9) Escriba una función ISO C que permita procesar sobre sí mismo (sin generar archivos intermedios ni cargar el archivo completo a memoria) un archivo texto con palabras separadas por espacios. El procesamiento consiste en duplicar las palabras que tengan al menos de 2 vocales.**

resuelto en ejercicio9.c

**10) ¿Qué es la compliación condicional? Ejemplifique**

(resuelto en otro final).
