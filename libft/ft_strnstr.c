/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:26:49 by ichettri          #+#    #+#             */
/*   Updated: 2023/12/05 17:21:42 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The	strnstr(void) function locates the first occurrence of the null-termi-
		nated string needle in the string haystack,
			where not more than len char-
		acters are searched.  Characters that appear after a `\0' character are
		not searched.

If needle is an empty string, haystack is returned; if needle occurs
		nowhere in haystack, NULL is returned; otherwise a pointer to the first
		character of the first occurrence of needle is returned.
*/

#include "libft.h"

// #include <stdio.h>
// #include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	flag;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		flag = i;
		while (haystack[flag] == needle[j] && flag < len)
		{
			flag++;
			j++;
			if (!needle[j])
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	src[] = "mybaby";
// 	char	dst[] = "no";
// 	char	*ptr;

// 	ptr = ft_strnstr(src, "bab", 5);
// 	// ptr = strnstr(src, "bab", 5);
// 	printf("%s\n", ptr);
// 	return (0);
// }
