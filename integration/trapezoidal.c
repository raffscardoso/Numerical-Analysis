/*************** COMPOSITE TRAPEZOIDAL'S RULE *************/
/*
    The integral can be even better approximated by partitioning the integration interval, applying the trapezoidal rule to each subinterval, and summing the results. In practice, this "chained" (or "composite") trapezoidal rule is usually what is meant by "integrating with the trapezoidal rule".
    Let{xk} be a partition of [a, b] such that a = x0 < x1 < x2 < x3< ... < xN = b and h be the length of the k-th subinterval (that is, h = x_{k}-x_{k-1}).
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
void trapezoidal(int n, float h, float a, float b);
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

   n = (b-a)/h;  //Calculating n

   trapezoidal(n, h, a, b);  //Calling function
   exit(0);
}

void trapezoidal(int n, float h, float a, float b)
{
   int       i = 1;       //Declaration of variables in int
   float     px = 0;      //Declaration of variables in int

   px += function(a); //Calling function
   while (i < n)  //Check condition
   {
      px += 2*function(a+i*h);  //Calling function
      i++;  //Incrementing i
   }
   px += function(b);  //Calling function

   px = (h*px)/2;
   printf("Value of integral between [%.1f, %.1f] is %f\n", a, b, px);

   return ;
}

float function(float val)
{
   float        fx, x = val;  //Declaration of variables in float

   fx = x*(1-(x*x));  // Function Equation

   return fx;  //Returning the value of f(x) at x1
}
