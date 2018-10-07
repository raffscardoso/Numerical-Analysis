/*		GAUSS ELIMINATION 		*/

/* In linear algebra, Gaussian elimination (also known as row reduction) is an algorithm for solving systems of linear equations. It is usually understood as a sequence of operations performed on the corresponding matrix of coefficients. This method can also be used to find the rank of a matrix, to calculate the determinant of a matrix, and to calculate the inverse of an invertible square matrix.

To perform row reduction on a matrix, one uses a sequence of elementary row operations to modify the matrix until the lower left-hand corner of the matrix is filled with zeros, as much as possible. There are three types of elementary row operations: 

1) Swapping two rows,
2) Multiplying a row by a nonzero number,
3) Adding a multiple of one row to another row.

   Using these operations, a matrix can always be transformed into an upper triangular matrix, and in fact one that is in row echelon form. */

/*************** PROGRAM STARTS HERE ***************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* DEFINED CONSTANTS *********/
#define MAX        15
#define MAXC       0

/********* FUNCTION DECLARATION *********/
void gausseli(float co[MAX][MAX+1], float con[MAX], int n);
void backsub(float sol[MAX], float co[MAX][MAX+1], int n);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int         i = 0, j, n;             //Declaration of variables in int
   float       co[MAX][MAX+1], con[MAX]; //Declaration of arrays in float

   // Input Section
   printf("Enter the order of matrix:- ");
   scanf("%d", &n);

   while (i < n)  //Check condition
   {
      printf("Enter Equation no. %d\n", i+1);
      for (j = 0; j < n; j++)
      {
         printf("Enter the co-efficient of x%d:- ", j+1);
         scanf("%f", &co[i][j]);
      }
      printf("Enter the value:- ");
      scanf("%f", &con[i]);
      printf("\n");
      i++;  // Incrementing i
   }

   gausseli(co, con, n);  //Calling function
   exit(0);
}

/********* FUNCTION DEFINITION *********/
void gausseli(float co[MAX][MAX+1], float con[MAX], int n)
{
   int        i, j, k = 0; //Declaration of variables in int
   float      sol[MAX];    //Declaration of arrays in float
   float      val;         //Declaation of variables in float

   for (i = 0; i < n; i++)
   {
      co[i][n] = con[i];
   }

   while (k < n)
   {
      for (i = 0; i < n; i++)
      {
         if (k >= i)
         {
            continue;
         }
         val = co[i][k]/co[k][k];
         for (j = 0; j < n+1; j++)
         {
            co[i][j] = (co[i][j]-val*co[k][j]);
         }
      }
      k++;
   }

   for (i = 0; i < n; i++)
   {
      if (co[i][i] == 0)
      {
         printf("The given system of equations have no ");
         printf("or infinitely many solutions.\n");
         exit(1);
      }
   }

   backsub(sol, co, n);

   printf("The solutions of the Equation are:-\n");
   for (i = 0; i < n; i++)
   {
      printf("Value of x%d is %f\n", i+1, sol[i]);
   }
   return ;
}

void backsub(float sol[MAX], float co[MAX][MAX+1], int n)
{
   int        i, j;
   float      val;

   sol[n-1] = co[n-1][n]/co[n-1][n-1];
   for (i = n-2; i >= 0; i--)
   {
      for (j = i+1; j < n; j++)
      {
         val += co[i][j]*sol[j];
      }
      sol[i] = (co[i][n]-val)/co[i][i];
      val = 0;
   }

   return ;
}
