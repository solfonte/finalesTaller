/**
Implemente una función C++ denominada DobleSiNo que reciba dos listas de elementos y
devuelva una nueva lista duplicando los elementos de la primera que no están en la
segunda:
std::list<T> DobleSiNo(std::list<T> a,std::list<T> b);

asumo que la clase T tiene implementado el operador ==
**/
#include <list>
#include <iterator>
#include <iostream>//no va enrealidad

std::list<int> DobleSiNo(std::list<int> a,std::list<int> b){
  std::list<int> listaFinal;
  std::list<int>::iterator aIt;
  for (aIt = a.begin(); aIt != a.end(); ++aIt){
    bool elementoEsta = false;
    std::list<int>::iterator bIt;
    for (bIt = b.begin(); bIt != b.end(); bIt++){
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

int main(){

  std::list<int> a;
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  a.push_back(4);
  a.push_back(9);

  std::list<int> b;
  b.push_back(1);
  b.push_back(5);
  b.push_back(3);
  b.push_back(4);
  std::list<int> c = DobleSiNo(a,b);
  std::list<int>::iterator it;
  for (it = c.begin(); it != c.end(); ++it){
    std::cout << *it << "\n";
  }

  return 0;
}
