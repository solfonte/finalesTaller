**1) Explique qué es y para qué sirve un constructor de copia en C++.**  
  **a) Indique cómo se comporta el sistema si éste no es definido por el desarrollador;**  
  **b) Explique al menos una estrategia para evitar que una clase particular sea copiable;**  
  **c) Indique qué diferencia existe entre un constructor de copia y uno move.**      

Un constructor por copia en c++ es un tipo de constructor de clase que devuelve una copia de la instancia recibida por parametro.
  a) Si este no es definido por el desarrollador, el compilador crea uno por defecto.
  b) Para que una clase no sea copiable se puede eliminar el constructor por copia de la siguiente manera:
    Supongamos que tenemos una clase Complejo. Eliminamos el constructor por copia asi:
    ```
    Complejo(Complejo& c) delete;
    ```
  c) La diferencia entre estos dos constructores es que el primero devuelve una copia de una instancia recibida. Osea, copia los atributos de la clase recibida por parametros. En cambio, el constructor por movimiento lo que hace es "mover" las referencias y/o punteros que se encuentren dentro de la instancia recibida por parametro, y esta instancia recibida deja de apuntar a estas referencias y/o punteros.

  **Chequear esta respuesta**

  **2) Escriba una función ISO C llamada Replicar que reciba 1 cadena (S), dos índices (I1 e I2) y una cantidad (Q). La función debe retornar una copia de S salvo los caracteres que se encuentran entre los índices I1 e I2 que serán duplicados Q veces.Ej. replicar(“Hola”, 1, 2, 3) retorna “Hololola”.**  


  **3) Describa con exactitud las siguientes declaraciones/definiciones globales:**  
  **1. void (*F)(int i);**
  **2. static void B(float a, float b){}**
  **3. int *(*C)[5];**

  Supongo que son declaraciones/definiciones en c
  1. Se trata de la declaracion de una funcion que retorna void, y recibe pr parametro un tipo de dato int.
  2. Se trata de la definicion de un procedimiento que no puede ser llamado desde otro modulo, ya que se define con ```static```, y recibe por parametros dos floats.
  3. Se trata de la declaracion de un arreglo de 5 elementos, y este arreglo contiene punteros a ints.

  **4) Escribir un programa ISO C que reciba por argumento el nombre de un archivo de texto y lo procese sobre sí mismo (sin crear archivos intermedios ni subiendo todo su contenido a memoria). El procesamiento consiste en eliminar las líneas de 1 sola palabra.**

  parte de la resolucion en ejercicio4.c

  **5) Declare una clase de elección libre. Incluya todos los campos de datos requeridos con su correcta exposición/publicación, y los operadores ++, -, ==, >> (carga), << (impresión), constructor move y operador float().**  


**6) ¿Qué es una macro de C? Describa las buenas prácticas para su definición y ejemplifique.**  

En C una macro es una porción de código que se traduce en tiempo de preproceso. Osea, al momento de traducir el codigo a codigo maquina, durante la etapa de preproceso.

**faltan las buenas practicas.**

  **7) Escriba un programa que reciba por línea de comandos un Puerto y una IP. El programa debe aceptar una única conexión e imprimir en stdout la sumatoria de los enteros recibidos en cada paquete. Un paquete está definido como una sucesión de números recibidos como texto, en decimal, separados por comas y terminado con un signo igual (ej: “27,12,32=”). Al recibir el texto ‘FIN’ debe finalizar el programa ordenadamente liberando los recursos.**



  **8) Describa el proceso de transformación de código fuente a un ejecutable. Precise las etapas, las tareas desarrolladas y los tipos de error generados en cada una de ellas.**

  La compilacion consta de 3 etapas: preprocesamiento, compilacion y link edicion (en ese orden). Se parte del codigo fuente y al finalizar se obtiene el ejecutable.
    * Prerpocesamiento: se procesan las macros y las directivas al compilador.
    * Compilacion: Se pasa de un archivo de texto a un codigo objeto. Contiene la info sobre las funciones, segmento de texto datos etc.
    * Link edicion: etapa en la que se linkean los distintos modulos para generar el archivo ejecutable. Junta las dependencias.

**faltan los errores**

  **9) ¿Qué ventaja ofrece un lock raii frente al tradicional lock/unlock ?**  

  Un lock raii es una clase que realiza un lock de un mutex al crearse, y luego realiza el unlock de la clase al destruirse. El destructor se invoca automaticamente por ser raii, al finalizar el scope de la funcion, con lo cual no se corre el riesgo de dejar un hilo bloqueado, ya sea porque el desarrollador se olvido o porque se lanzo una excepcion, por ejemplo.

  **10) ¿Qué significa que una función es blocante?¿Cómo subsanaría esa limitación en términos de mantener el programa ‘vivo’ ?**  
