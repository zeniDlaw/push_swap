/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:40:52 by ichettri          #+#    #+#             */
/*   Updated: 2023/12/09 15:29:43 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer.

Return value: The array of new strings resulting from the split.
NULL if the allocation fails.
*/

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_wordlen(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	if (s[i] && s[i] != c)
		count++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] && s[i + 1] != c)
			count++;
		i++;
	}
	return (count);
}

char	**ft_freesplt(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return (NULL);
}

static char	**process(char const *s, char **arr, char c)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		flag = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > flag)
		{
			arr[j] = ft_substr(s, flag, i - flag);
			if (arr[j++] == NULL)
				return (ft_freesplt(arr));
		}
	}
	arr[j] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char		**split;
	const char	*d;

	d = s;
	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (ft_wordlen(s, c) + 1));
	if (!split)
		return (NULL);
	split = process(d, split, c);
	return (split);
}

// int	main(void)
// {
// 	char	**split;
// 	int		i;

// 	i = 0;
// 	split = ft_split("4 4rtrt     r    7x  brott.whats.up.bro", '.');
// 	while (split[i])
// 		printf("%s\n", split[i++]);
// 	ft_freesplt(split);
// 	return (0);
// }
