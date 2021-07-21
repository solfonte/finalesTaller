#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#define TAM_MAX 800

static int obtenerLineaCorregida(char leido[TAM_MAX],FILE* read){
  char aux;
  int bytes = 0, cantLetras = 0,i = 0,escribi = 0;
  fread(&aux,1,1,read);
  while (aux != '\n'){
    while (aux != ' ' && aux != '\n'){
      cantLetras ++;
      fread(&aux,sizeof(char),1,read);
    }
    if (cantLetras > 3){
      fseek(read,-(cantLetras + 1),SEEK_CUR);
      while (escribi < cantLetras){
        fread(&aux,1,1,read);
        leido[i] = aux;
        i++;
        bytes++;
        escribi++;
      }
      fread(&aux,1,1,read);
      leido[i] = aux;
      i++;
      bytes++;
    }
    fread(&aux,1,1,read);
    cantLetras = 0;
    escribi = 0;
  }
  leido[i] = aux;
  bytes++;
  return bytes;
}

//funcion pedida
void procesarArchivo(const char* path){

  FILE* read = fopen(path,"r");
  FILE* write = fopen(path,"r+");

  int bytesTotales = 0,tamLinea;
  char leido[TAM_MAX];

  while (!feof(read)){
    tamLinea = obtenerLineaCorregida(leido,read);
    fwrite(leido,sizeof(char),tamLinea,write);
    bytesTotales += tamLinea;
  }
  fseek(write,bytesTotales,SEEK_CUR);
  ftruncate(fileno(write),bytesTotales);
  fclose(write);
  fclose(read);
}

int main(int argc,const char* argv[]){
  if (argc < 2) return -1;
  procesarArchivo(argv[1]);
  return 0;
}
