#include "check_main.h"

#define EPS 1.0e-7

typedef long long int (__cdecl *fn_compare_int_t)(const void *, const void *);
typedef long long int (__cdecl *fn_mysort_t)(void *, size_t, size_t, long long int (*comparator)(const void *, const void *));
typedef long long int (__cdecl *fn_swap_t)(void *p1, void *p2, size_t size);

fn_compare_int_t compare_int;
fn_mysort_t mysort;
fn_swap_t swap;

static long long int compare_double(const void *p, const void *q)
{
    double res = (*(double *)p) - (*(double *)q);
    if (res < 0)
        return -1;
    return 1;
}

START_TEST(test_sort_int)
{
    int arr[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    size_t n = 9;
    size_t size = sizeof(int);
    long long int (*compare)(const void *, const void *) = compare_int;

    mysort(arr, n, size, compare);

    int arr_etalon[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (size_t i = 0; i < n; i++)
        ck_assert_int_eq(arr[i], arr_etalon[i]);
}
END_TEST

START_TEST(test_sort_int_two_elems)
{
    int arr[2] = {100, -100};
    size_t n = 2;
    size_t size = sizeof(int);
    long long int (*compare)(const void *, const void *) = compare_int;

    mysort(arr, n, size, compare);

    int arr_etalon[2] = {-100, 100};
    for (size_t i = 0; i < n; i++)
        ck_assert_int_eq(arr[i], arr_etalon[i]);
}
END_TEST

START_TEST(test_sort_int_identical_elems)
{
    int arr[5] = {5, 5, 5, 5, 5};
    size_t n = 5;
    size_t size = sizeof(int);
    long long int (*compare)(const void *, const void *) = compare_int;

    mysort(arr, n, size, compare);

    int arr_etalon[5] = {5, 5, 5, 5, 5};
    for (size_t i = 0; i < n; i++)
        ck_assert_int_eq(arr[i], arr_etalon[i]);
}
END_TEST

START_TEST(test_sort_int_one_elems)
{
    int arr[1] = {5};
    size_t n = 1;
    size_t size = sizeof(int);
    long long int (*compare)(const void *, const void *) = compare_int;

    mysort(arr, n, size, compare);

    int arr_etalon[1] = {5};
    for (size_t i = 0; i < n; i++)
        ck_assert_int_eq(arr[i], arr_etalon[i]);
}
END_TEST

START_TEST(test_sort_double)
{
    double arr[4] = {3.3, 22.4, 0.1, 0.2};
    size_t n = 4;
    size_t size = sizeof(double);
    long long int (*compare)(const void *, const void *) = compare_double;

    mysort(arr, n, size, compare);

    double arr_etalon[4] = {0.1, 0.2, 3.3, 22.4};
    for (size_t i = 0; i < n; i++)
        ck_assert_double_eq_tol(arr[i], arr_etalon[i], EPS);
}
END_TEST

START_TEST(test_swap_int)
{
    int a = 5, b = 6;
    int *pa = &a;
    int *pb = &b;
    size_t size = sizeof(int);

    swap(pa, pb, size);

    ck_assert_int_eq(*pa, 6);
    ck_assert_int_eq(*pb, 5);
}
END_TEST

START_TEST(test_swap_double)
{
    double a = 6.6, b = 5.5;
    double *pa = &a;
    double *pb = &b;
    size_t size = sizeof(double);

    swap(pa, pb, size);

    ck_assert_double_eq_tol(*pa, 5.5, EPS);
    ck_assert_double_eq_tol(*pb, 6.6, EPS);
}
END_TEST

START_TEST(test_compare_int_one)
{
    int a = 1, b = 10;
    int *pa = &a;
    int *pb = &b;

    int rc = compare_int(pa, pb);

    ck_assert_int_lt(rc, 0);
}
END_TEST

START_TEST(test_compare_int_two)
{
    int a = -40, b = 10;
    int *pa = &a;
    int *pb = &b;

    int rc = compare_int(pa, pb);

    ck_assert_int_le(rc, 0);
}
END_TEST


Suite *sort_suite(void)
{
    HMODULE hlib = LoadLibrary("libapp.dll");
    if (!hlib)
        printf("Cannot open library.\n");

    compare_int = (fn_compare_int_t) GetProcAddress(hlib, "compare_int");
    mysort = (fn_mysort_t) GetProcAddress(hlib, "mysort");
    swap = (fn_swap_t) GetProcAddress(hlib, "swap");

    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n  SORT  ");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, test_sort_int);
    tcase_add_test(tc_pos, test_sort_int_two_elems);
    tcase_add_test(tc_pos, test_sort_int_identical_elems);
    tcase_add_test(tc_pos, test_sort_int_one_elems);
    tcase_add_test(tc_pos, test_sort_double);
    tcase_add_test(tc_pos, test_swap_int);
    tcase_add_test(tc_pos, test_swap_double);
    tcase_add_test(tc_pos, test_compare_int_one);
    tcase_add_test(tc_pos, test_compare_int_two);
    suite_add_tcase(s, tc_pos);

    FreeLibrary(hlib);

    return s;
}
