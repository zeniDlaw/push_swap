/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:56:37 by ichettri          #+#    #+#             */
/*   Updated: 2023/12/05 20:16:47 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
		The memset() function writes len bytes of value c (converted to an
		unsigned char) to the string b.

RETURN VALUES
		The memset() function returns its first argument.
*/

#include "libft.h"

// #include <stdio.h>
// #include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = b;
	while (len > 0)
	{
		*ptr = (unsigned char)c;
		ptr++;
		len--;
	}
	return (b);
}

// int	main(void)
// {
// 	char	str[10];
// 	char	str1[10];

// 	ft_memset(str1, 'A', 8);
//  memset(str, 'A', 10);
// 	printf("%s\n", str1);
// 	return (0);
// }
