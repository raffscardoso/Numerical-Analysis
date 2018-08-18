/****************** Usage: For finding the real roots of any given Polynomial equation. ****************************/

/********************* Specification: The program takes coeffients of the equation, their corresponding powers and coeffients of the quadratic which is a factor of the polynomial as the input and computes the root for the given polynomial equation using Horner's method ***********************/

/*************** Given Equation: Any polynomial Equation **************/
/*************** Roots are: Depends on the equation ***************/

/* Given the polynomial 
   p(x) = a0 + a1x + a2x^2 + .......... + anx^n 
   where a0, ........., an are real numbers, we wish to evaluate the polynomial at a specific value of x, say x0.

   To accomplish this, we define a new sequence of constants as follows:

   bn = an
   b_{n-1} = a_{n-1} + b_{n}x_{0}
           .
           .
           .
   b_{0} = a_{0} + b_{1}x_{0}

   then b0 is the value of p(x0).
   To see why this works, note that the polynomial can be written in the form
   p(x) = a0 + x(a1 + x(a2 + ........ + x(a_{n-1} + anx0)))
        = a0 + x(a1 + x(a2 + ........ + x(b_{n-1})))
        .
        .
        .
        = a0 + x0(b1)
        = b0.
*/

/**************** PROGRAM STARTS HERE ***************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        32

/********* FUNCTION DECLARATION *********/
void reminder(float coeff[], int expo[], float p, float q, int nitems);
void swapi(int *a, int *b);
void swapf(float *a, float *b);
void bubble_sort(int expo[], float coeff[], int nitems);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int        i = 0, nitems = 0; //Declaration of variables in int
   int        expo[MAX];         //Declaration of arrays in int
   char       co[MAX], ex[MAX];  //Declaration of arrays in char
   float      p, q;              //Declaration of variables in float
   float      coeff[MAX];        //Declaration of arrays in float

   printf("Enter the co-efficients and it's corresponding powers as input if a corresponding co-efficient is not there then enter ZERO as the co-efficient.\nIf you are done by entering the polynomial terms then type any lower case letter to terminate the input process.\n\n");

   while (1)  //Infinte Loop
   {
      printf("Enter the co-effient: ");
      scanf("%s", co);
      if (*co >= 'a' && *co <= 'z')  //Check condition
      {
         break;  //Getting out of the loop
      }

      printf("Enter it's corresponding power: ");
      scanf("%s", ex);
      if (*co >= 'a' && *co <= 'z')  //Check condition
      {
         fprintf(stderr, "These values for powers can't be accepted as inputs.\n");
         exit(2);
      }

      printf("\n");

      coeff[i] = atof(co);  //Converting input
      expo[i] = atoi(ex);   //Converting input

      i++;  //Incrementing i
      nitems++;  //Incrementing nitems
   }

   printf("Enter the value of 'p' in x^2 + px + q:- ");
   scanf("%f", &p);
   printf("Enter the value of 'q' in x^2 + px + q:- ");
   scanf("%f", &q);

   bubble_sort(expo, coeff, nitems);  //Calling Function
   reminder(coeff, expo, p, q, nitems);  //Calling Function
   exit(0);
}

/********* FUNCTION DEFINITION *********/
void reminder(float coeff[], int expo[], float p, float q, int nitems)
{
  int          i = 0;                    //Declaration of variables in int
  float        co_a, co_b0, co_b1, R, S; //Declaration of variables in float
  float        qcoeff[MAX];              //Declaration of arrays in int

   co_a = coeff[i];
   qcoeff[i] = co_a, i++;

   co_a = coeff[i];
   co_b0 = qcoeff[i-1];
   qcoeff[i] = co_a - p*co_b0, i++;

   while (i < (nitems-2))  //Check condition
   {
      co_a = coeff[i];
      co_b0 = qcoeff[i-1];
      co_b1 = qcoeff[i-2];

      qcoeff[i] = co_a - p*co_b0 - q*co_b1;
      i++;
   }

   co_a = coeff[i];
   co_b0 = qcoeff[i-1];
   co_b1 = qcoeff[i-2];

   R = co_a - p*co_b0 - q*co_b1;
   S = coeff[i+1] - q*co_b0;

   for (i = 0; i < nitems-3; i++)
   {
      printf("(%.3f)x^%d + ", qcoeff[i], expo[i+2]);
   }
   printf("Q(x) = (%.3f)x^%d \n", qcoeff[i], expo[i+2]);

   printf("R(x) = (%.3f)x + (%.3f)\n", R, S);
   return ;
}

void bubble_sort(int expo[], float coeff[], int nitems)
{
   int        i, j;  //Declaration of variables in int

   for (i = 0; i < nitems; i++)
   {
      for (j = 0; j < (nitems-i-1); j++)
      {
         if (expo[j+1] > expo[j])
         {
            swapi(&expo[j+1], &expo[j]);    //Swaping items
            swapf(&coeff[j+1], &coeff[j]);  //Swaping items
         }
      }
   }

   return ;
}

void swapi(int *a, int *b)
{
   int        temp;  //Declaration of variables in int

   temp = *a;
   *a = *b;
   *b = temp;

   return ;
}

void swapf(float *a, float *b)
{
   float        temp;  //Declaration of variables in float

   temp = *a;
   *a = *b;
   *b = temp;

   return ;
}
