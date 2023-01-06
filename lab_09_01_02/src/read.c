#include "read.h"

int read_product(FILE *f, product_t *product)
{
    size_t byte_len = 0;    

    if (feof(f))
        return FEOF_ERROR;

    if ((getline(&product->product_name, &byte_len, f)) == -1)
        return SCANF_ERROR;
    
    if (!product->product_name)
        return SCANF_ERROR;

    if (product->product_name[strlen(product->product_name) - 1] == '\n')
        product->product_name[strlen(product->product_name) - 1] = '\0';

    if (fscanf(f, "%lf", &product->weight) != 1 || product->weight < 0)
        return SCANF_ERROR;

    if (fscanf(f, "%lf", &product->volume) != 1 || product->volume < 0)
        return SCANF_ERROR;

    fscanf(f, "\n");

    return EXIT_SUCCESS;
}

int read_products(FILE *f, product_array_t *products)
{
    size_t i = 0;
    int incr = 1;
    int rc = EXIT_SUCCESS;

    while ((rc = read_product(f, &products->product[i])) == EXIT_SUCCESS)
    {
        if (i == (size_t)(STRUCT_SIZE * incr - 1))
        {
            products->product = realloc(products->product, (STRUCT_SIZE * 2 * incr) * sizeof(product_t));
            incr++;
        }
    
        i++;
    }

    products->len = i;

    if (rc == SCANF_ERROR)
    {
        products->len++;
        return EXIT_FAILURE;
    }

    if (!i)
        return EXIT_FAILURE;

    if (rc != FEOF_ERROR)
        return EXIT_FAILURE;
    
    return EXIT_SUCCESS;
}

void print_product_info(product_t product)
{
    printf("%s\n", product.product_name);
    printf("%.6lf\n", product.weight);
    printf("%.6lf\n", product.volume);
}

void print_product(product_array_t products)
{
    for (size_t i = 0; i < products.len; i++)
        print_product_info(products.product[i]);
}
