#include "utils.h"
#include "read.h"
#include "allocate.h"
#include "operations.h"
#include "print.h"

int main(void)
{
	char command[CMD_LEN + 1];

	if (fgets(command, CMD_LEN + 1, stdin) == NULL)
		return READ_CMD_ERROR;

	if (command[strlen(command) - 1] == '\n')
		command[strlen(command) - 1] = '\0';

	if (strlen(command) >= CMD_LEN)
		return MAX_LEN_ERROR;

	if (strcmp(command, "val") && strcmp(command, "ddx") && strcmp(command, "sum") && strcmp(command, "dvd"))
		return CMD_NOT_FIND;

	node_t *list = allocate_node();
	node_t *head = list;
	node_t *new_list = allocate_node();
	node_t *new_head = new_list;

	if (list_number_read(&list))
	{
		free_list(head);
		free_list(new_list);
		return LIST_NOT_READABLE;
	}

	if (!strcmp(command, "val"))
	{
		int n;
			
		if (scanf("%d", &n) != 1)
		{
			free_list(head);
			free_list(new_head);
			head = NULL;
			new_head = NULL;
			return SCAN_ERROR;
		}

		printf("%d\n", val_operation(head, n));
	}
	else if (!strcmp(command, "ddx"))
	{
		ddx_operation(head);
		print_list(head);
	}
	else if (!strcmp(command, "sum"))
	{
		node_t *result = NULL;
		if (list_number_read(&new_list))
		{
			free_list(head);
			free_list(new_head);
			head = NULL;
			new_head = NULL;
			return LIST_NOT_READABLE;
		}
		result = sum_operation(head, new_head);
		print_list(result);
		free_list(result);
	}
	else if (!strcmp(command, "dvd"))
	{
		node_t *result = NULL;
		result = dvd_operation(head, true);
		print_list(result);
		free_list(result);
		result = dvd_operation(head, false);
		print_list(result);
		free_list(result);
	}

	free_list(head);
	free_list(new_head);

	return EXIT_SUCCESS;
}
