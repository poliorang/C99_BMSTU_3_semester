#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node node_t;
struct node
{
    char *word;
    node_t *next;
};
node_t *create_node(char *line);

int read_node(char *line, node_t **list);

node_t *push_front(node_t *list, node_t *node);

void print_list(node_t *list);

void free_list(node_t *list);

#endif
