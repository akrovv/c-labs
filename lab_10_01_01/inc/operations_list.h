#ifndef __OPERATIONS_LIST_H__
#define __OPERATIONS_LIST_H__

#include "utils.h"

void list_free(node_t **head);
int copy(node_t *head, node_t **new_head);
void append(node_t **head_a, node_t **head_b);
node_t *sort(node_t *head, int (*comparator)(const void *, const void *));
void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *));

#endif

