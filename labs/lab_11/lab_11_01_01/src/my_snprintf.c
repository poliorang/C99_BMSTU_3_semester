#include "my_snprintf.h"

int my_snprintf(char *restrict s, size_t n, const char *restrict format, ...)
{
    va_list args;
    va_start(args, format);

    size_t len = 0;

    while (*format)
    {
        if (*format != '%')
        {
            if (s && n && len < n)
                s[len] = *format;

            format++;
            len++;
            continue;
        }

        if (*(format + 1) == 'x' || *(format + 1) == 'o')
        {
            uint32_t num = va_arg(args, uint32_t);
            char str[MAX_LEN_STR] = "\0";
            int len_num = 0;

            if (*(format + 1) == 'x')
                convert_int_to_str_in_system(str, num, &len_num, 16);
            else
                convert_int_to_str_in_system(str, num, &len_num, 8);

            for (int i = 0; i < len_num; i++, len++)
                if (s && n && len < n)
                    s[len] = str[i];


            format += 2;
            continue;
        }

        if (*(format + 1) == 's')
        {
            char *str = va_arg(args, char*);

            if (str)
                for (; *str; str++, len++)
                    if (s && n && len < n)
                        s[len] = *str;

            format += 2;
            continue;
        }

        if (*(format + 1) == 'l' && *(format + 2) == 'l' && (*(format + 3) == 'x' || *(format + 3) == 'o'))
        {
            uint64_t num = va_arg(args, uint64_t);
            if (num == 0)
            {
                s[len] = '0';
                len++;
            }
            else
            {
                char str[MAX_LEN_STR] = "\0";
                int len_num = 0;
                if (*(format + 3) == 'x')
                    convert_int_to_str_in_system(str, num, &len_num, 16);
                else
                    convert_int_to_str_in_system(str, num, &len_num, 8);

                for (int i = 0; i < len_num; i++, len++)
                    if (s && n && len < n)
                        s[len] = str[i];
            }

            format += 4;
            continue;
        }
    }

    if (s && n)
    {
        if (len >= n)
            s[n - 1] = '\0';
        else
            s[len] = '\0';
    }

    va_end(args);

    return len;
}
