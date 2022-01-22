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

node_t *fill_list(node_t *list, int num)
{
    while (num)
    {
        node_t *node = create_node(num % 10);
        if (!node)
            return NULL;

        list = push_front(list, node);
        num /= 10;
    }

    return list;
}

int find_min(node_t *head)
{
    int min_num = head->data;
    node_t *cur = head->next;

    while (cur)
    {
        if (cur->data < min_num)
            min_num = cur->data;

        cur = cur->next;
    }

    return min_num;
}

node_t *new_head_and_tail(node_t *list, int min_num)
{
    node_t *head = list;
    node_t *cur = list;
    while (cur)
    {
        if (cur->data == min_num)
            break;

        cur = cur->next;
    }

    node_t *new_head = cur->next;
    cur->next = NULL;

    node_t *new_list = new_head;
    while (new_list->next)
        new_list = new_list->next;

    new_list->next = head;

    return new_head;
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
    node_t *next = head;
    for (node_t *cur = head; cur; cur = next)
    {
        next = cur->next;
        free(cur);
    }
}
