#ifndef OBJECTS_H
#define OBJECTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARG_ERR 1
#define FILE_ERR 2
#define EMPTY_FILE 3
#define ERR_COUNT 4
#define ERR_LONG_WORD 5
#define ERR_PARAM 6
#define ERR_KEY 7
#define ERR_STRUCT 8
#define ALLOCATE_ERR 9

#define MAX_NAME_LEN 25

#define ARG_TWO 2
#define ARG_THREE 3
#define COUNT_ELEM 3


typedef struct
{
    char *name;
    double weight;
    double volume;
} obj_t;

void insertion_sort(obj_t *a, const size_t n);
void print_structure(const obj_t obj);
void print_structures(const obj_t *a, const size_t n);
int count_structures(FILE *f, size_t *count);
void clear_string_fields(obj_t *arr, const size_t count);
void clean_up(FILE *f, obj_t *arr, const size_t count);
int read_from_file(obj_t *arr, FILE *f, const size_t count);
void free_string_fields(obj_t *arr, const size_t count);

#endif
