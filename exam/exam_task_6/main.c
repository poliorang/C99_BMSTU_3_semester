#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(void)
{
    setbuf(stdout, NULL);

    node_t *head = NULL;
    int num = 0;

    if ((scanf("%d", &num) != 1 || num < 0))
    {
        printf("ERROR: 1");
        return EXIT_FAILURE;
    }

    head = fill_list(head, num);
    if (head == NULL)
    {
        printf("ERROR: 2");
        free_list(head);
        return EXIT_FAILURE;
    }

    int min_num = find_min(head);

    node_t *new_head = new_head_and_tail(head, min_num);

    print_list(new_head);
    free_list(new_head);
    
    return EXIT_SUCCESS;
}
