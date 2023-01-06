#include "operations_list.h"
#include "operations.h"

static node_t *create_node(void *data)
{
    node_t *tmp = malloc(sizeof(node_t));

    if (!tmp)
        return NULL;

    tmp->data = data;
    tmp->next = NULL;

    return tmp;
}

static node_t *list_push(node_t **head, node_t *node)
{
    node->next = (*head);
    (*head) = node;

    return *head;
}

void list_free(node_t **head)
{
    while ((*head)->next)
        pop_front(head);

    free(*head);
}

int copy(node_t *head, node_t **new_head)
{
    if (!head)
        return EXIT_FAILURE;

    node_t *tmp = create_node(head->data);

    if (!tmp)
        return EXIT_FAILURE;

    head = head->next;

    for (; head; head = head->next)
    {
        node_t *node = create_node(head->data);
        if (!node)
        {
            list_free(&tmp);
            return EXIT_FAILURE;
        }
        if (!list_push(&tmp, node))
        {
            list_free(&tmp);
            return EXIT_FAILURE;
        }
    }

    *new_head = create_node(tmp->data); 
    node_t *cur = tmp->next;

    for (; cur; cur = cur->next)
    {
        node_t *node = create_node(cur->data);
        if (!node)
        {
            list_free(&tmp);
            list_free(new_head);
            return EXIT_FAILURE;
        }
        if (!list_push(new_head, node))
        {
            list_free(&tmp);
            list_free(new_head);
            return EXIT_FAILURE;
        }
    }
    list_free(&tmp); 

    return EXIT_SUCCESS;
}

void append(node_t **head_a, node_t **head_b)
{
    if (!(*head_a))
        *head_a = *head_b;
    else if (*head_b)
    {
        node_t *cur = *head_a;
        
        for (; cur->next; cur = cur->next);

        cur->next = *head_b;
    }
    
    *head_b = NULL;
}

node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    node_t *sort = NULL;
    
    while (head)
    {
        node_t *node = head;
        head = head->next;
        sorted_insert(&sort, node, comparator);
    }

    return sort;
}

void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *))
{
    node_t *cur = *head;
    node_t *prev = NULL;
    element->next = NULL;

    if (!cur)
        *head = element;
    else
    {
        while (cur && comparator(cur->data, element->data) < 0)
        {
            prev = cur;
            cur = cur->next;
        }

        if (prev)
            prev->next = element;
        else
            *head = element;

        element->next = cur;
    }
}
