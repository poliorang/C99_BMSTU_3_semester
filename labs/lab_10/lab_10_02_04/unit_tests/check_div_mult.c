#include <check.h>
#include "list.h"
#include "divide_multiplicate.h"

START_TEST(test_count_nodes)
{
    node_t *list = create_list(70);
    int count = count_factors(list);

    ck_assert_int_eq(count, 3);

    free_list(list);
}
END_TEST

START_TEST(test_multiplicate)
{
    node_t *one = create_list(70);
    node_t *two = create_list(35);
    node_t *res_1 = create_list(2450);
    node_t *res = res_1;

    node_t *one_two_1 = multiplicate(one, two);
    node_t *one_two = one_two_1;

    while (res)
    {
        ck_assert_int_eq(res->elem, one_two->elem);
        ck_assert_int_eq(res->pow, one_two->pow);
        res = res->next;
        one_two = one_two->next;
    }

    free_list(one);
    free_list(two);
    free_list(res_1);
    free_list(one_two);
    free_list(one_two_1);
}
END_TEST


START_TEST(test_divide)
{
    node_t *one = create_list(70);
    node_t *two = create_list(35);
    node_t *res_1 = create_list(2);
    node_t *res = res_1;

    node_t *one_two_1 = divide_without_remainder(one, two);
    node_t *one_two = one_two_1;

    while (res)
    {
        ck_assert_int_eq(res->elem, one_two->elem);
        ck_assert_int_eq(res->pow, one_two->pow);
        res = res->next;
        one_two = one_two->next;
    }

    free_list(one);
    free_list(two);
    free_list(res_1);
    free_list(one_two);
    free_list(one_two_1);
}
END_TEST


Suite* div_mul_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n  DIVIDE_MULTIPLICATE  ");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, test_count_nodes);
    tcase_add_test(tc_pos, test_multiplicate);
    tcase_add_test(tc_pos, test_divide);

    suite_add_tcase(s, tc_pos);


    return s;
}

