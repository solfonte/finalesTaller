#ifndef _NUMERO_H_
#define _NUMERO_H_

#include <ostream>
#include <istream>

class Numero{

  private:
    long int numero;
  public:
    Numero& operator++();//pre-incremento
    Numero operator-(const Numero& numero,const Numero& otroNumero) const;
    bool operator==(const Numero& otroNumero) const;
    std::istream& operator>>(std::istream& in,Numero& otroNumero);
    std::ostream& operator<<(std::ostream& out,const Numero& otroNumero);
    Numero(Numero&& otroNumero);
    operator float() const;
};

#endif
