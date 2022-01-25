#ifndef INSERT_H
#define INSERT_H

#include <stdio.h>
#include <stdlib.h>
#include "errors_structures.h"
#include "list.h"

void insert(node_t **list, node_t *elem, node_t *before);
void insert_from_file(FILE *f, node_t **head);

#endif
