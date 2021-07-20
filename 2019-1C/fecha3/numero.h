#ifndef __NUMERO_H__
#define __NUMERO_H__

#include <iostream>

class Numero{
  private:
    long int numero;
  public:
    Numero operator+(Numero& otroNumero);
    Numero operator++(int);//post incremento
    Numero& operator--();//pre incremento
    std::ostream& operator>>(std::ostream& out,Numero& numero);
    std::istream& operator<<(std::istream& in,Numero& numero);
    operator long() const;
};

#endif
