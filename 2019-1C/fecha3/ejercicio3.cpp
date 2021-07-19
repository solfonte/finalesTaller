#include <iostream>
#include <thread>
#include <utility>
#include <mutex>

class NumerosProtegidos{

  private:
    std::mutex mutex;
    int numeros[100];
    int proximaPosicionImprimir = 0;
  public:
    NumerosProtegidos(){
      // inicializo variable global unica
      for (int i = 0; i < 100; i++){
        this->numeros[i] = i + 1;
      }
    }

    bool imprimirSiElProximoEsPar(){
      std::lock_guard<std::mutex> lck(this->mutex);
      if (this->proximaPosicionImprimir % 2 == 0 && this->proximaPosicionImprimir <= 100){
        std::cout << " " << this->numeros[this->proximaPosicionImprimir] << " ";
        this->proximaPosicionImprimir ++;
      }
      return (proximaPosicionImprimir > 100? true:false);
    }

    bool imprimirSiElProximoEsImpar(){
      std::lock_guard<std::mutex> lck(this->mutex);
      if (this->proximaPosicionImprimir % 2 == 1 && (this->proximaPosicionImprimir < 100)){
        std::cout << " " << this->numeros[this->proximaPosicionImprimir] << " ";
        this->proximaPosicionImprimir ++;
      }
      return (proximaPosicionImprimir > 100? true:false);
    }
};


void imprimirNumerosPares(NumerosProtegidos* numeros){
  bool termine = false;
  while (!termine){
    termine = numeros->imprimirSiElProximoEsPar();
  }
}

void imprimirNumerosImpares(NumerosProtegidos* numeros){
  bool termine = false;
  while (!termine){
    termine = numeros->imprimirSiElProximoEsImpar();
  }

}

int main(){

  NumerosProtegidos numeros;
  std::thread threadPar(imprimirNumerosPares, &numeros);
  std::thread threadImpar(imprimirNumerosImpares, &numeros);

  threadPar.join();
  threadImpar.join();


  return 0;
}
