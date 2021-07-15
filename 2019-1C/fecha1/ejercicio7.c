/*****
Escriba un programa que reciba por línea de comandos un Puerto y una IP. El programa debe aceptar
una única conexión e imprimir en stdout la sumatoria de los enteros recibidos en cada paquete. Un paquete
está definido como una sucesión de números recibidos como texto, en decimal, separados por comas y terminado
con un signo igual (ej: “27,12,32=”).
Al recibir el texto ‘FIN’ debe finalizar el programa ordenadamente liberando los recursos.**
****/

//puerto e ip -> cliente

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char const *argv[]) {
  if (argc != 2){
    printf("faltan argumentos\n");
    return -1;
  }
  char* puerto = argv[1];
  char* host = argv[2];

  struct addrinfo hints;
  struct addrinfo* resultados,*ptr;

  memset(hints,0,sizeof(struct addrinfo));
  hints->ai_family = AF_INET;
  hints->ai_socktype = SOCK_STREAM;
  hints->ai_flags = 0;

  if (getaddrinfo(host,puerto,&hints,&resultados) < 0){
    printf("error\n");
    return 0;
  }
  ptr = resultados;
  int socket_fd = socket(info->ai_family,info->ai_socktype,info->ai_protocol);
  connect(socket_fd,ptr->ai_addr,ptr->ai_addrlen);
  freeaddrinfo(resultados);

  ssize_t bytes_rcv = 0;
  bool termine = false, error = false, fin = false;
  char buffer[200];
  size_t length = 200;

  int acumulador = 0;
  while(!termine && !error){
    ssize_t tam_recv = length - (size_t)bytes_rcv;
    ssize_t resultado_recv = recv(socket_fd,buffer,tam_rcv,0);
    bytes_rcv = resultado_recv;
    if (resultado_recv == 0){
      termine = true;
    }else if (resultado_recv == -1){
      error = true;
    }else {
      for (int i = 0; i < bytes_rcv; i += 2){
        if (buffer[i] != 'F' && buffer[i] != 'I' && buffer[i] != 'N'){
          acumulador += buffer[i];
        }else{
          fin = true;
        }
      }
      bytes_rcv = 0;
    }
  }

  if (!fin){
    for (int i = 0; i < bytes_rcv; i += 2){
      if (buffer[i] != 'F' && buffer[i] != 'I' && buffer[i] != 'N'){
        acumulador += buffer[i];
      }else{
        fin = true;
      }
    }
  }


  printf("la suma es: %i", acumulador);

  shutdown(socket_fd,SHUT_RDWR);
  close(socket_fd);
  return 0;
}
