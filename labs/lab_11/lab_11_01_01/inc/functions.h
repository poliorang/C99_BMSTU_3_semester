#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <limits.h>

#define MAX_LEN_STR 511

void convert_int_to_str_in_system(char *str, unsigned long long int num, int *len, int base);

#endif
