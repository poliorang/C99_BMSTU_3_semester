#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/key.h"
#include "../inc/sort.h"
#include "../inc/functions.h"

#define ARG_ERROR 1
#define OPEN_FILE_ERROR 2
#define KEY_ERROR 3
#define INCORRECT_NUMBER 4

#define ARG_COUNT_THREE 3
#define ARG_COUNT_FOUR 4

#define FIRST_ARG 1
#define SECOND_ARG 2
#define THIRD_ARG 3

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

