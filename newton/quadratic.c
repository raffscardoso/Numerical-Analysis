/****************** Usage: For finding the real roots of any given Quadratic equation. ****************************/

/********************* Specification: The program takes coeffients of the equation and guess value as the input and computes the root for the given equation using Newton-Raphson method ***********************/

/*************** Given Equation: ax^2 + bx + c = 0**************/
/*************** Root is: Depends on the Equation ***************/

/* This method is generally used to improve the result obtained by one of the
previous methods. Let x0 be an approximate root of f(x) = 0 and let x1 = x0 + h be
the correct root so that f(x1) = 0.
Expanding f(x0 + h) by Taylor’s series, we get
          f(x0) + hf′(x0) + h2/2! f′′(x0) + ...... = 0
Since h is small, neglecting h2 and higher powers of h, we get
          f(x0) + hf′(x0) = 0 or h = – f(x0)/f'(x0)
A better approximation than x0 is therefore given by x1, where
          x1 = x0 - f(x0)/f'(x0)
Successive approximations are given by x2, x3, ....... , xn + 1, where
          x(n+1) = xn - f(xn)/f'(xn)             (n = 0, 1, 2, 3, .......)
Which is Newton-Raphson formula.   */

/*************** PROGRAM STARTS HERE ***************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* FUNCTION DECLARATION *********/
float function(float co_a, float co_b, float co_c, float val);
void check_bound(float co_a, float co_b, float co_c, float a);
float function_d(float co_a, float co_b, float co_c, float val);
void newton(float co_a, float co_b, float co_c, float a);

/********** MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   float         co_a, co_b, co_c, a, val;  //Declaration of variables in float

   if (argc != 5)  //Verification of arguments
   {
      fprintf(stderr, "Usage: %s <x^2 coeff> <x^1 coeff> <x^0 coeff> <guess>\n", argv[0]);
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

   a = atof(argv[4]);  //Converting arguments

   check_bound(co_a, co_b, co_c, a);  //Calling Function

   printf("By using Newton-Raphson method: \n");
   printf("The equation is: \n");
   printf("\t");
   printf("f(x) = (%.1f)x^2 + (%.1f)x + (%.1f)\n", co_a, co_b, co_c);

   printf("------------------------\n");
   printf("   f(x)    f'(x)     \n");
   printf("------------------------\n");

   newton(co_a, co_b, co_c, a); //Calling Function

   exit(0);
}

void newton(float co_a, float co_b, float co_c, float a)
{
   float        fa, fa_d, root, i = 0;  //Declaration of variables in float

   while (1)  //Infinte Loop
   {
      fa = function(co_a, co_b, co_c, a);  //Calling Functions
      fa_d = function_d(co_a, co_b, co_c, a); //Calling Functions
      printf("%f  %f\n", fa, fa_d);

      root = a - (fa/fa_d);
      
      if (floor(a*10000) == floor(root*10000)) //Comparing the roots
      {
         printf("The given root is %f after %.1f iterations\n", root, i);
         break;  //Getting out of the loop
      }
      a = root;
      i++;  //Incrementing i
   }

   return ;
}

float function(float co_a, float co_b, float co_c, float val)
{
   float        fx, x = val;  //Declaration of variables in float

   fx = (co_a * x * x) + (co_b * x) + (co_c);  // f(x)

   return fx;  //Returning the value of f(x) at x1
}

float function_d(float co_a, float co_b, float co_c, float val)
{
   float        fx_d, x = val;  //Declaration of variables in float

   fx_d = 2 * co_a * x + co_b;  // f'(x)
   return fx_d;  //Returning the value of f'(x) at x1
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
