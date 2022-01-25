#include <check.h>
#include "my_snprintf.h"

START_TEST(test_d_1)
{
    char line_my[MAX_LEN_STR] = "\0", line_real[MAX_LEN_STR] = "\0";
    int res_my = 0, res_real = 0;

    int num = 10;
    char f[] = "%d";

    res_my = my_snprintf(line_my, 7, f, num);
    res_real = snprintf(line_real, 7, f, num);

    ck_assert_int_eq(res_real, res_my);
    ck_assert_str_eq(line_real, line_my);
}
END_TEST

START_TEST(test_d_2)
{
    char line_my[MAX_LEN_STR] = "\0", line_real[MAX_LEN_STR] = "\0";
    int res_my = 0, res_real = 0;

    int num = -234;
    char f[] = "%d";

    res_my = my_snprintf(line_my, 7, f, num);
    res_real = snprintf(line_real, 7, f, num);

    ck_assert_int_eq(res_real, res_my);
    ck_assert_str_eq(line_real, line_my);
}
END_TEST

START_TEST(test_d_3)
{
    char line_my[MAX_LEN_STR] = "\0", line_real[MAX_LEN_STR] = "\0";
    int res_my = 0, res_real = 0;

    int num = 10293;
    char f[] = "%d";

    res_my = my_snprintf(line_my, 2, f, num);
    res_real = snprintf(line_real, 2, f, num);

    ck_assert_int_eq(res_real, res_my);
    ck_assert_str_eq(line_real, line_my);
}
END_TEST

START_TEST(test_d_4)
{
    char line_my[MAX_LEN_STR] = "\0", line_real[MAX_LEN_STR] = "\0";
    int res_my = 0, res_real = 0;

    int num = 1;
    char f[] = "dd";

    res_my = my_snprintf(line_my, 7, f, num);
    res_real = snprintf(line_real, 7, f, num);

    ck_assert_int_eq(res_real, res_my);
    ck_assert_str_eq(line_real, line_my);
}
END_TEST

START_TEST(test_d_5)
{
    char line_my[MAX_LEN_STR] = "\0", line_real[MAX_LEN_STR] = "\0";
    int res_my = 0, res_real = 0;

    int num = 10;
    char f[] = "%d";
    char p[] = "qqq";

    res_my = my_snprintf(line_my, 7, f, num, p);
    res_real = snprintf(line_real, 7, f, num, p);

    ck_assert_int_eq(res_real, res_my);
    ck_assert_str_eq(line_real, line_my);
}
END_TEST

START_TEST(test_d_6)
{
    char line_my[MAX_LEN_STR] = "\0", line_real[MAX_LEN_STR] = "\0";
    int res_my = 0, res_real = 0;

    int num = 10;
    char f[] = "%dder";

    res_my = my_snprintf(line_my, 7, f, num);
    res_real = snprintf(line_real, 7, f, num);

    ck_assert_int_eq(res_real, res_my);
    ck_assert_str_eq(line_real, line_my);
}
END_TEST

START_TEST(test_d_7)
{
    char line_my[MAX_LEN_STR] = "\0", line_real[MAX_LEN_STR] = "\0";
    int res_my = 0, res_real = 0;

    int num = 1;
    char f[] = "dec1";

    res_my = my_snprintf(line_my, 7, f, num);
    res_real = snprintf(line_real, 7, f, num);

    ck_assert_int_eq(res_real, res_my);
    ck_assert_str_eq(line_real, line_my);
}
END_TEST

START_TEST(test_d_8)
{
    char line_my[MAX_LEN_STR] = "\0", line_real[MAX_LEN_STR] = "\0";
    int res_my = 0, res_real = 0;

    char num[] = "d";
    char f[] = "%d";

    res_my = my_snprintf(line_my, 7, f, num);
    res_real = snprintf(line_real, 7, f, num);

    ck_assert_int_eq(res_real, res_my);
    ck_assert_str_eq(line_real, line_my);
}
END_TEST

START_TEST(test_d_9)
{
    char line_my[MAX_LEN_STR] = "\0", line_real[MAX_LEN_STR] = "\0";
    int res_my = 0, res_real = 0;

    int num = 12;
    char f[] = "%d";

    res_my = my_snprintf(line_my, 0, f, num);
    res_real = snprintf(line_real, 0, f, num);

    ck_assert_int_eq(res_real, res_my);
    ck_assert_str_eq(line_real, line_my);
}
END_TEST

START_TEST(test_d_10)
{
    char line_my[MAX_LEN_STR] = "\0", line_real[MAX_LEN_STR] = "\0";
    int res_my = 0, res_real = 0;

    int num_1 = 12;
    char f[] = "%d";
    int num_2 = 34;

    res_my = my_snprintf(line_my, 7, f, num_1, num_2);
    res_real = snprintf(line_real, 7, f, num_1, num_2);

    ck_assert_int_eq(res_real, res_my);
    ck_assert_str_eq(line_real, line_my);
}
END_TEST

START_TEST(test_d_11)
{
    char line_my[MAX_LEN_STR] = "\0", line_real[MAX_LEN_STR] = "\0";
    int res_my = 0, res_real = 0;

    int num = 12;
    char f[] = "res%d";

    res_my = my_snprintf(line_my, 7, f, num);
    res_real = snprintf(line_real, 7, f, num);

    ck_assert_int_eq(res_real, res_my);
    ck_assert_str_eq(line_real, line_my);
}
END_TEST

START_TEST(test_d_12)
{
    char line_my[3] = "\0", line_real[3] = "\0";
    int res_my = 0, res_real = 0;

    int num = 0;
    char f[] = "%d";

    res_my = my_snprintf(line_my, 10, f, num);
    res_real = snprintf(line_real, 10, f, num);

    ck_assert_int_eq(res_real, res_my);
    ck_assert_str_eq(line_real, line_my);
}
END_TEST

START_TEST(test_d_13)
{
    char line_my[3] = "\0", line_real[3] = "\0";
    int res_my = 0, res_real = 0;

    int num = 12;
    char f[] = "%d";

    res_my = my_snprintf(line_my, 2, f, num);
    res_real = snprintf(line_real, 2, f, num);

    ck_assert_int_eq(res_real, res_my);
    ck_assert_str_eq(line_real, line_my);
}
END_TEST

START_TEST(test_d_without_format)
{
    char line_my[10] = "\0", line_real[10] = "\0";
    int res_my = 0, res_real = 0;

    int num = 12345;
    char f[] = "";

    res_my = my_snprintf(line_my, 7, f, num);
    res_real = snprintf(line_real, 7, f, num);

    ck_assert_int_eq(res_real, res_my);
    ck_assert_str_eq(line_real, line_my);
}
END_TEST

Suite *my_snprintf_d_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n  MY SNPRINTF  ");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, test_d_1);
    tcase_add_test(tc_pos, test_d_2);
    tcase_add_test(tc_pos, test_d_3);
    tcase_add_test(tc_pos, test_d_4);
    tcase_add_test(tc_pos, test_d_5);
    tcase_add_test(tc_pos, test_d_6);
    tcase_add_test(tc_pos, test_d_7);
    tcase_add_test(tc_pos, test_d_8);
    tcase_add_test(tc_pos, test_d_9);
    tcase_add_test(tc_pos, test_d_10);
    tcase_add_test(tc_pos, test_d_11);
    tcase_add_test(tc_pos, test_d_12);
    tcase_add_test(tc_pos, test_d_13);
    tcase_add_test(tc_pos, test_d_without_format);
    suite_add_tcase(s, tc_pos);

    return s;
}
