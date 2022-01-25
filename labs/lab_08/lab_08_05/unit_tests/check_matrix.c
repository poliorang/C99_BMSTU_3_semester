#include <check.h>
#include "matrix.h"

START_TEST(test_find_min)
{
    matrix_r a;
    a.row = 3;
    a.column = 4;
    a.matrix = allocate_matrix(a.row, a.column);

    for (int i = 0; i < a.row; i++)
        for (int j = 0; j < a.column; j++)
            a.matrix[i][j] = i + j;

    int r_ok = 0, c_ok = 0;
    int r, c;
    find_first_min(a, &r, &c);

    free_matrix(a);

    ck_assert_int_eq(r, r_ok);
    ck_assert_int_eq(c, c_ok);
}
END_TEST


START_TEST(test_multiplicate_matrix)
{
    matrix_r a, b;
    a.row = 2;
    a.column = 2;
    b.row = 2;
    b.column = 2;
    a.matrix = allocate_matrix(a.row, a.column);
    b.matrix = allocate_matrix(b.row, b.column);

    for (int i = 0; i < a.row; i++)
        for (int j = 0; j < a.column; j++)
        {
            b.matrix[i][j] = 1;
            a.matrix[i][j] = 1;
        }

    multiplicate_matrix(a, &b);

    int m[2][2];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            m[i][j] = 2;

    for (int i = 0; i < b.row; i++)
        for (int j = 0; j < b.column; j++)
            ck_assert_int_eq(m[i][j], b.matrix[i][j]);

    free_matrix(a);
    free_matrix(b);
}
END_TEST

START_TEST(test_exponentiate_matrix)
{
    matrix_r a;
    a.row = 2;
    a.column = 2;
    a.matrix = allocate_matrix(a.row, a.column);

    int p = 3;

    for (int i = 0; i < a.row; i++)
        for (int j = 0; j < a.column; j++)
            a.matrix[i][j] = 1;

    exponentiate_matrix(&a, p);

    int m[2][2];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            m[i][j] = 4;

    for (int i = 0; i < a.row; i++)
        for (int j = 0; j < a.column; j++)
            ck_assert_int_eq(m[i][j], a.matrix[i][j]);

    free_matrix(a);
}
END_TEST

START_TEST(test_identity_matrix)
{
    matrix_r a;
    a.row = 2;
    a.column = 2;
    a.matrix = allocate_matrix(a.row, a.column);

    int p = 0;

    for (int i = 0; i < a.row; i++)
        for (int j = 0; j < a.column; j++)
            a.matrix[i][j] = 1;

    exponentiate_matrix(&a, p);

    int m[2][2];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
            m[i][j] = 0;
            if (i == j)
                m[i][j] = 1;
        }

    for (int i = 0; i < a.row; i++)
        for (int j = 0; j < a.column; j++)
            ck_assert_int_eq(m[i][j], a.matrix[i][j]);

    free_matrix(a);
}
END_TEST

START_TEST(test_del_columns)
{
    matrix_r a;
    a.row = 2;
    a.column = 3;
    a.matrix = allocate_matrix(a.row, a.column);
    for (int i = 0; i < a.row; i++)
        for (int j = 0; j < a.column; j++)
            a.matrix[i][j] = i + j;

    int m[2][2];

    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 2;
    m[1][1] = 3;

    make_matrix_square(&a);

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            ck_assert_int_eq(m[i][j], a.matrix[i][j]);

    free_matrix(a);
}
END_TEST

START_TEST(test_del_rows)
{
    matrix_r a;
    a.row = 3;
    a.column = 2;
    a.matrix = allocate_matrix(a.row, a.column);
    for (int i = 0; i < a.row; i++)
        for (int j = 0; j < a.column; j++)
            a.matrix[i][j] = i + j;

    int m[2][2];

    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 2;
    m[1][1] = 3;

    make_matrix_square(&a);

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            ck_assert_int_eq(m[i][j], a.matrix[i][j]);

    free_matrix(a);
}
END_TEST


Suite* matrix_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n  MATRIX  ");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, test_find_min);
    tcase_add_test(tc_pos, test_multiplicate_matrix);
    tcase_add_test(tc_pos, test_exponentiate_matrix);
    tcase_add_test(tc_pos, test_identity_matrix);
    tcase_add_test(tc_pos, test_del_columns);
    tcase_add_test(tc_pos, test_del_rows);

    suite_add_tcase(s, tc_pos);

    return s;
}

