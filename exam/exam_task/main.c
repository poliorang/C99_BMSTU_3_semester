#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(void)
{
    setbuf(stdout, NULL);

    node_t *pos = NULL, *neg = NULL;
    int num = 0, rc = 0;

    while ((rc = scanf("%d", &num)) == 1 && num != 0)
    {
        node_t *node = NULL;
        node = create_node(num);
        if (!node)
        {
            printf("ERROR: 2");
            free_list(pos);
            free_list(neg);
            return EXIT_FAILURE;
        }

        if (num < 0)
            neg = push_front(neg, node);
        if (num > 0)
            pos = push_front(pos, node);
    }

    if (rc != 1)
    {
        printf("ERROR: 1");
        free_list(pos);
        free_list(neg);
        return EXIT_FAILURE;
    }

    pos = connect_lists(pos, neg);
    if (pos == NULL)
    {
        printf("ERROR: 3");
        free_list(pos);
        return EXIT_FAILURE;
    }

    print_list(pos);

    return EXIT_SUCCESS;
}
