#include "push_swap.h"
#include "./ft_printf/libftprintf.h"

int rr(t_list **stackA, t_list **stackB)
{
    if ((ft_lstsize(*stackA) < 2) || (ft_lstsize(*stackB) < 2))
        return (-1);
    rotate(stackA);
    rotate(stackB);
    ft_printf("rr\n");
    return (0);
}

// Shifts down all elements of a stack by 1. The last element becomes the first one | rra and rrb

int reverse_rotate(t_list **stack)
{
    t_list *head;
    t_list *tail;

    if (ft_lstsize(*stack) < 2)
        return (-1);
    head = *stack;
    tail = ft_lstlast(head);
    while (head)
    {
        if (head->next->next == NULL)
        {
            head->next = NULL;
            break;
        }
        head = head->next;
    }
    tail->next = *stack;
    *stack = tail;
    return (0);
}

int  rra(t_list **stackA)
{
    if (reverse_rotate(stackA) == -1)
        return (-1);
    ft_printf("rra\n");
    return (0);
}

int  rrb(t_list **stackB)
{
    if (reverse_rotate(stackB) == -1)
        return (-1);
    ft_printf("rrb\n");
    return (0);
}

int rrr(t_list **stackA, t_list **stackB)
{
    if ((ft_lstsize(*stackA) < 2) || (ft_lstsize(*stackB) < 2))
        return (-1);
    reverse_rotate(stackA);
    reverse_rotate(stackB);
    ft_printf("rrr\n");
    return (0);
}
