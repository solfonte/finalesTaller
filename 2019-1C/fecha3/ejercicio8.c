/*
**8) Escriba un programa (desde la inicialización hasta la liberación de los recursos) que reciba
paquetes de la forma [nnn+nn+....+nnnn] (numeros separados por +, encerrados entre corchetes) e imprima
el resultado de la suma de cada paquete por pantalla. Al recibir un
paquete vacío (“[]”) debe cerrarse ordenadamente. No considere errores.**
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>
#include <stddef.h>


int main(int argc, const char* argv[]){

  if (argc < 3){
    printf("FALTAN ARGUMENTOS\n");
    return -1;
  }

  const char* port = argv[1];
  const char* host = argv[2];

  struct addrinfo hints;
  struct addrinfo* res;

  memset(&hints,0,sizeof(struct addrinfo));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = 0;

  getaddrinfo(NULL,port,&hints,&res) < 0)

  int sock_fd = socket(res->ai_family,res->ai_socktype,res->ai_protocol);
  connect(sock_fd,res->ai_addr,res->addrlen);
  freeaddrinfo(res);

  char buf;
  bool termine = false;
  int acumulador = 0;
  char aux = '0';

  while (!termine){
    ssize_t recv = recv(sock_fd,&buf,sizeof(buf),0);
    if (buf == '['){
      aux = buf;
    }else if (buf == ']'){
      if (aux == buf){
        termine = true;
      }else{
        printf("El resultado de la suma es: %i\n",acumulador);
        acumuldor = 0;
      }
    }else{
      if (buf != '+' && buf != '['){
        acumulador += (buf - '0');
      }
      aux = '0';
    }
  }

  shutdown(sock_fd,SHUT_RDWR);
  close(sock_fd);
}
