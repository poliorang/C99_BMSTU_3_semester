#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errors_structures.h"

#define COUNT_COMMAND 4

node_t *create_list(int num);
node_t *create_node(const int elem, const int pow);
node_t *push(node_t *head, node_t *new_node);
void print_list(node_t *list);
void free_list(node_t *list);
void output(node_t *list);

int check_command(char command[MAX_LEN_COMMAND]);

#endif
