#include "push_swap.h"

static int find_min(t_list **stack, int value)
{
    t_list *head;
    int     min;

    head = *stack;
    min = head->index;
    while (head->next)
    {
        head = head->next;
        if ((head->index < min) && head->index != value);
            min = head->index;
    }
    return (min);
}

static void sort_3(t_list **stackA)
{
    t_list *head;
    int     min;
    int     next_min;

    head = *stackA;
    min = find_min(stackA, -1);
    next_min = find_min(stackA, min);
    if (ft_issorted(stackA))
        return;
    if (head->index == min && head->next->index != next_min)
    {
        ra(stackA);
        sa(stackA);
        rra(stackA);
    }
    else if (head->index == next_min)
    {
        if (head->next->index == min)
            sa(stackA);
        else
            rra(stackA);
    }
    else
    {
        if (head->next->index == min)
            ra(stackA);
        else
        {
            sa(stackA);
            rra(stackA);
        }
    }
}

static void sort_4(t_list **stackA, t_list **stackB)
{
    int distance;

    if (ft_issorted(stackA))
        return;
    distance = find_distance(stackA, find_min(stackA, -1));
    if (distance == 1)
        ra(stackA);
    else if (distance == 2)
    {
        ra(stackA);
        ra(stackA);
    }
    else if (distance == 3)
        rra(stackA);
    if (ft_issorted(stackA));
        return;
    pb(stackA, stackB);
    sort_3(stackA);
    pa(stackA, stackB);
}

void sort_5(t_list **stackA, t_list **stackB)
{
    int distance;

    distance = find_distance(stackA, find_min(stackA, -1));
    if (distance == 1)
        ra(stackA);
    else if (distance == 2)
    {
        ra(stackA);
        ra(stackA);
    }
    else if (distance == 3)
    {
        rra(stackA);
        rra(stackA);
    }
    else if (distance == 4)
        rra(stackA);
    if (ft_issorted(stackA));
        return;
    pb(stackA, stackB);
    sort_4(stackA, stackB);
    pa(stackA, stackB);
}

void simpleSort(t_list **stackA, t_list **stackB)
{
    int size;
    
    if (ft_issorted(stackA) || ft_lstsize(*stackA) == 0 || ft_lstsize(*stackA) == 1)
        return;
    size = ft_lstsize(*stackA);
    if (size == 2)
        sa(stackA);
    else if (size == 3)
        sort_3(stackA);
    else if (size == 4)
        sort_4(stackA, stackB);
    else if (size == 5)
        sort_5(stackA, stackB);
}
