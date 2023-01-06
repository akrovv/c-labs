#include "utils.h"
#include "check_snprintf.h"
#include <limits.h>

#define SIZE_STR 100

START_TEST(check_char_one_element)
{
    char str[SIZE_STR];
    char result[SIZE_STR];
    result[0] = 'a';
    result[1] = '\0';

    int n = 10;
    int func_result = 1;

    ck_assert_int_eq(my_snprintf(str, n, "%c", 'a'), func_result);
    ck_assert_str_eq(result, str);
}
END_TEST

START_TEST(check_char_few_elements)
{
    char str[SIZE_STR];
    char result[SIZE_STR] = "abcdef\0";
    int n = 10;

    int func_result = 6;

    ck_assert_int_eq(my_snprintf(str, n, "%c%c%c%c%c%c", 'a', 'b', 'c', 'd', 'e', 'f'), func_result);
    ck_assert_str_eq(result, str);
}
END_TEST

START_TEST(check_char_few_elements_not_fitted)
{
    char str[SIZE_STR];
    char result[SIZE_STR] = "ab\0";
    int n = 3;

    int func_result = 6;

    ck_assert_int_eq(my_snprintf(str, n, "%c%c%c%c%c%c", 'a', 'b', 'c', 'd', 'e', 'f'), func_result);
    ck_assert_str_eq(result, str);
}
END_TEST

START_TEST(check_char_few_elements_and_str)
{
    char str[SIZE_STR];
    char result[SIZE_STR] = "res: word +\0";
    int n = 20;

    int func_result = 11;

    ck_assert_int_eq(my_snprintf(str, n, "res: %c%c%c%c +", 'w', 'o', 'r', 'd'), func_result);
    ck_assert_str_eq(result, str);
}
END_TEST

START_TEST(check_digit_one_element)
{
    char str[SIZE_STR];
    char result[SIZE_STR] = "1\0";
    int n = 10;

    int func_result = 1;

    ck_assert_int_eq(my_snprintf(str, n, "%d", 1), func_result);
    ck_assert_str_eq(result, str);
}
END_TEST

START_TEST(check_digit_few_elements)
{
    char str[SIZE_STR];
    char result[SIZE_STR] = "123456789\0";
    int n = 10;

    int func_result = 9;

    ck_assert_int_eq(my_snprintf(str, n, "%d%d%d%d%d%d%d%d%d", 1, 2, 3, 4, 5, 6, 7, 8, 9), func_result);
    ck_assert_str_eq(result, str);
}
END_TEST

START_TEST(check_char_digit)
{
    char str[SIZE_STR];
    char result[SIZE_STR] = "w 2 r 0\0";
    int n = 10;

    int func_result = 7;

    ck_assert_int_eq(my_snprintf(str, n, "%c %d %c %d", 'w', 2, 'r', 0), func_result);
    ck_assert_str_eq(result, str);
}
END_TEST

START_TEST(check_oct)
{
    char str[SIZE_STR];
    char result[SIZE_STR] = "173\0";
    int n = 10;

    int func_result = 3;

    ck_assert_int_eq(my_snprintf(str, n, "%o", 123), func_result);
    ck_assert_str_eq(result, str);
}
END_TEST

START_TEST(check_all)
{
    char str[SIZE_STR];
    char result[SIZE_STR] = "24 march 2003\0";
    int n = 20;

    int func_result = 13;

    ck_assert_int_eq(my_snprintf(str, n, "%o %c%c%c%c%c %i", 20, 'm', 'a', 'r', 'c', 'h', 2003), func_result);
    ck_assert_str_eq(result, str);
}
END_TEST

START_TEST(check_negative_element)
{
    char str[SIZE_STR];
    char result[SIZE_STR] = "-1\0";
    int n = 10;

    int func_result = 2;

    ck_assert_int_eq(my_snprintf(str, n, "%d", -1), func_result);
    ck_assert_str_eq(result, str);
}
END_TEST

START_TEST(check_int_min_max)
{
    char str[SIZE_STR];
    char result[SIZE_STR] = "-2147483648\0";
    char result2[SIZE_STR] = "2147483647\0";
    int n = 20;

    int func_result_min = 11;
    int func_result_max = 10;

    ck_assert_int_eq(my_snprintf(str, n, "%d", INT_MIN), func_result_min);
    ck_assert_str_eq(result, str);
    ck_assert_int_eq(my_snprintf(str, n, "%d", INT_MAX), func_result_max);
    ck_assert_str_eq(result2, str);
}
END_TEST

START_TEST(check_h_l_int)
{
    char str[SIZE_STR];
    char result[SIZE_STR] = "10\0";
    int n = 20;

    int func_result = 2;

    ck_assert_int_eq(my_snprintf(str, n, "%hd", 10), func_result);
    ck_assert_int_eq(my_snprintf(str, n, "%ld", 10), func_result);
    ck_assert_str_eq(result, str);
}
END_TEST

START_TEST(check_h_l_oct)
{
    char str[SIZE_STR];
    char result[SIZE_STR] = "12\0";
    int n = 20;

    int func_result = 2;

    ck_assert_int_eq(my_snprintf(str, n, "%ho", 10), func_result);
    ck_assert_int_eq(my_snprintf(str, n, "%lo", 10), func_result);
    ck_assert_str_eq(result, str);
}
END_TEST

START_TEST(check_negative_oct)
{
    char str[SIZE_STR];
    char result[SIZE_STR] = "37777777777\0";
    int n = 20;

    int func_result = 11;

    ck_assert_int_eq(my_snprintf(str, n, "%o", -1), func_result);
    ck_assert_str_eq(result, str);
}
END_TEST

START_TEST(check_zero_oct)
{
    char str[SIZE_STR];
    char result[SIZE_STR] = "0\0";
    int n = 20;

    int func_result = 1;

    ck_assert_int_eq(my_snprintf(str, n, "%o", 0), func_result);
    ck_assert_str_eq(result, str);
}
END_TEST

START_TEST(check_large_negative_oct)
{
    char str[SIZE_STR];
    char result[SIZE_STR] = "37777772671\0";
    int n = 20;

    int func_result = 11;

    ck_assert_int_eq(my_snprintf(str, n, "%o", -2631), func_result);
    ck_assert_str_eq(result, str);
}
END_TEST

// NEGATIVE

START_TEST(check_zero_len)
{
    char str[SIZE_STR];
    int n = 0;

    int func_result = 2;

    ck_assert_int_eq(my_snprintf(str, n, "%d", 10), func_result);
}
END_TEST

START_TEST(check_null_pointer)
{
    int n = 10;

    int func_result = 2;

    ck_assert_int_eq(my_snprintf(NULL, n, "%d", 10), func_result);
}
END_TEST

START_TEST(check_overflow)
{
    char str[SIZE_STR];
    char result[SIZE_STR] = "100000000000\0";
    int n = 20;

    int func_result = 10;

    ck_assert_int_ne(my_snprintf(str, n, "%hd", 100000000000), func_result);
    ck_assert_str_ne(result, str);
}
END_TEST

Suite *snprintf_suite(void)
{
    Suite *st_process;
    TCase *tc_pos, *tc_neg;

    st_process = suite_create("_SNPRINTF_");
    tc_pos = tcase_create("_POSITIVE_");
    tcase_add_test(tc_pos, check_char_one_element);
    tcase_add_test(tc_pos, check_char_few_elements);
    tcase_add_test(tc_pos, check_char_few_elements_not_fitted);
    tcase_add_test(tc_pos, check_char_few_elements_and_str);
    tcase_add_test(tc_pos, check_digit_one_element);
    tcase_add_test(tc_pos, check_digit_few_elements);
    tcase_add_test(tc_pos, check_char_digit);
    tcase_add_test(tc_pos, check_oct);
    tcase_add_test(tc_pos, check_all);
    tcase_add_test(tc_pos, check_negative_element);
    tcase_add_test(tc_pos, check_int_min_max);
    tcase_add_test(tc_pos, check_h_l_int);
    tcase_add_test(tc_pos, check_h_l_oct);
    tcase_add_test(tc_pos, check_negative_oct);
    tcase_add_test(tc_pos, check_zero_oct);
    tcase_add_test(tc_pos, check_large_negative_oct);
    suite_add_tcase(st_process, tc_pos);

    tc_neg = tcase_create("_NEGATIVE_");
    tcase_add_test(tc_neg, check_zero_len);
    tcase_add_test(tc_neg, check_null_pointer);
    tcase_add_test(tc_neg, check_overflow);
    suite_add_tcase(st_process, tc_neg);

    return st_process;
}

