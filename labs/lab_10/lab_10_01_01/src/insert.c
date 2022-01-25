#include "insert.h"

// вставить в список элемент до указанного
void insert(node_t **head, node_t *elem, node_t *before)
{
    node_t *list = *head;
    node_t *buf = NULL;
    elem->next = NULL;
    before->next = NULL;

    if (((package_r *)((*head)->data))->number == ((package_r *)(before->data))->number &&
        (((package_r *)((*head)->data))->weight - ((package_r *)(before->data))->weight) < EPS)
    {
        buf = (*head)->next;
        elem->next = before;
        *head = elem;
        before->next = buf;
        return;
    }

    while ((*head)->next != NULL)
    {
        if (((package_r *)((*head)->next->data))->number == ((package_r *)(before->data))->number &&
            (((package_r *)((*head)->next->data))->weight - ((package_r *)(before->data))->weight) < EPS)
        {
            buf = (*head)->next->next;
            elem->next = before;
            (*head)->next = elem;
            before->next = buf;
            (*head) = list;
            return;
        }
        (*head) = (*head)->next;
    }
    (*head) = list;
    free_list(head);
}

// вставить элементы из файла в список (перед указанными)
void insert_from_file(FILE *f, node_t **head)
{
    node_t *element, *next_element;
    while (!feof(f))
    {
        element = NULL;
        next_element = NULL;
        if ((element = read_node(f)) == NULL || (next_element = read_node(f)) == NULL)
        {
            free_list(&element);
            free_list(&next_element);
            break;
        }
        insert(head, element, next_element);
        if (*head == NULL)
        {
            free_list(&element);
            free_list(&next_element);
            free_list(head);
            return;
        }
    }
}

