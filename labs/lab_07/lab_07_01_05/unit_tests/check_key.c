#include <check.h>
#include "../inc/key.h"

START_TEST(test_count_elems)
{
    int arr[5] = {20, 1, 10, 2, 4};
    int *pb = arr;
    int *pe = arr + 5;
    int res;

    res = count_elems_in_arr(pb, pe);
    ck_assert_int_eq(res, 2);
}
END_TEST


START_TEST(test_key_first_arg_null)
{
    int size = 3;
    int arr[3] = {3, 2, 1};

    int *pb = NULL, *pe = NULL;

    int rc = key(NULL, arr + size, &pb, &pe);

    ck_assert_int_ne(rc, OK);

    if (!rc)
        free(pb);
}
END_TEST


START_TEST(test_key_second_arg_null)
{
    int arr[3] = {3, 2, 1};

    int *pb = NULL, *pe = NULL;

    int rc = key(arr, NULL, &pb, &pe);

    ck_assert_int_ne(rc, OK);

    if (!rc)
        free(pb);
}
END_TEST


START_TEST(test_key_pointers_order)
{
    int size = 3;
    int arr[3] = {3, 2, 1};
    int *pb = NULL, *pe = NULL;

    int rc = key(arr + size, arr, &pb, &pe);

    ck_assert_int_ne(rc, OK);

    if (!rc)
        free(pb);
}
END_TEST


START_TEST(test_key_src_one_elem)
{
    int size = 1;
    int arr[1] = {3};
    int *pb = NULL, *pe = NULL;

    int rc = key(arr, arr + size, &pb, &pe);

    ck_assert_int_ne(rc, OK);

    if (!rc)
        free(pb);
}
END_TEST


START_TEST(test_key_one_elem_in_arr)
{
    int size = 5;
    int arr[5] = {100, 3, 2, 1, 0};
    int *pb = NULL, *pe = NULL;

    int rc = key(arr, arr + size, &pb, &pe);

    ck_assert_int_eq(rc, OK);

    if (!rc)
        free(pb);
}
END_TEST


START_TEST(test_key_ok)
{
    int size = 5;
    int arr[5] = {20, 5, 9, 3, 1};
    int *pb = NULL, *pe = NULL;

    int rc = key(arr, arr + size, &pb, &pe);

    ck_assert_int_eq(rc, OK);

    if (!rc)
        free(pb);

}
END_TEST



Suite* key_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create(" KEY  ");

    tc_neg = tcase_create(" negatives ");

    tcase_add_test(tc_neg, test_key_first_arg_null);
    tcase_add_test(tc_neg, test_key_second_arg_null);
    tcase_add_test(tc_neg, test_key_pointers_order);
    tcase_add_test(tc_neg, test_key_src_one_elem);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, test_count_elems);
    tcase_add_test(tc_pos, test_key_one_elem_in_arr);
    tcase_add_test(tc_pos, test_key_ok);

    suite_add_tcase(s, tc_pos);

    return s;
}

