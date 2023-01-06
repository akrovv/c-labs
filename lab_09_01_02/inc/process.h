#ifndef __PROCESS_H__
#define __PROCESS_H__

#include "utils.h"
#include "read.h"

int search_name_by_substring(product_array_t *products, char substring[]);
int selection_sort_by_density(product_array_t *products);

#endif
