/*
Escribir un programa ISO C MULTIPLATAFORMA que procese el archivo “bigEndian.dat” sobre sí mismo, leyendo nros. de
4 bytes Big-Endian y triplicando los impares.
*/

#include <inttypes.h>

#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(){

  const char* file = "bigEndian.dat";

  FILE* read = fopen(file,"r");
  FILE* write = fopen(file,"r+");

  int elementos = 0;
  uint32_t aux,num;

  //leo contenido total
  while (!feof(read)){
    elementos += fread(&num,sizeof(uint32_t),1,read);
  }

  //copio al final para expandir
  //solo escribo una vez porque pide duplicar
  int elemEscritos = 0;
  rewind(read);
  fseek(write,0,SEEK_END);
  while (elemEscritos < elementos){
    fread(&num,sizeof(uint32_t),1,read);
    elemEscritos += fwrite(&num,sizeof(uint32_t),1,write);
  }
  elemEscritos = 0;
  rewind(read);
  fseek(write,0,SEEK_END);
  while (elemEscritos < elementos){
    fread(&num,sizeof(uint32_t),1,read);
    elemEscritos += fwrite(&num,sizeof(uint32_t),1,write);
  }

  //resuelvo el problema
  int bytes = 0;
  rewind(write);
  fseek(read,-elementos * sizeof(uint32_t),SEEK_END);
  fread(&num,sizeof(uint32_t),1,read);

  while (!feof(read)){
    aux = ntohl(num);
    fwrite(&num,sizeof(uint32_t),1,write);
    bytes += sizeof(uint32_t);
    if (aux % 2 == 1){
      fwrite(&num,sizeof(uint32_t),1,write);
      bytes += sizeof(uint32_t);
      fwrite(&num,sizeof(uint32_t),1,write);
      bytes += sizeof(uint32_t);
    }
    fread(&num,sizeof(uint32_t),1,read);
  }

  ftruncate(fileno(write),bytes);

  fclose(write);
  fclose(read);
  return 0;
}
