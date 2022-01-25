#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"
#include "matrix.h"
#include "add_delete.h"
#include "allocate_in_out.h"

int main(void)
{
    matrix_r matrix_a, matrix_b;

    // выделение памяти под матрицы и заполнение
    if (fill_matrix(&matrix_a))
        return ALLOCATE_ERROR;

    if (fill_matrix(&matrix_b))
    {
        free_matrix(matrix_a);
        return ALLOCATE_ERROR;
    }

    // приведение матрицы к квадратному виду путем удаления строк и столбцов
    if (make_matrix_square(&matrix_a) || make_matrix_square(&matrix_b))
    {
        free_matrix(matrix_a);
        free_matrix(matrix_b);
        return ALLOCATE_ERROR;
    }

    // приведение матриц к одинаковым размерам путем добавления строк и столбцов
    if (count_rows(matrix_a) > count_rows(matrix_b))
        if (add_rows_and_columns(&matrix_b, count_rows(matrix_a)))
        {
            free_matrix(matrix_a);
            free_matrix(matrix_b);
            return ALLOCATE_ERROR;
        }

    if (count_rows(matrix_a) < count_rows(matrix_b))
        if (add_rows_and_columns(&matrix_a, count_rows(matrix_b)))
        {
            free_matrix(matrix_a);
            free_matrix(matrix_b);
            return ALLOCATE_ERROR;
        }

    // получие степеней матриц
    int degree_p, degree_q;
    if (get_degree(&degree_p, &degree_q))
    {
        free_matrix(matrix_a);
        free_matrix(matrix_b);
        return INPUT_ERROR;
    }

    // возведение матрицы в степень
    if (exponentiate_matrix(&matrix_a, degree_p))
    {
        free_matrix(matrix_a);
        free_matrix(matrix_b);
        return ALLOCATE_ERROR;
    }
    if (exponentiate_matrix(&matrix_b, degree_q))
    {
        free_matrix(matrix_a);
        free_matrix(matrix_b);
        return ALLOCATE_ERROR;
    }

    // умножение матриц
    if (multiplicate_matrix(matrix_a, &matrix_b))
    {
        free_matrix(matrix_a);
        free_matrix(matrix_b);
        return ALLOCATE_ERROR;
    }

    print_matrix(matrix_b);

    free_matrix(matrix_a);
    free_matrix(matrix_b);

    return EXIT_SUCCESS;
}

