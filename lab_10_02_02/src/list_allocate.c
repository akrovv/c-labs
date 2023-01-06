#include "allocate.h"

node_t *allocate_node(void)
{
    node_t *node = malloc(sizeof(node_t));

    if (!node)
        return NULL;

    node->data = 0;
    node->next = NULL;

    return node;
}

void free_list(node_t *head)
{
    while (head)
    {
        node_t *tmp = head;
        head = head->next;
        free(tmp);
    }
}

