#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_List
{
    int     value;
    int     index;
    struct s_list *next;
}               t_list;

char *ft_strcat(char *dest, const char *src);
int token_counter(char *str);
char **split_quotes(char *str, int *token_count);
char **split_noquotes(int argc, char **argv, int *token_count);
int has_duplicate(t_stack *stack, int value);
int is_within_int(const char *str);
void free_tokens(char **tokens, int count);
int push(t_list **dest, t_list **src);

void rotate(t_stack *stack);
int sa(t_list **stackA);
int sb(t_stack **stackB)
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

void radixSort(t_stack *stackA, t_stack *stackB);

int ft_issorted(t_list **stack);

void stack_index(t_list **stack);

#endif

/** Stack Implementation Using Arrrays
 *  Simple and fast access to elements but fixed size,
 * which might waste memory or overflow.
 */