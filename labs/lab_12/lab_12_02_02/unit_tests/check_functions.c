#include <check.h>
#include "array.h"

int res_array[10] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };

START_TEST(test_fibonacci_1)
{
    int array[5];
    int count = 5;

    fill_fibonacci(array, count);

    for (int i = 0; i < 5; i++)
        ck_assert_int_eq(res_array[i], array[i]);
}
END_TEST

START_TEST(test_fibonacci_2)
{
    int array[1];
    int count = 1;

    fill_fibonacci(array, count);

    int res_array[1] = { 0 };

    for (int i = 0; i < 1; i++)
        ck_assert_int_eq(res_array[i], array[i]);
}
END_TEST

START_TEST(test_fibonacci_3)
{
    int array[2];
    int count = 2;

    fill_fibonacci(array, count);

    for (int i = 0; i < 2; i++)
        ck_assert_int_eq(res_array[i], array[i]);
}
END_TEST

START_TEST(test_filter_1)
{
    int src[6] = { 1, 1, 2, 2, 3, 3 };
    int dst[6];
    int count = 3;

    filter(src, 6, dst, &count);
    int res[3] = { 1, 2, 3 };

    for (int i = 0; i < 3; i++)
        ck_assert_int_eq(res[i], dst[i]);
}
END_TEST

START_TEST(test_filter_2)
{
    int src[5] = { 4, 3, 2, 1, 1 };
    int dst[5];
    int count = 5;

    filter(src, 6, dst, &count);
    int res[4] = { 4, 3, 2, 1};

    for (int i = 0; i < 4; i++)
        ck_assert_int_eq(res[i], dst[i]);
}
END_TEST

START_TEST(test_filter_3)
{
    int src[5] = { 4, 3, 2, 1, 1 };
    int dst[1];
    int count = 0;

    filter(src, 6, dst, &count);
    ck_assert_int_eq(count, 5);
}
END_TEST

START_TEST(test_filter_4)
{
    int src[5] = { 4, 3, 2, 1, 1 };
    int dst[1];
    int count = 0;

    filter(src, 6, dst, &count);
    ck_assert_int_eq(count, 5);

    filter(src, 6, dst, &count);
    int res[4] = { 4, 3, 2, 1};

    for (int i = 0; i < 4; i++)
        ck_assert_int_eq(res[i], dst[i]);

}
END_TEST

Suite *functions_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n  FUNCTIONS  ");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, test_fibonacci_1);
    tcase_add_test(tc_pos, test_fibonacci_2);
    tcase_add_test(tc_pos, test_fibonacci_3);
    tcase_add_test(tc_pos, test_filter_1);
    tcase_add_test(tc_pos, test_filter_2);
    tcase_add_test(tc_pos, test_filter_3);
    tcase_add_test(tc_pos, test_filter_4);
    suite_add_tcase(s, tc_pos);

    return s;
}
