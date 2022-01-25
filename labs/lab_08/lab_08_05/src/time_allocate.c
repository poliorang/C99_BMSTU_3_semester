#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "error.h"
#include "allocate_in_out.h"

int **allocate_matrix_malloc(int rows, int columns)
{
    int **matrix = malloc((size_t)rows * sizeof (int *));
    if (!matrix)
        return NULL;
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = malloc((size_t)columns * sizeof (int));
        if (!matrix[i])
        {
            free_matrix(matrix, rows);
            return NULL;
        }
    }
    return matrix;
}

int main(void)
{
    setbuf(stdout, NULL);
    matrix_r a, b;
    clock_t start, end;
    int size = 10000;

    printf("\n Size --> %d x %d\n", size, size);
    start = clock();
    if ((a.matrix = allocate_matrix_malloc(size, size)) == NULL)
        return ALLOCATE_ERROR;
    end = clock();

    printf("\nTime for MALLOC allocation --> %lf", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    if ((b.matrix = allocate_matrix(size, size)) == NULL)
        return ALLOCATE_ERROR;
    end = clock();

    printf("\nTime for CALLOC allocation --> %lf", (double)(end - start) / CLOCKS_PER_SEC);

    free_matrix(a.matrix, size);
    free_matrix(b.matrix, size);
    return EXIT_SUCCESS;
}
