#include <stdlib.h>
#include <stdbool.h>
#include "ft_printf/libftprintf.h"
#include "libft/libft.h"
#include "push_swap.h"

char *ft_strcat(char *dest, const char *src) 
{
    char *dest_end;
    dest_end = dest;
    while (*dest_end != '\0') {
        dest_end++;
    }
    while (*src != '\0') {
        *dest_end = *src;
        dest_end++;
        src++;
    }

    *dest_end = '\0';

    return dest;
}

void free_tokens(char **tokens, int count)
{
    int i;

    i = 0;
    while (i < count)
    {
        free(tokens[i]);
        i++;
    }
    free(tokens);
}

char *ft_strncpy(char *dest, const char *src, size_t n) 
{
    size_t i;

    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }

    for (; i < n; i++) {
        dest[i] = '\0';
    }

    return dest;
}

char **split_quotes(char *str, int *token_count)
{
    int in_quote;
    int token_index;
    int len;
    const char *start;

    in_quote = 0;
    token_index = 0;
    len = 0;
    start = NULL;
    *token_count = token_counter(str);
    char **tokens;

    tokens = malloc(*token_count * sizeof(char *));
    if (!tokens)
    {
        ft_putstr_fd("Memory Allocation Failed for Tokens\n", 2);
        exit(EXIT_FAILURE);
    }
    while (*str)
    {
        if (*str == '"')
        {
            in_quote = !in_quote;
            if (!in_quote && start)
            {
                len = str - start;
                tokens[token_index] = (char *)malloc(len + 1);
                if (!tokens[token_index])
                {
                    ft_putstr_fd("Failed Memory Allocation\n", 2);
                    exit(EXIT_FAILURE);
                }
                ft_strncpy(tokens[token_index], start, len);
                tokens[token_index][len] = '\0';
                token_index++;
                start = NULL;
            }
            else if (!start)
                start = str;
            str++;
        }
        if (start)
        {
            len = 0;
            len = str - start;
            tokens[token_index] = (char *)malloc(len + 1);
            if (!tokens[token_index])
            {
                ft_putstr_fd("Faild Memory Allocation\n", 2);
                exit(EXIT_FAILURE);
            }
            ft_strncpy(tokens[token_index], start, len);
            tokens[token_index][len] = '\0';
        }
    }
    return (tokens);
}

char **split_noquotes(int argc, char **argv, int *token_count)
{
    int i;
    char **tokens;

    i = 1;
    tokens = malloc(sizeof(char *) * (argc - 1));
    while (i < argc)
    {
        tokens[i - 1] = ft_strdup(argv[i]);
        i++;
    }
    *token_count = argc - 1;
    return (tokens);
}
