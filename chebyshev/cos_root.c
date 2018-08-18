/****************** Usage: For finding the real roots of any given Quadratic equation. ****************************/

/********************* Specification: The program takes guess value as the input and computes the root for the given equation using Chebyshev method ***********************/

/*************** Given Equation: 3x - cos(x) - 1 **************/
/*************** Root is: 0.607102 ***************/

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
float function(float val);
float function_d(float val);
float function_d_d(float val);
void check_bound(float a);
void chebyshev(float a);

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

   check_bound(a);  //Calling Function

   printf("By using chebyshev method: \n");
   printf("The equation is: \n");
   printf("\t");
   printf("f(x) = 3x - cos(x)- 1\n");

   printf("---------------------------\n");
   printf("   f(x)    f'(x)    f''(x) \n");
   printf("---------------------------\n");

   chebyshev(a); //Calling Function

   exit(0);
}

void chebyshev(float a)
{
   float        fa, fa_d, fa_d_d, root, i = 0;  //Declaration of variables in float

   while (1)  //Infinte Loop
   {
      fa = function(a);  //Calling Functions
      fa_d = function_d(a); //Calling Functions
      fa_d_d = function_d_d(a); //Calling Functions
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

float function(float val)
{
   float        fx, x = val;  //Declaration of variables in float

   fx = 3 * x - cosf(x) - 1;  // f(x)

   return fx;  //Returning the value of f(x) at x1
}

float function_d(float val)
{
   float        fx_d, x = val;  //Declaration of variables in float

   fx_d = 3 + sinf(x);  // f'(x)
   return fx_d;  //Returning the value of f'(x) at x1
}

float function_d_d(float val)
{
   float        fx_d_d, x = val;  //Declaration of variables in float

   fx_d_d = cosf(x);  // f''(x)
   return fx_d_d;  //Returning the value of f''(x) at x1
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
