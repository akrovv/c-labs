#include "check_allocate.h"
#include "utils.h"
#include "allocate.h"

START_TEST(allocate_struct_correct)
{
    product_array_t product_array;
    product_array.product = NULL;
	product_array.len = 0;
    int rc = allocate_struct(&product_array.product);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    free(product_array.product);
}
END_TEST

Suite *allocate_suite(void)
{
    Suite *st_process;
    TCase *tc_pos;

    st_process = suite_create("_ALLOCATE_STRUCT_");
    tc_pos = tcase_create("_POSITIVE_");
    tcase_add_test(tc_pos, allocate_struct_correct);
    suite_add_tcase(st_process, tc_pos);

    return st_process;

}
