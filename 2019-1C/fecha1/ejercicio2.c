

//NO FUNCIONA BIEN
/*
#define TAM_MAX 1000


char* Replicar (char* cadena,int i1,int i2,int q){

  char aux[TAM_MAX];
  char final[TAM_MAX];

  size_t tam_cadena = strlen(cadena);

  if (i1 < 0 || i2 < 0 || tam_cadena < (i1 + 1) || tam_cadena < (i2 + 1)){
    return NULL;
  }

  size_t longACopiar = i2 - i1 + 1;

  strncpy((void*)(&aux),(void*)(&cadena[i1]),longACopiar);

  printf("cadena1: %s\n",aux);

  strncpy((void*)(&final),(void*)cadena,i1);

  printf("cadena2: %s\n",final);

  for (int i = 0; i < q; i++){
    // falta ver que no me pase del largo
    int inicio = (i1 == 0? 0 : i1 + 1) + longACopiar * i;
    strncpy((void*)(&final[inicio]),(void*) (aux),longACopiar);
  }
  strncpy((void*)(&final),(void*)(&cadena),tam_cadena - i2);

  char* cadenaCompleta = (char*)malloc(sizeof(char) * (tam_cadena + longACopiar * (q-1)));
  strncpy (cadenaCompleta,final,(tam_cadena + longACopiar * (q-1)));
  return cadenaCompleta;
}
*/

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
