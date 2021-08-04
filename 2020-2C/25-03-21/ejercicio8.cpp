/*

**8) Implemente una función C++ denominada SoloMuliplos que reciba una
lista de elementos numéricos y un elemnto numérico x. La función debe
 devolver una nueva lista con los elementos de la primera que sean múltiplos
 de x:**
```
std::list<T> SoloMultiplos(std::list<T> a,T x);
```

asumo que la clase T tiene implementado el operador ==

*/

#include <list>
#include <iterator>
#include <iostream> //no va

//devuelve una nueva lista con los elementos de la primera que sean múltiplos
//de x
std::list<int> SoloMultiplos(std::list<int> a,int x){
  std::list<int> aux;
  std::list<int>::iterator it;
  for (it = a.begin(); it != a.end(); ++it){
    if (*it % x == 0){
      aux.push_back(*it);
    }
  }
  return aux;
}

int main(){
  std::list<int> a;
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  a.push_back(4);

  int i = 2;

  std::list<int> c = SoloMultiplos(a,i);
  std::list<int>::iterator it;
  for (it = c.begin(); it != c.end(); ++it){
    std::cout << *it << "\n";
  }

  return 0;
}
