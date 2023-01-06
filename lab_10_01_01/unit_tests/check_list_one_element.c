#include "check_list_one_element.h"
#include "operations.h"
#include "utils.h"

// Positive

START_TEST(check_find_one_element)
{
    node_t *node = malloc(sizeof(node_t));
    char *name = "BMSTU";
    node->next = NULL;
    node->data = name;
    node_t *res = find(node, name, comparator);
    ck_assert_ptr_eq((char *)res->data, name);
    node->data = NULL;
    free(node);
}
END_TEST

START_TEST(check_find_few_elements)
{
    node_t *node = malloc(sizeof(node_t));
    node_t *node2 = malloc(sizeof(node_t));
    node_t *node3 = malloc(sizeof(node_t));
    char *name = "BMSTU";
    char *name2 = "MSU";
    char *name3 = "HSE";
    node->next = node2;
    node->data = name;

    node2->next = node3;
    node2->data = name2;

    node3->next = NULL;
    node3->data = name3;

    node_t *res = find(node, name3, comparator);
    ck_assert_ptr_eq(res->data, "HSE");
    node->data = NULL;
    node2->data = NULL;
    node3->data = NULL;
    free(node);
    free(node2);
    free(node3);
}
END_TEST

START_TEST(check_find_not_find)
{
    node_t *node = malloc(sizeof(node_t));
    node_t *node2 = malloc(sizeof(node_t));
    node_t *node3 = malloc(sizeof(node_t));
    char *name = "BMSTU";
    char *name2 = "MSU";
    char *name3 = "HSE";
    char *name4 = "MISIS";
    node->next = node2;
    node->data = name;

    node2->next = node3;
    node2->data = name2;

    node3->next = NULL;
    node3->data = name3;

    node_t *res = find(node, name4, comparator);
    ck_assert_ptr_eq(res, NULL);
    node->data = NULL;
    node2->data = NULL;
    node3->data = NULL;
    free(node);
    free(node2);
    free(node3);
}
END_TEST

START_TEST(check_pop_front)
{
    node_t *node = malloc(sizeof(node_t));
    node_t *node2 = malloc(sizeof(node_t));
    node_t *node3 = malloc(sizeof(node_t));
    char *name = "BMSTU";
    char *name2 = "MSU";
    char *name3 = "HSE";
    node->next = node2;
    node->data = name;

    node2->next = node3;
    node2->data = name2;

    node3->next = NULL;
    node3->data = name3;

    void *res = pop_front(&node);
    ck_assert_ptr_eq(res, name);
    node->data = NULL;
    node2->data = NULL;
    node3->data = NULL;
    free(node2);
    free(node3);
}
END_TEST

// Negative

START_TEST(check_pop_front_null)
{
    void *res = pop_front(NULL);
    ck_assert_ptr_eq(res, NULL);
}
END_TEST

START_TEST(check_pop_front_pointer_null)
{
    node_t *node = NULL;
    void *res = pop_front(&node);
    ck_assert_ptr_eq(res, NULL);
}
END_TEST

START_TEST(check_pop_back_null)
{
    void *res = pop_back(NULL);
    ck_assert_ptr_eq(res, NULL);
}
END_TEST

START_TEST(check_pop_back_pointer_null)
{
    node_t *node = NULL;
    void *res = pop_back(&node);
    ck_assert_ptr_eq(res, NULL);
}
END_TEST


Suite *one_element_suite(void)
{
    Suite *st_process;
    TCase *tc_pos, *tc_neg;

    st_process = suite_create("_ONE_ELEMENT_LIST_");
    tc_pos = tcase_create("_POSITIVE_");
    tcase_add_test(tc_pos, check_find_one_element);
    tcase_add_test(tc_pos, check_find_few_elements);
    tcase_add_test(tc_pos, check_find_not_find);
    tcase_add_test(tc_pos, check_pop_front);
    suite_add_tcase(st_process, tc_pos);

    tc_neg = tcase_create("_NEGATIVE_");
    tcase_add_test(tc_neg, check_pop_front_null);
    tcase_add_test(tc_neg, check_pop_front_pointer_null);
    tcase_add_test(tc_neg, check_pop_back_null);
    tcase_add_test(tc_neg, check_pop_back_pointer_null);
    suite_add_tcase(st_process, tc_neg);

    return st_process;
}