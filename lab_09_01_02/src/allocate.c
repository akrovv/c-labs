#include "allocate.h"

int allocate_struct(product_t  **products)
{
    product_t *products_list = malloc(sizeof(product_t) * STRUCT_SIZE);

    if (!products_list)
        return EXIT_FAILURE;

    for (size_t i = 0; i < STRUCT_SIZE; i++)
    {
        products_list[i].volume = 0.0;
        products_list[i].weight = 0.0;
        products_list[i].product_name = NULL;
    }

    *products = products_list;

    return EXIT_SUCCESS;
}

void struct_free(product_array_t *products)
{
    for (size_t i = 0; i < products->len; i++)
        free(products->product[i].product_name);
    free(products->product);
}
