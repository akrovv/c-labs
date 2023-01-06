#ifndef __UTILS_H__

#define __UTILS_H__

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define STRUCT_SIZE 15

#define COUNT_ARGS_ERROR 1
#define FILE_OPEN_ERROR 2
#define ALLOCATE_ERROR 3
#define READ_PRODUCT_ERROR 4
#define NOT_FOUND_PRODUCT 5
#define FEOF_ERROR 6
#define SCANF_ERROR 7

typedef struct
{
    char *product_name;
    double weight;
    double volume;
} product_t;

typedef struct
{
    product_t *product;
    size_t len;
} product_array_t;


#endif
