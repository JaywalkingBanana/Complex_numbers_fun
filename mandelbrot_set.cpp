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
  
  out.open("mandelbrot_set.txt");
  Complex z, c(-2, -2), x_step(0.004, 0), y_step(0, 0.004), reset_var, reset_x(-4, 0);
  for(int i = 0; i <= 1000; i++){
    for(int j = 1; j <= 1000; j++){
      for(int k = 1; k <= 100; k++)
        z = Mandelbrot(z, c);
      if(z.getRadius() <= 2.0)
        out<<0;
      else
        out<<1;
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
