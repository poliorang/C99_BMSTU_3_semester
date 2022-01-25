#include "sort.h"

int comparator_packs(const void *p, const void *q)
{
    package_r *pack_one = (package_r *)p;
    package_r *pack_two = (package_r *)q;

    if ((pack_one->weight - pack_two->weight) < 0)
        return -1;

    if ((pack_one->weight - pack_two->weight) > 0)
        return 1;

    return 0;
}

void front_back_split(node_t *head, node_t **back)
{
    if (head && back)
    {
        node_t *current = head;

        while (head->next && head->next->next)
        {
            current = current->next;
            head = head->next->next;
        }

        *back = current->next;
        current->next = NULL;
    }
}

node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    if (!comparator || !head || !head->next)
        return head;

    node_t *sortrd_one = NULL, *sorted_two = NULL;
    node_t *back = NULL, *new_head = NULL;

    front_back_split(head, &back);
    sortrd_one = sort(head, comparator);
    sorted_two = sort(back, comparator);

    new_head = sorted_merge(&sortrd_one, &sorted_two, comparator);

    return new_head;
}

node_t *sorted_merge(node_t **head_a, node_t **head_b, int (*comparator)(const void *, const void *))
{
    if (!head_a || !head_b || comparator == NULL)
        return NULL;

    node_t *head = NULL, *buf = NULL;

    if ((*head_a) || (*head_b))
    {
        if (!(*head_b) || (*head_a && comparator((*head_a)->data, (*head_b)->data) < 0))
        {
            head = *head_a;
            buf = head;
            *head_a = (*head_a)->next;
        }
        else if (*head_b)
        {
            head = *head_b;
            buf = head;
            *head_b = (*head_b)->next;
        }
    }

    while (*head_a && *head_b)
    {
        if (comparator((*head_a)->data, (*head_b)->data) < 0)
        {
            buf->next = (*head_a);
            buf = buf->next;
            (*head_a) = (*head_a)->next;
        }
        else
        {
            buf->next = (*head_b);
            buf = buf->next;
            (*head_b) = (*head_b)->next;
        }
    }

    while (*head_a)
    {
        buf->next = (*head_a);
        buf = buf->next;
        (*head_a) = (*head_a)->next;
    }

    while (*head_b)
    {
        buf->next = (*head_b);
        buf = buf->next;
        (*head_b) = (*head_b)->next;
    }

    buf = NULL;
    *head_a = NULL;
    *head_b = NULL;

    return head;
}
