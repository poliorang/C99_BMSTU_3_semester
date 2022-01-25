#include "objects.h"

void insertion_sort(obj_t a[], const size_t n)
{
    double el;
    int pos;
    for (size_t i = 1; i < n; i++)
    {
        obj_t obj_for_el = a[i];
        el = a[i].weight / a[i].volume;
        pos = i - 1;
        while (pos >= 0 && ((a[pos].weight / a[pos].volume) > el))
        {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = obj_for_el;
    }
}

void print_struct(const obj_t obj)
{
    printf("%s\n%.6lf\n%.6lf\n", obj.name, obj.weight, obj.volume);
}

void print_from_loop(const obj_t a[], const size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%s\n%.6lf\n%.6lf\n", a[i].name, a[i].weight, a[i].volume);
}
