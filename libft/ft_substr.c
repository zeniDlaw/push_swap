/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:01:38 by ichettri          #+#    #+#             */
/*   Updated: 2023/12/08 20:32:01 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Description: Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’.

Return value: The substring.
NULL if the allocation fails.
*/

#include "libft.h"
// #include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = start;
	j = 0;
	while (s[i] && j < len)
		sub[j++] = s[i++];
	sub[j] = '\0';
	return (sub);
}

// int	main(void)
// {
// 	char	src[] = "Hello.bro.whats.up.bro";
// 	char	*dest;

// 	dest = ft_substr(src, 6, 3);
// 	printf("%s\n", dest);
// 	return (0);
// }
