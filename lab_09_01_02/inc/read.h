#ifndef __READ_H__
#define __READ_H__

#include "utils.h"

int read_products(FILE *f, product_array_t *products);
void print_product(product_array_t products);
void print_product_info(product_t product);

#endif 
