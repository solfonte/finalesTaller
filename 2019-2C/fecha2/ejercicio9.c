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
#include <arpa/inet.h>

void procesarArchivo(FILE* read,FILE* write){
  uint16_t num;
  uint16_t aux;

  int bytes = 0,cantLeido = 0;
  char numeroTexto[1000];
  cantLeido = fread(&num,sizeof(uint16_t),1,read);
  while (!feof(read)){
    aux = htons(num);
      if (aux % 3 != 0){
       fwrite(&num,sizeof(uint16_t),1,write);
       bytes += sizeof(uint16_t);
     }
     cantLeido = fread(&num,sizeof(uint16_t),1,read);
  }
   rewind(write);
   ftruncate(fileno(write),bytes);
}

 int main(int argc, char const *argv[]) {
   FILE* read = fopen(argv[1],"rb");
   FILE* write = fopen(argv[1],"rb+");

   procesarArchivo(read,write);

   fclose(write);
   fclose(read);
   return 0;
 }
