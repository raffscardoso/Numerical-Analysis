/****************** Usage: For finding the real roots of any given Polynomial equation. ****************************/

/********************* Specification: The program takes coeffients of the equation and their corresponding powers as the input and computes the root for the given polynomial equation using Graeffe's method ***********************/

/*************** Given Equation: Any polynomial Equation **************/
/*************** Roots are: Depends on the equation ***************/

/* In mathematics, Graeffe's method or Dandelin–Lobachesky–Graeffe method is an algorithm for finding all of the roots of a polynomial.
 The method separates the roots of a polynomial by squaring them repeatedly. This squaring of the roots is done implicitly, that is, only working on the coefficients of the polynomial. */

/**************** PROGRAM STARTS HERE ***************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        32
#define   POWLIM     35

/********* FUNCTION DECLARATION *********/
void graeffe(double coeff[], int nitems, int n);
int pow1(int ind);
void swapi(int *a, int *b);
void swapf(double *a, double *b);
void bubble_sort(int expo[], double coeff[], int nitems);

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

   printf("Enter the no. of iterations:- ");
   scanf("%d", &n);

   bubble_sort(expo, coeff, nitems);  //Calling Function

   if (n <= 3)
   {
      graeffe(coeff, nitems, n);  //Calling Function
   }
   else
   {
      printf("The precision is almost reached upto 3 iterations.\n");
      printf("So enter no. of iterations 3 or less than it.\n");
      exit(3);
   }

   exit(0);
}

/********* FUNCTION DEFINITION *********/
void graeffe(double coeff[], int nitems, int n)
{
   int        i = 0, j, k = 0, one, m = 1;  //Declaration of variables in int
   double     bcoeff[MAX], R[MAX];  //Declaration of arrays in double

   while (k < n)  //Check condition
   {
      i = 0;
      bcoeff[0] = powf(coeff[i], 2);

      for (j = 1; j < nitems; j++)
      {
         bcoeff[j] = powf(coeff[j], 2);
         i = 1;
         while ((i+j) <=  nitems && (i<=j))  //Check condition
         {
            one = pow1(i);
            bcoeff[j] = bcoeff[j] + one*(2*coeff[j-i]*coeff[j+i]);
            i++;  //Incrementing i
         }
      }

      printf("Roots value after iteration %d\n", k+1);
      for (i = 0; i < nitems-1; i++)
      {
         R[i] = powf((bcoeff[i+1]/bcoeff[i]), 1/(powf(2, m)));
         printf("R%d is %f ", i+1, R[i]);
      }
      printf("\n");
      m = m + 1;

      for (i = 0; i < nitems; i++)
      {
         coeff[i] = bcoeff[i];
      }

      k++;  //Incrementing k
   }
   return ;
}

void bubble_sort(int expo[], double coeff[], int nitems)
{
   int        i, j;  //Declaration of variables in int

   for (i = 0; i < nitems; i++)
   {
      for (j = 0; j < (nitems-i-1); j++)
      {
         if (expo[j+1] > expo[j])  //Check condition
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

int pow1(int ind)
{
   int        i = 1, i1 = -1;  //Declaration of variables in int

   if (ind%2 == 0)
   {
      return i;  //returning 1
   }
   else
   {
      return i1;  //returning -1
   }
}
