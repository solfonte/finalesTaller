/***
Escriba un programa (desde la inicialización hasta la liberación de los recursos) que reciba
paquetes de la forma [nnn+nn+....+nnnn] (numeros separados por +, encerrados entre corchetes) e imprima
el resultado de la suma de cada paquete por pantalla. Al recibir un
paquete vacío (“[]”) debe cerrarse ordenadamente. No considere errores.
***/

#include <stdlib.h>
#include <string.h>
#include <string>
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
  struct addrinfo* res,*ptr;

  memset(&hints,0,sizeof(struct addrinfo));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = 0;

  getaddrinfo(host,port,&hints,&res);

    int sock_fd = -1;
    ptr = res;

    while (ptr != NULL && sock_fd < 0){
      sock_fd = socket(res->ai_family,res->ai_socktype,res->ai_protocol);

      ptr = ptr->ai_next;
    }

  connect(sock_fd,res->ai_addr,res->ai_addrlen);
  freeaddrinfo(res);

  char buf;
  bool termine = false;
  int acumulador = 0;
  char aux = '0';

  int numero;
  std::string numTexto;

  while (!termine){
    recv(sock_fd,&buf,sizeof(buf),0);

    if (buf == '['){
      aux = buf;
    }else if (buf == '+'){
      numero = std::stoi(numTexto);
      acumulador += numero;
      numTexto.clear();
    }else if (buf == ']' && aux == '['){
      termine = true;
    }else if (buf == ']' && aux != '['){
      numero = std::stoi(numTexto);
      acumulador += numero;
      printf("El resultado de la suma es: %i\n",acumulador);
      numTexto.clear();
      acumulador = 0;
    }else{
      numTexto.push_back(buf);
      aux = '\0';
    }
  }

  shutdown(sock_fd,SHUT_RDWR);
  close(sock_fd);
}
