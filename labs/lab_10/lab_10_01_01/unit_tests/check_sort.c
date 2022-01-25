#include <check.h>
#include "sort.h"
#include "list.h"

START_TEST(test_sort)
{
    FILE *f = fopen("unit_tests/shared/test_05_in.txt", "r");
    FILE *fout = fopen("unit_tests/shared/test_05_out.txt", "r");

    node_t *list = NULL;
    list = create_list(f);

    node_t *reverse_list = NULL;
    reverse_list = create_list(fout);

    list = sort(list, comparator_packs);

    node_t *one = list;
    node_t *two = reverse_list;

    while (one)
    {
        ck_assert_int_eq(((package_r *)(one->data))->number, ((package_r *)(two->data))->number);
        ck_assert_double_eq(((package_r *)(one->data))->weight, ((package_r *)(two->data))->weight);
        one = one->next;
        two = two->next;
    }

    fclose(fout);
    fclose(f);
    free_list(&reverse_list);
    free_list(&list);
}
END_TEST

START_TEST(test_sorted_merge_01)
{
    FILE *f1 = fopen("unit_tests/shared/test_06_01.txt", "r");
    FILE *f2 = fopen("unit_tests/shared/test_06_02.txt", "r");
    FILE *f3 = fopen("unit_tests/shared/test_06_03.txt", "r");

    node_t *list_one = NULL, *list_two = NULL, *out = NULL;
    list_one = create_list(f1);
    list_two = create_list(f2);
    out = create_list(f3);

    node_t *list = NULL;
    list = sorted_merge(&list_one, &list_two, comparator_packs);


    node_t *one = list;
    node_t *two = out;

    while (one)
    {
        ck_assert_int_eq(((package_r *)(one->data))->number, ((package_r *)(two->data))->number);
        ck_assert_double_eq(((package_r *)(one->data))->weight, ((package_r *)(two->data))->weight);
        one = one->next;
        two = two->next;
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
    free_list(&list_one);
    free_list(&list_two);
    free_list(&list);
    free_list(&out);
}
END_TEST

START_TEST(test_sorted_merge_02)
{
    FILE *f1 = fopen("unit_tests/shared/test_07_01.txt", "r");
    FILE *f2 = fopen("unit_tests/shared/test_07_02.txt", "r");
    FILE *f3 = fopen("unit_tests/shared/test_07_03.txt", "r");

    node_t *list_one = NULL, *list_two = NULL, *out = NULL;
    list_one = create_list(f1);
    list_two = create_list(f2);
    out = create_list(f3);

    node_t *list = NULL;
    list = sorted_merge(&list_one, &list_two, comparator_packs);


    node_t *one = list;
    node_t *two = out;

    while (one)
    {
        ck_assert_int_eq(((package_r *)(one->data))->number, ((package_r *)(two->data))->number);
        ck_assert_double_eq(((package_r *)(one->data))->weight, ((package_r *)(two->data))->weight);
        one = one->next;
        two = two->next;
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
    free_list(&list_one);
    free_list(&list_two);
    free_list(&list);
    free_list(&out);
}
END_TEST

START_TEST(test_front_back_split)
{
    FILE *f1 = fopen("unit_tests/shared/test_08_01.txt", "r");
    FILE *f2 = fopen("unit_tests/shared/test_08_02.txt", "r");

    node_t *list_one = NULL, *list_two = NULL;
    list_one = create_list(f1);
    list_two = create_list(f2);


    node_t *list = NULL;
    front_back_split(list_one, &list);

    node_t *one = list;
    node_t *two = list_two;

    while (one)
    {
        ck_assert_int_eq(((package_r *)(one->data))->number, ((package_r *)(two->data))->number);
        ck_assert_double_eq(((package_r *)(one->data))->weight, ((package_r *)(two->data))->weight);
        one = one->next;
        two = two->next;
    }

    fclose(f1);
    fclose(f2);
    free_list(&list);
    free_list(&list_one);
    free_list(&list_two);
}
END_TEST

Suite* sort_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n  SORT  ");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, test_sort);
    tcase_add_test(tc_pos, test_sorted_merge_01);
    tcase_add_test(tc_pos, test_sorted_merge_02);
    tcase_add_test(tc_pos, test_front_back_split);

    suite_add_tcase(s, tc_pos);


    return s;
}

