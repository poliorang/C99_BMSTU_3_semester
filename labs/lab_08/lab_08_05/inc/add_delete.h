#ifndef ADD_DEL_H
#define ADD_DEL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "error.h"
#include "error.h"

int add_rows_and_columns(matrix_r *matrix, int size);
void delete_row(matrix_r *matrix, int r);
int delete_column(matrix_r *matrix, int c);
int add_row(matrix_r *matrix, int *row);
int add_column(matrix_r *matrix);
int *get_new_row(matrix_r matrix);

#endif
