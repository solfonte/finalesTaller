/***
Escriba un programa que imprima por salida estándar los números entre 1 y 100, en orden ascendente.
Se pide que los números sean contabilizados por una variable global única y que los pares sean escritos
por un hilo mientras que los impares sean escritos por otro.
**Contemple la correcta sincronización entre hilos y la liberación de los recursos utilizados.**
*****/

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


/*


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

    void imprimirNumerosPares(){
      bool termine = false;
      while (!termine){
        termine = this->imprimirSiElProximoEsImpar();
      }
    }

    void imprimirNumerosImpares(){
      bool termine = false;
      while (!termine){
        termine = this->imprimirSiElProximoEsImpar();
      }
    }

    void operator()(bool par){
      if (par){
        this->imprimirNumerosPares();
      }else{
        this->imprimirNumerosImpares();
      }
    }

};

int main(){

  NumerosProtegidos numeros();

  std::thread threadPar(numeros,true);
  std::thread threadImpar(numeros,false);

  threadPar.join();
  threadImpar.join();


  return 0;
}*/
