/****************** Usage: For finding the real roots of any given Polynomial equation. ****************************/

/********************* Specification: The program takes coeffients of the equation, their corresponding powers and an approx. root as the input and computes the root for the given polynomial equation using Birge-Vieta method ***********************/

/*************** Given Equation: Any polynomial Equation **************/
/*************** Roots are: Depends on the equation ***************/

/* One can use Horner's method twice to efficiently evaluate the value of the polynomial function and its first derivative; this combination is called Birge–Vieta's method. This method provides quadratic convergence for simple roots at the cost of two polynomial evaluations per step. */

/**************** PROGRAM STARTS HERE ***************/
#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        32
#define   POWLIM     35

/********* FUNCTION DECLARATION *********/
float reminder(float coeff[], int expo[], float h, int nitems);
void swapi(int *a, int *b);
void swapf(float *a, float *b);
void bubble_sort(int expo[], float coeff[], int nitems);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int        i = 0, nitems = 0, n; //Declaration of variables in int
   int        expo[MAX];            //Declaration of arrays in int
   char       co[MAX], ex[MAX];     //Declaration of arrays in char
   float      h, root;              //Declaration of variables in float
   float      coeff[MAX];           //Declaration of arrays in float

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

   printf("Enter the value of 'h' in (x-h):- ");
   scanf("%f", &h);

   printf("Enter the no. of iterations:- ");
   scanf("%d", &n);

   bubble_sort(expo, coeff, nitems);  //Calling Function

   i = 0;
   while (i < n)
   {
      root = reminder(coeff, expo, h, nitems);  //Calling Function
      h = root;
      i++;
   }
   printf("The root of the given Equation is %f\n", root);

   exit(0);
}

/********* FUNCTION DEFINITION *********/
float reminder(float coeff[], int expo[], float h, int nitems)
{
  int          i = 0;
  float        co_a, co_b, remind, c;
  float        qcoeff[MAX], qqcoeff[MAX];

   co_a = coeff[i];
   qcoeff[i] = co_a;

   while (i < (nitems-2))
   {
      co_a = coeff[i+1];
      co_b = qcoeff[i];
      qcoeff[i+1] = co_a + h * co_b;
      i++;
   }

   co_a = coeff[i+1];
   co_b = qcoeff[i];
   remind = co_a + h * co_b;

   co_a = qcoeff[i];
   qqcoeff[i] = co_a;

   while (i < (nitems-3))
   {
      co_a = qcoeff[i+1];
      co_b = qqcoeff[i];
      qqcoeff[i+1] = co_a + h * co_b;
      i++;
   }

   co_a = qcoeff[i+1];
   co_b = qqcoeff[i];
   c = co_a + h * co_b;

   h = h - (remind/c);
   return h;
}

void bubble_sort(int expo[], float coeff[], int nitems)
{
   int        i, j;

   for (i = 0; i < nitems; i++)
   {
      for (j = 0; j < (nitems-i-1); j++)
      {
         if (expo[j+1] > expo[j])
         {
            swapi(&expo[j+1], &expo[j]);
            swapf(&coeff[j+1], &coeff[j]);
         }
      }
   }

   return ;
}

void swapi(int *a, int *b)
{
   int        temp;

   temp = *a;
   *a = *b;
   *b = temp;

   return ;
}

void swapf(float *a, float *b)
{
   float        temp;

   temp = *a;
   *a = *b;
   *b = temp;

   return ;
}

/*int check(char *str)
{
   int        cval = 0, chk = 0;
   char       *sstr;

   sstr = str;
   while (*sstr != '\0')
   {
      if (*sstr < '0' || *sstr > '9')  //Check condition
      {
         printf("sstr is %s\n", sstr);
         if ((*sstr == '-' || *sstr == '+') && chk == 0)
         {
            chk = chk + 1;
         }
         else if ((*sstr == '-' || *sstr == '+') && chk != 0)
         {
            cval = 1;
         }
         else
         {
            return 2;
         }
      }

      sstr++;
   }

   return cval;
}*/
