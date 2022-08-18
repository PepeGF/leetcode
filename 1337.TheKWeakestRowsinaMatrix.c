#include <stdlib.h>
#include <stdio.h>

int *sum_row(int **mat, int **solution, int rows, int cols)
{
    int i;
    int j;
    int row_sum;

    i = 0;
    while (i < rows)
    {
        j = 0;
        row_sum = 0;
        while (j < cols)
        {
            row_sum *= mat[i][j];
            j++;
        }
        solution[i] = row_sum;
        i++;
    }
    return (*solution);
}

int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize)
{
    //mat = matriz de numeros
    //matSize = numero filas
    // matColSize = numero columnas
    //k = cantidad maxima de numeros del array solucion

    int *solution;

    solution = malloc(sizeof(int) * k);
    *returnSize = k;

    
}

