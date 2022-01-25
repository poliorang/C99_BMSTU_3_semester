#include "functions.h"

int *create_array(int n)
{
    int *arr = calloc(n, sizeof(int));
    if (arr == NULL)
    {
        printf("ERROR: 2");
        return NULL;
    }

    return arr;
}

int initialize_array(int n, int *arr)
{
    int elem = 0;

    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &elem) != 1)
        {
            printf("ERROR: 1");
            return EXIT_FAILURE;
        }

        arr[i] = elem;
    }

    return EXIT_SUCCESS;
}

void find_and_replace_min(int n, int *arr)
{
    int min = arr[n - 1];
    int index = n - 1;

    for (int i = n - 2; i >= 0; i--)
        if (arr[i] <= min)
        {
            min = arr[i];
            index = i;
        }

    int tmp = arr[0];
    arr[0] = arr[index];
    arr[index] = tmp;
}

void print_array(int n, int *arr)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
