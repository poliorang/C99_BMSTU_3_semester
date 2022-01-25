#include <check.h>
#include "../inc/objects.h"

START_TEST(test_read_structure)
{
    size_t count = 2;
    obj_t *obj = malloc(count * sizeof (obj_t));

    FILE *f = fopen("unit_tests/shared/test_01.txt", "r");
    read_from_file(obj, f, count);

    char name1[MAX_NAME_LEN];
    strcpy(name1, "pen");
    double weight1 = 4.5, volume1 = 5.5;

    char name2[MAX_NAME_LEN];
    strcpy(name2, "phone");
    double weight2 = 40.3, volume2 = 10.2;

    ck_assert_str_eq(name1, obj[0].name);
    ck_assert_str_eq(name2, obj[1].name);
    ck_assert_double_eq(weight1, obj[0].weight);
    ck_assert_double_eq(weight2, obj[1].weight);
    ck_assert_double_eq(volume1, obj[0].volume);
    ck_assert_double_eq(volume2, obj[1].volume);

    clean_up(f, obj, count);
}
END_TEST


START_TEST(test_count_structures)
{
    FILE *f = fopen("unit_tests/shared/test_02.txt", "r");

    size_t count = 0;
    size_t count_res = 3;
    count_structures(f, &count);

    ck_assert_int_eq((int)count_res, (int)count);
    fclose(f);
}
END_TEST


START_TEST(test_sort_structures)
{
    size_t count = 4;

    obj_t *a = malloc(count * sizeof (obj_t));
    obj_t *res = malloc(count * sizeof (obj_t));

    FILE *f = fopen("unit_tests/shared/test_03_01.txt", "r");
    FILE *f_res = fopen("unit_tests/shared/test_03_02.txt", "r");

    read_from_file(a, f, count);
    read_from_file(res, f_res, count);

    insertion_sort(a, count);

    for (size_t i = 0; i < count; i++)
    {
        ck_assert_str_eq(a[i].name, res[i].name);
        ck_assert_double_eq(a[i].weight, res[i].weight);
        ck_assert_double_eq(a[i].volume, res[i].volume);
    }

    clean_up(f, a, count);
    clean_up(f_res, res, count);
}
END_TEST


Suite* objects_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("\n  OBJECTS  ");

    tc_pos = tcase_create(" positives ");

    tcase_add_test(tc_pos, test_read_structure);
    tcase_add_test(tc_pos, test_count_structures);
    tcase_add_test(tc_pos, test_sort_structures);

    suite_add_tcase(s, tc_pos);

    return s;
}
