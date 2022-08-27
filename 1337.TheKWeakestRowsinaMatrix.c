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

void	get_k_mins(int *sum_row, int *solution)
{
	(void)sum_row;
	(void)solution;
	return ;
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

	int *sum_row;
	int *solution;

	sum_row = malloc(sizeof(int) * matSize);
	add_row(mat, sum_row, matSize, *matColSize);
	*returnSize = k;
	solution = malloc(sizeof(int) * k);
	get_k_mins(sum_row, solution);


	return (sum_row);
}

int main(void)
{
	int *mat[] = 
	{
		(int[]) {1,1,0,0,0},
		(int[]) {1,1,1,1,0},
		(int[]) {1,0,0,0,0},
		(int[]) {1,1,0,0,0},
		(int[]) {1,1,1,1,1}
	};
	int mat_rows = 5;
	int mat_cols = 5;
	kWeakestRows(mat, 5, &mat_rows, 5, &mat_cols);
	print_matrix(mat, mat_rows, mat_cols);
	return 0;
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
