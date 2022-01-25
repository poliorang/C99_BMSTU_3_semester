#ifndef CHECK_MAIN_H
#define CHECK_MAIN_H

#include <stdlib.h>
#include <check.h>
#include "../inc/functions.h"
#include "../inc/key.h"
#include "../inc/sort.h"

Suite *sort_suite(void);
Suite *key_suite(void);
Suite *functions_suite(void);

#endif

