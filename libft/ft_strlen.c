/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:52:35 by ichettri          #+#    #+#             */
/*   Updated: 2023/12/05 19:47:06 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The strlen() function computes the length of the string s.  The strnlen()
     function attempts to compute the length of s, but never scans beyond the
     first maxlen bytes of s.

RETURN VALUES
     The strlen() function returns the number of characters that precede the
     terminating NUL character.  The strnlen() function returns either the
     same result as strlen() or maxlen, whichever is smaller.
*/

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

// int	main(void)
// {
// 	char	s[] = "NAnaokay   lessgooo";

// 	printf("%d\n", ft_strlen(s));
//     printf("%lu\n",strlen(s));
// 	return (0);
// }
