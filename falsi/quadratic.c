/****************** Usage: For finding the real roots of any given Transcendental equation. ****************************/

/********************* Specification: The program takes coeffients of the equation and upper and lower values of the interval as the input and computes the root for the given equation using Regular-falsi's method ***********************/

/*************** Given Equation: ax^2 + bx + c = 0**************/
/*************** Roots is: Depends on the Equation ***************/

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
void falsi(float co_a, float co_b, float co_c, float a, float b);
float function(float co_a, float co_b, float co_c, float val);
void check_bound(float co_a, float co_b, float co_c, float a, float b);

/********** MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   float         co_a, co_b, co_c, a, b, val;  //Declaration of variables in float

   if (argc != 6)  //Verification of arguments
   {
      fprintf(stderr, "Usage: %s <upper> <lower>\n", argv[0]);
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
   b = atof(argv[5]);  //Converting arguments

   check_bound(co_a, co_b, co_c, a, b);  //Calling Function

   printf("By using Regular-falsi method: \n");
   printf("The equation is: \n");
   printf("\t");
   printf("f(x) = (%.1f)x^2 + (%.1f)x + (%.1f)\n", co_a, co_b, co_c);

   printf("-------------------\n");
   printf("    f(a)     f(b)  \n");
   printf("-------------------\n");

   falsi(co_a, co_b, co_c, a, b); //Calling Function

   exit(0);
}

/********* FUNCTION DEFINITION *********/
void falsi(float co_a, float co_b, float co_c, float a, float b)
{
   float        fa, fb, fc, root, c, i = 0;  //Declaration of variables in float

   while (1)
   {
      fa = function(co_a, co_b, co_c, a);  //Calling Functions
      fb = function(co_a, co_b, co_c, b);  //Calling Functions
      printf("%.5f    %.5f\n", fa, fb);

      if (fa * fb < 0)
      {
         root = a - (((b-a)/(fb-fa))*fa);  // Function Equation
         c = root;
      }
      
      fc = function(co_a, co_b, co_c, c);  //Calling Functions
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

float function(float co_a, float co_b, float co_c, float val)
{
   float        fx, x = val;  //Declaration of variables in float

   fx = (co_a * x * x) + (co_b * x) + co_c;  // Function Equation

   return fx;  //Returning the value of f(x) at x1
}

void check_bound(float co_a, float co_b, float co_c, float a, float b)
{
   float        fa, fb;  //Declaration of variables in float

   fa = function(co_a, co_b, co_c, a);  //Calling Functions
   fb = function(co_a, co_b, co_c, b);  //Calling Functions

   if ((fa * fb) == 0)  //Check condition
   {
      printf("The root is one of the boundaries.\n");
      exit(0);
   }

   return ;
}
