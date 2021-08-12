/***
Escribir un programa ISO C que procese el archivo “nros2bytes.dat”
sobre sí mismo, duplicando los enteros de 2 bytes múltiplos de 3.
***/

#include <inttypes.h>

#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(){

  const char* file = "nros2Bytes.dat";

  FILE* read = fopen(file,"r");
  FILE* write = fopen(file,"r+");

  int elementos = 0;
  uint16_t aux,num;

  //leo contenido total
  while (!feof(read)){
    elementos += fread(&num,sizeof(uint16_t),1,read);
  }

  //copio al final para expandir
  //solo escribo una vez porque pide duplicar
  int elemEscritos = 0;
  rewind(read);
  fseek(write,0,SEEK_END);
  while (elemEscritos < elementos){
    fread(&num,sizeof(uint16_t),1,read);
    elemEscritos += fwrite(&num,sizeof(uint16_t),1,write);
  }

  //resuelvo el problema
  int bytes = 0;
  rewind(write);
  fseek(read,-elementos * sizeof(uint16_t),SEEK_END);
  fread(&num,sizeof(uint16_t),1,read);

  while (!feof(read)){
    aux = ntohs(num);
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
