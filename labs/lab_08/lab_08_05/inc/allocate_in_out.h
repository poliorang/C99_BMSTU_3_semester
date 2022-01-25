#ifndef ALL_IO_H
#define ALL_IO_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "error.h"

int **allocate_matrix(int n, int m);
void free_matrix(matrix_r matrix);

int input_matrix(matrix_r *matrix);
void print_matrix(matrix_r matrix);
int fill_matrix(matrix_r *matrix);
int get_degree(int *p, int *q);

#endif
