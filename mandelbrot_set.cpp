#include<iostream>
#include<fstream>
#include<math.h>
#include<vector>
#include"complex.h"

using namespace std;

Complex Mandelbrot(Complex z, Complex c);

int main(){

  vector <Complex> mandel_var;
  ofstream out;
  
  out.open("mandelbrot_set_n2_highres.dat");
  Complex z, c(-2, -2), x_step(0.0004, 0), y_step(0, 0.0004), reset_var, reset_x(-4, 0);
  for(int i = 0; i <= 10000; i++){
    for(int j = 1; j <= 10000; j++){
      for(int k = 1; k <= 100; k++)
        z = Mandelbrot(z, c);
      if(z.getRadius() <= 2.0)
        out<<z.getRadius()<<" ";
      else
        out<<0<<" ";
      c = c + x_step;   
      z = reset_var;
      z.printComplex();
      c.printComplex();
}
    
    out<<endl;
    c = c + reset_x;
    c = c + y_step;
}  
  out.close(); 
}

Complex Mandelbrot(Complex z, Complex c){
  return (z * z) + c;
}
