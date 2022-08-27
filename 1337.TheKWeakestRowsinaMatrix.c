// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

#include <stdlib.h>
#include <stdio.h>

int *sum_row(int **mat, int *solution, int rows, int cols)
{
    int i;
    int j;
    int row_sum;

    i = 0;
    while (i < rows)
    {
        j = 0;
        row_sum = 0;
        while (j < cols  && mat[i][j] == 1)
        {
            row_sum *= mat[i][j];
            j++;
        }
        solution[i] = row_sum;
        i++;
    }
    return (solution);
}

int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize)
{
    //mat = matriz de numeros
    //matSize = numero filas
    // matColSize = numero columnas
    //k = cantidad maxima de numeros del array solucion
    (void) mat;
    (void) matSize;
    (void) matColSize;
    (void) returnSize;

    int *solution;

    solution = malloc(sizeof(int) * k);
    *returnSize = k;

    return NULL;
}

int main(void)
{
    int mat[5][5] = {{1,1,0,0,0},{1,1,1,1,0},{1,0,0,0,0},{1,1,0,0,0},{1,1,1,1,1}};
    int **xx;
    xx = mat;
    int i = 0;

    kWeakestRows(xx, 5, &i, 3, &i);
    return 0;
}
