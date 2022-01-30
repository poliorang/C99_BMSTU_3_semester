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

int count_nodes(node_t *head)
{
    int count = 0;
    node_t *node = head;
    while (node)
    {
        count++;
        node = node->next;
    }

    return count;
}

node_t *reverse(node_t *head, node_t *tail)
{
    int count = count_nodes(head);
    node_t *new_head = tail;
    node_t *new = new_head;

    for (int i = 0; i < count; i++)
    {
        node_t *cur = head;
        for (int j = 0; j < count - i - 1; j++)
            cur = cur->next;
        new_head->next = cur;
        new_head = new_head->next;
        new_head->next = NULL;
    }

    return new;
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

void print_list(node_t *head)
{
    node_t *node = head;
    while (node)
    {
        printf("%d ", node->data);
        node = node->next;
    }
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
