**1) Declare la clase Número para encapsular una cadena numérica larga. Incluya al menos: Constructor(unsigned long), Constructor default y Constructor move; Operador <<, (), =, long y ++(int). Implemente el operador >>.**

resuelto en Numero.h  

**2) ¿Qué significa que una función es blocante?¿Cómo subsanaría esa limitación en término de mantener el programa ‘vivo’ ?**  

(ej 10 primera fecha)  

**3) Explique qué son los métodos virtuales y para qué sirven. De un breve ejemplo donde su uso sea imprescindible.**  

Los metodos virtuales son los metodos definidos dentro de una clase base y se redefinen en una clase derivada. Sirven para poder aplicar polimorfismo. Su uso imprescindible es, por ejemplo, en los casos en los que tenemos clases abstractas (o el ejemplo de la clase figura, que las distintas figuras tienen distintos comportamientos).  

**4) Escribir un programa C que procese el archivo “numeros.txt” sobre sí mismo (sin crear archivos intermedios y sin subir el archivo a memoria). El procesamiento consiste en leer grupos de 4 caracteres hexadecimales y reemplazarlos por los correspondientes dígitos decimales (que representen el mismo número leído pero en decimal).**

resuelto

**5) Explique qué se entiende por “compilación condicional”. Ejemplifique mediante código.**  

La compilacion condicional es el proceso en el cual se verifica condicionalmente si una parte de un archivo de codigo fuente debe ser compilado o no. Un uso común para la compilación condicional es evitar inclusiones múltiples del mismo archivo de encabezado.  
Por ejemplo,  

```
#ifndef __CLASE__
#define __CLASE__
.
.
.
#endif
```
Si ```__CLASE__``` ya fue definido, entonces salta directamente a la directiva ```#endif```. Si no, la define.  

**6) Escriba un programa C que tome 2 cadenas por línea de comandos: A y B; e imprima la cadena A después de haber duplicado todas las ocurrencias de B..**  
**ej.: reemp.exe “Este es el final” final -----> Este es el final final**

resuelto en otra fecha

**7) Escriba las siguientes definiciones/declaraciones:**  
  **a) Definición de una la función SUMA, que tome dos enteros largos con signo y devuelva su suma. Esta función sólo debe ser visible en el módulo donde se la define.**  
  ```
  static long int SUMA(long int numero, long int otroNumero){
    return numero + otroNumero;
  }
  ```
  **b) Declaración de un puntero a puntero a entero sin signo.**  
    ```
    extern unsigned int **p;
    ```
  **c) Definición de un caracter solamente visible en el módulo donde se define.**  
  ```
  static char c;
  ```

**8) ¿Qué valor arroja sizeof(int)? Justifique .**  

La salida de sizeof(int) depende de la arquitectura y el compilador que utilicemos. Puede devolver 4 en el caso de una arquitectura de 32 bits, u 8 en el caso de una arquitectura de 64 bits.  

**9) Describa el concepto de loop de eventos (events loop) utilizado en programación orientada a eventos y, en particular, en entornos de interfaz gráfica (GUIs).**

El loop de eventos es el bucle que maneja los eventos que se encuentran en la cola de eventos. El mismo es un patron muy usado en todas las aplicaciones que interactuan con el usuario de manera grafica, y consiste en un while que se ejecuta mientras se deba continuar atendiendo eventos. Por cada evento que procesa, se ejecuta un handler para dicho evento.  

**10) ¿Qué ventaja ofrece un lock raii frente al tradicional lock/unlock ?**  
ej 9 primera fecha  
