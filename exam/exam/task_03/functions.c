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

node_t *find_count_min(node_t *head, int *min_num)
{
    if (!head)
        return NULL;

    *min_num = head->data;
    int count = 1;
    node_t *node = head->next;

    while (node)
    {
        if (node->data < *min_num)
        {
            *min_num = node->data;
            count = 1;
        }
        else if (node->data == *min_num)
            count++;

        node = node->next;
    }

    node_t *new_node = create_node(count);

    return new_node;
}

node_t *add_count(node_t *head, node_t *node, int min_num)
{
    node_t *tmp = head;
    while(tmp)
    {
        if (tmp->data == min_num)
        {
            node->next = tmp->next;
            tmp->next = node;
            break;
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
