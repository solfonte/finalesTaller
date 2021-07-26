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
  int bytes = 1;
  char numeroTexto[1000];
  while(!feof(read)){
    cantLeido = fread(hexa,sizeof(char),4,read);
    for (int i = cantLeido - 1; i >= 0; i--){
      int caracter = ((int)(hexa[i]) - '0');
      if (caracter > 10) caracter -= 7;
      numero += caracter * potencia;
      potencia = potencia << 4;
    }
    sprintf(numeroTexto,"%d",numero);
    fwrite(numeroTexto,sizeof(int),1,write);
    bytes++;
    cantLeido = 0;
    numero = 0;
  }
  fseek(write,bytes,SEEK_CUR);
  ftruncate(fileno(write),bytes);
  fclose(write);
  fclose(read);
}

int main(int argc, const char* argv[]){
  if (argc < 2) return -1;
  procesarArchivo(argv[1]);
  return 0;
}
