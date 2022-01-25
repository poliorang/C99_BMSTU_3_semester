#include <string.h>
#include <windows.h>
#include "errors_structures.h"

typedef long long int (__cdecl *fn_pack_array_t)(FILE *, int *, const int *);
typedef long long int (__cdecl *fn_create_arr_t)(FILE *, int **, int **, size_t *);
typedef long long int (__cdecl *fn_print_array_t)(FILE *, const int *, const int *);

typedef long long int (__cdecl *fn_count_elems_in_arr_t)(const int *, const int *);
typedef long long int (__cdecl *fn_key_t)(const int *, const int *, int **, int **);

typedef long long int (__cdecl *fn_compare_int_t)(const void *, const void *);
typedef long long int (__cdecl *fn_mysort_t)(void *, size_t, size_t, long long int (*comparator)(const void *, const void *));

int main(int argc, char *argv[])
{
    HMODULE hlib;

    fn_pack_array_t pack_array_;
    fn_create_arr_t create_arr_;
    fn_print_array_t print_array_;
    fn_count_elems_in_arr_t count_elems_in_arr_;
    fn_key_t key_;
    fn_compare_int_t compare_;
    fn_mysort_t mysort_;

    hlib = LoadLibrary("libapp.dll");
    if (!hlib)
    {
        printf("Cannot open library.\n");
        return EXIT_FAILURE;
    }

    pack_array_ = (fn_pack_array_t) GetProcAddress(hlib, "pack_array");
    if (!pack_array_)
    {
        printf("Can not load function.\n");
        FreeLibrary(hlib);
        return EXIT_FAILURE;
    }

    create_arr_ = (fn_create_arr_t) GetProcAddress(hlib, "create_arr");
    if (!create_arr_)
    {
        printf("Can not load function.\n");
        FreeLibrary(hlib);
        return EXIT_FAILURE;
    }

    print_array_ = (fn_print_array_t) GetProcAddress(hlib, "print_array");
    if (!print_array_)
    {
        printf("Can not load function.\n");
        FreeLibrary(hlib);
        return EXIT_FAILURE;
    }

    count_elems_in_arr_ = (fn_count_elems_in_arr_t) GetProcAddress(hlib, "count_elems_in_arr");
    if (!count_elems_in_arr_)
    {
        printf("Can not load function.\n");
        FreeLibrary(hlib);
        return EXIT_FAILURE;
    }

    key_ = (fn_key_t) GetProcAddress(hlib, "key");
    if (!key_)
    {
        printf("Can not load function.\n");
        FreeLibrary(hlib);
        return EXIT_FAILURE;
    }

    compare_ = (fn_compare_int_t) GetProcAddress(hlib, "compare_int");
    if (!compare_)
    {
        printf("Can not load function.\n");
        FreeLibrary(hlib);
        return EXIT_FAILURE;
    }

    mysort_ = (fn_mysort_t) GetProcAddress(hlib, "mysort");
    if (!mysort_)
    {
        printf("Can not load function.\n");
        FreeLibrary(hlib);
        return EXIT_FAILURE;
    }

    setbuf(stdout, NULL);

    if (argc < ARG_COUNT_THREE || argc > ARG_COUNT_FOUR)
    {
        FreeLibrary(hlib);
        return ARG_ERROR;
    }

    if ((argc == ARG_COUNT_FOUR) && (strcmp(argv[THIRD_ARG], "f") != 0))
    {
        FreeLibrary(hlib);
        return PARAMS_ERROR;
    }

    FILE *f = fopen(argv[FIRST_ARG], "r");
    if (f == NULL)
    {
        FreeLibrary(hlib);
        return FILE_ERROR;
    }

    int *arr, *arr_end;
    size_t count;
    if (create_arr_(f, &arr, &arr_end, &count))
    {
        FreeLibrary(hlib);
        fclose(f);
        return ERR_COUNT;
    }

    fclose(f);

    // с фильтрацией
    if (argc == ARG_COUNT_FOUR && (strcmp(argv[THIRD_ARG], "f") == 0))
    {
        int *new_arr = NULL, *new_arr_end = NULL;

        if (!arr || !arr_end)
        {
            FreeLibrary(hlib);
            return PARAMS_ERROR;
        }
        if (arr + 1 == arr_end || arr == arr_end)
        {
            FreeLibrary(hlib);
            return PARAMS_ERROR;
        }

        if (arr_end < arr)
        {
            FreeLibrary(hlib);
            return PARAMS_ERROR;
        }


        new_arr = calloc((size_t)count, sizeof(int));

        if (new_arr == NULL)
            return MEMORY_ALLOCATION_ERROR;

        if (new_arr == NULL)
        {
            printf("Memory allocation error.\n");
            FreeLibrary(hlib);
            return EXIT_FAILURE;
        }

        int key_rc = key_(arr, arr_end, &new_arr, &new_arr_end);
        free(arr);

        count = (size_t)(new_arr_end - new_arr);
        if (key_rc)
        {
            FreeLibrary(hlib);
            return KEY_ERROR;
        }

        arr = new_arr;
        arr_end = new_arr_end;
    }

    mysort_(arr, count, sizeof(int), compare_);

    FILE *fout = fopen(argv[SECOND_ARG], "w");

    if (fout == NULL)
        return OPEN_FILE_ERROR;

    print_array_(fout, arr, arr_end);
    fclose(fout);

    return EXIT_SUCCESS;
}
