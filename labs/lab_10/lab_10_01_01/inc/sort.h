#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "errors_structures.h"
#include "sort.h"

void front_back_split(node_t *head, node_t **back);
node_t *sorted_merge(node_t **head_a, node_t **head_b, int (*comparator)(const void *, const void *));
node_t *sort(node_t *head, int (*comparator)(const void *, const void *));
int comparator_packs(const void *p, const void *q);

#endif
