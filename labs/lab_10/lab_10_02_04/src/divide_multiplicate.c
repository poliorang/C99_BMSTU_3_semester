#include "divide_multiplicate.h"

// перемещение узлов из одного списка в другой
node_t *move_nodes(node_t *multi, node_t *list)
{
    node_t *new_node = NULL;
    while (list)
    {
        if ((new_node = create_node(list->elem, list->pow)) == NULL)
        {
            free_list(multi);
            return NULL;
        }
        multi = push(multi, new_node);
        list = list->next;
    }

    return multi;
}

// умножение двух чисел (списков)
node_t *multiplicate(node_t *list_one, node_t *list_two)
{
    node_t *multi = NULL, *new_node = NULL;
    node_t *one = list_one, *two = list_two;
    int elem = 0, pow = 0;

    while (one && two)
    {
        if (one->elem < two->elem)
        {
            elem = one->elem;
            pow = one->pow;
            one = one->next;
        }
        else if (one->elem > two->elem)
        {
            elem = two->elem;
            pow = two->pow;
            two = two->next;
        }
        else if (one->elem == two->elem)
        {
            elem = one->elem;
            pow = one->pow + two->pow;
            one = one->next;
            two = two->next;
        }

        if ((new_node = create_node(elem, pow)) == NULL)
        {
            free_list(multi);
            return NULL;
        }
        multi = push(multi, new_node);
    }

    // добавление оставшихся в списках элементов
    if ((multi = move_nodes(multi, one)) == NULL)
    {
        free_list(multi);
        return NULL;
    }
    if ((multi = move_nodes(multi, two)) == NULL)
    {
        free_list(multi);
        return NULL;
    }

    return multi;
}

// количество узлов в списке
int count_factors(node_t *list)
{
    node_t *one = list;
    int count = 0;
    while (one)
    {
        count++;
        one = one->next;
    }

    return count;
}

// проверка, делятся ли без остатка два числа
node_t *divide_without_remainder(node_t *list_one, node_t *list_two)
{
    node_t *division = NULL, *new_node = NULL;
    node_t *one = list_one, *two = list_two;
    if (count_factors(one) < count_factors(two))
    {
        one = list_two;
        two = list_two;
    }

    while (one && two)
    {
        if (one->elem == two->elem)
        {
            if (one->pow == two->pow)
                two = two->next;
            else if (one->pow > two->pow)
            {
                if ((new_node = create_node(one->elem, one->pow - two->pow)) == NULL)
                {
                    free_list(division);
                    return NULL;
                }

                division = push(division, new_node);
                two = two->next;
            }
            else if (one->pow < two->pow)
            {
                free_list(division);
                return NULL;
            }
        }
        else
        {
            if ((new_node = create_node(one->elem, one->pow)) == NULL)
            {
                free_list(division);
                return NULL;
            }

            division = push(division, new_node);
        }
        one = one->next;
    }

    if (two)
    {
        free_list(division);
        return NULL;
    }

    // добавление оставшихся в списке элементов
    if ((division = move_nodes(division, one)) == NULL)
    {
        free_list(division);
        return NULL;
    }

    return division;
}
