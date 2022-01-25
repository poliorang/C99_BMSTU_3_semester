#ifndef ERR_STRUCT_H
#define ERR_STRUCT_H

#include <stdio.h>
#include <stdlib.h>

#define SCNF_ERR 1
#define ALLOCATE_ERR 2
#define INPUT_ERR 3
#define MULTIPLICATE_ERR 4
#define SQUARE_ERR 5
#define DIVIDE_ERR 6

#define MAX_LEN_COMMAND 4

typedef struct node node_t;

struct node
{
    int elem; // элемент
    int pow;  // степень
    node_t *next;
};


#endif
