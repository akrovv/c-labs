#include "read.h"
#include "allocate.h"

int list_number_read(node_t **head)
{  
    int n;
    int number;

    if (scanf("%d", &n) != 1)
        return EXIT_FAILURE;

    if (n <= 0)
        return EXIT_FAILURE;

    if (scanf("%d", &number) != 1)
        return EXIT_FAILURE;

    (*head)->data = number;

    n--;

    for (; n > 0; n--)
    {
        if (scanf("%d", &number) != 1)
            return EXIT_FAILURE;

        (*head)->next = allocate_node();
        *head = (*head)->next;
        (*head)->data = number;
    }

    return EXIT_SUCCESS;
}
