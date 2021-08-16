/***
Escriba un programa que reciba por línea de comandos un Puerto y una IP. El programa debe establecer una unica conexión, y enviar todo el texto
ingresado por stdin. Cuando se ingrese el texto ‘FIN’ debe finalizar el programa sin enviar dicho texto.
***/

#include <sys/socket.h>
#include <stdio.h>
#include <netdb.h>
#include <unistd.h>
#include <cstring>

int main(int argc, const char* argv[]){
  const char* port = argv[1];
  const char* host = argv[2];

  struct addrinfo hints, *res, *ptr;
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;

  getaddrinfo(host,port,&hints,&res);

  int fd = -1;
  ptr = res;
  const struct sockaddr *addr;
  socklen_t addrlen;

  while (ptr != NULL && fd < 0){
    fd = socket(ptr->ai_family,ptr->ai_socktype,ptr->ai_protocol);
    addr = ptr->ai_addr;
    addrlen = ptr->ai_addrlen;
    ptr = ptr->ai_next;
  }
  connect(fd,addr,addrlen);
  freeaddrinfo(res);
  char buf;
  bool termine = false;
  char fin[] = "FIN";
  int i = 0;
  while (!termine){
    recv(fd,&buf,sizeof(buf),0);
    if (buf == fin[i]){
       i++;
      if (i == 3) termine = true;
    }else{
      i = 0;
      fwrite(&buf,sizeof(buf),1,stdin);
    }
  }
  shutdown(fd,SHUT_RDWR);
  close(fd);
  return 0;
}
