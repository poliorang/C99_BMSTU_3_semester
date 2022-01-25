#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

void swap(void *p1, void *p2, size_t size);
void mysort(void *base, size_t nmemb, size_t size, int (*compar)(const void*, const void*));
int compare_int(const void *p, const void *q);

#endif

