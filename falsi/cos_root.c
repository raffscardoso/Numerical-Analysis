/****************** Usage: For finding the real roots of any given Transcendental equation. ****************************/

/********************* Specification: The program takes upper and lower values of the interval as the input and computes the root for the given equation using Regular-falsi's method ***********************/

/*************** Given Equation: 3x - cos(x) - 1 = 0 **************/
/*************** Roots is: 0.607102 ***************/

/* The bisection method guarantees that the iterative process will converge. It is,
however, slow. Thus, attempts have been made to speed up** the bisection
method retaining its guaranteed convergence. A method of doing this is called
the method of false position.
It is sometimes known as the method of linear interpolation.
This is the oldest method for finding the real roots of a numerical equation
and closely resembles the bisection method.
In this method, we choose two points x0 and x1 such that f(x0) and f(x1) are
of opposite signs. Since the graph of y = f(x) crosses the X-axis between these
two points, a root must lie in between these points.
Consequently, f(x0) f(x1) < 0

The equation of the chord joining points {x0, f(x0)} and {x1, f(x1)} is

         y – f(x0) = (f(x1)-f(x0)/x1-x0)(x-x0)

The method consists in replacing the curve AB by means of the chord AB
and taking the point of intersection of the chord with the X-axis as an
approximation to the root.
So the abscissa of the point where the chord cuts y = 0 is given by

         x2 = x0 - (x1-x0)f(x0)/(f(x1)-f(x0))

which is an approximation to the root.
If f(x0) and f(x2) are now of opposite signs, then the root lies between x0 and
x2. So replacing x1 with x2 in (7), we obtain the next approximation, x3. However,
the root could also lie between x1 and x2 and then we find x3 accordingly.
This procedure is repeated until the root is found to the desired accuracy. */

/*************** PROGRAM STARTS HERE ***************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* FUNCTION DECLARATION *********/
void falsi(float a, float b);
float function(float val);
void check_bound(float a, float b);

/********** MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   float         a, b;  //Declaration of variables in float

   if (argc != 3)  //Verification of arguments
   {
      fprintf(stderr, "Usage: %s <upper> <lower>\n", argv[0]);
      exit(1);
   }

   a = atof(argv[1]);  //Converting arguments
   b = atof(argv[2]);  //Converting arguments

   check_bound(a, b);  //Calling Function

   printf("By using Regular-falsi method: \n");
   printf("The equation is: \n");
   printf("\t");
   printf("f(x) = 3x - cos(x) - 1\n");

   printf("------------------------\n");
   printf("    f(a)     f(b)  f(c) \n");
   printf("------------------------\n");

   falsi(a, b); //Calling Function

   exit(0);
}

/********* FUNCTION DEFINITION *********/
void falsi(float a, float b)
{
   float        fa, fb, fc, root, c, i = 0;  //Declaration of variables in float

   fa = function(a);  //Calling Functions
   fb = function(b);  //Calling Functions

   if (fa * fb < 0)
   {
      root = a - (((b-a)/(fb-fa))*fa);  // Function Equation
      c = root;
   }
   fc = function(c);  //Calling Functions

   while (1)
   {
      fa = function(a);  //Calling Functions
      fb = function(b);  //Calling Functions
      printf("%f    %f   %.f\n", fa, fb, fc);

      fc = function(c);  //Calling Functions
      if (fb * fc < 0)
      {
         root = b - (((c-b)/(fc-fb))*fb);  // Function Equation
         a = b;
         b = c;
         c = root;
      }
      else
      {
         root = a - (((c-a)/(fc-fa))*fa);  // Function Equation
         a = b;
         b = c;
         c = root;
      }

      if (floor(b*10000) == floor(root*10000)) //Comparing the roots
      {
         printf("The given root is %f after %.1f iterations\n", root, i);
         break;  //Getting out of the loop
      }
      i++;  //Incrementing i
   }

   return ;
}

float function(float val)
{
   float        fx, x = val;  //Declaration of variables in float

   fx = 3 * x - cosf(x) - 1;  // Function Equation

   return fx;  //Returning the value of f(x) at x1
}

void check_bound(float a, float b)
{
   float        fa, fb;  //Declaration of variables in float

   fa = function(a);  //Calling Functions
   fb = function(b);  //Calling Functions

   if ((fa * fb) == 0)  //Check condition
   {
      printf("The root is one of the boundaries.\n");
      exit(0);
   }

   return ;
}
