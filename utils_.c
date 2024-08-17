#include <stdlib.h>
#include "ft_printf/libftprintf.h"
#include "libft/libft.h"
#include <limits.h>
#include "push_swap.h"

int ft_issorted(t_list **stack)
{
    t_list *head;

    head = *stack;
    while (head && head->next)
    {
        if (head->value > head->next->value)
            return (0);
        head = head->next;
    }
    return (1);
}

void ft_free(char **str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    while (i >= 0)
        free(str[i--]);
}

int find_distance(t_list **stack, int index)
{
    t_list *head;
    int distance;

    distance = 0;
    head = *stack;
    while (head)
    {
        if (head->index == index)
            break;
        distance++;
        head = head->next;
    }
    return (distance);
}

void make_top(t_list **stack, int distance)
{
    t_list *head;
    int temp;

    if (distance == 0)
        return;
    head = *stack;
    temp = ft_lstsize(head) - distance;
    if (distance <= (ft_lstsize(head) / 2))
    {
        while (distance-- > 0)
            ra(stack);
    }
    else
    {
        while (temp-- > 0)
            rra(stack);
    }
}
