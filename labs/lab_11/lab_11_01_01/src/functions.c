#include "functions.h"

static void flip_str(char *str, int len)
{
    for (int i = 0; i < len / 2; i++)
    {
        char cur = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = cur;
    }
}

static int len_num(long long int num, int base)
{
    int len = 0;

    if (num == 0)
        return 1;

    if (num < 0)
        num += LLONG_MAX;

    for (; num > 0; num /= base, len++);

    return len;
}

void convert_int_to_str_in_system(char *str, unsigned long long int num, int *len, int base)
{
    char numbers[20] = "0123456789abcdef";
    *len = len_num(num, base);

    if (num == 0)
        str[0] = '0';

    for (int i = 0; num > 0; num /= base, i++)
        str[i] = numbers[num % base];

    flip_str(str, *len);
}
