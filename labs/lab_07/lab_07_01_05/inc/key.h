#ifndef KEY_H
#define KEY_H

#include <stdio.h>
#include <stdlib.h>

#define OK 0

#define EMPTY_ARRAY_ERROR 1
#define PARAMS_ERROR -2
#define MEMORY_ALLOCATION_ERROR -3

int count_elems_in_arr(const int *arr, const int *arr_end);
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

#endif

