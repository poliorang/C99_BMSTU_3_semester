#include <check.h>
#include "my_snprintf.h"

START_TEST(test_llx_1)
{
    char line_my[MAX_LEN_STR] = "\0", line_real[MAX_LEN_STR] = "\0";
    int res_my = 0, res_real = 0;

    uint64_t num = 10;
    char f[] = "%llx";

    res_my = my_snprintf(line_my, 50, f, num);
    res_real = snprintf(line_real, 50, f, num);

    ck_assert_int_eq(res_real, res_my);
    ck_assert_str_eq(line_real, line_my);
}
END_TEST

START_TEST(test_llx_2)
{
    char line_my[MAX_LEN_STR] = "\0", line_real[MAX_LEN_STR] = "\0";
    int res_my = 0, res_real = 0;

    uint64_t num = 3865;
    char f[] = "%llx";

    res_my = my_snprintf(line_my, 50, f, num);
    res_real = snprintf(line_real, 50, f, num);

    ck_assert_int_eq(res_real, res_my);
    ck_assert_str_eq(line_real, line_my);
}
END_TEST

START_TEST(test_llx_3)
{
    char line_my[MAX_LEN_STR] = "\0", line_real[MAX_LEN_STR] = "\0";
    int res_my = 0, res_real = 0;

    uint64_t num = -847;
    char f[] = "%llx";

    res_my = my_snprintf(line_my, 50, f, num);
    res_real = snprintf(line_real, 50, f, num);

    ck_assert_int_eq(res_real, res_my);
    ck_assert_str_eq(line_real, line_my);
}
END_TEST

START_TEST(test_x_1)
{
    char line_my[MAX_LEN_STR] = "\0", line_real[MAX_LEN_STR] = "\0";
    int res_my = 0, res_real = 0;

    uint64_t num = 8486257;
    char f[] = "%x";

    res_my = my_snprintf(line_my, 50, f, num);
    res_real = snprintf(line_real, 50, f, num);

    ck_assert_int_eq(res_real, res_my);
    ck_assert_str_eq(line_real, line_my);
}
END_TEST

START_TEST(test_x_2)
{
    char line_my[MAX_LEN_STR] = "\0", line_real[MAX_LEN_STR] = "\0";
    int res_my = 0, res_real = 0;

    uint64_t num = 847;
    char f[] = "%x";

    res_my = my_snprintf(line_my, 50, f, num);
    res_real = snprintf(line_real, 50, f, num);

    ck_assert_int_eq(res_real, res_my);
    ck_assert_str_eq(line_real, line_my);
}
END_TEST

Suite *my_snprintf_x_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n  MY SNPRINTF  ");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, test_llx_1);
    tcase_add_test(tc_pos, test_llx_2);
    tcase_add_test(tc_pos, test_llx_3);
    tcase_add_test(tc_pos, test_x_1);
    tcase_add_test(tc_pos, test_x_2);
    suite_add_tcase(s, tc_pos);

    return s;
}
