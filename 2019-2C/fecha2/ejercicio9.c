/*
9) Escribir un programa ISO C que procese el archivo de enteros
 de 2 bytes bigendian cuyo nombre es recibido como parámetro. El
 procesamiento consiste en eliminar los número múltiplos de 3, trabajando
 sobre el mismo archivo (sin archivos intermedios ni en memoria).**
*/

//no anda bien

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>

void procesarArchivo(FILE* read,FILE* write){
  uint16_t num;
  int bytes = 0,cantLeido = 0;
  char numeroTexto[1000];

  while (!feof(read)){
    cantLeido = fread(&num,sizeof(uint16_t),1,read);
      if (num % 3 != 0){
        //no es multiplo de 3
        printf("no es multiplo de 3\n");
        bytes += fwrite(&num,sizeof(uint16_t),1,write);
     }
      fseek(write,-bytes,SEEK_CUR);
      ftruncate(fileno(write),bytes);
  }
}

 int main(int argc, char const *argv[]) {
   FILE* read = fopen(argv[1],"rb");
   FILE* write = fopen(argv[1],"rb+");

   procesarArchivo(read,write);

   fclose(write);
   fclose(read);
   return 0;
 }
