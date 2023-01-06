#include "process.h"

int selection_sort_by_density(product_array_t *products)
{
	for (size_t i = 0; i < products->len - 1; i++)
	{
		size_t min = i;
		double density_min = products->product[min].weight / products->product[min].volume;

		for (size_t j = i + 1; j < products->len; j++)
		{
			double density = products->product[j].weight / products->product[j].volume;

			if (density_min > density)
			{
				min = j;
				density_min = density;
			}
		}

		if (min != i)
		{
			product_t tmp = products->product[min];
			products->product[min] = products->product[i];
			products->product[i] = tmp;
		}
	}

	return EXIT_SUCCESS;
}

int search_name_by_substring(product_array_t *products, char substring[])
{
	size_t counter = 0;
	for (size_t i = 0; i < products->len; i++)
	{
		char *string = strstr(products->product[i].product_name, substring);
		if (string != NULL && strlen(string) == strlen(products->product[i].product_name))
		{
			print_product_info(products->product[i]);
			counter++;
		}
	}

	return counter;
}
