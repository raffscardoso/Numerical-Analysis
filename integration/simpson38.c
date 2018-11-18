/*************** COMPOSITE SIMPSON'S RULE *************/
/* Simpson’s 3/8 Rule
    The trapezoidal  rule  was  based  on  approximating  the  integrand  by  a  first  order  polynomial, and  then  integrating  the  polynomial  over 
interval  of  integration.    Simpson’s  3/8  rule  is  an extension  of  simpson's 1/3  rule  where  the  integrand  is  approximated  by  a  third  order  
polynomial 
    I = ∫f(x)dx from a to b
    where 
         a = lower limit of the integration
         b = upper limit of the integration.

    ∫f(x)dx from a to b = (3h/8)(f(x0)+3f(x1)+3f(x2)+2f(x3)....+f(x3N))
*/

/*************** PROFRAM STRATS HERE ***************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* FUNCTION DECLARATION *********/
void simpson38(int n, float h, float a, float b);
float function(float val);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   int          n;          //Declaration of variables in int
   float        a, b, h;    //Declaration of variables in float

   if (argc != 4)  //Check condition
   {
      fprintf(stderr, "Usage: %s <lower-limit> <Upper-limit> <no. of intervals>.\n", argv[0]);
      exit(1);
   }

   a = atof(argv[1]); //Taking arguments as input
   b = atof(argv[2]);
   n = atof(argv[3]);

   h = (b-a)/(3*n);  //Calculating h

   simpson38(n, h, a, b);  //Calling function
   exit(0);
}

/********* FUNCTION DEFINITION *********/
void simpson38(int n, float h, float a, float b)
{
   int       i = 1, N = (3*n);   //Declaration of variables in int
   float     px = 0;             //Declaration of variables in int

   px += function(a); //Calling function
   while (i < N)  //Check condition
   {
      if (i%3 != 0)  //Check condition
      {
         px += 3*function(a+i*h);  //Calling function
      }
      else if (i%3 == 0)  //Check condition
      {
         px += 2*function(a+i*h);  //Calling function
      }
      i++;  //Incrementing i
   }
   px += function(b);  //Calling function

   px = (3*h*px/8);
   printf("Value of integral between [%.1f, %.1f] is %f\n", a, b, px);

   return ;
}

float function(float val)
{
   float        fx, x = val;  //Declaration of variables in float

   fx = 1/(3*x+5);  // Function Equation

   return fx;  //Returning the value of f(x) at x1
}
