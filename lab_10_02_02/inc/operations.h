#ifndef __OPERATIONS_H__
#define __OPERATIONS_H__

#include "utils.h"
#include <math.h>
#include <stdbool.h>

int val_operation(node_t *head, int n);
void ddx_operation(node_t *head);
node_t *sum_operation(node_t *head, node_t *new_head);
node_t *dvd_operation(node_t *head, bool even);

#endif
