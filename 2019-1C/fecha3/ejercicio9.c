#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

//funcion pedida
void procesarArchivo(const char* path){

  FILE* read = fopen(path,"r");
  FILE* write = fopen(path,"r+");

  int bytesTotales = 0;

  int cantLetras = 0;
  char aux;
  fread(&aux,sizeof(char),1,read);
  while (!feof(read)){

    while (aux != ' ' && aux != '\n' && !feof(read)){
      cantLetras++;
      fwrite(&aux,sizeof(char),1,write);
      fread(&aux,sizeof(char),1,read);
    }
    if (cantLetras > 3){
      fseek(write,-cantLetras,SEEK_CUR);
    }else{
      bytesTotales += cantLetras;
    }
    fwrite(&aux,sizeof(char),1,write);
    bytesTotales++;
    fread(&aux,sizeof(char),1,read);
    cantLetras = 0;
  }
  rewind(write);
  ftruncate(fileno(write),bytesTotales);
  fclose(write);
  fclose(read);
}

int main(int argc,const char* argv[]){
  if (argc < 2) return -1;
  procesarArchivo(argv[1]);
  return 0;
}


/*while (aux != ' ' && aux != '\n'){
  cantLetras ++;
  fread(&aux,sizeof(char),1,read);
}
if (cantLetras > 3){
  fseek(read,-(cantLetras + 1),SEEK_CUR);
  while (escribi < cantLetras){
    fread(&aux,1,1,read);
    leido[i] = aux;
    i++;
    bytes++;
    escribi++;
  }
  fread(&aux,1,1,read);
  leido[i] = aux;
  i++;
  bytes++;
}
fread(&aux,1,1,read);
cantLetras = 0;
escribi = 0;
}
leido[i] = aux;
bytes++;*/
