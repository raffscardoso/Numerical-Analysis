#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h> // NOVO: Biblioteca para medir o tempo

/********* DEFINED CONSTANTS *********/
#define MAX      15
#define MAXC     0

/********* FUNCTION DECLARATION *********/
void gausseli(float co[MAX][MAX+1], int n);
void backsub(float sol[MAX], float co[MAX][MAX+1], int n);

/********* MAIN STARTS HERE *********/
int main(void)
{
    int         i, j, n;
    float       co[MAX][MAX+1];

    FILE *inputFile;
    inputFile = fopen("input.dat", "r");

    if (inputFile == NULL) {
        printf("Erro: Nao foi possivel abrir o arquivo 'input.dat'.\n");
        exit(1);
    }

    fscanf(inputFile, "%d", &n);
    if (n > MAX) {
        printf("Erro: A ordem da matriz (%d) excede o maximo permitido (%d).\n", n, MAX);
        fclose(inputFile);
        exit(1);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) {
            if (fscanf(inputFile, "%f", &co[i][j]) != 1) {
                printf("Erro de leitura no arquivo. Verifique o formato.\n");
                fclose(inputFile);
                exit(1);
            }
        }
    }
    fclose(inputFile);


    clock_t start_time, end_time;
    double cpu_time_used;

    printf("Iniciando calculo para matriz de ordem %d...\n", n);

    start_time = clock();

    gausseli(co, n);

    end_time = clock();

    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("\nTempo de execucao: %f segundos\n", cpu_time_used);

    return 0;
}

/********* FUNCTION DEFINITION *********/
void gausseli(float co[MAX][MAX+1], int n)
{
    int       i, j, k = 0;
    float     sol[MAX];
    float     val;

    while (k < n)
    {
        for (i = 0; i < n; i++)
        {
            if (k >= i)
            {
                continue;
            }
            if (co[k][k] == 0) {
                printf("Erro: Pivô zero encontrado. O sistema pode não ter solução única.\n");
                printf("Pivoteamento (troca de linhas) seria necessário para resolver.\n");
                exit(1);
            }
            val = co[i][k] / co[k][k];
            for (j = 0; j < n + 1; j++)
            {
                co[i][j] = (co[i][j] - val * co[k][j]);
            }
        }
        k++;
    }

    for (i = 0; i < n; i++)
    {
        if (co[i][i] == 0)
        {
            printf("O sistema de equacoes nao tem solucao unica.\n");
            return;
        }
    }

    backsub(sol, co, n);

    printf("\nA solucao do sistema e:\n");
    for (i = 0; i < n; i++)
    {
        printf("x%d = %f\n", i + 1, sol[i]);
    }
    return;
}

void backsub(float sol[MAX], float co[MAX][MAX+1], int n)
{
    int     i, j;
    float   val; 

    sol[n - 1] = co[n - 1][n] / co[n - 1][n - 1];

    for (i = n - 2; i >= 0; i--)
    {
        val = 0;
        for (j = i + 1; j < n; j++)
        {
            val += co[i][j] * sol[j];
        }
        sol[i] = (co[i][n] - val) / co[i][i];
    }
    return;
}
