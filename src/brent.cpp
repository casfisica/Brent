#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include "libbrent.h"

double fun(double x){
  double f=(x+3)*(x-1)*(x-1);
  return f;
}//end of the fun



int main()
{
  double a0=0;
  double b0=10;
  double x;
  bool flag=true;
  
  std::cout << "f(a0)=" << fun(a0) << ", f(b0)=" << fun(b0) << std::endl;
  std::cout << std::endl;
  double raiz= brent(&fun, a0, b0, 0.0001, 100, flag);
  std::cout << "Raiz fun=" << raiz << std::endl;

//  std::cout << std::endl;
//  
//  raiz= brent(&fun, a0, b0, 0.0000001, 10000, flag);
//  std::cout << "Raiz fun=" << raiz << std::endl;
// 
//  std::cout << std::endl;
//  
//  raiz= brent(&fun, a0, b0, 0.001, 100, flag);
//  std::cout << "Raiz fun=" << raiz << std::endl;
// 
// 
//  raiz= brent(&sin, -0.6, 1, 0.001, 100, flag);
//  std::cout << "Raiz fun=" << raiz << std::endl;
// 
// 
//  raiz= brent(&cos, -100, 100, 0.0001, 100, flag);
//  std::cout << "Raiz fun=" << raiz << std::endl;
//  
  
}//end main
