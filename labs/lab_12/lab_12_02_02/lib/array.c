#include "array.h"

ARR_DLL void ARR_DECL fill_fibonacci(int *array, int count)
{
    if (count >= 1)
        array[0] = 0;

    if (count >= 2)
        array[1] = 1;

    for (int i = 2; i < count; i++)
        array[i] = array[i - 1] + array[i - 2];
}

ARR_DLL int ARR_DECL filter(int *src, int src_len, int *dst, int *dst_len)
{
    int n = 0;

    for (int i = 0; i < src_len; i++)
    {
        int flag = 0;
        for (int j = 0; j < i; j++)
        {
            if (src[i] == src[j])
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
            n++;
    }

    if (n > *dst_len)
    {
        *dst_len = n;
        return 1;
    }

    n = 0;
    for (int i = 0; i < src_len; i++)
    {
        int flag = 0;
        for (int j = 0; j < i; j++)
        {
            if (src[i] == src[j])
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            dst[n] = src[i];
            n++;
        }
    }

    *dst_len = n;
    return 0;
}
