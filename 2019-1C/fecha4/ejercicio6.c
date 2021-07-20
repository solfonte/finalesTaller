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
  struct addrinfo* res;

  memset(&hints,0,sizeof(struct addrinfo));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = 0;

  getaddrinfo(NULL,port,&hints,&res);
  int sock_fd = socket(res->ai_family,res->ai_socktype,res->ai_protocol);
  connect(sock_fd,res->ai_addr,res->ai_addrlen);
  freeaddrinfo(res);

  char buff;
  bool termine = false;
  bool hubo_error = false;
  size_t bytes_rcv = 0;
  char fin[] = "FIN";
  int i = 0;
  while (!termine && !hubo_error){
    ssize_t resultado = recv(sock_fd,&buff,sizeof(buff),0);
    if (resultado == -1){
      hubo_error = true;
    }else if (fin[i] == buff){
      if (i == 3) termine = true;
    }else{
      fwrite(&buff,sizeof(buff),1,stdout);
      i = 0;
    }
  }

  shutdown(sock_fd,SHUT_RDWR);
  close(sock_fd);

  return 0;
}
