#ifndef _complex_h
#define _complex_h

class Complex{

public:
  Complex();
  Complex(double a, double b);   
  
  Complex operator + (Complex);
  Complex operator * (Complex);
  Complex operator - (Complex);
  Complex operator / (Complex);
  Complex operator ^ (double);
  
  double getReal();
  double getImaginary(); 
  double getArgument();
  double getAngle();
  double getRadius();
  double getDistanceto(Complex complNum);   
  Complex getConjugate();
  Complex getComplex(double radius, double angle);
  Complex raisetoPower(double k);
  void printComplex();
  
private:
  double real_part;
  double imaginary_part;
};
#endif
