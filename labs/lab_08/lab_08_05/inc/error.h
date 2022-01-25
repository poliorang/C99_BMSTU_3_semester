#ifndef ERROR_H
#define ERROR_H

#define INPUT_ERROR 1
#define MATRIX_ERROR 2
#define ALLOCATE_ERROR 3
#define ADD_DELETE_ERROR 4

typedef struct
{
    int row;
    int column;
    int **matrix;
} matrix_r;

#endif

