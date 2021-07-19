
//puerto e ip -> cliente

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  if (argc != 2){
    printf("faltan argumentos\n");
    return -1;
  }
  const char* puerto = argv[1];
  const char* host = argv[2];

  struct addrinfo hints;
  struct addrinfo* res;

  memset(&hints,0,sizeof(struct addrinfo));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = 0;

  if (getaddrinfo(host,puerto,&hints,&res) < 0){
    printf("error\n");
    return 0;
  }
  int socket_fd = socket(res->ai_family,res->ai_socktype,res->ai_protocol);
  connect(socket_fd,res->ai_addr,res->ai_addrlen);
  freeaddrinfo(res);

  char buf;
  bool error = false, termine = false;
  char fin = 'F';
  int contador = 0;
  int acumulador = 0;
  while(!termine && !error){
    ssize_t resultado_recv = recv(socket_fd,&buf,sizeof(buf),0);
    if (resultado_recv == -1){
      error = true;
    }else if (buf == fin){//no recibe otra letra
      termine = true;
    }else {
      if (contador % 2 == 0){
        acumulador += buf;
      }
    }
  }

  printf("la suma es: %i", acumulador);
  shutdown(socket_fd,SHUT_RDWR);
  close(socket_fd);
  return 0;
}
