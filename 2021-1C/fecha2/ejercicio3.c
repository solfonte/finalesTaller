/***
Escribir un programa ISO C MULTIPLATAFORMA que procese el archivo “valores.txt” sobre sí mismo.
El procesamiento consiste en leer números separados por 1 espacio que se encuentran en base 3 y escribirlos en 4 símbolos base hexadecimales,
también separados por 1 espacio.
 ***/


#include <stdio.h>

int main(){
  const char* file = "valores.txt";

  FILE* read = fopen(file,"r");
  FILE* write = fopen(file,"r+");

  int numero = 0, digitos = 0;
  unsigned char aux;
  int baseTres = 1;
  fread(&aux,sizeof(aux),1,read);
  while(!feof(read)){
    while (aux != ' ' && aux != '\n' && !feof(read)){
      digitos ++;
      fread(&aux,sizeof(aux),1,read);
    }

    int i = 0;
    while (i < digitos){
    //  printf("digitos: %i y aux: %c y caracter: %i\n", digitos,aux,caracter);
    fseek(read,-2,SEEK_CUR);
    fread(&aux,sizeof(aux),1,read);
    int caracter = ((int)aux - '0');


      numero += baseTres * caracter;
      baseTres = baseTres * 3;
      i++;
    }
    fread(&aux,sizeof(aux),1,read);
    fread(&aux,sizeof(aux),1,read);

    printf("numero: %i\n", numero);
    baseTres = 1;
    digitos = 0;
    fread(&aux,sizeof(aux),1,read);


//paso a base 16
    char base16[4];
    for (int j = 3; j >= 0; j--){
      base16[j] = ((char)(numero % 16) + '0');
      numero = numero / 16;
      printf("escribo: %c\n", base16[j]);

    }
    fwrite(base16,sizeof(base16),1,write);
    char espacio = ' ';
    fwrite(&espacio,sizeof(espacio),1,write);
    numero = 0;

  }
  fclose(read);
  fclose(write);
  return 0;
}
