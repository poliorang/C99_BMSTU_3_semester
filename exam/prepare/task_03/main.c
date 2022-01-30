#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

// 1 2 3 4 99 5 6 7

int main(void)
{
    setbuf(stdout, NULL);

    node_t *head = NULL, *head2 = NULL, *tail = NULL;
    int num = 0, rc = 0, max = -1, flag = 0;

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

        if (flag) {
            head2 = node;
            flag = 0;
        }

        if (num > max)
        {
            max = num;
            tail = node; // запомнить хвост
            flag = 1;
        }

        head = push_back(head, node);
    }

    tail->next = NULL;

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

    head = reverse(head, tail);
    head = connect_lists(head, head2);

    print_list(head);
    free_list(head);
    
    return EXIT_SUCCESS;
}
