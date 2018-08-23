/****************** Usage: For finding the smallest real root of any given Polynomial equation. ****************************/

/********************* Specification: The program takes coeffients of the equation and their corresponding powers as the input and computes the smallest real root for the given polynomial equation using Ramanujan's method *****************/

/*************** Given Equation: Any polynomial Equation **************/
/*************** Smallest root is: Depends on the equation ***************/

/* It is an iterative method which can be used to determine the smallest root of the equation f(x) = 0, 
     where f(x) is of the form 
     f(x) = 1 – (a1x + a2x2 + a3x3 + ....)

     For smaller values of x, we can write,

     [1 – (a1x + a2x2 + a3x3 + ....)]–1 = b1 + b2x + b3x2 + ....
     ⇒ 1 + (a1x + a2x2 + a3x3 + ...) + (a1x + a2x2 + a3x3 + ....)2 + ....
     = b1 + b2x + b3x2 + ....

    Expanding L.H.S. by Binomial theorem.
    Comparing the coefficient of like powers of x on both sides, we get

    b1 = 1
    b2 = a1 = a1b1
    b3 = a1^2 + a2 = a1b2 + a2b1
    bn = a1bn – 1 + a2bn – 2 + ....... + an – 1b1

    n = 2, 3, .....

    Ramanujan stated that the successive convergents viz. b
    b_n/b_(n + 1) approach a root of the equation f(x) = 0.*/

/**************** PROGRAM STARTS HERE ***************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        32
#define   POWLIM     35

/********* FUNCTION DECLARATION *********/
void swapi(int *a, int *b);
void swapf(double *a, double *b);
void bubble_sort(int expo[], double coeff[], int nitems);
void ramanujan(double coeff[], int nitems, int n);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int        i = 0, nitems = 0, n; //Declaration of variables in int
   int        expo[MAX];            //Declaration of arrays in int
   char       co[MAX], ex[MAX];     //Declaration of arrays in char
   double     coeff[MAX];           //Declaration of arrays in double

   printf("Enter the co-efficients and it's corresponding powers as input if a corresponding co-efficient is not there then enter ZERO as the co-efficient.\nIf you are done by entering the polynomial terms then type any lower case letter to terminate the input process.\n\n");

   while (1)  //Infinte Loop
   {
      printf("Enter the co-effient: ");
      scanf("%s", co);
      if (*co >= 'a' && *co <= 'z')  //Check condition
      {
         break;
      }

      printf("Enter it's corresponding power: ");
      scanf("%s", ex);
      if (*ex >= 'a' && *ex <= 'z')  //Check condition
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

   printf("Enter the no. of convergents:- ");
   scanf("%d", &n);

   bubble_sort(expo, coeff, nitems);  //Calling Function
   ramanujan(coeff, nitems, n);
   exit(0);
}

/********* FUNCTION DEFINITION *********/
void ramanujan(double coeff[], int nitems, int n)
{
   int          i = 0, j, k = 1;
   double       constant;
   double       bcoeff[MAX];

   if (coeff[0] < 0)
   {
      constant = -1 * coeff[0];
      for (j = 1; j < nitems; j++)
      {
         coeff[j] = coeff[j] / (constant);
      }
   }
   else if (coeff[0] > 0)
   {
      constant = coeff[0];
      for (j = 1; j < nitems; j++)
      {
         coeff[j] = coeff[j] / (constant);
      }
   }

   if (nitems < n)
   {
      for (j = nitems; j < n+1; j++)
      {
         coeff[j] = 0;
      }
   }
   j = 0;

   bcoeff[i] = 1;
   while (k-1 < n)
   {
      i = 0;
      while (i < k)
      {
         bcoeff[k] = bcoeff[k] + (coeff[i+1] * bcoeff[k-i-1]);
         i++;
      }
      printf("Root after iteration no.%d is %f\n", k, bcoeff[k-1]/bcoeff[k]);
      k++;
   }
}

void bubble_sort(int expo[], double coeff[], int nitems)
{
   int        i, j;  //Declaration of variables in int

   for (i = 0; i < nitems; i++)
   {
      for (j = 0; j < (nitems-i-1); j++)
      {
         if (expo[j+1] < expo[j])  //Check condition
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

void swapf(double *a, double *b)
{
   double        temp;  //Declaration of variables in double

   temp = *a;
   *a = *b;
   *b = temp;

   return ;
}
