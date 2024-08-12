#include "push_swap.h"

static t_list *getnextmin(t_list **stack)
{
    t_list *head;
    t_list *min;
    int is_min;

    min = NULL;
    is_min = 0;
    head = *stack;
    if (head)
    {
        while (head)
        {
            if ((head->index == -1) && (!is_min || head->value < min->value))
            {
                min = head;
                is_min = 1;
            }
            head = head->next; 
        }
    }
    return (min);
}

void stack_index(t_list **stack)
{
    t_list *head;
    int index;

    index = 0;
    head = getnextmin(stack);
    while (head)
    {
        head->index = index++;
        head = getnextmin(stack);
    }
}

