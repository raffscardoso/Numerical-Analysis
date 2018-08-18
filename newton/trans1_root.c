/****************** Usage: For finding the real roots of any given Transcedental equation. ****************************/

/********************* Specification: The program takes guess value as the input and computes the root for the given equation using Newton-Raphson method ***********************/

/*************** Given Equation: x^2 + 4sin(x) = 0 **************/
/*************** Roots are: -1.933754 & 0  ***************/

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
float function(float val);
void check_bound(float a);
float function_d(float val);
void newton(float a);

/********** MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   float         a;  //Declaration of variables in float

   if (argc != 2)  //Verification of arguments
   {
      fprintf(stderr, "Usage: %s <guess>\n", argv[0]);
      exit(1);
   }

   a = atof(argv[1]);  //Converting arguments

   if (a == 0)
   {
      printf("log(0) is undefined so give a value which is other than zero\n");
      exit(2);
   }

   check_bound(a);  //Calling Function

   printf("By using Newton-Raphson method: \n");
   printf("The equation is: \n");
   printf("\t");
   printf("f(x) = x^2 + 4sin(x)\n");

   printf("------------------------\n");
   printf("   f(x)    f'(x)     \n");
   printf("------------------------\n");

   newton(a); //Calling Function

   exit(0);
}

void newton(float a)
{
   float        fa, fa_d, root, i = 0;  //Declaration of variables in float

   while (1)  //Infinte Loop
   {
      fa = function(a);  //Calling Functions
      fa_d = function_d(a); //Calling Functions
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

float function(float val)
{
   float        fx, x = val;  //Declaration of variables in float

   fx = x * x + 4 * sinf(x);  // f(x)

   return fx;  //Returning the value of f(x) at x1
}

float function_d(float val)
{
   float        fx_d, x = val;  //Declaration of variables in float

   fx_d = 2 * x + 4 * cosf(x);  // f'(x)
   return fx_d;  //Returning the value of f'(x) at x1
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
