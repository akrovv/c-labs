#include "check_operations.h"
#include "allocate.h"
#include "operations.h"
#include "print.h"

START_TEST(test_val_operation_bigger_zero)
{
    int n = 3;
    node_t *list = allocate_node();
	node_t *head = list;

    for (int i = 0; i < n; i++)
    {
        list->data = i + 1;
        list->next = allocate_node();
        list = list->next;
    }

    int res_expect = 54;
    int res;
    res = val_operation(head, n);
    ck_assert_int_eq(res_expect, res);
    free_list(head);
}
END_TEST

START_TEST(test_val_operation_zero)
{
    int n = 1;
    node_t *list = allocate_node();
	node_t *head = list;

    for (int i = 0; i < n; i++)
    {
        list->data = i;
        list->next = allocate_node();
        list = list->next;
    }

    int res_expect = 0;
    int res = val_operation(head, n);
    ck_assert_int_eq(res_expect, res);
    free_list(head);
}
END_TEST

START_TEST(test_val_operation_negative)
{
    int n = -2;
    int len = 4;
    node_t *list = allocate_node();
	node_t *head = list;

    for (int i = 0; i < len; i++)
    {
        list->data = i;
        list->next = allocate_node();
        list = list->next;
    }

    int res_expect = -6;
    int res = val_operation(head, n);
    ck_assert_int_eq(res_expect, res);
    free_list(head);
}
END_TEST

Suite *operations_suite(void)
{
    Suite *st_process;
    TCase *tc_pos; // *tc_neg

    st_process = suite_create("_OPERATIONS_LIST_");
    tc_pos = tcase_create("_POSITIVE_");
    tcase_add_test(tc_pos, test_val_operation_bigger_zero);
    tcase_add_test(tc_pos, test_val_operation_zero);
    tcase_add_test(tc_pos, test_val_operation_negative);
    suite_add_tcase(st_process, tc_pos);


    return st_process;
}