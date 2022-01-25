#include <check.h>
#include "reverse.h"

START_TEST(test_reverse)
{
    FILE *f = fopen("unit_tests/shared/test_04_in.txt", "r");
    FILE *fout = fopen("unit_tests/shared/test_04_out.txt", "r");

    node_t *list = NULL;
    list = create_list(f);

    node_t *reverse_list = NULL;
    reverse_list = create_list(fout);

    list = reverse(list);

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

Suite* reverse_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n  REVERSE  ");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, test_reverse);

    suite_add_tcase(s, tc_pos);


    return s;
}

