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
        if (ft_ispresent(temp, args, i))
            throw_error("Error: Something went wrong");
        if (temp < -2147483648 || temp > 2147483647)
            throw_error("Error: Something went wrong");
        i++;
    }
    if (argc == 2)
        ft_free(args);
}

void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

static void sort_stack(t_list **stackA, t_list **stackB)
{
    if (ft_lstsize(*stackA) <= 5)
        simpleSort(stackA, stackB);
    else
        radixSort(stackA, stackB);
}

void print_stack(t_list *head) {
    t_list *current = head;

    while (current != NULL) {
        ft_printf("%d ", current->value);
        current = current->next;
    }

    printf("\n");
}

int main(int argc, char **argv)
{
    t_list **stackA;
    t_list **stackB;

    if (argc < 2)
        ft_printf("Usuage: ./push_swap 98 66 56..\n");
    else
    {
        parse_input(argc, argv);
        stackA = (t_list **)malloc(sizeof(t_list));
        stackB = (t_list **)malloc(sizeof(t_list));
        *stackA = NULL;
        *stackB = NULL;
        initi_stacks(stackA, argc, argv);
        print_stack(*stackA);
        if (ft_issorted(stackA))
        {
            free_stack(stackA);
            free_stack(stackB);
            return (0);
        }
        sort_stack(stackA, stackB);
        print_stack(*stackA);
        free_stack(stackA);
        free_stack(stackB);
    }
    return (0);
}