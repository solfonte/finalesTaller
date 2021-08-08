/*******
Escribir un programa ISO C que reciba por argumento el nombre de un archivo de texto y
lo procese sobre sí mismo (sin crear archivos intermedios ni subiendo todo su contenido
a memoria). El procesamiento consiste en eliminar las líneas de 1 sola palabra.
*******/

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

static void procesarArchivo(FILE* read,FILE* write){

  int bytesTotales = 0, tamLinea = 0, espacios = 0;
  char aux;

  fread(&aux,sizeof(aux),1,read);

  while(!feof(read)){
//itero por linea
    while(aux != '\n' && !feof(read)){
      fwrite(&aux,sizeof(aux),1,write);
      if (aux == ' '){
        espacios++;
      }
      tamLinea++;
      fread(&aux,sizeof(aux),1,read);
    }

//cuento los espacios de la linea
    if (espacios == 0){
      fseek(write,-tamLinea,SEEK_CUR);
  }else{
    bytesTotales += fwrite(&aux,sizeof(aux),1,write);
    bytesTotales += tamLinea;
  }
  espacios = 0;
  tamLinea = 0;
  fread(&aux,sizeof(aux),1,read);
  }
  ftruncate(fileno(write),bytesTotales);
}

int main(int argc, char const *argv[]) {
  FILE* read = fopen(argv[1],"r");
  FILE* write = fopen(argv[1],"r+");

  procesarArchivo(read,write);

  fclose(read);
  fclose(write);
  return 0;
}
