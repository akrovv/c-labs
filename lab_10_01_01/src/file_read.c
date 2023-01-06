#define _GNU_SOURCE
#include "read.h"
#include "allocate.h"

static int read_object_name(FILE *f, node_t **node)
{
    size_t byte_len;
    char *university_name = NULL;

    if ((getline(&university_name, &byte_len, f)) == -1)
    {
        free(university_name);
        return EXIT_FAILURE;
    }
    
    if (!university_name)
        return EXIT_FAILURE;

    if (university_name[strlen(university_name) - 1] == '\n')
        university_name[strlen(university_name) - 1] = '\0';

    (*node)->next = allocate_node();
    (*node)->data = university_name;
    *node = (*node)->next;

    return EXIT_SUCCESS;
}



int file_read(FILE *f, node_t *node)
{
    while (read_object_name(f, &node) == EXIT_SUCCESS);
    
    return EXIT_SUCCESS;
}

