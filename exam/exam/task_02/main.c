#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(void)
{
    node_t *list = NULL;

    char *line = NULL;
    int rc = read_node(line, &list);
    while (rc == 0)
        rc = read_node(line, &list);

    print_list(list);

    free_list(list);

    return EXIT_SUCCESS;
}
