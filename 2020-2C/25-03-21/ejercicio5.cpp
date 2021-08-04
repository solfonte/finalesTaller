/*
5) Escriba un programa que reciba por línea de comandos un Puerto y una IP. El programa debe conectarse
y quedar en escucha de paquetes con la forma “d..d+d..d+...=”. El programa debe imprimir en stdout cada suma
hasta que la misma sea 0 (cero). En ese caso debe finalizar ordenadamente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <stdbool.h>
#include <string>

int main(int argc,const char* argv[]){

  if (argc < 3){
    printf("FALTAN ARGUMENTOS\n");
    return -1;
  }
  const char* port = argv[1];
  const char* host = argv[2];

  struct addrinfo hints;
  struct addrinfo* res, *ptr;

   memset(&hints,0,sizeof(struct addrinfo));
   hints.ai_family = AF_INET;
   hints.ai_socktype = SOCK_STREAM;
   hints.ai_flags = 0;

   getaddrinfo(host,port,&hints,&res);
   ptr = res;
   int sock_fd = socket(ptr->ai_family,ptr->ai_socktype,ptr->ai_protocol);
   connect(sock_fd,ptr->ai_addr,ptr->ai_addrlen);
   freeaddrinfo(res);

   char buff;
   bool termine = false;
   bool hubo_error = false;
   size_t bytes_recv = 0;
   int acumulador = 0;

   while (hubo_error != 0 && !termine){
     ssize_t resultado = recv(sock_fd,&buff,sizeof(buff),0);
     if (resultado == -1){
       hubo_error = true;
     }else if (buff != '+' && buff != '='){
       int numero = std::stoi(&buff);
       acumulador += numero;
     }else if(buff == '='){
       if (acumulador != 0){
         printf("suma: %i", acumulador);
         acumulador = 0;
       }else{
         termine = true;
       }
     }
   }

  shutdown(sock_fd,SHUT_RDWR);
  close(sock_fd);

  return 0;

}
