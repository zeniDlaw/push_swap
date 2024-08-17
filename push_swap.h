#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>

typedef struct s_list
{
    int     value;
    int     index;
    struct s_list *next;
}               t_list;

void stack_index(t_list **stack);

t_list	*ft_lstnew(int value);
int	ft_lstsize(t_list *head);
t_list	*ft_lstlast(t_list *head);
void	ft_lstadd_front(t_list **stack, t_list *new);
void	ft_lstadd_back(t_list **stack, t_list *new);

int push(t_list **dest, t_list **src);
int sa(t_list **stackA);
int sb(t_list **stackB);
int ss(t_list **stackA, t_list **stackB);
int pa(t_list **stackA, t_list **stackB);
int pb(t_list **stackA, t_list **stackB);
int rotate(t_list **stack);
int ra(t_list **stackA);
int rb(t_list **stackB);
int rr(t_list **stackA, t_list **stackB);
int reverse_rotate(t_list **stack);
int  rra(t_list **stackA);
int  rrb(t_list **stackB);
int rrr(t_list **stackA, t_list **stackB);

void simpleSort(t_list **stackA, t_list **stackB);
void radixSort(t_list **stackA, t_list **stackB);

int find_distance(t_list **stack, int index);
int ft_issorted(t_list **stack);
void ft_free(char **str);
void stack_index(t_list **stack);
void throw_error(char *str);

void stack_index(t_list **stack);

#endif

/** Stack Implementation Using Arrrays
 *  Simple and fast access to elements but fixed size,
 * which might waste memory or overflow.
 */