#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/libftprintf.h"

static void initi_stacks(t_list **stack, int argc, char **argv)
{
    t_list *new;
    char **args;
    int i;

    i = 0;
    if (argc == 2)
        args = ft_split(argv[1], ' ');
    else
    {
        i = 1;
        args = argv;
    }
    while (args[i])
    {
        new = ft_lstnew(ft_atoi(args[i]));
        ft_lstadd_back(stack, new);
        i++;
    }
    stack_index(stack);
    if (argc == 2)
        ft_free(args);
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

int is_valid_integer(const char *str) {
    if (*str == '\0') {
        return 0;
    }
    if (*str == '-' || *str == '+') {
        str++;
    }
    if (*str == '\0') {
        return 0;
    }
    while (*str) {
        if (!ft_isdigit(*str)) {
            return 0;
        }
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

void throw_error(char *str)
{
    ft_putendl_fd(str, 1);
    exit(0);
}

static int ft_ispresent(int num, char **argv, int i)
{
    i++;
    while (argv[i])
    {
        if (ft_atoi(argv[i]) == num)
            return (1);
        i++;
    }
    return (0);
}

static int ft_isnum(char *num)
{
    int i;

    i = 0;
    if (num[0] == '-')
        i++;
    while (num[i])
    {
        if (!ft_isdigit(num[i]))
            return(0);
        i++;
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

void parse_input(int argc, char **argv)
{
    int i;
    long temp;
    char **args;

    i = 0;
    if (argc == 2)
        args = ft_split(argv[1], ' ');
    else
    {
        i = 1;
        args = argv;
    }
    while (args[i])
    {
        temp = ft_atoi(args[i]);
        if (!ft_isnum(args[i]))
            throw_error("Error: Something went wrong");
        if (!ft_ispresent(temp, args, i))
            throw_error("Error: Something went wrong");
        if (temp < -2147483648 || temp > 2147483647)
            throw_error("Error: Something went wrong");
        i++;
    }
    if (argc == 2)
        ft_free(args);
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

void free_stack(t_stack *stack) {
    t_node *current = stack->top;
    t_node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    stack->top = NULL;
}

static void sort_stack(t_list **stackA, t_list **stackB)
{
    if (ft_lstsize(*stackA) <= 5)
        simpleSort(stackA, stackB);
    else
        radixSort(stackA, stackB);
}

int main(int argc, char **argv)
{
    t_list **stackA;
    t_list **stackB;

    if (argc < 2)
        ft_printf("Usuage: ./push_swap ............\n");
    else
    {
        parse_input(&stackA, argc, argv);
        stackA = (t_list **)malloc(sizeof(t_list));
        stackB = (t_list **)malloc(sizeof(t_list));
        *stackA = NULL;
        *stackB = NULL;
        initi_stacks(&stackA, &stackB);
        if (ft_issorted(stackA))
        {
            free_stack(stackA);
            free_stack(stackB);
            return (0);
        }
        sort_stack()
    }
    return (0);
}