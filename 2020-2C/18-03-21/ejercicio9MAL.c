/*9) Escriba una función ISO C que permita
procesar sobre sí mismo (sin generar archivos
  intermedios ni cargar el archivo completo a memoria) un archivo
  texto con palabras separadas por espacios. El procesamiento consiste
en duplicar las palabras que tengan al menos de 2 vocales.**
*/


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


//funcion pedida
void procesarArchivo(const char* path){

  FILE* read = fopen(path,"r");
  FILE* write = fopen(path,"r+");

  int bytesTot = 0;
  char leido[800];
  char aux;
  fread(&aux,sizeof(char),1,read);
  while (!feof(read)){
    int i = 0, vocales = 0;
    while (aux != ' ' && aux != '\n'){
      leido[i] = aux;
      i++;
      if (aux == 'a' || aux == 'e' || aux == 'i' || aux == 'o' || aux == 'u'){
        vocales++;
      }
      if (aux == 'A' || aux == 'E' || aux == 'I' || aux == 'O' || aux == 'U'){
        vocales++;
      }
      fread(&aux,sizeof(char),1,read);
    }
    fwrite(leido,sizeof(char),i,write);
    fwrite(&aux,sizeof(char),1,write);
    bytesTot += i + 1;
    if (vocales >= 2){
    fwrite(leido,sizeof(char),i,write);
    fwrite(&aux,sizeof(char),1,write);
    bytesTot += i + 1;
    }
    fread(&aux,sizeof(char),1,read);
  }
  ftruncate(fileno(write),bytesTot);
  fclose(read);
  fclose(write);
}

int main(){
  const char* nombre = "prueba.txt";
  procesarArchivo(nombre);
  return 0;
}
