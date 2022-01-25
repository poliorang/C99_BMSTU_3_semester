#include "check_main.h"

typedef long long int (__cdecl *fn_create_arr_t)(FILE *, int **, int **, size_t *);
typedef long long int (__cdecl *fn_print_array_t)(FILE *, const int *, const int *);

fn_create_arr_t create_arr;
fn_print_array_t print_array;

START_TEST(test_create_arr_ok)
{
    int array[5] = {1, 2, 3, 4, 5};
    int *pb = array;
    int *arr, *arr_end;
    size_t count;
    FILE *f = fopen("unit_tests/shared/test_03_01.txt", "r");
    create_arr(f, &arr, &arr_end, &count);

    ck_assert_int_eq((int)count, 5);
    for (int *i = arr; i < arr_end; i++, pb++)
        ck_assert_int_eq(*i, *pb);
    fclose(f);
    free(arr);
}
END_TEST

START_TEST(test_print_arr_ok)
{
    int arr[5] = {1, 2, 3, 4, 5};
    int *pb = arr, *pe = arr + 5;

    FILE *fin = fopen("unit_tests/shared/test_04_01.txt", "r");
    print_array(fin, pb, pe);
    fclose(fin);

    FILE *f = fopen("unit_tests/shared/test_04_01.txt", "r");
    for (int *i = pb; i < pe; i++)
    {
        int elem;
        fscanf(f, "%d", &elem);
        ck_assert_int_eq(*i, elem);
    }
    fclose(f);
}
END_TEST

Suite *functions_suite(void)
{
    HMODULE hlib = LoadLibrary("libapp.dll");
    hlib = LoadLibrary("libapp.dll");
    if (!hlib)
        printf("Cannot open library.\n");

    create_arr = (fn_create_arr_t) GetProcAddress(hlib, "create_arr");
    print_array = (fn_print_array_t) GetProcAddress(hlib, "print_array");

    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("\n  FUNCTIONS  ");

    tc_neg = tcase_create(" negatives ");
    suite_add_tcase(s, tc_neg);


    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, test_create_arr_ok);
    tcase_add_test(tc_pos, test_print_arr_ok);

    suite_add_tcase(s, tc_pos);

    FreeLibrary(hlib);

    return s;
}
