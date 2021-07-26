#ifndef _CADENA_H_
#define _CADENA_H_

#include <stdbool.h>

//devuelve true si la cadena (primer parametro) contiene a la subcadena (segundo parametro)
bool cadenaContiene(const char* string,const char* substring);

//devuelve la longitud de la cadena
int longitud(const char* cadena);

//convierte los caracteres alfabeticos de la cadena en mayusculas
void cadenaEnMayusculas(const char* cadena);

//devuelve si las cadenas son iguales
bool sonIguales(const char* cadena, const char* otraCadena);
#endif
