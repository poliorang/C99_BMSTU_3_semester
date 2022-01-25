#include "../inc/key.h"

// pb_src - указатель на начало массива входящего
// pe_src - указатель на конец массива входящего
// pb_dst - указатель на начало массива выходящего
// pe_dst - указатель на конец массива выходящего

int count_elems_in_arr(const int *arr, const int *arr_end)
{
    int sum = 0, count = 0;
    for (const int *i = arr; i != arr_end - 1; ++i)
    {
        for (const int *j = i + 1; j != arr_end; ++j)
            sum += *j;

        if (*i > sum)
            count++;

        sum = 0;
    }

    return count;
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    if (!pb_src || !pe_src)
        return PARAMS_ERROR;

    if (pb_src + 1 == pe_src || pb_src == pe_src)
        return PARAMS_ERROR;

    if (pe_src < pb_src)
        return PARAMS_ERROR;

    int count = count_elems_in_arr(pb_src, pe_src);
    if (count == 0)
        return EMPTY_ARRAY_ERROR;

    *pb_dst = calloc((size_t)count, sizeof(int));
    *pe_dst = *pb_dst + count;

    int sum = 0, index = 0;

    for (const int *i = pb_src; i != pe_src - 1; ++i)
    {
        for (const int *j = i + 1; j != pe_src; ++j)
            sum += *j;

        if (*i > sum)
            *(*pb_dst + index++) = *i;

        sum = 0;
    }

    return OK;
}

