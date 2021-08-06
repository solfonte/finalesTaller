/*
asumo que la clase T tiene implementado el operador ==
*/

#include <list>
#include <iterator>

//devuelve una nueva lista con los elementos de la primera que sean múltiplos
//de x
std::list<T> SoloMultiplos(std::list<T> a,T x){
  std::list<T> aux;
  std::list<T>::iterator it;
  for (it = a.begin(); it != a.end(); ++it){
    if (*it % x == 0){
      aux.push_back(*it);
    }
  }
  return aux;
}
