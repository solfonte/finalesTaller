/***
Escriba un programa que imprima por salida estándar los números entre 1 y 100, en orden ascendente.
Se pide que los números sean contabilizados por una variable global única y que los pares sean escritos
por un hilo mientras que los impares sean escritos por otro.
Contemple la correcta sincronización entre hilos y la liberación de los recursos utilizados.
***/

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

    bool imprimir(int modulo){
      std::lock_guard<std::mutex> lck(this->mutex);
      if (this->proximaPosicionImprimir % 2 == modulo && this->proximaPosicionImprimir < 100){
        std::cout << " " << this->numeros[this->proximaPosicionImprimir] << " ";
        this->proximaPosicionImprimir ++;
      }
      return (proximaPosicionImprimir >= 100? true:false);
    }

};

void imprimirNumerosPares(NumerosProtegidos& numeros){
  bool termine = false;
  while (!termine){
    termine = numeros.imprimir(0);
  }
}

void imprimirNumerosImpares(NumerosProtegidos& numeros){
  bool termine = false;
  while (!termine){
    termine = numeros.imprimir(1);
  }
}

int main(){

  NumerosProtegidos numeros;
  std::thread threadPar(imprimirNumerosPares,std::ref(numeros));
  std::thread threadImpar(imprimirNumerosImpares,std::ref(numeros));

  threadPar.join();
  threadImpar.join();

  return 0;
}
