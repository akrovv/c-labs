#ifndef __OPERATIONS_H__
#define __OPERATIONS_H__

#include "utils.h"

node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *));
int comparator(const void *a, const void *b);
void *pop_front(node_t **head);
void *pop_back(node_t **head);
void insert(node_t **head, node_t *elem, node_t *before);

#endif 
