// надеюсь, этот дефайн выглядит так
#define _POSIX_C_SOURCE 200809L
#include "list.h"

node_t *create_list(FILE *f)
{
    node_t *list = NULL;
    while (!feof(f))
    {

        size_t len = 0;
        node_t *new_node = NULL;
        char *line = NULL;

        ssize_t line_get = getdelim(&line, &len, '\n', f);

        if (line_get == -1)
            return list;
        line[line_get - 1] = '\0';
        new_node = create_node(line);
        list = push(list, new_node);
    }

    return list;
}

node_t *create_node(char *line)
{
    node_t *new_node = malloc(sizeof(node_t));

    if (new_node)
        new_node->line = line;

    return new_node;
}

node_t *push(node_t *head, node_t *new_node)
{
    node_t *current = head;

    if (!head)
        return new_node;

    while (current->next)
        current = current->next;

    current->next = new_node;
    return head;
}

void free_list(node_t *head)
{
    node_t *current = head, *next;

    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

node_t *reverse_words(node_t *head)
{
    node_t *list = head;
    while (list)
    {
        int len = strlen(list->line);
        for (int i = 0; i < len / 2; i++)
        {
            char buf = list->line[len - i - 1];
            list->line[len - i - 1] = list->line[i];
            list->line[i] = buf;
        }
        list = list->next;
    }

    return head;
}

node_t *reverse_list(node_t *head)
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

void print_list(node_t *head, FILE *f)
{
    node_t *current = head;
    while (current)
    {
        fprintf(f, "%s", current->line);
        current = current->next;
    }
}
