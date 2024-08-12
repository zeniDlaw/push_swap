#include "push_swap.h"
#include "./ft_printf/libftprintf.h"

int pa(t_list **stackA, t_list **stackB)
{
    if (push(stackA, stackB) == -1)
        return (-1);
    ft_printf("pa\n");
    return (0);
}

int pb(t_list **stackA, t_list **stackB)
{
    if (push(stackA, stackB) == -1)
        return (-1);
    ft_printf("pb\n");
    return (0);
}

// Shift up all elements of a stack by 1. The first element becomes the last one | ra and rb

int rotate(t_list **stack)
{
    t_list *head;
    t_list *tail;
    
    if (ft_lstsize(*stack) < 2)
        return (-1);
    head = *stack;
    tail = ft_lstlast(head);
    *stack = head->next;
    head->next = NULL;
    tail->next = head;
    return (0);
}

int ra(t_list **stackA)
{
    if (rotate(stackA) == -1)
        return (-1);
    ft_printf("ra\n");
    return (0);
}

int rb(t_list **stackB)
{
    if (rotate(stackB) == -1);
        return (-1);
    ft_printf("rb\n");
    return (0);
}
