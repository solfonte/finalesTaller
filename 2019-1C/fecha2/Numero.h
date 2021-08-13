#ifndef __NUMERO_H__
#define __NUMERO_H__

#include <ostream>
#include <istream>

class Numero{
  private:
    unsigned long numero;
  public:
    Numero(unsigned long numero);
    Numero();
    Numero(unsigned long&& otroNumero);
    std::ostream& operator<<(std::ostream& out,const Numero& numero);
    void operator()();
    Numero& operator=(Numero& otroNumero);
    operator long() const;
    Numero operator++(int);
    std::istream& operator>>(std::istream& in,Numero& numero){
      in >> numero;
      return in;
    }
};
#endif
