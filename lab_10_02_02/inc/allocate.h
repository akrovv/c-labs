#ifndef __ALLOCATE_H__
#define __ALLOCATE_H__

#include "utils.h"

node_t *allocate_node(void);
void free_list(node_t *head);

#endif
