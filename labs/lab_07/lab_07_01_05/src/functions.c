#include "../inc/functions.h"

void pack_array(FILE *f, int *arr, const int *arr_end)
{
    while (arr < arr_end)
    {
        fscanf(f, "%d", arr);
        arr++;
    }
}

int create_arr(FILE *f, int **arr, int **arr_end, size_t *n)
{
    size_t count = 0;
    int number;
    while (fscanf(f, "%d", &number) == 1)
        count++;

    if (count == 0)
        return ERR_COUNT;

    *n = count;

    *arr = calloc((size_t)count, sizeof (int));
    *arr_end = *arr + count;

    rewind(f);
    pack_array(f, *arr, *arr_end);

    return EXIT_SUCCESS;
}

void print_array(FILE *f, const int *arr, const int *arr_end)
{
    for (const int *i = arr; i < arr_end; ++i)
        fprintf(f, "%d ", *i);
}

