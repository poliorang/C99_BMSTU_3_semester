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

int find_max(node_t *head);

node_t *pop_max_elems(node_t *head, int max_num);

void print_list(node_t *head);

void free_list(node_t *head);

#endif
