# Finales de taller de programacion 75.42

Temas:
* sockets
* archivos
* strings
* clases c++


# Lenguaje C y C++

## Memoria

* El tamaño en bytes de los tipos depende de la arquitectura y del compilador.
* El compilador puede guardar las variables en posiciones de memoria múltiplos de 4 (depende de la arquitectura y de los flags de compilación): variables alineadas son accedidas más rápidamente que las desalineadas. Como contra, la alineación despedicia espacio (padding) hay un tradeoff entre velocidad y espacio.
* El tamaño de un puntero no depende de a que tipo apunta. Todos los punteros ocupan el mismo tamaño (que depende de la arquitectura).
* El padding se hace mas notorio en las estructuras: el acceso a cada atributo es rápido pero hay memoria desperdiciada.
* Endiannes: se vuelve relevante en el momento que queremos interpretar un int como una tira de bytes (char*) o viceversa. Se puede cambiar el endianess de una variable short int y int del endianess nativo o "del host" a big endian o "el endianess de la red" y viceversa:
```
#include <arpa/inet.h>.
```

  - Host to Network
```
    htons(short int) htonl(int)
```
  - Network to Host
  ```
  ntohs(short int) ntohl(int)
  ```
