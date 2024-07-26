/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:37:39 by ichettri          #+#    #+#             */
/*   Updated: 2023/11/13 12:44:17 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The isascii() function tests for an ASCII character, which is any charac-
     ter between 0 and octal 0177 inclusive.

*/

// #include <ctype.h>
// #include <stdio.h>

int	ft_isascii(int c)
{
	int	i;

	if (c >= 0 && c <= 0177)
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

// 	c = '+';
// 	printf("%d", ft_isascii(c));
// 	printf("%d", isascii(c));
// 	return (0);
// }
