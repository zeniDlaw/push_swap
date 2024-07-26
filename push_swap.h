#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>

typedef struct s_node
{
    int data;
    struct s_node *next;   
}               t_node;

typedef struct s_stack
{
    t_node *top;
}           t_stack;


char *ft_strcat(char *dest, const char *src);
int token_counter(char *str);
char **split_quotes(char *str, int *token_count);
char **split_noquotes(int argc, char **argv, int *token_count);
void free_tokens(char **tokens, int count);

#endif

/** Stack Implementation Using Arrrays
 *  Simple and fast access to elements but fixed size,
 * which might waste memory or overflow.
 */