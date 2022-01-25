#include "../inc/objects.h"
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc != ARG_THREE && argc != ARG_TWO)
        return ARG_ERR;

    FILE *f = fopen(argv[1], "r");

    if (f == NULL)
        return FILE_ERR;

    size_t count = 0;
    if (count_structures(f, &count))
    {
        fclose(f);
        return ERR_COUNT;
    }

    obj_t *arr = malloc(count * sizeof (obj_t));
    if (arr == NULL)
    {
        fclose(f);
        return ALLOCATE_ERR;
    }

    rewind(f);
    if (read_from_file(arr, f, count))
        return ERR_STRUCT;

    if (argc == ARG_TWO)
    {
        insertion_sort(arr, count);
        print_structures(arr, count);
    }

    if (argc == ARG_THREE)
    {
        if (!strcmp(argv[ARG_TWO], "ALL"))
            print_structures(arr, count);
        else
        {
            size_t n = 0;
            for (size_t i = 0; i < count; i++)
                if (!strncmp(argv[ARG_TWO], arr[i].name, strlen(argv[ARG_TWO])))
                {
                    n++;
                    print_structure(arr[i]);
                }
            if (n == 0)
            {
                clean_up(f, arr, count);
                return ERR_KEY;
            }
        }
    }

    clean_up(f, arr, count);

    return EXIT_SUCCESS;
}
