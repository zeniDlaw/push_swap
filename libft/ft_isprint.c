/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:47:09 by ichettri          #+#    #+#             */
/*   Updated: 2023/12/05 19:16:18 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The isprint() function tests for any printing character, including space
     (` ').  The value of the argument must be representable as an unsigned
     char or the value of EOF.
RETURN VALUES
     The isprint() function returns zero if the character tests false and
     returns non-zero if the character tests true.
*/
// #include <ctype.h>
// #include <stdio.h>

int	ft_isprint(int c)
{
	int	i;

	if (c >= 32 && c <= 126)
	{
		i = 1;
	}
	else
	{
		i = 0;
	}
	return (i);
}

// int	main(void)
// {
// 	char	c;

// 	c = '(';
// 	printf("%d", ft_isprint(c));
// 	printf("%d", isprint('c'));
// 	return (0);
// }
