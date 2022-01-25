#ifndef MAT_H
#define MAT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int **allocate_matrix(int n, int m);
void free_matrix(int **dtaa, int n);

#endif
