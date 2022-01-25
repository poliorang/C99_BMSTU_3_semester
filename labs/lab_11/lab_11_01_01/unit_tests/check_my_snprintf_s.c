#include <check.h>
#include "my_snprintf.h"

START_TEST(test_s_1)
{
    char line_my[MAX_LEN_STR] = "\0", line_real[MAX_LEN_STR] = "\0";
    int res_my = 0, res_real = 0;

    char str[] = "hello";
    char f[] = "%s";

    res_my = my_snprintf(line_my, 10, f, str);
    res_real = snprintf(line_real, 10, f, str);

    ck_assert_int_eq(res_real, res_my);
    ck_assert_str_eq(line_real, line_my);
}
END_TEST

START_TEST(test_s_2)
{
    char line_my[MAX_LEN_STR] = "\0", line_real[MAX_LEN_STR] = "\0";
    int res_my = 0, res_real = 0;

    char str[] = "hello hy";
    char f[] = "%s";

    res_my = my_snprintf(line_my, 0, f, str);
    res_real = snprintf(line_real, 0, f, str);

    ck_assert_int_eq(res_real, res_my);
    ck_assert_str_eq(line_real, line_my);
}
END_TEST

START_TEST(test_s_3)
{
    char line_my[MAX_LEN_STR] = "\0", line_real[MAX_LEN_STR] = "\0";
    int res_my = 0, res_real = 0;

    char str[] = "abcdefgh";
    char f[] = "%s";

    res_my = my_snprintf(line_my, 5, f, str);
    res_real = snprintf(line_real, 5, f, str);

    printf("\n%d %s\n%d %s\n", res_my, line_my, res_real, line_real);

    ck_assert_int_eq(res_real, res_my);
    ck_assert_str_eq(line_real, line_my);
}
END_TEST

START_TEST(test_s_4)
{
    char line_my[MAX_LEN_STR] = "\0", line_real[MAX_LEN_STR] = "\0";
    int res_my = 0, res_real = 0;

    char str[] = "";
    char f[] = "%s";

    res_my = my_snprintf(line_my, 50, f, str);
    res_real = snprintf(line_real, 50, f, str);

    ck_assert_int_eq(res_real, res_my);
    ck_assert_str_eq(line_real, line_my);
}
END_TEST

START_TEST(test_s_5)
{
    char line_my[MAX_LEN_STR] = "\0", line_real[MAX_LEN_STR] = "\0";
    int res_my = 0, res_real = 0;

    char str[] = "hey";
    char f[] = "апу %s";

    res_my = my_snprintf(line_my, 50, f, str);
    res_real = snprintf(line_real, 50, f, str);

    ck_assert_int_eq(res_real, res_my);
    ck_assert_str_eq(line_real, line_my);
}
END_TEST

Suite *my_snprintf_s_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n  MY SNPRINTF  ");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, test_s_1);
    tcase_add_test(tc_pos, test_s_2);
    tcase_add_test(tc_pos, test_s_3);
    tcase_add_test(tc_pos, test_s_4);
    tcase_add_test(tc_pos, test_s_5);
    suite_add_tcase(s, tc_pos);
    return s;
}
