/****************** Usage: For finding the real roots of any given Transcendental equation. ****************************/

/********************* Specification: The program takes coeffients of the equation and upper and lower values of the interval as the input and computes the root for the given equation using Bi-section method ***********************/

/*************** Given Equation: 2x-log(x)-7 = 0**************/
/*************** Roots is: 3.789282 ***************/

/********* Bisection method which is also known as bolzano method is based on the repeated application of intermediate value property. 
   Let the function f(x) be continous between a and b. For definiteness, let f(a) be (-)ve and f(b) be (+)ve. Then the first approximation to the root is x1 = (a+b)/2. 
   If f(x1)=0, then x1 is a root of f(x) = 0, otherwise, the root lies between a
 and x1 or x1 and baccording to f(x1) is (+)ve or (-)ve. Then we bisect the inte
rval as before and continue the process until the root is found to the desird ac
curacy. *********/

/*************** PROGRAM STARTS HERE ***************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* FUNCTION DECLARATION *********/
void bisect(float a, float b);
float function(float val);
void check_bound(float a, float b);

/********** MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   float         a, b;  //Declaration of variables in float

   if (argc != 3)  //Verification of arguments
   {
      fprintf(stderr, "Usage: %s <lower> <upper>\n", argv[0]);
      exit(1);
   }

   a = atof(argv[1]);  //Conversion of arguments
   b = atof(argv[2]);  //Conversion of arguments

   if ((a == 0) || (b == 0))
   {
      printf("log(0) is undefined so give a value which is other than zero\n");
      exit(2);
   }

   check_bound(a, b);  //Calling Function

   printf("By using Bisection method: \n");
   printf("The equation is: \n");
   printf("\t");
   printf("f(x) = 2x-log(x)-7\n");

   printf("--------------------------------\n");
   printf("   f(a)       f(b)      c       \n");
   printf("--------------------------------\n");
   bisect(a, b);  //Calling Function

   exit(0);
}

void bisect(float a, float b)
{
   float        i, fa, fb, fm, mid;  //Declaration of variables in float

   while (1)  //Producing an infinte loop
   {
      fa = function(a);  //Calling Functions
      fb = function(b);  //Calling Functions
      printf("%f  %f ", fa, fb);

      if ((fa * fb) > 0)  //Check condition
      {
         printf("Root doesn't exist between %.1f and %.1f\n", a, b);
         exit(0);
      }
      else
      {
         mid = (a + b) / 2;  //Calculating the mid-point of the interval
         fm = function(mid);  //Calculating the function value at mid-point
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

         if (floor(a*10000)/10000 == floor(b*10000)/10000) //Comparing the roots
         {
            printf("The given root is %f after %.1f iterations\n", b, i);
            break;  //Getting out of the loop
         }
      }
      i++;  //Incrementing of i
   }

   return ;
}

float function(float val)
{
   float        fx, x = val;  //Declaration of variables in float

   fx = 2 * x - log10f(x) - 7;  // Function Equation

   return fx;  //Returning the value of f(x) at x1
}

void check_bound(float a, float b)
{
   float        fa, fb;  //Declaration of variables in float

   fa = function(a);  //Calling Functions
   fb = function(b);  //Calling Functions

   if ((fa * fb) == 0)  //Check Condition
   {
      printf("The root is one of the boundaries.\n");
      exit(0);
   }

   return ;
}
