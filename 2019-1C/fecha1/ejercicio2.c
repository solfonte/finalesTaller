
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* Replicar (char* cadena,int i1,int i2,int q){
  int tamCadena = strlen(cadena);
  int tamanioFinal = tamCadena + (i2 - i1) * q;
  char* aux = malloc(tamanioFinal * 4);
  int i = 0;

  //copio la cadena entre 0 e i1;
  while (i < i1){
    aux[i] = cadena[i];
    i++;
  }

  //copio replicas
  int copia = 0;
  while (copia < q){
    for (int j = 0; j <= i2 - i1; j++){
      aux[i + j] = cadena[i1 + j];
    }
    i += i2 - i1 + 1;
    copia++;
  }

  int k = 0;
  //copio lo que queda
  while (cadena[i2 + k] != '\0'){
    aux[i] = cadena[i2 + k];
    k++;
  }
  aux = '\0';
  return aux;
}

int main(){

  char cadena[] = "hola";
  char* replica = Replicar(cadena,1,2,3);
  printf("cadena3: %s \n",replica);
  return 0;
}
