/*9) Escriba una función ISO C que permita
procesar sobre sí mismo (sin generar archivos
  intermedios ni cargar el archivo completo a memoria) un archivo
  texto con palabras separadas por espacios. El procesamiento consiste
en duplicar las palabras que tengan al menos de 2 vocales.**
*/

#include <stdio.h>
#include <unistd.h> //para ftruncate

//funcion pedida
void procesarArchivo(const char* path){

  FILE* read = fopen(path,"r");
  FILE* write = fopen(path,"r+");

  int elementos = 0;
  char aux;

  //leo contenido total
  while (!feof(read)){
    elementos += fread(&aux,sizeof(char),1,read);
  }

  //copio al final para expandir
  //solo escribo una vez porque pide duplicar
  int elemEscritos = 0;
  rewind(read);
  fseek(write,0,SEEK_END);
  while (elemEscritos < elementos){
    fread(&aux,sizeof(char),1,read);
    elemEscritos += fwrite(&aux,sizeof(char),1,write);
  }

  int bytesTot = 0;
  rewind(write);
  fseek(read,-elementos,SEEK_END);
  fread(&aux,sizeof(char),1,read);
  while (!feof(read)){
    int letras = 0, vocales = 0;
    while (aux != ' ' && aux != '\n' && !feof(read)){
      letras += fwrite(&aux,sizeof(char),1,write);
      bytesTot++;
      if (aux == 'a' || aux == 'e' || aux == 'i' || aux == 'o' || aux == 'u'){
        vocales++;
      }
      if (aux == 'A' || aux == 'E' || aux == 'I' || aux == 'O' || aux == 'U'){
        vocales++;
      }
      fread(&aux,sizeof(char),1,read);
    }
    bytesTot += fwrite(&aux,sizeof(char),1,write);

    if (vocales >= 2){
      int i = 0;
      fseek(read,-(letras + 1),SEEK_CUR);//el + 1 va por que escribi un espacio
      while (i < letras){
        fread(&aux,sizeof(char),1,read);
        bytesTot += fwrite(&aux,sizeof(char),1,write);
        i++;
      }
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
