#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "add_delete.h"
#include "allocate_in_out.h"
#include "error.h"

void find_first_min(matrix_r matrix, int *r, int *c);
int make_matrix_square(matrix_r *matrix);
int multiplicate_matrix(matrix_r matrix_a, matrix_r *matrix_b);
void copy_matrix(matrix_r matrix, matrix_r *new_matrix);
int copy_matrix_in_new(matrix_r matrix, matrix_r *new_matrix);
void identity_matrix(matrix_r *matrix);
int exponentiate_matrix(matrix_r *matrix, int degree);
int count_rows(matrix_r matrix);


#endif
