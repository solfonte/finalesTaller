//puerto e ip -> cliente

/***
Escriba un programa que reciba por línea de comandos un Puerto y una IP.
El programa debe aceptar una única conexión e imprimir en stdout la sumatoria
de los enteros recibidos en cada paquete. Un paquete está definido como una
sucesión de números recibidos como texto, en decimal, separados por comas y
terminado con un signo igual (ej: “27,12,32=”). Al recibir el texto ‘FIN’
debe finalizar el programa ordenadamente liberando los recursos.
***/

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdbool.h>
#include <string>
#include <string.h>

int main(int argc, char const *argv[]) {
  if (argc != 3){
    printf("faltan argumentos\n");
    return -1;
  }
  const char* puerto = argv[1];
  const char* host = argv[2];

  struct addrinfo hints;
  struct addrinfo* res, *ptr;

  memset(&hints,0,sizeof(struct addrinfo));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  getaddrinfo(host,puerto,&hints,&res);
  int sock_fd = -1;
  ptr = res;

  while (ptr != NULL && sock_fd < 0){
    sock_fd = socket(ptr->ai_family,ptr->ai_socktype,ptr->ai_protocol);
    ptr = ptr->ai_next;
  }

  int val = 1;
  setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
  bind(sock_fd, ptr->ai_addr,ptr->ai_addrlen);
  listen(sock_fd, 1);
  int peer = accept(sock_fd, NULL, NULL);
  freeaddrinfo(res);

  char buf;
  bool error = false, termine = false;
  char fin = 'F';
  int acumulador = 0;
  int numero;

  std::string numTexto;

  while(!termine && !error){
    ssize_t resultado_recv = recv(peer,&buf,sizeof(buf),0);
    if (resultado_recv == -1){
      error = true;
    }else if (buf == fin){//no recibe otra letra
      termine = true;
    }else {
      if (buf == ','){
        numero = std::stoi(numTexto);
        acumulador += numero;
        numTexto.clear();
      }else if (buf == '='){
        numero = std::stoi(numTexto);
        acumulador += numero;
        printf("la suma es: %i\n", acumulador);
        numTexto.clear();
        acumulador = 0;
      }else{
        numTexto.push_back(buf);
      }
    }
  }

  shutdown(peer,SHUT_RDWR);
  shutdown(sock_fd,SHUT_RDWR);
  close(peer);
  close(sock_fd);

  return 0;
}
