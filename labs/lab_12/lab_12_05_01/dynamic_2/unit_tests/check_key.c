#include "check_main.h"

typedef long long int (__cdecl *fn_count_elems_in_arr_t)(const int *, const int *);
typedef long long int (__cdecl *fn_key_t)(const int *, const int *, int **, int **);

fn_count_elems_in_arr_t count_elems_in_arr;
fn_key_t key;

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

START_TEST(test_key_src_one_elem)
{
    int size = 1;
    int arr[1] = {3};
    int *pb = NULL, *pe = NULL;
    pb = calloc((size_t)1, sizeof(int));

    int rc = key(arr, arr + size, &pb, &pe);

    ck_assert_int_ne(rc, 0);

    free(pb);
}
END_TEST

START_TEST(test_key_one_elem_in_arr)
{
    int size = 5;
    int arr[5] = {100, 3, 2, 1, 0};
    int *pb = NULL, *pe = NULL;
    pb = calloc((size_t)5, sizeof(int));

    int rc = key(arr, arr + size, &pb, &pe);

    ck_assert_int_eq(rc, 0);

    if (!rc)
        free(pb);
}
END_TEST

START_TEST(test_key_ok)
{
    int size = 5;
    int arr[5] = {20, 5, 9, 3, 1};
    int *pb = NULL, *pe = NULL;
    pb = calloc((size_t)5, sizeof(int));

    int rc = key(arr, arr + size, &pb, &pe);

    ck_assert_int_eq(rc, 0);

    free(pb);

}
END_TEST

Suite *key_suite(void)
{
    HMODULE hlib = LoadLibrary("libapp.dll");
    if (!hlib)
        printf("Cannot open library.\n");

    count_elems_in_arr = (fn_count_elems_in_arr_t) GetProcAddress(hlib, "count_elems_in_arr");
    key = (fn_key_t) GetProcAddress(hlib, "key");

    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create(" KEY  ");

    tc_neg = tcase_create(" negatives ");

    tcase_add_test(tc_neg, test_key_src_one_elem);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, test_count_elems);
    tcase_add_test(tc_pos, test_key_one_elem_in_arr);
    tcase_add_test(tc_pos, test_key_ok);

    suite_add_tcase(s, tc_pos);

    FreeLibrary(hlib);

    return s;
}
