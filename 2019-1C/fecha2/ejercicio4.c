
/***
Escribir un programa C que procese el archivo “numeros.txt” sobre sí mismo (sin crear archivos intermedios y sin subir
el archivo a memoria). El procesamiento consiste en leer grupos de 4 caracteres
hexadecimales y reemplazarlos por los correspondientes dígitos decimales
(que representen el mismo número leído pero en decimal).
***/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

//el programa lee caracteres hexadecimales, las letras deben estar en mayuscula

void procesarArchivo(const char* path){
  FILE* write = fopen(path,"r+");
  FILE* read = fopen(path,"r");
  unsigned char hexa[6];
  int cantLeido;
  int numero = 0;
  int potencia = 1;
  int bytes = 0;
  char enter = '\n';

  cantLeido = fread(hexa,sizeof(char),5,read);
  while(!feof(read)){
    char numeroTexto[10];
    for (int i = cantLeido - 2; i >= 0; i--){
      int caracter = ((int)(hexa[i]) - '0');
      if (caracter > 10) caracter -= 7;
      numero += caracter * potencia;
      potencia = potencia << 4;
    }
    bytes += sprintf(numeroTexto,"%d",numero);

    fwrite(numeroTexto,sizeof(char),bytes,write);
    fwrite(&enter,sizeof(char),1,write);
    bytes++;
    numero = 0;
    potencia = 1;
    cantLeido = fread(hexa,sizeof(char),5,read);
  }
  ftruncate(fileno(write),bytes - 1);
  fclose(write);
  fclose(read);
}

int main(int argc, const char* argv[]){
  if (argc < 2) return -1;
  procesarArchivo(argv[1]);
  return 0;
}
