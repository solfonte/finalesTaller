#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//NO FUNCIONA BIEN

#define TAM_MAX 1000


char* Replicar (char* cadena,int i1,int i2,int q){

  char aux[TAM_MAX];
  size_t tam_cadena = strlen(cadena);

  if (i1 < 0 || i2 < 0 || tam_cadena < (i1 + 1) || tam_cadena < (i2 + 1)){
    return NULL;
  }

  size_t longACopiar = i2 - i1 + 1;

  strncpy((void*)(&aux),(void*)(&cadena[i1]),longACopiar);
  char final[TAM_MAX];

  strncpy((void*)(&final[0]),(void*)(&cadena[0]),i1);
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

int main(){

  char cadena[] = "hola";
  char* replica = Replicar(cadena,1,2,4);
  printf("cadena: %s \n",replica);
  return 0;
}
