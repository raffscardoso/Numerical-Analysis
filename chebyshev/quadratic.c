/****************** Usage: For finding the real roots of any given Quadratic equation. ****************************/

/********************* Specification: The program takes coeffients of the equation and guess value as the input and computes the root for the given equation using Chebyshev method ***********************/

/*************** Given Equation: ax^2 + bx + c = 0**************/
/*************** Root is: Depends on the Equation ***************/

/* Chebysav method is like approimating the given Transcedental Equation into a quadratic equation f(x) = 0, f(x) ~ a0 + a1x + a2x^2

Let xk be an approximate root
f'(x) = a1 + a2x
f''(x) = 2a2  by subsituting the value xk in all the equations we get the values of f(xk), f'(xk), f''(xk)

we get,
      f(x) ~ fk + (x-xk)f'_k + (x-xk)^2*f''_k/2 ==> 0
      x_(k+1) = xk - fk/f'k - (fk^2 f''_k)/2((f'_k)^3)*/

/*************** PROGRAM STARTS HERE ***************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* FUNCTION DECLARATION *********/
float function(float co_a, float co_b, float co_c, float val);
float function_d(float co_a, float co_b, float co_c, float val);
float function_d_d(float co_a, float co_b, float co_c, float val);
void check_bound(float co_a, float co_b, float co_c, float a);
void chebyshev(float co_a, float co_b, float co_c, float a);

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

   printf("By using chebyshev method: \n");
   printf("The equation is: \n");
   printf("\t");
   printf("f(x) = (%.1f)x^2 + (%.1f)x + (%.1f)\n", co_a, co_b, co_c);

   printf("------------------------\n");
   printf("   f(x)    f'(x)     \n");
   printf("------------------------\n");

   chebyshev(co_a, co_b, co_c, a); //Calling Function

   exit(0);
}

void chebyshev(float co_a, float co_b, float co_c, float a)
{
   float        fa, fa_d, fa_d_d, root, i = 0;  //Declaration of variables in float

   while (1)  //Infinte Loop
   {
      fa = function(co_a, co_b, co_c, a);  //Calling Functions
      fa_d = function_d(co_a, co_b, co_c, a); //Calling Functions
      fa_d_d = function_d_d(co_a, co_b, co_c, a); //Calling Functions
      printf("%f  %f  %f\n", fa, fa_d, fa_d_d);

      root = a - (fa/fa_d) - (fa*fa*fa_d_d)/(2*fa_d*fa_d*fa_d);
      
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

float function_d_d(float co_a, float co_b, float co_c, float val)
{
   float        fx_d_d;  //Declaration of variables in float

   fx_d_d = 2 * co_a ;  // f''(x)
   return fx_d_d;  //Returning the value of f''(x) at x1
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
