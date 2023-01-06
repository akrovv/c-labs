#include "utils.h"
#include "operations.h"
#include "operations_list.h"
#include "allocate.h"
#include "read.h"

int main(int argc, char **argv)
{
	if (argc < 4)
		return TOO_FEW_PARAMS;
	
	FILE *f_src = fopen(argv[1], "r");

	if (!f_src)
		return FILE_OPEN_ERROR;

	FILE *f_dst = fopen(argv[3], "w");

	if (!f_dst)
	{
		fclose(f_src);
		return FILE_CREATE_ERROR;
	}

	node_t *list = allocate_node();
	node_t *head = list;

	file_read(f_src, list);

	if (!strcmp("f", argv[2]))
	{
		if (argv[4][strlen(argv[4]) - 1] == '\n')
			argv[4][strlen(argv[4]) - 1] = '\0';

		node_t *answer = find(head, argv[4], comparator);
		if (answer)
			fprintf(f_dst, "%s\n", (char *)answer->data);
		else
		{
			fprintf(f_dst, "Элемент не найден\n");
			list_free(&head);
			fclose(f_src);
			fclose(f_dst);
			return NOT_FIND;
		}
	}
	else if (!strcmp("pf", argv[2]))
		fprintf(f_dst, "%s\n", (char *)pop_front(&head));
	else if (!strcmp("pb", argv[2]))
		fprintf(f_dst, "%s\n", (char *)pop_back(&head));
	else if (!strcmp("cp", argv[2]))
	{
		node_t *new_head = NULL;
		copy(head, &new_head);
		list_free(&new_head);
	}
	else if (!strcmp("ap", argv[2]))
	{
		if (argv[4][strlen(argv[4]) - 1] == '\n')
			argv[4][strlen(argv[4]) - 1] = '\0';

		char *word = argv[4];

		node_t *test = allocate_node();
		test->data = word;
		test->next = NULL;

		append(&head, &test);
	}
	else if (!strcmp("s", argv[2]))
	{
		node_t *res = NULL; 
		res = sort(head, comparator);

		fprintf(f_dst, "%s\n", (char *)res->data);
	}
	
	fclose(f_src);
	fclose(f_dst);

	list_free(&head);

	return EXIT_SUCCESS;
}
