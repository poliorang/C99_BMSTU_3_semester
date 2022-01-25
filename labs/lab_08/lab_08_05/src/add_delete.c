#include "add_delete.h"

int add_rows_and_columns(matrix_r *matrix, int size)
{
    while (matrix->row < size)
    {
        int *row = get_new_row(*matrix);
        if (row == NULL)
            return ALLOCATE_ERROR;

        if (add_row(matrix, row))
            return ADD_DELETE_ERROR;
    }

    while (matrix->column < size)
        if (add_column(matrix))
            return ADD_DELETE_ERROR;

    return EXIT_SUCCESS;
}

void delete_row(matrix_r *matrix, int r)
{
    free(matrix->matrix[r]);

    if (r < matrix->row)
        memmove(matrix->matrix + r, matrix->matrix + r + 1, sizeof(int *) * (matrix->row - 1 - r));

    matrix->row--;
}

int delete_column(matrix_r *matrix, int c)
{
    int *buf = NULL;
    for (int i = 0; i < matrix->row; i++)
    {
        if (c < matrix->column)
            memmove(&matrix->matrix[i][c], &matrix->matrix[i][c + 1], sizeof(int) * (matrix->column - 1 - c));

        if ((buf = realloc(matrix->matrix[i], (matrix->column - 1) * sizeof(int))) == NULL)
            return ALLOCATE_ERROR;

        matrix->matrix[i] = buf;
    }
    matrix->column--;

    return EXIT_SUCCESS;
}

int *get_new_row(matrix_r matrix)
{
    int *row = NULL;
    row = calloc(matrix.column, sizeof (int));

    if (!row)
        return NULL;

    for (int j = 0; j < matrix.column; j++)
    {
        double prod = 1.0;
        int i = 0;

        while (i < matrix.row)
        {
            prod *= abs(matrix.matrix[i][j]);
            i++;
        }
        double add = pow(prod, 1.0 / (double)i);
        row[j] = (int)add;
    }

    return row;
}

int add_row(matrix_r *matrix, int *row)
{
    int **tmp = NULL;
    if ((tmp = realloc(matrix->matrix, sizeof (int *) * (matrix->row + 1))) == NULL)
        return ALLOCATE_ERROR;

    matrix->matrix = tmp;
    matrix->matrix[matrix->row] = row;
    matrix->row++;

    return EXIT_SUCCESS;
}

int add_column(matrix_r *matrix)
{
    matrix->column++;
    for (int i = 0; i < matrix->row; i++)
    {
        int max = matrix->matrix[i][0];
        for (int j = 0; j < matrix->column - 1; j++)
            if (matrix->matrix[i][j] > max)
                max = matrix->matrix[i][j];
        int *tmp = NULL;
        if ((tmp = realloc(matrix->matrix[i], matrix->column * sizeof(int))) == NULL)
            return ALLOCATE_ERROR;

        matrix->matrix[i] = tmp;
        matrix->matrix[i][matrix->column - 1] = max;
    }

    return EXIT_SUCCESS;
}

