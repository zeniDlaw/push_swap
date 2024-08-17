#include "push_swap.h"

static int getmaxbits(t_list **stack)
{
    t_list *head;
    int max;
    int max_bits;

    head = *stack;
    max = head->index;
    max_bits = 0;
    while (head)
    {
        if (head->index > max)
            max = head->index;
        head = head->next;
    }
    while ((max >> max_bits) != 0)
        max_bits++;
    return (max_bits);
}

void radixSort(t_list **stackA, t_list **stackB)
{
    t_list *headA;
    int i;
    int j;
    int size;
    int max_bits;

    i = 0;
    headA = *stackA;
    size = ft_lstsize(headA);
    max_bits = getmaxbits(stackA);
    while (i < max_bits)
    {
        j = 0;
        while (j++ < size)
        {
            headA = *stackA;
            if (((headA->index >> i) & 1) == 1)
                ra(stackA);
            else
                pb(stackA, stackB);
        }
        while (ft_lstsize(*stackB) != 0)
            pa(stackA, stackB);
        i++;
    }
}
