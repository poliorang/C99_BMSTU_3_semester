#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errors_structures.h"


node_t *create_node(const int number, const double weight);
node_t *read_node(FILE *f);
node_t *create_list(FILE *f);
node_t *push(node_t *head, node_t *new_node);
void free_list(node_t **list);
void print_list(FILE *f, node_t *list);


#endif
