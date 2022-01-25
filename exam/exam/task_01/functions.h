#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;
struct node
{
    int data;
    node_t *next;
};

node_t *create_node(int num);

node_t *push_front(node_t *head, node_t *node);

node_t *connect_lists(node_t *pos, node_t *neg);

void print_list(node_t *head);

void free_list(node_t *head);

#endif
