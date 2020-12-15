#include<iostream>
#include<math.h>
#include"complex.h"

using namespace std;

Complex::Complex(){
  real_part = 0;
  imaginary_part = 0;
}

Complex::Complex(double a, double b){
  real_part = a;
  imaginary_part = b;
}

/* ******************************************************************************************************************************** */

Complex Complex::operator+ (Complex input_val){
  double tempa, tempb;
  tempa = real_part + input_val.getReal();
  tempb = imaginary_part + input_val.getImaginary();
  Complex temp(tempa, tempb);
  return temp;
}

Complex Complex::operator* (Complex input_val){
  double tempa, tempb;
  tempa = real_part * input_val.getReal() - imaginary_part * input_val.getImaginary();
  tempb = real_part * input_val.getImaginary() + imaginary_part * input_val.getReal();
  Complex temp(tempa, tempb);
  return temp;
}

Complex Complex::operator- (Complex input_val){
  double tempa, tempb;
  tempa = real_part - input_val.getReal();
  tempb = imaginary_part - input_val.getImaginary();
  Complex temp(tempa, tempb);
  return temp;
}

Complex Complex::operator/ (Complex input_val){
  double tempa, tempb;
  tempa = input_val.getReal();
  tempb = input_val.getImaginary();
  Complex var(real_part, imaginary_part);
  Complex temp(tempa, tempb);
  Complex denominator = temp * temp.getConjugate();
  temp = var * temp.getConjugate();
  double real_denominator = denominator.getReal();
  double tempa1, tempb1;
  tempa1 = temp.getReal();
  tempb1 = temp.getImaginary();
  Complex temp1(tempa1 / real_denominator, tempb1 / real_denominator);
  return temp1;
}

Complex Complex::operator^ (double k){
  Complex temp(real_part, imaginary_part);
  temp = temp.raisetoPower(k);
  return temp;
}

/* ************************************************************************************************************************************ */

double Complex::getReal(){
  return real_part;
}

double Complex::getImaginary(){
  return imaginary_part;
}

double Complex::getAngle(){
  double ang;
  ang = atan(imaginary_part / real_part) / M_PI * 180;
  if((real_part >=0 && imaginary_part >= 0) || (real_part >=0 && imaginary_part < 0))
    return ang;
  else if(real_part < 0 && imaginary_part >= 0)
    return ang + 180;  
    else
    return ang - 180;
}

double Complex::getRadius(){
  return sqrt(real_part * real_part + imaginary_part * imaginary_part);
}

double Complex::getDistanceto(Complex complNum){
  return sqrt((complNum.getReal() - real_part) * (complNum.getReal() - real_part)+(complNum.getImaginary() - imaginary_part) * (complNum.getImaginary() - imaginary_part));
}

void Complex::printComplex(){
  if(imaginary_part >= 0)
    cout<<real_part<<"+"<<imaginary_part<<"i"<<endl;
  else
    cout<<real_part<<imaginary_part<<"i"<<endl;    
}

Complex Complex::getConjugate(){
  Complex temp(real_part, - imaginary_part);
  return temp;
}

Complex Complex::getComplex(double radius, double angle){
  double real, imaginary, rad_angle;
  rad_angle = angle / 180 * M_PI;
  real = radius * cos(rad_angle);
  imaginary = radius * sin(rad_angle);
  Complex complexNumber(real, imaginary);
  return complexNumber;
}  

Complex Complex::raisetoPower(double k){
  Complex val(real_part, imaginary_part);
  double temp_angle, temp_radius;
  temp_angle = val.getAngle();
  temp_radius = val.getRadius();
  temp_angle = k * temp_angle;
  temp_radius = pow(temp_radius, k);
  return getComplex(temp_radius, temp_angle);
}
