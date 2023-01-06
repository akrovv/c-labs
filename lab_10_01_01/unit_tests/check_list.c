#include "check_list.h"
#include "operations_list.h"
#include "utils.h"
#include "operations.h"

// Positive

START_TEST(check_copy_one_element)
{
    char *name = "BMSTU";
    node_t *node = malloc(sizeof(node_t));
    node->data = name;
    node->next = NULL;
    node_t *node_res;
    copy(node, &node_res);

    ck_assert_ptr_eq(node_res->next, NULL);
    
    free(node);
    free(node_res);
}
END_TEST

// Negative

START_TEST(check_copy_null)
{
    ck_assert_int_eq(copy(NULL, NULL), EXIT_FAILURE);
}
END_TEST


Suite *list_suite(void)
{
    Suite *st_process;
    TCase *tc_pos, *tc_neg;

    st_process = suite_create("_FEW_ELEMENTS_LIST_");
    tc_pos = tcase_create("_POSITIVE_");
    tcase_add_test(tc_pos, check_copy_one_element);
    suite_add_tcase(st_process, tc_pos);

    tc_neg = tcase_create("_NEGATIVE_");
    tcase_add_test(tc_neg, check_copy_null);
    suite_add_tcase(st_process, tc_neg);

    return st_process;
}