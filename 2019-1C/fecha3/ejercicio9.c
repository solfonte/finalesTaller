/***
Escriba una función ISO C que permita procesar un archivo texto que contenga frases (1 por línea)
sobre sí mismo, sin generar archivos intermedios ni cargar el archivo completo a memoria. El procesamiento
consiste en eliminar las palabras de más de 3 letras de cada línea.
***/

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

//funcion pedida
void procesarArchivo(const char* path){

  FILE* read = fopen(path,"r");
  FILE* write = fopen(path,"r+");
  int bytesTotales = 0;
  int cantLetras = 0;
  char aux;

  fread(&aux,sizeof(char),1,read);
  while (!feof(read)){

    while (aux != ' ' && aux != '\n' && !feof(read)){
      cantLetras++;
      fwrite(&aux,sizeof(char),1,write);
      fread(&aux,sizeof(char),1,read);
    }

    if (cantLetras > 3){
      fseek(write,-cantLetras,SEEK_CUR);
      if (aux == '\n') bytesTotales += fwrite(&aux,sizeof(char),1,write);
    }else{
      bytesTotales += fwrite(&aux,sizeof(char),1,write);
      bytesTotales += cantLetras;
    }

    fread(&aux,sizeof(char),1,read);
    cantLetras = 0;
  }

  ftruncate(fileno(write),bytesTotales);
  fclose(write);
  fclose(read);
}

int main(int argc,const char* argv[]){
  if (argc < 2) return -1;
  procesarArchivo(argv[1]);
  return 0;
}
