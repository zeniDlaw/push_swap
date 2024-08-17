#include "push_swap.h"
#include "./ft_printf/libftprintf.h"

int swap(t_list **stack)
{
    t_list *head;
    t_list *next;
    int temp_value;
    int temp_index;

    if (ft_lstsize(*stack) < 2)
        return (-1);
    head = *stack;
    next = head->next;
    if (!head && !next)
        throw_error("Error: Somethiing went wrong while swapping!");
    temp_value = head->value;
    temp_index = head->index;
    head->value = next->value;
    head->index = next->index;
    next->value = temp_value;
    next->index = temp_index;
    return (0);
}

int sa(t_list **stackA)
{
    if (swap(stackA) == -1)
        return(-1);
    ft_printf("sa\n");
    return(0);
}

int sb(t_list **stackB)
{
    if (swap(stackB) == -1)
        return(-1);
    ft_printf("sb\n");
    return (0);
}

int ss(t_list **stackA, t_list **stackB)
{
    if ((ft_lstsize(*stackA) < 2) || (ft_lstsize(*stackB) < 2))
        return (-1);
    swap(stackA);
    swap(stackB);
    ft_printf("ss\n");
    return (0);
}

int push(t_list **dest, t_list **src)
{
    t_list *temp;
    t_list *head_dest;
    t_list *head_src;

    if (ft_lstsize(*src) == 0)
        return (-1);
    head_dest = *dest;
    head_src = *src;
    temp = head_src;
    head_src = head_src->next;
    *src = head_src;
    if (!head_dest)
    {
        head_dest = temp;
        head_dest->next = NULL;
        *dest = head_dest;
    }
    else
    {
        temp->next = head_dest;
        *dest = temp;
    }
    return (0);
}
