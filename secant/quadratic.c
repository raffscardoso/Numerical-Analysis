/****************** Usage: For finding the real roots of any given Quadratic equation. ****************************/

/********************* Specification: The program takes coeffients of the equation and upper, lower values of the interval as the input and computes the root for the given equation using secant method ***********************/

/*************** Given Equation: ax^2 + bx + c = 0**************/
/*************** Root is: Depends on the Equation ***************/

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
void secant(float co_a, float co_b, float co_c, float a, float b);
float function(float co_a, float co_b, float co_c, float val);
void check_bound(float co_a, float co_b, float co_c, float a);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   float        co_a, co_b, co_c, a, b, val;  //Declaration of variables in float

   if (argc != 6)  //Verification arguments
   {
      printf("Usage: %s <x^2 coeff> <x^1 coeff> <x^0 coeff> <root1> <root2>\n", argv[0]);
      exit(1);
   }

   co_a = atof(argv[1]);  //Taking a, b, c as inputs from the user
   co_b = atof(argv[2]);
   co_c = atof(argv[3]);

   val = ((co_b * co_b) - (4 * co_a * co_c)); //Value of discremenet

   if (val < 0) // Checking whether discriminant < zero
   {
      fprintf(stderr, "The given Equation has no real roots.\n");
      exit(2);
   }

   a = atof(argv[4]);  //Calling Function
   b = atof(argv[5]);  //Calling Function

   printf("By using Secant method: \n");
   printf("The equation is: \n");
   printf("\t");
   printf("f(x) = (%.1f)x^2 + (%.1f)x + (%.1f)\n", co_a, co_b, co_c);

   printf("----------------------\n");
   printf("   f(a)    f(b)     \n");
   printf("----------------------\n");

   secant(co_a, co_b, co_c, a, b);  //Calling Function

   exit(0);
}

/********* FUNCTION DEFINITION *********/
void secant(float co_a, float co_b, float co_c, float a, float b)
{
   float        fa, fb, root, i = 0;  //Declaration of variables in float

   while (1)  //Infinte Loop
   {
      fa = function(co_a, co_b, co_c, a);  //Calling Function
      fb = function(co_a, co_b, co_c, b);  //Calling Function

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

float function(float co_a, float co_b, float co_c, float val)
{
   float        fx, x = val;  //Declaration of variables in float

   fx = (co_a * x * x) + (co_b * x) + co_c;  // Function
   return fx;  //Returning the value of f(x) at x1
}

void check_bound(float co_a, float co_b, float co_c, float a)
{
   float        fa;  //Declaration of variables in float

   fa = function(co_a, co_b, co_c, a);  //Calling Functions

   if (fa == 0)  //Check condition
   {
      printf("The root is one of the boundaries.\n");
      exit(0);
   }

   return ;
}

