/***
Escriba un programa (desde la inicialización hasta la liberación de
los recursos) que reciba paquetes de la forma nnn+nn+....+nnnn= (numeros
separados por +, seguidos de =) e imprima el resultado de la suma de cada
paquete por pantalla. Al recibir un paquete vacío (“=”) debe cerrarse ordenadamente.
No considere errores.
***/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

//esta mal. Resuelto parecido en otra fecha de 2020

int main(int argc, const char* argv[]){
  //no se si es cliente o servidor, programo la parte de procesar los paquetes

  bool termine = false, hubo_error = false;
  int acumulador = 0;
  char buf;

  while (!termine && !hubo_error){
    ssize_t resultado = recv(sock_fd,&buf,sizeof(buf),0);
    if (resultado == -1){
      hubo_error = true;
    }else if(buf == '='){
      if (contador == 2){
        termine = true;
      }else{
        printf("la suma es: %i\n",acumulador);
        acumulador = 0;
      }
    }else{
      if (buf != '+'){
        acumulador += (buf - '0');
      }
    }
  }
}
