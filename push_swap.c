#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/libftprintf.h"

void initi_stacks(t_stack *stackA, t_stack *stackB)
{
    stackA->top = NULL;
    stackB->top = NULL;
}

int isEmpty(t_stack *stack)
{
    return(stack->top == NULL);
}

void push(t_stack *stack, int value)
{
    t_node *newNode;

    newNode = (t_node *)malloc(sizeof(t_node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

int is_validint(const char *str)
{
    long long result;
    int sign;

    result = 0;
    sign = 1;

    if (*str == '\0')
        return 0;
    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    else if (*str == '+')
    {
        sign = 1;
        str++;
    }
    if (*str == '\0')
        return (0);
    while (*str)
    {
        if (!ft_isdigit((unsigned char)*str))
            return(0);
        result = result * 10 + (*str - '0');
        if (sign == 1 && result > INT_MAX)
            return (0);
        if (sign == -1 && result < INT_MIN)
            return(0);
        str++;
    }
    return 1;
}

int pop(t_stack *stack)
{
    t_node *temp;
    int value;

    if (isEmpty(stack))
    {
        printf("Stack underflow\n");
        return (-1);
    }

    temp = stack->top;
    value = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return (value);
}

int peek(t_stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return (-1);
    }
    return (stack->top->data);
}

int is_space(char c)
{
    if (c == ' ')
        return (1);
    return(0);
}

int token_counter(char *str)
{
    int count;
    int in_quote;

    count = 0;
    in_quote = 0;
    while (*str)
    {
        while(is_space(*str))
            str++;
        if (*str == '"')
        {
            in_quote = !in_quote;
            str++;
        }
        if (*str && (!is_space(*str) || in_quote))
        {
            count++;
            while (*str && (!is_space(*str) || in_quote))
            {
                if (*str == '"')
                    in_quote = !in_quote;
                str++;
            }
        }
    }
    return (count);
}

void parsenstore(int argc, char **argv, t_stack *stackA)
{
    int token_count;
    char **tokens;
    char *input;
    int yes_quote;
    size_t total_len;
    int i;
    int j;
    int value;

    i = 1;
    value = 0;
    yes_quote = 0;
    while (i < argc)
    {
        if (ft_strchr(argv[i], '"'))
        {
            yes_quote = 1;
            break;
        }
        i++;
    }
    if (yes_quote)
    {
        total_len = 0;
        j = 1;
        while (j < argc)
        {
            total_len = total_len + ft_strlen(argv[i]) + 1;
            j++;
        }
        input = malloc(total_len);
        if (!input)
        {
            ft_putstr_fd("Failed to allocate memory", 2);
            exit(EXIT_FAILURE);
        }
        input[0] = '\0';
        i = 1;
        while (i < argc)
        {
            ft_strcat(input, argv[i]);
            if (i < argc - 1)
                ft_strcat(input, " ");
        }
        tokens = split_quotes(input, &token_count);
        free(input);
    }
    else
        tokens = split_noquotes(argc, argv, &token_count);
    i = 0;
    while (i < token_count)
    {
        if (!is_validint(tokens[i]))
        {
            ft_printf("Invalid input: %s\n", tokens[i]);
            free_tokens(tokens, token_count);
            exit(EXIT_FAILURE);
        }
        value = ft_atoi(tokens[i]);
        push(stackA, value);
    }
    free_tokens(tokens, token_count);
}

void print_stack(t_stack *stack) 
{
    t_node *current = stack->top;
    printf("Stack: ");
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    t_stack stackA;
    t_stack stackB;

    if (argc < 2)
        ft_printf("Usuage: ./push_swap ............\n");
    else
    {
        initi_stacks(&stackA, &stackB);
        parsenstore(argc, argv, &stackA);
        print_stack(&stackA);
    }
    return (0);
}