#include "matrix.h"

int **allocate_matrix(int n, int m)
{
    int32_t **data = calloc((size_t)n, sizeof(int));
    if (!data)
        return NULL;
    for (int i = 0; i < n; i++)
    {
        data[i] = calloc((size_t)m, sizeof (int));
        if (!data[i])
        {
            free_matrix(data, n);
            return NULL;
        }
    }
    return data;
}

void free_matrix(int32_t **data, int n)
{
    for (int i = 0; i < n; i++)
        free(data[i]);

    free(data);
}
