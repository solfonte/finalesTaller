**1) Declare una clase a elección considerando:**  
    *** Atributos que son necesarios**
    *** Accesibilidad a la Clase**
    *** Incluir los operadores +, ++ (post-incremento), --(pre-incremento), >> (impresión), << (carga desde consola), long**


**2) ¿Qué es un functor? ¿Qué ventaja ofrece frente a una función convencional? Ejemplifique.**  

Es la sobrecarga del operador (). **faltan las ventajas y los ejemplos**



**3) Escriba un programa que imprima por salida estándar los números entre 1 y 100, en orden ascendente. Se pide que los números sean contabilizados por una variable global única y que los pares sean escritos por un hilo mientras que los impares sean escritos por otro.**  
**Contemple la correcta sincronización entre hilos y la liberación de los recursos utilizados.**  

resuelto.  

**4) Explique qué es (a), (b), (c) y (d), haciendo referencia a su valor y momento de inicialización, su comportamiento y el area de memoria donde residen:**  
```
static int a;
int b()
{
static int c; char d=65;
return c+(int) d;
}
```


**5) Escriba una rutina que dibuje las dos diagonales de la pantalla en color rojo..**  



**6) ¿Por qué las librerías que usan Templates se publican con todo el código fuente y no como un .h y .o/.obj?.**  


**7) ¿Qué características debe tener un compilador C para se considerado “portable”?**  

Para que un compilador sea portable debe poder implementarse en todas las arquitecturas.

**8) Escriba un programa (desde la inicialización hasta la liberación de los recursos) que reciba paquetes de la forma [nnn+nn+....+nnnn] (numeros separados por +, encerrados entre corchetes) e imprima el resultado de la suma de cada paquete por pantalla. Al recibir un paquete vacío (“[]”) debe cerrarse ordenadamente. No considere errores.**  



**9) Escriba una función ISO C que permita procesar un archivo texto que contenga frases (1 por línea) sobre sí mismo, sin generar archivos intermedios ni cargar el archivo completo a memoria. El procesamiento consiste en eliminar las palabras de más de 3 letras de cada línea.**  



**10) ¿Qué diferencia existe entre un constructor por copia y uno por movimiento? Ejemplifique.**  
diferencia en la primera fecha
falta ejemplo
