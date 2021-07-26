/*******
Escribir un programa ISO C que reciba por argumento el nombre de un archivo de texto y
lo procese sobre sí mismo (sin crear archivos intermedios ni subiendo todo su contenido
a memoria). El procesamiento consiste en eliminar las líneas de 1 sola palabra.
*******/

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#define TAM_MAX 800

static int obtenerLineaCorregida(char leido[TAM_MAX],FILE* read){
  char aux = '\0';
  int i = 0, espacios = 0, bytes = 0;
  while(aux != '\n' && !feof(read)){
    fread(&aux,sizeof(char),1,read);
    if (aux == ' '){
      espacios++;
    }
    printf("%c",aux);
    leido[i] = aux;
    i++;
    bytes++;
  }
  if (espacios == 0){
    bytes = 0;
  }
  return bytes;
}

static void procesarArchivo(FILE* read,FILE* write){

  int bytesTotales = 0, tamLinea;
  char leido[TAM_MAX];

  while(!feof(read)){
    tamLinea = obtenerLineaCorregida(leido,read);
    fwrite(leido,sizeof(char),tamLinea,write);
    bytesTotales += tamLinea;
  }
  fseek(write,bytesTotales,SEEK_CUR);
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
