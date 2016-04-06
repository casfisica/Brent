/*                               Brent's method                                  */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 *Brent función tiene cinco argumentos , primero la función , 
 *segundo and third the interval extremes, fourth the accurancy required,
 *and last the  number of iterations (optional)
*/

double brent(double (*function)(double), double a, double b, double epsi, int iter)
{
  
  if ((function(a)*(function(b))>= 0)
    {
      cout << "The function does not have a single root between the poinst a and b.";
      break;
    }
    
    if ((std::abs (function(a)))<(std::abs (function(b))))
      {
	double temp =a;
	a=b;
	b=temp;
      }//end if
    double c=a;
    double s,Fa,Fb,Fc;
    bool mf = true;
    do 
      {
	Fa=function(a);
	Fb=function(b);
	Fc=function(c);
	
	if ( (Fa != Fc) && (Fb != Fc) )
	  {
	    s=(((a*Fb*Fc)/((Fa-Fb)*(Fa-Fc)))+((b*Fa*Fc)/((Fb-Fa)*(Fb-Fc)))+((c*Fb*Fa)/((Fc-Fa)*(Fc-Fb))));//Inverse quadratic interpolation
	  }else
	  {
	    s=(b-Fb*((b-a)/(Fb-Fa)));
	  }//end if else
	
	if ( ( () && () ) || ( () && () ) || ( () && () ) || ( () && () ) || ( () && () ) )



	
      }while( (function(b)==0) || (function(b)==0) || ((std::abs(b-a))<epsi) );

	
  

  
  return();
  
}
