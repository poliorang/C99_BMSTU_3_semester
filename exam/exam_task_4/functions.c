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

int find_max(node_t *head)
{
    int max_num = head->data;
    node_t *node = head->next;

    while (node)
    {
        if (node->data > max_num)
            max_num = node->data;

        node = node->next;
    }

    return max_num;
}

node_t *pop_max_elems(node_t *head, int max_num)
{
    while (head->data == max_num)
    {
        node_t *node = head;
        head = head->next;
        free(node);
    }

    node_t *tmp = head;
    while (tmp->next)
    {
        printf("%d\n", tmp->data);
        if (tmp->next->data == max_num)
        {
            node_t *node = tmp->next;
            tmp->next = tmp->next->next;
            free(node);
            continue;
        }
        tmp = tmp->next;
    }

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
