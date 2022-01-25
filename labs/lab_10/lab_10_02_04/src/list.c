#include "list.h"

// выделение памяти под список и запись данных
node_t *create_list(int num)
{
    // 20 первых простых чисел
    int prime_num[20] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71 };

    int i = 0, count = 0;
    node_t *list = NULL, *new_node = NULL;

    while (num != 1)
    {
        if (num % prime_num[i] == 0)
        {
            count++;
            num /= prime_num[i];
        }
        else
        {
            if (count != 0)
            {
                if ((new_node = create_node(prime_num[i], count)) == NULL)
                {
                    free_list(list);
                    return NULL;
                }
                list = push(list, new_node);
            }

            i++;
            count = 0;
        }
    }

    if (count != 0)
    {
        if ((new_node = create_node(prime_num[i], count)) == NULL)
        {
            free_list(list);
            return NULL;
        }
        list = push(list, new_node);
    }

    return list;
}

// создание узла списка
node_t *create_node(const int elem, const int pow)
{
    node_t *new_node = malloc(sizeof(node_t));

    if (new_node)
    {
        new_node->elem = elem;
        new_node->pow = pow;
        new_node->next = NULL;
    }

    return new_node;
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

// вывод списка с конца + 1
void output(node_t *list)
{
    print_list(list);
    printf("1");
}

// печать элементов списка с конца
void print_list(node_t *list)
{
    node_t *cur = list;

    if (cur)
    {
        print_list(cur->next);
        printf("%d %d ", cur->elem, cur->pow);
    }
}

// освободить память из под списка
void free_list(node_t *list)
{
    node_t *cur = list, *next;

    while (cur)
    {
        next = cur->next;
        free(cur);
        cur = next;
    }
}

// проверка, что заданная команда существует
int check_command(char command[MAX_LEN_COMMAND])
{
    char *lines[COUNT_COMMAND] = { "out", "mul", "sqr", "div" };

    for (int i = 0; i < COUNT_COMMAND; i++)
    {
        if (!strcmp(command, lines[i]))
            return EXIT_SUCCESS;
    }

    return INPUT_ERR;
}

