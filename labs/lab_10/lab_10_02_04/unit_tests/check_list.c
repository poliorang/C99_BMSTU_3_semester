#include <check.h>
#include "list.h"

START_TEST(test_command_ok_1)
{
    char command[MAX_LEN_COMMAND] = "out";
    int rc = check_command(command);

    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(test_command_ok_2)
{
    char command[MAX_LEN_COMMAND] = "div";
    int rc = check_command(command);

    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(test_command_not_ok_1)
{
    char command[MAX_LEN_COMMAND] = "del";
    int rc = check_command(command);

    ck_assert_int_ne(rc, 0);
}
END_TEST

START_TEST(test_create_list)
{
    node_t *cur = create_list(3);

    node_t *list = cur;
    while (list)
    {
        ck_assert_int_eq(list->elem, 3);
        ck_assert_int_eq(list->pow, 1);
        list = list->next;
    }

    free_list(cur);
}
END_TEST

START_TEST(test_create_node)
{
    node_t *node = create_node(5, 6);

    ck_assert_int_eq(node->elem, 5);
    ck_assert_int_eq(node->pow, 6);

    free(node);
}
END_TEST


START_TEST(test_push)
{
    node_t *node = create_node(5, 6);
    node_t *list = NULL;
    list = push(list, node);


    ck_assert_int_eq(list->elem, 5);
    ck_assert_int_eq(list->pow, 6);

    //free(node);
    free_list(list);
}
END_TEST


Suite* list_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("\n  LIST  ");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, test_command_ok_1);
    tcase_add_test(tc_pos, test_command_ok_2);
    tcase_add_test(tc_pos, test_create_list);
    tcase_add_test(tc_pos, test_create_node);
    tcase_add_test(tc_pos, test_push);

    suite_add_tcase(s, tc_pos);


    tc_neg = tcase_create(" negatives ");

    tcase_add_test(tc_neg, test_command_not_ok_1);

    suite_add_tcase(s, tc_neg);

    return s;
}

