/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:25:53 by ichettri          #+#    #+#             */
/*   Updated: 2023/12/05 19:11:13 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The isalpha() function tests for any character for which isupper(3) or
     islower(3) is true.  The value of the argument must be representable as
     an unsigned char or the value of EOF.

RETURN VALUES
     The isalpha() function returns zero if the character tests false and
     returns non-zero if the character tests true.
*/

// #include <ctype.h>
// #include <stdio.h>

int	ft_isalpha(int a)
{
	int	i;

	if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122))
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

// 	c = 'z';
// 	printf("%d\n", ft_isalpha(c));
// 	printf("%d\n", isalpha(c));
// 	return (0);
// }
