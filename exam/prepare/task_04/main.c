#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

// 1 2 3 4 99 5 6 7

int main(void)
{
    setbuf(stdout, NULL);

    node_t *head1 = NULL, *head2 = NULL;
    int num = 0, rc = 0;

    while ((rc = scanf("%d", &num)) == 1 && num != 0)
    {
        node_t *node = NULL;
        node = create_node(num);
        if (!node)
        {
            printf("ERROR: 2");
            free_list(head1);
            return EXIT_FAILURE;
        }

        head1 = push_back(head1, node);
    }

    while ((rc = scanf("%d", &num)) == 1 && num != 0)
    {
        node_t *node = NULL;
        node = create_node(num);
        if (!node)
        {
            printf("ERROR: 2");
            free_list(head2);
            return EXIT_FAILURE;
        }

        head2 = push_back(head2, node);
    }



    head1 = connect_lists(head1, head2);

    print_list(head1);
    free_list(head1);
    
    return EXIT_SUCCESS;
}
