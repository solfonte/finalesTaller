/***
5) Implemente una función C++ denominada PurgarMapa que reciba un mapa (clave-valor) por referencia
y le quite los elementos cuyos valores están repetidos.
***/


//Template <class T>
#include <map>
#include <iostream>

void PurgarMapa(std::map<int,char>& map){
  std::map<int,char> aux;
  for (auto it = map.begin(); it != map.end(); ++it){
    auto key = it->first;
    auto value = it->second;
    bool valorRepetido = false;
    for (auto it2 = map.begin(); it2 != map.end(); ++it2){
      if (key != it->first && it2->second == value){
        valorRepetido = true;
      }
    }
    if (!valorRepetido){
      aux.insert(std::pair<char,int>(key,value));
    }
  }
  std::cout << "tamanio:" << aux.size() << std::endl;
  aux.swap(map);

}

int main(){

  std::map<int,char> m;
  m.insert(std::pair<int,char>(1,'a'));
  m.insert(std::pair<int,char>(2,'a'));
  PurgarMapa(m);
  auto it=m.begin();
  return 0;
}
