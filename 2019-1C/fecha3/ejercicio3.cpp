/***
Escriba un programa que imprima por salida estándar los números entre 1 y 100, en orden ascendente.
Se pide que los números sean contabilizados por una variable global única y que los pares sean escritos
por un hilo mientras que los impares sean escritos por otro.
Contemple la correcta sincronización entre hilos y la liberación de los recursos utilizados.
***/

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mutex;
int numeros[100];
int proximaPosicionImprimir = 0;

bool imprimir(int modulo){
  std::lock_guard<std::mutex> lck(mutex);
    if (proximaPosicionImprimir % 2 == modulo && proximaPosicionImprimir < 100){
        std::cout << " " << numeros[proximaPosicionImprimir] << " ";
        proximaPosicionImprimir ++;
      }
    return (proximaPosicionImprimir >= 100? true:false);
  }

void imprimirNumerosPares(){
  bool termine = false;
  while (!termine){
    termine = imprimir(0);
  }
}

void imprimirNumerosImpares(){
  bool termine = false;
  while (!termine){
    termine = imprimir(1);
  }
}

int main(){

  for (int i = 0; i < 100; i++){
    numeros[i] = i + 1;
  }
  std::thread threadPar(imprimirNumerosPares);
  std::thread threadImpar(imprimirNumerosImpares);

  threadPar.join();
  threadImpar.join();

  return 0;
}
