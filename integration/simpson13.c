/*************** COMPOSITE SIMPSON'S RULE *************/
/* Simpson’s 1/3 Rule
    The trapezoidal  rule  was  based  on  approximating  the  integrand  by  a  first  order  polynomial, and  then  integrating  the  polynomial  over 
interval  of  integration.    Simpson’s  1/3  rule  is  an extension  of  Trapezoidal  rule  where  the  integrand  is  approximated  by  a  second  order  
polynomial 
    I = ∫f(x)dx from a to b
    where 
         a = lower limit of the integration
         b = upper limit of the integration.

    ∫f(x)dx from a to b = (h/3)(f(x0)+4f(x1)+2f(x2)+....+f(x2N))
*/

/*************** PROFRAM STRATS HERE ***************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* FUNCTION DECLARATION *********/
void simpson(int n, float h, float a, float b);
float function(float val);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   int          n;          //Declaration of variables in int
   float        a, b, h;    //Declaration of variables in float

   if (argc != 4)  //Check condition
   {
      fprintf(stderr, "Usage: %s <lower-limit> <Upper-limit> <h>.\n", argv[0]);
      exit(1);
   }

   a = atof(argv[1]); //Taking arguments as input
   b = atof(argv[2]);
   h = atof(argv[3]);

   n = (b-a)/(2*h);  //Calculating n

   simpson(n, h, a, b);  //Calling function
   exit(0);
}

void simpson(int n, float h, float a, float b)
{
   int       i = 1, N = (2*n);   //Declaration of variables in int
   float     px = 0;             //Declaration of variables in int

   px += function(a); //Calling function
   while (i < N)  //Check condition
   {
      if (i%2 == 1)  //Check condition
      {
         px += 4*function(a+i*h);  //Calling function
      }
      else if (i%2 == 0)  //Check condition
      {
         px += 2*function(a+i*h);  //Calling function
      }
      i++;  //Incrementing i
   }
   px += function(b);  //Calling function

   px = (h*px)/3;
   printf("Value of integral between [%.1f, %.1f] is %f\n", a, b, px);

   return ;
}

float function(float val)
{
   float        fx, x = val;  //Declaration of variables in float

   fx = x*(1-(x*x));  // Function Equation

   return fx;  //Returning the value of f(x) at x1
}
