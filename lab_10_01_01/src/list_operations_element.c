#include "operations.h"

int comparator(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *))
{
    for (; head; head = head->next)
    {
        if (!comparator(head->data, data))
            return head;
    }

    return NULL;
}

void *pop_front(node_t **head)
{
    void *data = NULL;

    if (head && *head)
    {
        data = (*head)->data;
        node_t *tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }

    return data;
}

static node_t *get_pre_last(node_t *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    
    while (head->next->next)
        head = head->next;

    return head;
}

void *pop_back(node_t **head)
{
    void *data = NULL;

    if (head && *head)
    {
        node_t *previous = get_pre_last(*head);
        
        if (previous)
        {
            data = previous->next->data;
            free(previous->next);
            previous->next = NULL;
        }
        else
        {
            data = (*head)->data;
            free(*head);
            *head = NULL;
        }
    }

    return data; 
}

