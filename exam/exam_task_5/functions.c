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

node_t *push_back(node_t *head, node_t *node)
{
    if (!head)
        return node;

    node_t *cur = head;
    while (cur->next)
        cur = cur->next;

    cur->next = node;

    return head;
}

node_t *fill_queue(node_t *queue, int num)
{
    while (num)
    {
        node_t *node = create_node(num % 10);
        if (!node)
            return NULL;

        queue = push_back(queue, node);
        num /= 10;
    }

    return queue;
}

void print_list(node_t *head)
{
    node_t *node = head;
    while (node)
    {
        printf("%d", node->data);
        node = node->next;
    }
}

void free_list(node_t *head)
{
    node_t *next = NULL;
    for (node_t *cur = head; cur; cur = next)
    {
        next = cur->next;
        free(cur);
    }
}
