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
  fgets(linea,TAM_MAX,file);
  printf("proxima linea q leo: %s\n",linea);
  int aux_tamanio_linea = strlen(linea);
  printf("tam proxima linea q leo: %i\n",aux_tamanio_linea);
  fseek(file, (-1)*(aux_tamanio_linea + tamanio_linea), SEEK_CUR);
  int escribi = fputs(linea,file);//hasta aca anda
  //fputs deja al archivo posicionado en la cantidad de caracteres que habia donde escribi la nueva linea
  fseek(file,(aux_tamanio_linea - tamanio_linea +1 ), SEEK_CUR);
  //fputc('\0',file);
  fgets(linea,TAM_MAX,file);
  printf("lo que pude escribir: %i\n",escribi);
  printf("cuando releo: %s\n",linea);


}

static void procesarArchivo(FILE* file){
  char linea[TAM_MAX];
  int tamanio_linea,espacios;
  while (fgets(linea,TAM_MAX,file) != NULL){
    espacios = 0;
    tamanio_linea = strlen(linea);
    printf("leo: %s\n", linea);
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
