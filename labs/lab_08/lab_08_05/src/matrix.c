#include "matrix.h"

void find_first_min(matrix_r matrix, int *row, int *column)
{
    int min = matrix.matrix[0][0];
    (*row) = 0;
    (*column) = 0;
    for (int i = 0; i < matrix.row; i++)
        for (int j = 0; j < matrix.column; j++)
            if (matrix.matrix[i][j] < min)
            {
                min = matrix.matrix[i][j];
                *row = i;
                *column = j;
            }
}

int make_matrix_square(matrix_r *matrix)
{
    int row, column;
    while (matrix->row > matrix->column)
    {
        find_first_min(*matrix, &row, &column);
        delete_row(matrix, row);
    }

    int **tmp = NULL;
    if ((tmp = realloc(matrix->matrix, matrix->row * sizeof(int *))) == NULL)
        return ALLOCATE_ERROR;

    matrix->matrix = tmp;

    while (matrix->row < matrix->column)
    {
        find_first_min(*matrix, &row, &column);
        if (delete_column(matrix, column))
            return ADD_DELETE_ERROR;
    }

    return EXIT_SUCCESS;
}

int multiplicate_matrix(matrix_r matrix_a, matrix_r *matrix_b)
{
    matrix_r tmp;
    tmp.row = matrix_a.row;
    tmp.column = matrix_a.column;
    tmp.matrix = allocate_matrix(matrix_a.row, matrix_a.column);

    if (tmp.matrix == NULL)
        return ALLOCATE_ERROR;

    for (int i = 0; i < matrix_a.row; i++)
        for (int c = 0; c < matrix_a.column; c++)
        {
            int summ = 0;
            for (int j = 0; j < matrix_a.column; j++)
                summ += matrix_a.matrix[i][j] * matrix_b->matrix[j][c];
            tmp.matrix[i][c] = summ;
        }

    for (int i = 0; i < matrix_a.row; i++)
        for (int j = 0; j < matrix_a.column; j++)
            matrix_b->matrix[i][j] = tmp.matrix[i][j];
    free_matrix(tmp);

    return EXIT_SUCCESS;
}

int copy_matrix_in_new(matrix_r matrix, matrix_r *new_matrix)
{
    new_matrix->row = matrix.row;
    new_matrix->column = matrix.column;
    new_matrix->matrix = allocate_matrix(new_matrix->row, new_matrix->column);
    if (new_matrix->matrix == NULL)
        return MATRIX_ERROR;

    copy_matrix(matrix, new_matrix);

    return EXIT_SUCCESS;
}

void copy_matrix(matrix_r matrix, matrix_r *new_matrix)
{
    for (int i = 0; i < new_matrix->row; i++)
        for (int j = 0; j < new_matrix->column; j++)
            new_matrix->matrix[i][j] = matrix.matrix[i][j];
}

void identity_matrix(matrix_r *matrix)
{
    for (int i = 0; i < matrix->row; i++)
        for (int j = 0; j < matrix->column; j++)
        {
            if (i == j)
                matrix->matrix[i][j] = 1;
            else
                matrix->matrix[i][j] = 0;
        }
}

int exponentiate_matrix(matrix_r *matrix, int degree)
{
    matrix_r new_matrix;
    if (copy_matrix_in_new(*matrix, &new_matrix))
        return ALLOCATE_ERROR;

    if (degree == 0)
        identity_matrix(matrix);
    else
        for (int i = 0; i < degree - 1; i++)
            if (multiplicate_matrix(new_matrix, matrix))
            {
                free_matrix(new_matrix);
                return ALLOCATE_ERROR;
            }

    free_matrix(new_matrix);

    return EXIT_SUCCESS;
}

int count_rows(matrix_r matrix)
{
    return matrix.row;
}
