#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

//el programa lee caracteres hexadecimales, las letras deben estar en mayuscula

void procesarArchivo(const char* path){
  FILE* write = fopen(path,"r+");
  FILE* read = fopen(path,"r");
  unsigned char hexa[5];
  int cantLeido;
  int numero = 0;
  int potencia = 1;
  int bytes = 0;
  char numeroTexto[1000];
  cantLeido = fread(hexa,sizeof(char),4,read);
  while(!feof(read)){
    printf("leo: %i\n", cantLeido);
    for (int i = cantLeido - 1; i >= 0; i--){
      int caracter = ((int)(hexa[i]) - '0');
      if (caracter > 10) caracter -= 7;
      numero += caracter * potencia;
      potencia = potencia << 4;
    }
    printf("final: %i\n", numero);
    bytes += sprintf(numeroTexto,"%d",numero);
    fwrite(numeroTexto,sizeof(int),1,write);
    cantLeido = 0;
    numero = 0;
    potencia = 1;
    cantLeido = fread(hexa,sizeof(char),4,read);
  }
  rewind(write);
  ftruncate(fileno(write),bytes);
  fclose(write);
  fclose(read);
}

int main(int argc, const char* argv[]){
  if (argc < 2) return -1;
  procesarArchivo(argv[1]);
  return 0;
}
