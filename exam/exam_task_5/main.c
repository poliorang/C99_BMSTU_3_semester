#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(void)
{
    setbuf(stdout, NULL);

    node_t *queue = NULL;
    int num = 0;

     if (scanf("%d", &num) != 1 || num <= 0)
     {
         printf("ERROR: 1");
         return EXIT_FAILURE;
     }

     queue = fill_queue(queue, num);
     if (queue == NULL)
     {
         printf("ERROR: 2");
         free(queue);
         return EXIT_FAILURE;
     }

    print_list(queue);
    free_list(queue);

    return EXIT_SUCCESS;
}
