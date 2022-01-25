#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(void)
{
    setbuf(stdout, NULL);
    int count;
    if (scanf("%d", &count) != 1 || count <= 0)
    {
        printf("ERROR: 1");
        return EXIT_FAILURE;
    }

    int *arr = NULL;
    if ((arr = create_array(count)) == NULL)
        return EXIT_FAILURE;

    if (initialize_array(count, arr))
    {
        free(arr);
        return EXIT_FAILURE;
    }

    find_and_replace_min(count, arr);
    print_array(count, arr);

    free(arr);
    return EXIT_SUCCESS;
}
