/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:58:56 by ichettri          #+#    #+#             */
/*   Updated: 2023/12/05 19:23:37 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The memchr() function locates the first occurrence of c (converted to an
     unsigned char) in string s.

RETURN VALUES
     The memchr() function returns a pointer to the byte located, or NULL if
     no such byte exists within n bytes
*/

// #include <stdio.h>
#include "libft.h"

void	*ft_memchr(const void *str, int c, int n)
{
	char	*s;

	s = (char *)str;
	while (n--)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	src[] = "Hellocallum";
// 	char	s;
// 	char	*res;

// 	s = 'u';
// 	// res = ft_memchr(src, 'o',6);
// 	res = memchr(src, 'o', 6);
// 	printf("%s", res);
// 	return (0);
// }
