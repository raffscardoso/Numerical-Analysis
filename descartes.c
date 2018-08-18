/****************** Usage: For finding nature of the given Polynomial equation of degree n. ****************************/

/********************* Specification: The program takes coeffients and their corresponding powers as the input and computes the sign of the roots for the given polynomial equation using Descartes rule of sign ***********************/

/*
 Descartes' rule of signs

Positive roots:-
The rule states that if the terms of a single-variable polynomial with real coefficients are ordered by descending variable exponent, then the number of positive roots of the polynomial is either equal to the number of sign differences between consecutive nonzero coefficients, or is less than it by an even number. Multiple roots of the same value are counted separately.

Negative roots:-
As a corollary of the rule, the number of negative roots is the number of sign changes after multiplying the coefficients of odd-power terms by −1, or fewer than it by an even number. This procedure is equivalent to substituting the negation of the variable for the variable itself. For example, to find the number of negative roots of f(x) = ax^3 + bx^2 + cx + d, we equivalently ask how many positive roots there are for -x in 
          f(-x) = a(-x)^3 + b(-x)^2 + c(-x) + d = -ax^3 + bx^2 - cx + d
Using Descartes' rule of signs on g(x) gives the number of positive roots xi of g, and since  g(x) = f(-x) it gives the number of positive roots (−xi) of f, which is the same as the number of negative roots xi of f. 

*/

/**************** PROGRAM STARTS HERE ***************/
#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        32

/********* FUNCTION DECLARATION *********/
int sign(int sign[]);
void function1(float coeff[], int expo[], int nitems);
void function2(float coeff[], int expo[], int nitems);
void swapi(int *a, int *b);
void swapf(float *a, float *b);
void bubble_sort(int expo[], float coeff[], int nitems);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int        i = 0, nitems = 0; //Declaration of variables in int
   int        expo[MAX];         //Declaration of arrays in int
   char       co[MAX], ex[MAX];  //Declaration of arrays in char
   float      coeff[MAX];        //Declaration arrays of  in float

   printf("Enter the co-efficients and it's corresponding powers as input, if a corresponding co-efficient is not there then don't enter any just proceed to the next term.\nIf you are done by entering the polynomial terms then type any lower case letter to terminate the input process.\n\n");

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

   bubble_sort(expo, coeff, nitems);  //Calling Function
   function1(coeff, expo, nitems);    //Calling Function
   function2(coeff, expo, nitems);    //Calling Function
   exit(0);
}

/********* FUNCTION DEFINITION *********/
void function1(float coeff[], int expo[], int nitems)
{
   int        i = 0, ch;  //Declaration of variables in int
   int        sign1[MAX]; //Declaration of arrays in int

   while (i < nitems)  //Check condition
   {
      if (coeff[i] < 0)  //Check condition
      {
         sign1[i] = 0;
      }
      else
      {
         sign1[i] = 1;
      }
      i++;  //Incrementing i
   }

   sign1[i] = -1;  //Adding sentinal to array

   ch = sign(sign1);  //Calling Function
   printf("No. of +ve roots of Equation can't exceed %d\n", ch);
   return ;
}

void function2(float coeff[], int expo[], int nitems)
{
   int        i = 0, ch, j;  //Declaration of variables in int
   int        sign1[MAX];    //Declaration of arrays in int

   for (j = 0; j < nitems; j++)
   {
      if ((expo[j]%2) == 1)  //Check condition
      {
         coeff[j] = -1 * coeff[j];
      }
   }

   while (i < nitems)  //Check condition
   {
      if (coeff[i] < 0)  //Check condition
      {
         sign1[i] = 0;
      }
      else
      {
         sign1[i] = 1;
      }
      i++;  //Incrementing i
   }

   sign1[i] = -1;  //Adding sentinal to array

   ch = sign(sign1);  //Calling Function
   printf("No. of -ve roots of Equation can't exceed %d\n", ch);
   return ;
}


int sign(int sign[])
{
   int        fb, sb, i = 0, change = 0;  //Declaration of variables in int

   while (sign[i+1] != -1)  //Check condition
   {
      fb = sign[i];
      sb = sign[i+1];

      if (((fb-sb) == 1) || ((fb-sb) == -1))  //Check condition
      {
         change++;
      }
      i++;  //Incrementing i
   }

   return change;  //Returning val
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
