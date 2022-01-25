#include "objects.h"
#include <string.h>
#include <ctype.h>

#define ARG_ERR 1
#define FILE_ERR 2
#define EMPTY_FILE 3
#define ERR_COUNT 4
#define ERR_LONG_WORD 5
#define ERR_PARAM 6
#define ERR_KEY 7
#define ERR_STRUCT 8

#define MAX_SIZE 15

#define ARG_TWO 2
#define ARG_THREE 3
#define COUNT_ELEM 3

int main(int argc, char *argv[])
{
    obj_t arr[MAX_SIZE];
    obj_t obj = { .name = "0", .weight = 0, .volume = 0 };

    size_t count = 0;

    if (argc != ARG_THREE && argc != ARG_TWO)
        return ARG_ERR;

    FILE *f = fopen(argv[1], "r");

    if (f == NULL)
        return FILE_ERR;

    while (!feof(f))
    {
        if (fscanf(f, "%s %lf %lf\n", obj.name, &obj.weight, &obj.volume) != ARG_THREE)
        {
            fclose(f);
            return ERR_PARAM;
        }

        if (strlen(obj.name) == 0)
            break;

        if (strlen(obj.name) >= MAX_NAME_LEN)
        {
            fclose(f);
            return ERR_LONG_WORD;
        }

        if (obj.volume <= 0 || obj.weight <= 0)
        {
            fclose(f);
            return ERR_PARAM;
        }

        arr[count++] = obj;
        if (count >= MAX_SIZE)
        {
            fclose(f);
            return ERR_COUNT;
        }
    }

    fclose(f);

    if (count == 0)
        return EMPTY_FILE;

    //1
    if (argc == ARG_TWO)
    {
        insertion_sort(arr, count);
        print_from_loop(arr, count);
    }

    //2
    if (argc == ARG_THREE)
    {
        if (!strcmp(argv[ARG_TWO], "ALL"))
            print_from_loop(arr, count);
        else
        {
            size_t n = 0;
            for (size_t i = 0; i < count; i++)
                if (!strncmp(argv[ARG_TWO], arr[i].name, strlen(argv[ARG_TWO])))
                {
                    n++;
                    print_struct(arr[i]);
                }
            if (n == 0)
                return ERR_KEY;
        }
    }

    return EXIT_SUCCESS;
}
