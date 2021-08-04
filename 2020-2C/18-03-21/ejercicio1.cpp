/*
**1) Escriba un programa (desde la inicialización hasta la liberación
de los recursos) que escuche el puerto 120 y reciba paquetes de la
forma: 		[CHAR_LIM]xxxxx.xxxxxxx[CHAR_LIM]**
**donde [CHAR_LIM] puede ser cualquier caracter ASCII**
**Al completar la recepción del paquete deberá imprimir el caracter con
más apariciones del mismo (sin considerar [CHAR_LIM]). Al recibir un paquete vacío
([CHAR_LIM][CHAR_LIM]) debe cerrarse ordenadamente. No considere errores.**
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(){

  const char* port = "120";

  struct addrinfo hints;
  struct addrinfo* res;

  memset(&hints,0,sizeof(struct addrinfo));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = 0;

  getaddrinfo(NULL,port, &hints,&res);
  int sock_fd = socket(res->ai_family,res->ai_socktype,res->ai_protocol);
  freeaddrinfo(res);
  int val = 1;
  setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
  bind(sock_fd, res->ai_addr,res->ai_addrlen);
  listen(sock_fd, 10);
  int peer = accept(sock_fd, NULL, NULL);

  char buff;
  char* aux = (char*)malloc(sizeof(char));
  int i = 0;
  bool termine = false, hubo_error = false;
  char fin[] = [CHAR_LIM];
  int contadorFin = 0, veces = 0;

  while (!hubo_error && !termine){
    ssize_t res = recv(sock_fd,&buff,sizeof(buff),0);
    if (buff == fin[contadorFin]){
      contadorFin ++;
      if (contadorFin == 3 && veces == 2){
        termine == true;
      }else if (contadorFin == 3){
        veces ++;
      }
    }else{
      aux[i] = buff;
      i++;
      aux = (char*)realloc(aux, sizeof(char) + sizeof(aux));
      contadorFin = 0;
    }
  }
  char mayor;
  char otro;
  int aparicionesMayor = 0;
  int aparicionesOtro = 0;
  for (int j = 0; j < i; j++){
    otro = aux[j];
    for (int k = j; k < i;k++){
      if (aux[j] == aux[k]) aparicionesOtro ++;
    }
    if (aparicionesOtro > aparicionesMayor){
      aparicionesMayor = aparicionesOtro;
      mayor = otro;
    }
    aparicionesOtro = 0;
  }

  printf("caracter con mas apariciones: %c",mayor);

  shutdown(peer,SHUT_RDWR);
  shutdown(sock_fd,SHUT_RDWR);
  close(peer);
  close(sock_fd);

}
