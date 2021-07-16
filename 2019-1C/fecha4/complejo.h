
#ifndef _COMPLEJO_H_
#define _COMPLEJO_H_

class Complejo{
  private:
    int re;
    int im;
  public:
    Complejo(const int& re,const int& im): re(re),im(im){}
    bool operator==(const Complejo& complejo);
    operator float() const;
    bool esImaginarioPuro() const;
    Complejo obtenerConjugado() const;
    Complejo& operator=(const Complejo& otroComplejo);
};

#endif
