#include "utils.h"

#include <stdarg.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_OC_NUM 37777777778

static void add_char_in_str(char *str, char letter, size_t *quantity, size_t len)
{
    if (str && *quantity < len - 1 && len > 0)
        str[*quantity] = letter;

    (*quantity)++;
}

static size_t get_len(long long digit)
{
    int len = 0;

    while (digit)
    {
        len++;
        digit /= 10;
    }

    return len;
}

static void add_digit_in_str(char *str, long long int digit, size_t *quantity, size_t len)
{
    if (!digit)
        add_char_in_str(str, '0', quantity, len);
    else
    {
        size_t digit_len = get_len(digit);
        size_t i = 0;
        bool over_flow = false;

        if (digit < 0)
            add_char_in_str(str, '-', quantity, len);

        if (digit < 0 && digit > INT_MIN)
            digit *= -1;
        else if (digit < 0 && digit <= INT_MIN)
            over_flow = true;

        while (i < digit_len)
        {
            long long int j = 1;

            for (size_t k = 0; k < digit_len - i - 1; k++)
                j *= 10;
            
            if (over_flow)
                add_char_in_str(str, '0' - digit / j, quantity, len);
            else
                add_char_in_str(str, '0' + digit / j, quantity, len);
            i++;
            digit %= j;
        }
    }
}

static long long int convert_to_oct(long long num)
{
    int oct = 8;
    long long int conv = 0;
    size_t i = 0;
    while (num)
    {
        long long int tmp = 1;
        for (size_t k = 0; k < i; k++)
            tmp *= 10;

        conv += (num % oct) * tmp;
        num /= oct;
        i++;
    }
    if (conv < 0)
        conv = MAX_OC_NUM + conv;

    return conv;
}

int my_snprintf(char *s, size_t n, const char *format, ...)
{
    va_list args;
    size_t quantity = 0;

    va_start(args, format);

    for (size_t i = 0; format[i]; i++)
    {
        if (format[i] == '%')
        {
            i++;

            if (format[i] == 'c')
            {
                char sym = va_arg(args, int);
                add_char_in_str(s, sym, &quantity, n);
            }
            else if (format[i] == 'd' || format[i] == 'i')
            {
                int digit = va_arg(args, int);
                add_digit_in_str(s, digit, &quantity, n);
            }
            else if (format[i] == 'o')
            {
                int digit = va_arg(args, int);
                long long int res = convert_to_oct(digit);
                add_digit_in_str(s, res, &quantity, n);
            }
            else if (format[i] == 'h' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
            {
                int digit = (short int) va_arg(args, int);
                add_digit_in_str(s, digit, &quantity, n);
                i++;
            }
            else if (format[i] == 'h' && format[i + 1] == 'o')
            {
                int digit = (short int) va_arg(args, int);
                int res = convert_to_oct(digit);
                add_digit_in_str(s, res, &quantity, n);
                i++;
            }
            else if (format[i] == 'l' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
            {
                int digit = (long int) va_arg(args, int);
                add_digit_in_str(s, digit, &quantity, n);
                i++;
            }
            else if (format[i] == 'l' && format[i + 1] == 'o')
            {
                int digit = (long int) va_arg(args, int);
                int res = convert_to_oct(digit);
                add_digit_in_str(s, res, &quantity, n);
                i++;
            }
            else if (format[i] == 'l' && format[i + 1] == 'c')
            {
                char sym = (long int) va_arg(args, int);
                add_char_in_str(s, sym, &quantity, n);
                i++;
            }
        }
        else
            add_char_in_str(s, format[i], &quantity, n);
    }
    va_end(args);

    if (s && n > 0)
    {
        if (quantity < n - 1)
            s[quantity] = '\0';
        else
            s[n - 1] = '\0';
    }

    return quantity;
}

