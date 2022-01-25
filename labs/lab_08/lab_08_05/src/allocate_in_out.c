#include "allocate_in_out.h"

int **allocate_matrix(int rows, int columns)
{
    int **matrix = calloc((size_t)rows, sizeof (int *));
    if (!matrix)
        return NULL;
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = calloc((size_t)columns, sizeof (int));
        if (!matrix[i])
        {
            for (int j = 0; j < rows; j++)
                free(matrix[j]);
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}

void free_matrix(matrix_r matrix)
{
    for (int i = 0; i < matrix.row; i++)
        free(matrix.matrix[i]);
    free(matrix.matrix);
}

int input_matrix(matrix_r *a)
{
    for (int i = 0; i < a->row; i++)
        for (int j = 0; j < a->column; j++)
            if (scanf("%d", &a->matrix[i][j]) != 1)
                return INPUT_ERROR;

    return EXIT_SUCCESS;
}

void print_matrix(matrix_r a)
{
    for (int i = 0; i < a.row; i++)
        for (int j = 0; j < a.column; j++)
            printf("%d%s", a.matrix[i][j], j == a.column - 1 ? "\n" : " ");
}

int fill_matrix(matrix_r *matrix)
{
    if (scanf("%d%d", &matrix->row, &matrix->column) != 2 || matrix->row <= 0 || matrix->column <= 0)
        return INPUT_ERROR;

    matrix->matrix = allocate_matrix(matrix->row, matrix->column);
    if (matrix->matrix == NULL)
        return MATRIX_ERROR;

    if (input_matrix(matrix))
    {
        free_matrix(*matrix);
        return INPUT_ERROR;
    }

    return EXIT_SUCCESS;
}

int get_degree(int *p, int *q)
{
    if (scanf("%d%d", p, q) != 2 || *p < 0 || *q < 0)
        return INPUT_ERROR;

    return EXIT_SUCCESS;
}
