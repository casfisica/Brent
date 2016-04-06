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
    double s,Fa,Fb,Fc,d;
    bool mf = true;
    bool c1,c2,c3,c4,c5;
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

	//Conditions
	if ( (s > (((3*a+b)/4) && (s < b))))
	  {
	    c1=true;
	  }//end if condition 1
	
	if ( mf && ((std::abs (s-b)) >= ((std::abs (b-c))/2)) )
	  {
	    c2=true;
	  }//end if condition 2
	
	if ( !mf && ((std::abs (s-b)) >= ((std::abs (c-d))/2)) )
	  {
	    c3=true;
	  }//end if condition 3

	if ( mf && (std::abs (b-c)) < (std::abs (epsi)) )
	  {
	    c4=true;
	  }//end if condition 4
	  
	if ( !mf && (std::abs (c-d)) < (std::abs (epsi)) )
	  {
	    c5=true;
	  }//end if condition 5
	
	if ( (c1) || (c2) || (c3) || (c4) || (c5) )
	  {
	    s=((a+b)/2);
	  }else
	  {
	    mf=false; 
	  }//end if else
	
	d=c;
	c=b;
	
	if (fa*function(s) < 0)
	  {
	    b=s;
	  }else
	  {
	    a=s;
	  }//end if else
	
	if ((std::abs (function(a)))<(std::abs (function(b))))
	  {
	    double temp =a;
	    a=b;
	    b=temp;
	  }//end if
	
	
      }while( (function(b)==0) || (function(s)==0) || ((std::abs(b-a))<epsi) );
  
  return(s);
  
}
