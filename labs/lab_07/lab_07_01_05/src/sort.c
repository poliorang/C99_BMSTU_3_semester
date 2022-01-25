#include "../inc/sort.h"

int compare_int(const void *p, const void *q)
{
    return (*(int *)p) - (*(int *)q);
}

void swap(void *p1, void *p2, size_t size)
{
    char buf;
    char *pb = p1;
    char *pe = p2;
    for (size_t i = 0; i < size; i++, pb++, pe++)
    {
        buf = *pb;
        *pb = *pe;
        *pe = buf;
    }
}

void mysort(void *base, size_t nmemb, size_t size, int (*compar)(const void*, const void*))
{
    char *pb1 = base; // начало массива
    char *pe1 = pb1 + (nmemb - 1) * size; // конец массива
    int flag;
    char *next;
    
    for (; pe1 >= pb1; pe1 -= size)
    {
        flag = 0;
        for (char *pb2 = base; pb2 < pe1; pb2 += size)
        {
            next = pb2 + size;
            if (compar(pb2, next) > 0)
            {
                flag = 1;
                swap(pb2, next, size);
            }
        }
        if (flag)
            pe1 = next;
    }
}


