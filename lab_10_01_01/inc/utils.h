#ifndef __UTILS_H__

#define __UTILS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOO_FEW_PARAMS 1
#define FILE_OPEN_ERROR 2
#define FILE_CREATE_ERROR 3
#define NOT_FIND 4

typedef struct node
{
    void *data;
    struct node *next;
} node_t;


#endif
