#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(void)
{
    setbuf(stdout, NULL);

    node_t *head = NULL, *tail = NULL;
    int num = 0, rc = 0;

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

        tail = node; // запомнить хвост
        head = push_back(head, node);
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
        free_list(head);
        return EXIT_FAILURE;
    }

    node_t *new_head = reverse(head, tail);

    print_list(new_head);
    free_list(new_head);
    
    return EXIT_SUCCESS;
}
