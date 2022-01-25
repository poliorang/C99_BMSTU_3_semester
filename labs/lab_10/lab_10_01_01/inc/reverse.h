#ifndef REVERSE_H
#define REVERSE_H

#include <stdio.h>
#include <stdlib.h>
#include "errors_structures.h"
#include "list.h"

node_t *reverse(node_t *head);
node_t *rev(node_t *head, node_t *new_list);

#endif
