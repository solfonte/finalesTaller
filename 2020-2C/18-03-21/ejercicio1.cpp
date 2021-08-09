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
#include <string>

//no anda

int main(){

  const char* port = "8080";

  struct addrinfo hints;
  struct addrinfo* res,*ptr;

  memset(&hints,0,sizeof(struct addrinfo));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  getaddrinfo("127.0.0.1",port, &hints,&res);
  int sock_fd = -1;
  ptr = res;

  while (sock_fd < 0){
    sock_fd = socket(ptr->ai_family,ptr->ai_socktype,ptr->ai_protocol);
    ptr = ptr->ai_next;
  }

  int val = 1;
  setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
  bind(sock_fd, res->ai_addr,res->ai_addrlen);
  listen(sock_fd, 1);
  int peer = accept(sock_fd, NULL, NULL);
  freeaddrinfo(res);

//hasta aca servidor

  char buff,aux = '0';
  std::string caracteres;
  bool termine = false;
  int corchete = 0, i = 0;

  while (!termine){
    recv(peer,&buff,sizeof(buff),0);

    if (buff == '['){
      aux = buff;
      corchete++;
      i++;
    }else if (buff == ']'){
      if (i == 2 && caracteres.empty()){
        termine = true;
      }else{
        aux = '\0';
        corchete = 0;
        char mayor;
        char otro;
        int aparicionesMayor = 0;
        int aparicionesOtro = 0;
        std::string::iterator it1;
        for (it1 = caracteres.begin(); it1 != caracteres.end(); ++it1){
          std::string::iterator it2 = caracteres.begin();
          otro = *it2;
          for (;it2 != caracteres.end(); ++it2){
            if (*it1 == *it2) aparicionesOtro ++;
          }
          if (aparicionesOtro > aparicionesMayor){
            aparicionesMayor = aparicionesOtro;
            mayor = otro;
          }
          aparicionesOtro = 0;
        }
        printf("caracter con mas apariciones: %c",mayor);
        caracteres.clear();
      }
    }else if (aux != '['){
      caracteres.push_back(buff);
      i = 0;
    }
  }

  shutdown(peer,SHUT_RDWR);
  shutdown(sock_fd,SHUT_RDWR);
  close(peer);
  close(sock_fd);

}
