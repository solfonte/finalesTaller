**1) Describa con exactitud las siguientes declaraciones/definiciones globales:**
**● extern char *(*A)();**
**● float *(*C)[5];**
**● short *B(){return NULL;}**

resuelto en otro final
**2) Escriba una rutina que dibuje un cuadrado amarillo centrado y de 1/3 del alto de la ventana.**

resuelto parecido en la fecha anterior pero con 1/4

**3) ¿Se puede evitar que un objeto de una clase sea copiado?¿y clonado?. En caso afirmativo explique cómo puede hacerse. En caso negativo explique por qué no se puede.**

resuelto en otro final

**4) Declare la clase NumeroGrande para almacenar Numeros de 1000 dígitos, considerando:**
**● Atributos que considere necesarios**
**● Accesibilidad a la Clase**
**● Incluir los operadores -, ++ (post-incremento), --(pre-incremento), >> (impresión), << (carga desde consola), float**

resuelto en otro final

**5) Mediante una porción de código ejemplifique el uso de un constructor por copia. Expliqué el por qué de la necesidad de su uso.**

Podemos usar el constructor por copia de las siguientes maneras:

```c
  Complejo complejo(1,2)
  Complejo numeroComplejo(complejo);
```

En la primer linea estamos llamando al constructor de la clase Complejo que devuelve una instancia valida recibiendo parametros. En la segunda linea, lo que hacemos es crear un nuevo objeto instanciando su constructor por copia. La idea es que al crear un objeto de esta manera, lo que hacemos es crear una nueva instancia copiando bit a bit el objeto recibido por parametro.

La necesidad de su uso se da en el caso de que queramos crear una copia de un objeto en caso de que no queramos modificar la instancia original.

**6) ¿Qué es la STL?¿Qué recursos (funciones, algoritmos, etc.) ofrece?¿Qué ventaja nos da su uso?**

La STL es la standard template library de c++. En esta biblioteca podemos encontrar una serie de containers, que son templates. Nos ofrece iteradores, containers (vectores, listas, mapas, etc), algoritmos de sort, etc. Su uso nos trae la ventaja de que no tenemos que implementar nosotros todo eso que nos ofrece la libreria, ademas de que si se utilizan de manera correcta pueden hacer muy eficiente nuestro codigo.  

**7) Escriba un programa que reciba por línea de comandos un Puerto y una IP. El programa debe conectarse al destino indicado y quedar en escucha de paquetes con la forma “d..d|d..d|… >”. El programa debe imprimir en stdout el checksum (sumatoria módulo 256) de cada paquete. Cuando se reciba un paquete vacío se debe finalizar ordenadamente.**



**8) ¿Qué es un Deadlock? Ejemplifique con código que constituya un indefectible caso.**

resuelto en otro final

**9) Escribir un programa ISO C MULTIPLATAFORMA que procese el archivo “bigEndian.dat” sobre sí mismo, leyendo nros. de 4 bytes Big-Endian y triplicando (escribirlos 3 veces) los múltiplos de 3.**

resuelto en otro final

**10) Implemente un programa de 2 threads (producer-consumer) que genere e imprima los números del 1 al 100.**

resuelto en el tema anterior
