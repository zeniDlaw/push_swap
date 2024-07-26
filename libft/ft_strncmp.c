/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:25:36 by ichettri          #+#    #+#             */
/*   Updated: 2023/12/05 17:54:39 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The	strncmp(void) function compares not more than n characters.  Because
		strncmp() is designed for comparing strings rather than binary data,
		characters that appear after a `\0' character are not compared

 The strcmp() and strncmp() functions return an integer greater than,
		equal to, or less than 0, according as the string s1 is greater than,
		equal to, or less than the string s2.  The comparison is done using
		unsigned characters, so that `\200' is greater than `\0'.
*/

// #include <stdio.h>
// #include <string.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && str1[i] && str2[i] && i < n - 1)
		i++;
	return (str1[i] - str2[i]);
}

// int	main(void)
// {
// 	// char	s1[] = "abcdef";
// 	// char	s2[] = abc\375xx"";

// 	printf("%d\n",ft_strncmp("abcdef", "abc\375xx", 5));
// 	return (0);
// }
