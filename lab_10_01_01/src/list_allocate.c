#include "allocate.h"

node_t *allocate_node(void)
{
    node_t *node = malloc(sizeof(node_t));

    if (!node)
        return NULL;

    node->data = NULL;
    node->next = NULL;

    return node;
}

