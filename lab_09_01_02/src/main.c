#include "utils.h"
#include "read.h"
#include "allocate.h"
#include "process.h"

int main(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
		return COUNT_ARGS_ERROR;

	FILE *f_src;
	product_array_t product_array;

	product_array.product = NULL;
	product_array.len = 0;

	f_src = fopen(argv[1], "r");

	if (!f_src)
		return FILE_OPEN_ERROR;

	if (allocate_struct(&product_array.product))
	{
		fclose(f_src);
		return ALLOCATE_ERROR;
	}
	if (read_products(f_src, &product_array))
	{
		struct_free(&product_array);
		fclose(f_src);
		return READ_PRODUCT_ERROR;
	}

	if (argc == 2)
	{
		selection_sort_by_density(&product_array);
		print_product(product_array);
	}
	else if (argc == 3 && !strcmp(argv[2], "ALL"))
		print_product(product_array);
	else if (strcmp("ALL", argv[2]))
		if (!search_name_by_substring(&product_array, argv[2]))
		{
			struct_free(&product_array);
			fclose(f_src);
			return NOT_FOUND_PRODUCT;
		}

	struct_free(&product_array);
	fclose(f_src);
	
	return EXIT_SUCCESS;
}
