#include <string.h>
#include "key.h"
#include "sort.h"
#include "functions.h"
#include "errors_structures.h"

int main(int argc, char *argv[])
{
    setbuf(stdout, NULL);

    if (argc < ARG_COUNT_THREE || argc > ARG_COUNT_FOUR)
        return ARG_ERROR;

    if ((argc == ARG_COUNT_FOUR) && (strcmp(argv[THIRD_ARG], "f") != 0))
        return PARAMS_ERROR;

    FILE *f = fopen(argv[FIRST_ARG], "r");
    if (f == NULL)
        return FILE_ERROR;

    int *arr, *arr_end;
    size_t count;
    if (create_arr(f, &arr, &arr_end, &count))
    {
        fclose(f);
        return ERR_COUNT;
    }

    fclose(f);

    // с фильтрацией
    if (argc == ARG_COUNT_FOUR && (strcmp(argv[THIRD_ARG], "f") == 0))
    {
        int *new_arr = NULL, *new_arr_end = NULL;

        if (!arr || !arr_end)
            return PARAMS_ERROR;

        if (arr + 1 == arr_end || arr == arr_end)
            return PARAMS_ERROR;

        if (arr_end < arr)
            return PARAMS_ERROR;

        new_arr = calloc((size_t)count, sizeof(int));

        int key_rc = key(arr, arr_end, &new_arr, &new_arr_end);
        free(arr);

        count = (size_t)(new_arr_end - new_arr);
        if (key_rc)
            return KEY_ERROR;

        arr = new_arr;
        arr_end = new_arr_end;
    }

    mysort(arr, count, sizeof(int), compare_int);

    FILE *fout = fopen(argv[SECOND_ARG], "w");
    print_array(fout, arr, arr_end);
    fclose(fout);

    free(arr);

    return EXIT_SUCCESS;
}
