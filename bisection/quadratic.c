/****************** Usage: For finding the real roots of any given quadratic equation. ****************************/

/********************* Specification: The program takes coeffients of the equation and upper and lower values of the interval as the input and computes the root for the given equation using Bi-section method ***********************/

/*************** Given Equation: 1*x^2 + 5*x^1 + 2 = 0 **************/
/*************** Roots are: -0.438416 & -4.561523 *************/

/********* Bisection method which is also known as bolzano method is based on the repeated application of intermediate value property. 
   Let the function f(x) be continous between a and b. For definiteness, let f(a) be (-)ve and f(b) be (+)ve. Then the first approximation to the root is x1 = (a+b)/2. 
   If f(x1)=0, then x1 is a root of f(x) = 0, otherwise, the root lies between a and x1 or x1 and baccording to f(x1) is (+)ve or (-)ve. Then we bisect the interval as before and continue the process until the root is found to the desird accuracy. *********/

/*************** PROGRAM STARTS HERE ***************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* FUNCTION DECLARATION *********/
void bisect(float co_a, float co_b, float co_c, float a, float b);
float function(float co_a, float co_b, float co_c, float val);
void check_bound(float co_a, float co_b, float co_c, float a, float b);

/********** MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   float         a, b, co_a, co_b, co_c, val;  //Declaration of variables in float

   if (argc != 6)  //Verification of arguments
   {
      fprintf(stderr, "Usage: %s <x^2 coeff> <x^1 coeff> <x^0 coeff> <lower> <upper>\n", argv[0]);
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

   a = atof(argv[4]);  //Conversion of arguments
   b = atof(argv[5]);  //Conversion of arguments

   check_bound(co_a, co_b, co_c, a, b);  //Calling Functions

   printf("By using Bisection method: \n");
   printf("The equation is: \n");
   printf("\t");
   printf("f(x) = 1*x^2 + 5*x^1 + 2\n");

   printf("--------------------------------\n");
   printf("   f(a)       f(b)      c       \n");
   printf("--------------------------------\n");

   bisect(co_a, co_b, co_c, a, b);  //Calling Functions

   exit(0);
}

void bisect(float co_a, float co_b, float co_c, float a, float b)
{
   float        i, fa, fb, fm, mid;  //Declaration of variables in float

   while (1)
   {
      fa = function(co_a, co_b, co_c, a);  //Calling Functions
      fb = function(co_a, co_b, co_c, b);  //Calling Functions
      printf("%f  %f ", fa, fb);

      if ((fa * fb) > 0)  //Check condition
      {
         printf("Root doesn't exist between %.1f and %.1f\n", a, b);
         exit(0);
      }
      else
      {
         mid = (a + b) / 2;
         fm = function(co_a, co_b, co_c, mid);  //Calling Functions
         printf(" %f\n", mid);

         if (fm == 0.0000)  //Check condition
         {
            printf("%f is the given root\n", mid);
            exit(0);
         }
         else if ((fa * fm) < 0)  //Check condition
         {
            b = mid;
         }
         else if ((fm * fb) < 0)  //Check condition
         {
            a = mid;
         }

         if (floorf(a*10000)/10000 == floorf(b*10000)/10000)  //Comparing roots
         {
            printf("The given root is %f found after %.1f iterations.\n", b, i);
            break;  //Getting out of the loop
         }
      }
      i++;  //Incrementing of i
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
