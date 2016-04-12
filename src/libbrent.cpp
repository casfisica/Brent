/*                               Brent's method                                  */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

/*
 *Brent función tiene cinco argumentos , primero la función , 
 *segundo and third the interval extremes, fourth the accurancy required,
 *and last the  number of iterations (optional)
*/

double brent(double (*func)(double), double a, double b, double epsi, int iter, bool debug)
{
  double tb,ta,dif;
  
  if (func(a)==0 || func(b)==0)
    {
      if (func(a)==0){return a;}else{return b;}
      
    }else
    {
      if (func(a)*(func(b))> 0)
	{
	  std::cout << "The function does not have a single root between the poinst a and b."<< std::endl;
	  
	}
      
      if ((std::abs (func(a)))<(std::abs (func(b))))
	{
	  tb=a;
	  ta=b;
	 
	}else
	{
	  ta=a;
	  tb=b;
	 
	}//end if else
      int cont=0;
      double c=ta;
      double s,Fa,Fb,Fc,d;
      bool mf = true;
      bool c1,c2,c3,c4,c5;
      do 
	{
	  c1=false;
	  c2=false;
	  c3=false;
	  c4=false;
	  c5=false;
	  Fa=func(ta);
	  Fb=func(tb);
	  Fc=func(c);
	  
	  if ( (Fa != Fc) && (Fb != Fc) )
	    {
	      s=(((ta*Fb*Fc)/((Fa-Fb)*(Fa-Fc)))+((tb*Fa*Fc)/((Fb-Fa)*(Fb-Fc)))+((c*Fb*Fa)/((Fc-Fa)*(Fc-Fb))));//Inverse quadratic interpolation
	      if (debug)
		{
		  std::cout << "iter= " << cont<<" ,a=" << ta <<" ,F(a)="<< Fa<<" ,b="<< tb<<" ,F(b)="<< Fb<<" ,c="<< c<<" ,F(c)="<< Fc<<" ,condición true ,s= " << s << " dif="<< dif <<std::endl;
		}
	    }else
	    {
	      s=(tb-Fb*((tb-ta)/(Fb-Fa)));
	      if (debug)
		{
		  std::cout << "iter= " << cont<<" ,a=" << ta <<" ,F(a)="<< Fa<<" ,b="<< tb<<" ,F(b)="<< Fb<<" ,c="<< c<<" ,F(c)="<< Fc<<" ,condición false ,s= " << s << " dif="<< dif <<std::endl;
		}
	    }//end if else
	  
	  //Conditions
	  if ( (s > (((3*ta+tb)/4) && (s < tb))))
	    {
	      c1=true;
	      if (debug)
		{
	      std::cout << "cond1=true"<< std::endl;
		}
	    }//end if condition 1
	  
	  if ( mf && ((std::abs (s-tb)) >= ((std::abs (tb-c))/2)) )
	    {
	      c2=true;
	      if (debug)
		{
	      std::cout << "cond2=true"<< std::endl;
		}
	    }//end if condition 2
	  
	  if ( !mf && ((std::abs (s-tb)) >= ((std::abs (c-d))/2)) )
	    {
	      c3=true;
	      if (debug)
		{
	      std::cout << "cond1=true"<< std::endl;
		}
	    }//end if condition 3
	  
	  if ( mf && (std::abs (b-c)) < (std::abs (epsi)) )
	    {
	      c4=true;
	      if (debug)
		{
		  std::cout << "cond5=true"<< std::endl;
		}
	    }//end if condition 4
	  
	  if ( !mf && (std::abs (c-d)) < (std::abs (epsi)) )
	    {
	      c5=true;
	      if (debug)
		{
		  std::cout << "cond5=true"<< std::endl;
		}
	    }//end if condition 5
	  
	  if ( (c1) || (c2) || (c3) || (c4) || (c5) )
	    {
	      s=((ta+tb)/2);
	    }else
	    {
	      mf=false; 
	    }//end if else
	  
	  d=c;
	  c=tb;
	  
	  if (Fa*func(s) < 0)
	    {
	      tb=s;
	    }else
	    {
	      ta=s;
	    }//end if else
	  
	  if ((std::abs (func(ta)))<(std::abs (func(tb))))
	    {
	      double temp =ta;
	      ta=tb;
	      tb=temp;
	    }//end if
	  cont++;
	  dif=(std::abs(func(s)));
	  
	  if (func(tb)==0)
	    {
	      if (debug)
		{
		  std::cout << "breake1 ";
		}
	      break;
	    }
	  if (func(s)==0)
	    {
	      if (debug)
		{
		  std::cout << "breake2 ";
		}
	      break;}
	  if (dif<epsi)
	    {
	      if (debug)
		{
		  std::cout << "breake3 ";
		}
	      break;
	    }
	  if (cont > iter)
	    {
	      if (debug)
		{
		  std::cout << "breake4 ";
		}
	      break;
	    }
	  
	}while(true);
      return(s);
    }//end if else 
  
}
