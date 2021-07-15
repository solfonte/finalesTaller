/*******
Escribir un programa ISO C que reciba por argumento el nombre de un archivo de texto y
lo procese sobre sí mismo (sin crear archivos intermedios ni subiendo todo su contenido
a memoria). El procesamiento consiste en eliminar las líneas de 1 sola palabra.
*******/

#include <stdio.h>
#include <string.h>
#define TAM_MAX 800

//no anda bien

static void eliminar_linea(FILE*file,int tamanio_linea){
  char linea[TAM_MAX];
  fscanf(file, "%[^\n] ", linea);
  int aux_tamanio_linea = strlen(linea);
  fseek(file, (-1)*(aux_tamanio_linea + tamanio_linea), SEEK_CUR);
  fwrite((void*)linea,aux_tamanio_linea,1,file);
}

static void procesarArchivo(FILE* file){
  char linea[TAM_MAX];
  int tamanio_linea,espacios;
  while (!feof(file)){
    espacios = 0;
    fscanf(file, "%[^\n] ", linea);
    tamanio_linea = strlen(linea);
    printf("tam: %i\n", tamanio_linea);
    for (int i = 0; i < tamanio_linea; i++){
      if (linea[i] == ' '){
        espacios++;
      }
    }
    if (espacios == 0){
      eliminar_linea(file, tamanio_linea);
    }
  }
}

int main(int argc, char const *argv[]) {

  FILE* fp = fopen(argv[1],"r+");

  if (fp == NULL){
    printf("ERROR\n");
    return 0;
  }

  procesarArchivo(fp);

  fclose(fp);
  return 0;
}
