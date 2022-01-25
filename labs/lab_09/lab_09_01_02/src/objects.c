#define _POSIX_C_SOURCE 200809L
#include "../inc/objects.h"

void insertion_sort(obj_t *a, const size_t n)
{
    double el;
    size_t pos;
    for (size_t i = 1; i < n; i++)
    {
        obj_t obj_for_el = a[i];
        el = a[i].weight / a[i].volume;
        pos = i - 1;
        while ((int)pos >= 0 && ((a[pos].weight / a[pos].volume) > el))
        {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = obj_for_el;
    }
}

void print_structure(const obj_t obj)
{
    printf("%s\n%lf\n%lf\n", obj.name, obj.weight, obj.volume);
}

void print_structures(const obj_t *a, const size_t n)
{
    for (size_t i = 0; i < n; i++)
        print_structure(a[i]);
}

int count_structures(FILE *f, size_t *count)
{
    char name[MAX_NAME_LEN];
    double weight, volume;

    while (!feof(f))
    {
        if (fscanf(f, "%s %lf %lf\n", name, &weight, &volume) != ARG_THREE)
            return ERR_PARAM;
        (*count)++;
    }

    return EXIT_SUCCESS;
}

void clear_string_fields(obj_t *arr, const size_t count)
{
    for (size_t i = 0; i < count; i++)
        arr[i].name = NULL;
}

void free_string_fields(obj_t *arr, const size_t count)
{
    for (size_t i = 0; i < count; i++)
        free(arr[i].name);
}

void clean_up(FILE *f, obj_t *arr, const size_t count)
{
    free_string_fields(arr, count);
    free(arr);
    fclose(f);
}

int read_from_file(obj_t *arr, FILE *f, const size_t count)
{
    clear_string_fields(arr, count);

    for (size_t i = 0; i < count; i++)
    {
        size_t len = 0;
        ssize_t read = getline(&arr[i].name, &len, f);

        if (read == -1 || fscanf(f, "%lf%lf\n", &arr[i].weight, &arr[i].volume) != ARG_TWO)
        {
            clean_up(f, arr, count);
            return FILE_ERR;
        }

        arr[i].name[strlen(arr[i].name) - 1] = '\0';
        if (strlen(arr[i].name) == 0 || strlen(arr[i].name) >= MAX_NAME_LEN)
        {
            clean_up(f, arr, count);
            return ERR_LONG_WORD;
        }

        if (arr[i].volume <= 0 || arr[i].weight <= 0)
        {
            clean_up(f, arr, count);
            return ERR_PARAM;
        }
    }

    return EXIT_SUCCESS;
}
