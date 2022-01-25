#ifndef ERR_H
#define ERR_H

typedef struct node node_t;

struct node
{
    char *line;
    node_t *next;
};

#endif
