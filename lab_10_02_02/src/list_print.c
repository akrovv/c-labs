#include "print.h"

void print_list(node_t *head)
{
    for (; head->next; head = head->next)
        printf("%d ", head->data);

    printf("L\n");
}
