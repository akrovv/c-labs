#include "operations.h"
#include "allocate.h"

static int get_len(node_t *head)
{
    int n = 0;

    for (; head->next; head = head->next)
        n++;

    return n;
}

int val_operation(node_t *head, int n)
{
    int len = get_len(head);
    int result = 0;

    for (; head; head = head->next, len--)
        result += head->data * pow(n, len);

    return result;
}

void ddx_operation(node_t *head)
{
    int len = get_len(head);

    for (; head->next; head = head->next, len--)
        head->data *= len;
}

node_t *sum_operation(node_t *head, node_t *new_head)
{
    node_t *result = allocate_node();
    node_t *head_result = result;
    int len = get_len(head);
    int new_len = get_len(new_head);

    while (len > new_len)
    {
        result->next = allocate_node();
        result->data = head->data;
        result = result->next;
        head = head->next;
        len--;
    }

    while (new_len > len)
    {
        result->next = allocate_node();
        result->data = new_head->data;
        result = result->next;
        new_head = new_head->next;
        new_len--;
    }

    for (; head; head = head->next, new_head = new_head->next, result = result->next)
    {
        result->data = head->data + new_head->data;
        result->next = allocate_node();
    }

    return head_result;
}

node_t *dvd_operation(node_t *head, bool even)
{
    node_t *parity_list = allocate_node();
    node_t *head_parity = parity_list;
    int len = get_len(head);

    for (; head; head = head->next, len--)
        if (len % 2 == 0 && even)
        {
            parity_list->data = head->data;
            parity_list->next = allocate_node();
            parity_list = parity_list->next;
        }
        else if (len % 2 == 1 && !even)
        {
            parity_list->data = head->data;
            parity_list->next = allocate_node();
            parity_list = parity_list->next;
        }

    return head_parity;
}
