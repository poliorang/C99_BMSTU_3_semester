#include "errors_structures.h"
#include "list.h"
#include "divide_multiplicate.h"

int main(void)
{
    char command[MAX_LEN_COMMAND];
    if (scanf("%s", command) != 1)
        return SCNF_ERR;

    if (check_command(command))
        return INPUT_ERR;
    
    node_t *list_one = NULL, *list_two = NULL;
    node_t *result = NULL;
    int num_one = 0, num_two = 0;

    // вывод
    if (!strcmp(command, "out"))
    {
        if (scanf("%d", &num_one) != 1 || num_one <= 0)
            return INPUT_ERR;

        if ((result = create_list(num_one)) == NULL)
        {
            free_list(result);
            return ALLOCATE_ERR;
        }
    }

    // умножение
    if (!strcmp(command, "mul"))
    {
        if (scanf("%d%d", &num_one, &num_two) != 2 || num_one <= 0 || num_two <= 0)
            return INPUT_ERR;

        if ((list_one = create_list(num_one)) == NULL)
        {
            free_list(list_one);
            return ALLOCATE_ERR;
        }
        if ((list_two = create_list(num_two)) == NULL)
        {
            free_list(list_one);
            free_list(list_two);
            return ALLOCATE_ERR;
        }

        if ((result = multiplicate(list_one, list_two)) == NULL)
        {
            free_list(list_one);
            free_list(list_two);
            free_list(result);
            return MULTIPLICATE_ERR;
        }
        free_list(list_one);
        free_list(list_two);
    }

    // возведение в квадрат
    if (!strcmp(command, "sqr"))
    {
        if (scanf("%d", &num_one) != 1 || num_one <= 0)
            return INPUT_ERR;

        if ((list_one = create_list(num_one)) == NULL)
        {
            free_list(list_one);
            return ALLOCATE_ERR;
        }
        if ((list_two = create_list(num_one)) == NULL)
        {
            free_list(list_one);
            free_list(list_two);
            return ALLOCATE_ERR;
        }

        if ((result = multiplicate(list_one, list_two)) == NULL)
        {
            free_list(list_one);
            free_list(list_two);
            free_list(result);
            return SQUARE_ERR;
        }
        free_list(list_one);
        free_list(list_two);
    }

    // деление без остатка
    if (!strcmp(command, "div"))
    {
        if (scanf("%d%d", &num_one, &num_two) != 2 || num_one <= 0 || num_two <= 0)
            return INPUT_ERR;

        if ((list_one = create_list(num_one)) == NULL)
        {
            free_list(list_one);
            return ALLOCATE_ERR;
        }
        if ((list_two = create_list(num_two)) == NULL)
        {
            free_list(list_one);
            free_list(list_two);
            return ALLOCATE_ERR;
        }

        if ((result = divide_without_remainder(list_one, list_two)) == NULL)
        {
            free_list(list_one);
            free_list(list_two);
            free_list(result);
            return DIVIDE_ERR;
        }

        free_list(list_one);
        free_list(list_two);
    }

    output(result);
    free_list(result);

    return EXIT_SUCCESS;
}
