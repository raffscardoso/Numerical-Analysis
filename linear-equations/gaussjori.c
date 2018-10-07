/*		INVERSE OF A MATRIX USING GAUSS JORDAN METHOD		*/

/*
To find the inverse of matrix A, using Gauss-Jordan elimination, we must find a sequence of elementary row operations that reduces A to the identity and then perform the same operations on In to obtain inverse of A.
*/

/*************** PROGRAM STARTS HERE ***************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* DEFINED CONSTANTS *********/
#define MAX        15
#define MAXC       0

/********* FUNCTION DECLARATION *********/
void gaussjori(float co[MAX][MAX], float ai[MAX][MAX], int n);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int         i = 0, j, n;                //Declaration of variables in int
   float       co[MAX][MAX], ai[MAX][MAX]; //Declaration of 2d-arrays in float

   // Input Section
   printf("Enter the order of matrix:- ");  //Taking order of the matrix
   scanf("%d", &n);

   printf("Enter the elements of matrix in row-wise order: \n");
   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n; j++)
      {
         ai[i][j] = 0;
         scanf("%f", &co[i][j]);

         if (i == j)  //Check condition
         {
            ai[i][j] = 1;  //Constructing identity matrix
         }
      }
   }
   gaussjori(co, ai, n);  //Calling function
   exit(0);
}

void gaussjori(float co[MAX][MAX], float ai[MAX][MAX], int n)
{
   int        i, j, k = 0; //Declaration of variables in int
   float      val;         //Declaation of variables in float

   while (k < n)  //Check condition
   {
      for (i = 0; i < n; i++)
      {
         if (i == k)  //check condition
         {
            continue;  //Skipping the iteration
         }
         val = co[i][k]/co[k][k];
         for (j = 0; j < n+1; j++)
         {
            co[i][j] = (co[i][j]-val*co[k][j]); //Applying row transformations
            ai[i][j] = (ai[i][j]-val*ai[k][j]); //Applying row transformations
         }
      }
      k++;  //Incremnting k
   }

   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n; j++)
      {
         ai[i][j] = (ai[i][j]/co[i][i]);  //Normalizing
         printf("%f ", ai[i][j]);
      }
      printf("\n");
   }
   return ;
}
