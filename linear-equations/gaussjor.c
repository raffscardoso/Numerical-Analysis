/*			GAUSS-JORDAN ELIMINATION METHOD		*/

/*The following row operations on the augmented matrix of a system produce the augmented matrix of an equivalent system, i.e., a system with the same solution as the original one.
• Interchange any two rows.
• Multiply each element of a row by a nonzero constant.
• Replace a row by the sum of itself and a constant multiple of another row of the matrix.

For these row operations, we will use the following notations.
• Ri↔Rj means: Interchange row i and row j.
• αRi means: Replace row i with α times row i.
• Ri+αRj means: Replace row i with the sum of row i and α times row j.

The Gauss-Jordan elimination method to solve a system of linear equations is described in the following steps.
1. Write the augmented matrix of the system.
2. Use row operations to transform the augmented matrix in the form described below, which is called the reduced row echelon form (RREF).
(a) The rows (if any) consisting entirely of zeros are grouped together at the bottom of the matrix.
(b) In each row that does not consist entirely of zeros, the leftmost nonzero element is a 1 (called a leading 1 or a pivot).
(c) Each column that contains a leading 1 has zeros in all other entries.
(d) The leading 1 in any row is to the left of any leading 1’s in the rows below it.
3. Stop process in step 2 if you obtain a row whose elements are all zeros except the last one on the right. In that case, the system is inconsistent and has no solutions. Otherwise, finish step 2 and read the solutions of the system from the final matrix.

*/

/*************** PROGRAM STARTS HERE ***************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* DEFINED CONSTANTS *********/
#define MAX        15
#define MAXC       0

/********* FUNCTION DECLARATION *********/
void gaussjor(float co[MAX][MAX+1], float con[MAX], int n);

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

   gaussjor(co, con, n);  //Calling function
   exit(0);
}

/********* FUNCTION DEFINITION *********/
void gaussjor(float co[MAX][MAX+1], float con[MAX], int n)
{
   int        i, j, k = 0; //Declaration of variables in int
   float      sol[MAX];    //Declaration of arrays in float
   float      val;         //Declaation of variables in float

   for (i = 0; i < n; i++)
   {
      co[i][n] = con[i];  //Creating argumnted matrix
   }

   while (k < n)
   {
      for (i = 0; i < n; i++)
      {
         if (i == k)
         {
            continue; //Skipping the loop
         }
         val = co[i][k]/co[k][k];
         for (j = 0; j < n+1; j++)
         {
            co[i][j] = (co[i][j]-val*co[k][j]);
         }
      }
      k++;  //Incrementing k
   }

   for (i = 0; i < n; i++)
   {
      sol[i] = co[i][3]/co[i][i];
      printf("Value of x%d is %f\n", i+1, sol[i]);
   }
   return ;
}
