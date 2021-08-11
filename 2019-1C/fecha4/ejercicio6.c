/***
Escriba un programa que reciba por línea de comandos un
Puerto y una IP. El programa debe aceptar una unica conexión e imprimir en stdout todo lo recibido.
Al recibir el texto ‘FIN’ debe finalizar el programa sin imprimir dicho texto.
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
  hints.ai_flags = AI_PASSIVE;

  getaddrinfo(host,port,&hints,&res);
  int sock_fd = -1;
  ptr = res;

  while (ptr != NULL && sock_fd < 0){
    sock_fd = socket(ptr->ai_family,ptr->ai_socktype,ptr->ai_protocol);
    ptr = ptr->ai_next;
  }

  int val = 1;
  setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
  bind(sock_fd, res->ai_addr,res->ai_addrlen);
  listen(sock_fd, 1);
  int peer = accept(sock_fd, NULL, NULL);
  freeaddrinfo(res);

  char buff;
  bool termine = false;
  bool hubo_error = false;
  char fin[] = "FIN";
  int i = 0;
  while (!termine && !hubo_error){
    ssize_t resultado = recv(peer,&buff,sizeof(buff),0);
    if (resultado == -1){
      hubo_error = true;
    }else if (fin[i] == buff){
      i++;
      if (i == 3) termine = true;
    }else{
      fwrite(&buff,sizeof(buff),1,stdout);
      i = 0;
    }
  }

  shutdown(peer,SHUT_RDWR);
  shutdown(sock_fd,SHUT_RDWR);
  close(peer);
  close(sock_fd);

  return 0;
}
