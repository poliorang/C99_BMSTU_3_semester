#include "reverse.h"

node_t *reverse(node_t *head)
{
    node_t *list = NULL;

    for (node_t *node = head, *next_node; node != NULL; node = next_node)
    {
        next_node = node->next;
        node->next = list;
        list = node;
    }

    return list;
}
