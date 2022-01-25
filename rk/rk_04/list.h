#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errors_structures.h"

node_t *create_list(FILE *f);
node_t *create_node(char *line);
node_t *push(node_t *head, node_t *new_node);
void free_list(node_t *head);

node_t *reverse_words(node_t *head);
node_t *reverse_list(node_t *head);
void print_list(node_t *head, FILE *f);

#endif
