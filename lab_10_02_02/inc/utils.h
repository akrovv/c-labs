#ifndef __UTILS_H__

#define __UTILS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMD_LEN 4

#define READ_CMD_ERROR 1
#define MAX_LEN_ERROR 2
#define CMD_NOT_FIND 3
#define SCAN_ERROR 4
#define LIST_NOT_READABLE 5

typedef struct node
{
    int data;
    struct node *next;
} node_t;


#endif
