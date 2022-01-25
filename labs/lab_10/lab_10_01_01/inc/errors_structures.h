#ifndef ERR_STRUCT_H
#define ERR_STRUCT_H

#define EPS 1e-8

#define ARG_ONE 1
#define ARG_TWO 2
#define ARG_THREE 3
#define ARG_FOUR 4
#define ARG_FIVE 5

#define ARG_ERR 1
#define FILE_ERR 2
#define CREATE_LIST_ERR 3
#define INSERT_ERR 4


typedef struct node node_t;
struct node
{
    void *data;
    node_t *next;
};

typedef struct
{
    int number;
    double weight;
} package_r;


#endif
