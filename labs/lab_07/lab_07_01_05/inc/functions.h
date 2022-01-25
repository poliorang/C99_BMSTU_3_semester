#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

#define ERR_COUNT -1
#define FILE_ERROR -2

#define OK 0

int create_arr(FILE *f, int **arr, int **arr_end, size_t *n);
void pack_array(FILE *f, int *arr, const int *arr_end);
void print_array(FILE *f, const int *arr, const int *arr_end);

#endif

