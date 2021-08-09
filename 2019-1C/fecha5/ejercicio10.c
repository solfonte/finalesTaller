/***Escriba un programa C que tome 2 cadenas por línea de comandos: A y B; e imprima la
cadena A después de haber duplicado todas las ocurrencias de B..
ej.: reemp.exe “El final está aprobado” aprobado -----> El final está aprobado aprobado
***/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  if(argc < 3){
    printf("FALTAN ARGUMENTOS\n");
    return -1;
  }
  const char* cadenaA = argv[1];
  const char* cadenaB = argv[2];

  ssize_t largoCadenaA = strlen(cadenaA);
  ssize_t largoCadenaB = strlen(cadenaB);

  char* final = malloc(4 * sizeof(char) * strlen(cadenaA));
  memset(final,0,4*strlen(cadenaA));
  
  char* palabra = strstr(cadenaA, cadenaB);
  const char* aux = cadenaA;
  int i = 0;

  while (palabra != aux){
    final[i] = *aux;
    i++;
    aux++;
  }
  for (int j = 0; j < largoCadenaB; j++){
      final[i + j] = cadenaB[j];
  }
  i += largoCadenaB;
  final[i] = ' ';
  i++;
  while (*aux != '\0'){
    final[i] = *aux;
    i++;
    aux++;
  }
  for (int k = 0; k < largoCadenaA + largoCadenaB + 1; k++){
    printf("%c",final[k]);
  }
  printf("\n");
  free(final);
  return 0;
}
