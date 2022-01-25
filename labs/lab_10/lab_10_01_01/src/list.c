#include "list.h"

// создание узла
node_t *create_node(const int number, const double weight)
{
    package_r *pack;
    node_t *new_node;

    if ((pack = malloc(sizeof (package_r))) == NULL)
        return NULL;

    if ((new_node = malloc(sizeof (node_t))) == NULL)
    {
        free(pack);
        return NULL;
    }

    pack->number = number;
    pack->weight = weight;

    new_node->data = (void *)pack;
    new_node->next = NULL;

    return new_node;
}

// считать один узел из файла
node_t *read_node(FILE *f)
{
    node_t *node;
    int number;
    double weight;

    if (fscanf(f, "%d%lf", &number, &weight) != 2)
        return NULL;

    node = create_node(number, weight);

    return node;
}

// считать данные из файла в список
node_t *create_list(FILE *f)
{
    node_t *head = NULL, *node = NULL;
    int number = 0;
    double weight = 0.0;

    while (fscanf(f, "%d%lf", &number, &weight) == 2)
    {
        node = create_node(number, weight);
        head = push(head, node);
    }

    return head;
}

// добавить элемент в список
node_t *push(node_t *head, node_t *new_node)
{
    node_t *cur = head;

    if (!head)
        return new_node;

    while (cur->next)
        cur = cur->next;

    cur->next = new_node;
    return head;
}

// освобождение списка
void free_list(node_t **list)
{
    while (*list)
    {
        node_t *cur = (*list)->next;
        free((*list)->data);
        free(*list);
        (*list) = cur;
    }
}

// печать в файл
void print_list(FILE *f, node_t *list)
{
    rewind(f);
    node_t *cur = list;

    while (cur)
    {
        fprintf(f, "%d\n%lf\n", ((package_r *)(cur->data))->number, ((package_r *)(cur->data))->weight);
        cur = cur->next;
    }
}

