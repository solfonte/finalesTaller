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
    std::cout << key<< " => " << value << '\n';

    bool valorRepetido = false;
    for (auto it2 = map.begin(); it2 != map.end(); ++it2){
      if (key != it->first && it2->second == value){
        valorRepetido = true;
        std::cout << "rep\n";
      }
    }
    if (!valorRepetido){
      aux.insert(std::pair<char,int>(key,value));
    }
  }
  aux.swap(map);

}

int main(){

  std::map<int,char> m;
  m.insert(std::pair<char,int>(1,'a'));
  m.insert(std::pair<char,int>(2,'a'));
  PurgarMapa(m);
  auto it=m.begin();
  std::cout << it->first << " => " << it->second << '\n';
  it++;
  std::cout << it->first << " => " << it->second << '\n';

  return 0;
}
