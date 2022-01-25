#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(void)
{
    setbuf(stdout, NULL);

    node_t *head = NULL;
    int num = 0, rc;

    while ((rc = scanf("%d", &num)) == 1 && num != 0)
    {
        node_t *node = NULL;
        node = create_node(num);
        if (!node)
        {
            printf("ERROR: 2");
            free_list(head);
            return EXIT_FAILURE;
        }

        head = push_front(head, node);
    }

    if (rc != 1)
    {
        printf("ERROR: 1");
        free_list(head);
        return EXIT_FAILURE;
    }

    if (head == NULL)
    {
        printf("ERROR: 3");
        return EXIT_FAILURE;
    }

    int max_num = find_max(head);
    head = pop_max_elems(head, max_num);

    print_list(head);
    free_list(head);

    return EXIT_SUCCESS;
}
