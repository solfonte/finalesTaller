#ifndef __TELEFONO_H__
#define __TELEFONO_H__

#include <iostream>
#include <string>

class Telefono{

  private:
    std::string numero;
    int area;
  public:
    Telefono(const std::string& numero,const int& area):numero(numero),area(area){}
    Telefono(Telefono&& otroTelefono);
    Telefono(Telefono& telefono);
    std::ostream& operator<<(std::ostream& out,const Telefono& telefono);
    std::istream& operator>>(std::istream& in,const Telefono& telefono){
      in >> area >> numero;
      return in;
    }
    bool operator==(const Telefono& otroTelefono) const;
    Telefono& operator=(const Telefono& otroTelefono);
    operator long() const;
};

#endif
