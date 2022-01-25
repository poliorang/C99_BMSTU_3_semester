#ifndef OBJECTS_H
#define OBJECTS_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LEN 25

typedef struct
{
    char name[MAX_NAME_LEN];
    double weight;
    double volume;
} obj_t;

void insertion_sort(obj_t a[], const size_t n);
void print_struct(const obj_t obj);
void print_from_loop(const obj_t a[], const size_t n);

#endif
