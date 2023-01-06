#include "check_read.h"
#include "read.h"
#include "allocate.h"

START_TEST(read_correct_file_one_field)
{
    FILE *f;
    product_array_t array;
    allocate_struct(&array.product);
    f = fopen("test.txt", "w+");
    fprintf(f, "Akro\n");
    fprintf(f, "%d\n", 1);
    fprintf(f, "%d\n", 2);
    rewind(f);
    int rc = read_products(f, &array);

    fclose(f);
    struct_free(&array);
    remove("test.txt");
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST


START_TEST(read_correct_file_few_field)
{
    FILE *f;
    product_array_t array;
    allocate_struct(&array.product);
    f = fopen("test.txt", "w+");
    fprintf(f, "Akro\n");
    fprintf(f, "%d\n", 1);
    fprintf(f, "%d\n", 2);
    fprintf(f, "Mister\n");
    fprintf(f, "%d\n", 3);
    fprintf(f, "%d", 4);
    rewind(f);
    int rc = read_products(f, &array);

    fclose(f);
    struct_free(&array);
    remove("test.txt");
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(empty_file)
{
    FILE *f;
    product_array_t array;
    allocate_struct(&array.product);
    f = fopen("test.txt", "w+");
    rewind(f);
    int rc = read_products(f, &array);

    fclose(f);
    struct_free(&array);
    remove("test.txt");
    ck_assert_int_eq(rc, EXIT_FAILURE);
}
END_TEST

START_TEST(incorrect_weight)
{
    FILE *f;
    product_array_t array;
    allocate_struct(&array.product);
    f = fopen("test.txt", "w+");
    fprintf(f, "Akro\n");
    fprintf(f, "%d\n", 1);
    fprintf(f, "End?\n");
    rewind(f);
    int rc = read_products(f, &array);

    fclose(f);
    struct_free(&array);
    remove("test.txt");
    ck_assert_int_eq(rc, EXIT_FAILURE);
}
END_TEST

START_TEST(incorrect_struct_after_correct_struct)
{
    FILE *f;
    product_array_t array;
    allocate_struct(&array.product);
    f = fopen("test.txt", "w+");
    fprintf(f, "Akro\n");
    fprintf(f, "%d\n", 1);
    fprintf(f, "%d\n", 2);
    fprintf(f, "Mister\n");
    fprintf(f, "Word\n");
    fprintf(f, "World\n");
    rewind(f);
    int rc = read_products(f, &array);

    fclose(f);
    struct_free(&array);
    remove("test.txt");
    ck_assert_int_eq(rc, EXIT_FAILURE);
}
END_TEST

START_TEST(incorrect_volume)
{
    FILE *f;
    product_array_t array;
    allocate_struct(&array.product);
    f = fopen("test.txt", "w+");
    fprintf(f, "Akro\n");
    fprintf(f, "What?\n");
    fprintf(f, "%d\n", 2);
    rewind(f);
    int rc = read_products(f, &array);

    fclose(f);
    struct_free(&array);
    remove("test.txt");
    ck_assert_int_eq(rc, EXIT_FAILURE);
}
END_TEST

START_TEST(feof_eror)
{
    FILE *f;
    product_array_t array;
    allocate_struct(&array.product);
    f = fopen("test.txt", "w+");
    fprintf(f, "Akro\n");
    fprintf(f, "%d\n", 2);
    fprintf(f, "%d\n", 2);
    fprintf(f, "%d\n", 2);
    rewind(f);
    int rc = read_products(f, &array);

    fclose(f);
    struct_free(&array);
    remove("test.txt");
    ck_assert_int_eq(rc, EXIT_FAILURE);
}
END_TEST



Suite *read_suite(void)
{
    Suite *st_process;
    TCase *tc_pos, *tc_neg;

    st_process = suite_create("_READ_STRUCT_");
    tc_pos = tcase_create("_POSITIVE_");
    tc_neg = tcase_create("_NEGATIVE_");
    tcase_add_test(tc_pos, read_correct_file_one_field);
    tcase_add_test(tc_pos, read_correct_file_few_field);
    suite_add_tcase(st_process, tc_pos);
    tcase_add_test(tc_neg, empty_file);
    tcase_add_test(tc_neg, incorrect_weight);
    tcase_add_test(tc_neg, incorrect_volume);
    tcase_add_test(tc_neg, incorrect_struct_after_correct_struct);
    tcase_add_test(tc_neg, feof_eror);
    suite_add_tcase(st_process, tc_neg);

    return st_process;
}