#ifndef MYSNPRINTF_H
#define MYSNPRINTF_H

#include <stdarg.h>
#include "functions.h"

int my_snprintf(char *restrict s, size_t n, const char *restrict format, ...);

#endif
