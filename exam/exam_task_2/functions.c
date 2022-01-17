#include "functions.h"

node_t *create_node(char *line)
{
    node_t *node = malloc(sizeof(node_t));
    if (!node)
        return NULL;

    node->word = line;
    node->next = NULL;

    return node;
}

int read_node(char *line, node_t **list)
{
    int read;
    size_t len;

    read = getline(&line, &len, stdin);

    if (read != -1 && read < 81)
    {
        line[strlen(line) - 1] = '\0';

        if (strcmp(line, "The end") == 0)
        {
            printf("Empty list\n");
            free(line);
            return 3;
        }

        node_t *node = create_node(line);

        if (node != NULL)
            *list = push_front(*list, node);
        else
            return EXIT_FAILURE;
    }
    else
    {
        free(line);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

node_t *push_front(node_t *list, node_t *node)
{
    if (!list)
        return node;

    node->next = list;

    return node;
}

void print_list(node_t *list)
{
    node_t *tmp = list;
    while (tmp != NULL)
    {
        printf("'%s' ", tmp->word);
        tmp = tmp->next;
    }
}

void free_list(node_t *list)
{
    while (list != NULL)
    {
        node_t *tmp = list->next;
        free(list->word);
        free(list);
        list = tmp;
    }
}
