#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "errors_structures.h"

node_t *multiplicate(node_t *list_one, node_t *list_two);
node_t *move_nodes(node_t *multi, node_t *list);
int count_factors(node_t *list);
node_t *divide_without_remainder(node_t *list_one, node_t *list_two);

#endif
