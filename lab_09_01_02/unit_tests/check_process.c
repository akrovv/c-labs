#include "check_process.h"
#include "process.h"
#include "allocate.h"

START_TEST(sort_unsorted_struct)
{
    product_array_t products;
    products.len = 5;
    allocate_struct(&products.product);
    char *name = malloc(10 * sizeof(char));
    strcpy(name, "Gcc");
    int el = 10;
    for (size_t i = 0; i < products.len; i++)
    {
        products.product[i].product_name = name;
        products.product[i].weight = el--;
        products.product[i].volume = el;
    }

    int rc = selection_sort_by_density(&products);
    ck_assert_int_eq(rc, EXIT_SUCCESS);

    free(name);
    free(products.product);
}
END_TEST


Suite *process_suite(void)
{
    Suite *st_process;
    TCase *tc_pos;

    st_process = suite_create("_PROCESS_STRUCT_");
    tc_pos = tcase_create("_POSITIVE_");
    tcase_add_test(tc_pos, sort_unsorted_struct);
    suite_add_tcase(st_process, tc_pos);

    return st_process;
}