#include "functions.h"

node_t *create_node(int num)
{
    node_t *node = NULL;
    node = malloc(sizeof(node_t));
    if (node == NULL)
        return NULL;

    node->data = num;
    node->next = NULL;

    return node;
}

node_t *push_front(node_t *head, node_t *node)
{
    if (!head)
        return node;

    node->next = head;

    return node;
}

void print_list(node_t *head)
{
    node_t *node = head;
    while (node)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

node_t *connect_lists(node_t *pos, node_t *neg)
{
    if (pos == NULL)
        return neg;

    node_t *node = pos;
    while (node->next)
        node = node->next;

    node->next = neg;

    return pos;
}

void free_list(node_t *head)
{
    node_t *next = head;
    for (node_t *cur = head; cur; cur = next)
    {
        next = cur->next;
        free(cur);
    }
}
