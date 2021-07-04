**1) Declare la clase Número para encapsular una cadena numérica larga. Incluya al menos:   Constructor(unsigned long), Constructor default y Constructor move; Operador <<, (), =, long y ++(int). Implemente el operador >>.**



**2) ¿Qué significa que una función es blocante?¿Cómo subsanaría esa limitación en término de mantener el programa ‘vivo’ ?**  
en el final de la primera fecha esta la respuesta


**3) Explique qué son los métodos virtuales y para qué sirven. De un breve ejemplo donde su uso sea imprescindible.**  

Los metodos virtuales son los metodos declarados dentro de una clase base y se re definen en una clase derivada. Sirven para poder aplicar polimorfismo.
** falta ejemplo imprescindible**


**4) Escribir un programa C que procese el archivo “numeros.txt” sobre sí mismo (sin crear archivos intermedios y sin subir el archivo a memoria). El procesamiento consiste en leer grupos de 4 caracteres hexadecimales y reemplazarlos por los correspondientes dígitos decimales (que representen el mismo número leído pero en decimal).**


**5) Explique qué se entiende por “compilación condicional”. Ejemplifique mediante código.**  

La compilacion condicional es el proceso en el cual se verifica condicionalmente si una parte de un archivo de codigo fuente debe ser compilado o no.
Por ejemplo,
```
#ifndef __CLASE__
#define __CLASE__
.
.
.
#endif
```
Si __CLASE__ ya fue definido, entonces ejecuta directamente a la directiva ```#endif```. Si no, la define. Un uso común para la compilación condicional es evitar inclusiones múltiples del mismo archivo de encabezado.

**6) Escriba un programa C que tome 2 cadenas por línea de comandos: A y B; e imprima la cadena A después de haber duplicado todas las ocurrencias de B..**  
**ej.: reemp.exe “Este es el final” final -----> Este es el final final**



**7) Escriba las siguientes definiciones/declaraciones:**  
  **a) Definición de una la función SUMA, que tome dos enteros largos con signo y devuelva su suma. Esta función sólo debe ser visible en el módulo donde se la define.**
  **b) Declaración de un puntero a puntero a entero sin signo.**
  **c) Definición de un caracter solamente visible en el módulo donde se define.**



**8) ¿Qué valor arroja sizeof(int)? Justifique .**  

La salida de sizeof(int) depende de la arquitectura y el compilador que utilicemos. Esta puede resultar en 4, como en el caso de una arquitectura de 32 bits.

**9) Describa el concepto de loop de eventos (events loop) utilizado en programación orientada a eventos y, en particular, en entornos de interfaz gráfica (GUIs).**

** clase de poe**

**10) ¿Qué ventaja ofrece un lock raii frente al tradicional lock/unlock ?**  
en el final de la primera fecha esta la respuesta
