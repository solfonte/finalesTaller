/**
Implemente una función C++ denominada DobleSiNo que reciba dos listas de elementos y
devuelva una nueva lista duplicando los elementos de la primera que no están en la
segunda:
std::list<T> DobleSiNo(std::list<T> a,std::list<T> b);
**/

#include <list>
#include <iterator>

std::list<T> DobleSiNo(std::list<T> a,std::list<T> b){
  std::list<T> listaFinal;
  for (auto aIt = a.begin(); aIt != a.end(); ++aIt){
    bool elementoEsta = false;
    for (auto bIt = b.begin(); bIt != b.end(); bIt++){
      if (*bIt == *aIt){
        elementoEsta = true;
      }
    }
    if (!elementoEsta){
      listaFinal.push_back(*aIt);
      listaFinal.push_back(*aIt);
    }
  }
  return listaFinal;
}
