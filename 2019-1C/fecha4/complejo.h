#ifndef _COMPLEJO_H_
#define _COMPLEJO_H_

#include <stdlib.h>

typedef struct Complejo{
  long real;
  long imaginario;
}complejo_t;

//la funcion devuelve true si el complejo es imaginario puro
bool complejo_esImaginarioPuro(complejo_t* complejo);

//la funcion devueve el conjugado del complejo
Complejo_t complejo_obtenerConjugado(Complejo_t* complejo);

//la funcion devuelve el argumento del complejo
float complejo_obtenerArgumento(Complejo_t* complejo);

//la funcion devuelve el modulo del complejo
float complejo_obtenerModulo(Complejo_t* complejo);

//la funcion devuelve la suma de dos complejos
complejo_t complejo_sumar(complejo_t* unComplejo, complejo_t* otroComplejo);

#endif
