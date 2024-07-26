/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:46:34 by ichettri          #+#    #+#             */
/*   Updated: 2023/12/05 19:48:45 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Description Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.

Return value: The trimmed string.
NULL if the allocation fails.
*/

#include "libft.h"
// #include <stdio.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimm;
	int		i;
	int		j;
	int		k;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (j > i && ft_strchr(set, s1[j]))
		j--;
	trimm = malloc(j - i + 2);
	if (!trimm)
		return (NULL);
	k = 0;
	while (i <= j)
		trimm[k++] = s1[i++];
	trimm[k] = '\0';
	return (trimm);
}

// int	main(void)
// {
// 	char	dst[] = " lorem ipsum dolor sit amet";
// 	char	*r;

// 	r = ft_strtrim(dst, "l ");
// 	printf("%s", r);
// 	return (0);
// }
