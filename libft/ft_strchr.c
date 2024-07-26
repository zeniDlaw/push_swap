/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:20:30 by ichettri          #+#    #+#             */
/*   Updated: 2023/12/05 16:18:50 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	 The strchr() function locates the first occurrence of c (converted to a
     char) in the string pointed to by s.  The terminating null character is
     considered to be part of the string; therefore if c is `\0', the func-
     tions locate the terminating `\0'.

	RETURN VALUES
     The functions strchr() and strrchr() return a pointer to the located
     character, or NULL if the character does not appear in the string.
*/

// #include <stdio.h>
#include <stdlib.h>
// #include <string.h>

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	if (*s == (char)c)
		return (s);
	return (NULL);
}

// int	main(void)
// {
// 	char	src[] = "Hellocallum";
// 	char	s;
// 	char	*res;
// 	char *res1;
// 	s = 'u';
// 	res1 = ft_strchr(src, s);
// 	res = strchr(src, 'o');
// 	printf("%s\n", res);
// 	printf("%s\n", res1);
// 	return (0);
// }
