/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:59:54 by ichettri          #+#    #+#             */
/*   Updated: 2023/12/05 16:28:39 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The strrchr() function is identical to strchr(), except it locates the
		last occurrence of c.

	RETURN VALUES
		The functions strchr() and strrchr() return a pointer to the located
		character, or NULL if the character does not appear in the string
*/

#include "libft.h"

// #include <stdio.h>
// #include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	src[] = "Hullocallum";
// 	char	s;
// 	char	*res;

// 	s = 'u';
// 	// res = ft_strrchr(src, s);
// 	res = strrchr(src, 'u');
// 	printf("%s", res);
// 	return (0);
// }
