/****************** Usage: For finding the real roots of any given Quadratic equation. ****************************/

/********************* Specification: The program takes upper, lower values of the interval as the input and computes the root for the given equation using Secant method ***********************/

/*************** Given Equation: x^4 - 26x^2 + 49x - 25 = 0**************/
/*************** Roots are: 3.875776 & -5.915842 ***************/

/*This method is quite similar to that of the Regula-Falsi method except for the
condition f(x1).f(x2) < 0. Here the graph of the function y = f(x) in the
neighborhood of the root is approximated by a secant line or chords. Further,
the interval at each iteration may not contain the root.
Let the limits of interval initially be x0 and x1.

Then the first approximation is given by:
         x2 = x1 – [(x1-x0)/f(x1)-f(x0)]f(x1)
Again, the formula for successive approximation in general form is
         x(n+1) = xn - [xn - x(n-1)/f(xn)-f(x(n-1))]f(xn) */

/********* PROGRAM STARTS HERE *********/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* FUNCTION DECLARATION *********/
void secant(float a, float b);
float function(float val);
void check_bound(float a);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   float        a, b;  //Declaration of variables in float

   if (argc != 3)  //Verification arguments
   {
      printf("Usage: %s <root1> <root2>\n", argv[0]);
      exit(1);
   }

   a = atof(argv[1]);  //Calling Function
   b = atof(argv[2]);  //Calling Function

   printf("By using Secant method: \n");
   printf("The equation is: \n");
   printf("\t");
   printf("f(x) = x^4 - 26x^2 + 49x - 25\n");

   printf("----------------------\n");
   printf("   f(a)    f(b)     \n");
   printf("----------------------\n");

   secant(a, b);  //Calling Function

   exit(0);
}

/********* FUNCTION DEFINITION *********/
void secant(float a, float b)
{
   float        fa, fb, root, i = 0;  //Declaration of variables in float

   while (1)  //Infinte Loop
   {
      fa = function(a);  //Calling Function
      fb = function(b);  //Calling Function

      root = (a*fb - fa*b)/(fb-fa);
      printf("%f   %f\n", fa, fb);

      a = b;
      b = root;
      if (floorf(a*10000) == floorf(b*10000))  //Checking roots
      {
         printf("The root is %f found after %.1f iterations.\n", root, i);
         break;
      }
      i++;  //Incrementing i
   }

   return ;
}

float function(float val)
{
   float        fx, x = val;  //Declaration of variables in float

   fx = (x * x * x * x) - (26 * x * x) + 49 * x - 25;  // Function
   return fx;  //Returning the value of f(x) at x1
}

void check_bound(float a)
{
   float        fa;  //Declaration of variables in float

   fa = function(a);  //Calling Functions

   if (fa == 0)  //Check condition
   {
      printf("The root is one of the boundaries.\n");
      exit(0);
   }

   return ;
}

