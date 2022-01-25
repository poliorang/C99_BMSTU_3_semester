#include <check.h>
#include "list.h"

START_TEST(test_print_list)
{
    FILE *f = fopen("unit_tests/shared/test_03_in.txt", "r");

    node_t *list = NULL;
    list = create_list(f);

    FILE *fout = fopen("unit_tests/shared/test_03_out.txt", "w+");
    print_list(fout, list);

    rewind(f);
    rewind(fout);

    int elem_1 = 0, elem_2 = 0;
    double weight_1 = 0, weight_2 = 0;

    while (!feof(f))
    {
        fscanf(f, "%d%lf", &elem_1, &weight_1);
        fscanf(fout, "%d%lf", &elem_2, &weight_2);
        ck_assert_int_eq(elem_1, elem_2);
        ck_assert_double_eq(weight_1, weight_2);
    }

    free_list(&list);
    fclose(f);
    fclose(fout);
}
END_TEST


START_TEST(test_read_node)
{
    FILE *f = fopen("unit_tests/shared/test_01.txt", "r");
    node_t *node = NULL;
    node = read_node(f);

    ck_assert_int_eq(((package_r *)(node->data))->number, 3);
    ck_assert_double_eq(((package_r *)(node->data))->weight, 3.3);

    free_list(&node);
    fclose(f);
}
END_TEST

START_TEST(test_read_node_ok_file)
{
    FILE *f = fopen("unit_tests/shared/test_01.txt", "r");
    node_t *node = NULL;
    node = read_node(f);

    ck_assert_ptr_nonnull(node);

    free_list(&node);
    fclose(f);
}
END_TEST

START_TEST(test_create_node)
{
    const int elem = 3;
    const double weight = 3.3;

    node_t *node = NULL;
    node = create_node(elem, weight);

    ck_assert_int_eq(((package_r *)(node->data))->number, 3);
    ck_assert_double_eq(((package_r *)(node->data))->weight, 3.3);

    free_list(&node);
}
END_TEST

START_TEST(test_create_list_ok_file)
{
    FILE *f = fopen("unit_tests/shared/test_02.txt", "r");
    node_t *list = NULL;
    list = create_list(f);

    ck_assert_ptr_nonnull(list);

    free_list(&list);
    fclose(f);
}
END_TEST

START_TEST(test_create_list)
{
    FILE *f = fopen("unit_tests/shared/test_02.txt", "r");
    node_t *list = NULL;
    list = create_list(f);

    node_t *node = list;
    ck_assert_int_eq(((package_r *)(node->data))->number, 2);
    ck_assert_double_eq(((package_r *)(node->data))->weight, 2.2);
    node = node->next;
    ck_assert_int_eq(((package_r *)(node->data))->number, 3);
    ck_assert_double_eq(((package_r *)(node->data))->weight, 3.3);

    free_list(&list);
    fclose(f);
}
END_TEST


Suite* list_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n  LIST  ");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, test_read_node_ok_file);
    tcase_add_test(tc_pos, test_read_node);
    tcase_add_test(tc_pos, test_print_list);
    tcase_add_test(tc_pos, test_create_list);
    tcase_add_test(tc_pos, test_create_list_ok_file);
    tcase_add_test(tc_pos, test_create_node);
    suite_add_tcase(s, tc_pos);

    return s;
}

