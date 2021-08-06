/*
**3) Escribir un programa ISO C que procese el archivo “nros2bytes.dat”
sobre sí mismo, duplicando los enteros de 2 bytes múltiplos de 3.**
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdint.h>
#include <arpa/inet.h>

int main(){

  const char* file = "nros2Bytes.dat";

  FILE* read = fopen(file,"r");
  FILE* write = fopen(file,"r+");

  int bytes = 0, contador = 0;
  uint16_t num,aux;

  fread(&num,sizeof(uint16_t),1,read);
  while (!feof(read)){
    aux = htons(num);
    fwrite(&num,sizeof(uint16_t),1,write);
    bytes += sizeof(uint16_t);
    if (aux % 3 == 0){
      fwrite(&num,sizeof(uint16_t),1,write);
      bytes += sizeof(uint16_t);
    }
    fread(&num,sizeof(uint16_t),1,read);
  }
  ftruncate(fileno(write),bytes);
  fclose(write);
  fclose(read);
  return 0;
}
