**1) Declare una clase a elección considerando:**  
    *** Atributos que son necesarios**
    *** Accesibilidad a la Clase**
    *** Incluir los operadores +, ++ (post-incremento), --(pre-incremento), >> (impresión), << (carga desde consola), long**

resuelto en numero.h

**2) ¿Qué es un functor? ¿Qué ventaja ofrece frente a una función convencional? Ejemplifique.**  

Es la sobrecarga del operador (). Se usa para definir objetos que pueden ser llamados como funciones. La ventaja de los functors es que permiten que la clase reciba los argumentos una vez, al momento de construirse por ejemplo, y que la clase se los guarde como atributos.

Ejemplo:

```c
class Sumador{
  std::list<int> n;
  public:
    Sumador(std::list<int>& numeros): numeros(numeros){}
    void operator()(){
      int acumulador = 0;
      for (auto it = n.begin(); it != n.end(); ++it){
        acumulador += *it;
      }
      std::cout << "La suma da: " << acumulador << std::endl;
    }
};

int main(){
  std::list<int> numeros;
  numeros.push_back(1);
  numeros.push_back(56);
  numeros.push_back(8);
  numeros.push_back(23);

  Sumador s(numeros);
  s();
  return 0;
}
```

**3) Escriba un programa que imprima por salida estándar los números entre 1 y 100, en orden ascendente. Se pide que los números sean contabilizados por una variable global única y que los pares sean escritos por un hilo mientras que los impares sean escritos por otro.**  
**Contemple la correcta sincronización entre hilos y la liberación de los recursos utilizados.**  

resuelto.  

**4) Explique qué es (a), (b), (c) y (d), haciendo referencia a su valor y momento de inicialización, su comportamiento y el area de memoria donde residen:**  
```c
static int a;
int b(){
static int c; char d=65;
return c+(int) d;
}
```

resuelto en final del 18-03-21.

**5) Escriba una rutina que dibuje las dos diagonales de la pantalla en color rojo..**  

resuelto en ejercicio5.c

**6) ¿Por qué las librerías que usan Templates se publican con todo el código fuente y no como un .h y .o/.obj?.**  

Los templates son plantillas para generar clases. Se publican con todo el codigo porque el código template es procesado por el compilador y depende de tipo de dato que se use en el momento de compilar. Por eso, podemos especificar el tipo de dato o dejar que el compilador lo deduzca, pero dicho codigo debe compilarse al momento de definir el tipo.  

**7) ¿Qué características debe tener un compilador C para se considerado “portable”?**  

Un compilador C portable es aquel que soporta la sintaxis (y semantica) del lenguaje C dado un estandar y que no agrega ninguna sintaxis adicional por fuera del estandar (de tal manera que el mismo codigo podria ser compilado por otro compilador). Esto incluye tambien el proceso de compilacion estandar (precompilacion, compilacion, linkeo). Ademas el compilador debe ofrecer una implementacion a la libreria estandar de C respetando el estandar de C mencionado anteriormente tal que un programa compilado en un entorno pueda ser ejecutado en otro que tenga una libreria C compatible.

**8) Escriba un programa (desde la inicialización hasta la liberación de los recursos) que reciba paquetes de la forma [nnn+nn+....+nnnn] (numeros separados por +, encerrados entre corchetes) e imprima el resultado de la suma de cada paquete por pantalla. Al recibir un paquete vacío (“[]”) debe cerrarse ordenadamente. No considere errores.**  

resuelto.

**9) Escriba una función ISO C que permita procesar un archivo texto que contenga frases (1 por línea) sobre sí mismo, sin generar archivos intermedios ni cargar el archivo completo a memoria. El procesamiento consiste en eliminar las palabras de más de 3 letras de cada línea.**  

resuelto

**10) ¿Qué diferencia existe entre un constructor por copia y uno por movimiento? Ejemplifique.**  
diferencia en la primera fecha
Por ejemplo:

```c
class Nombre{
  private:
    std::string cadena;
  public:
    Nombre(Nombre& otroNombre){//constructor por copia
      this->cadena = otroNombre.cadena;
    }
    Nombre(Nombre&& otroNombre){//constructor por movimiento
      this->cadena = std::move(otroNombre.cadena);
    }
}
```
