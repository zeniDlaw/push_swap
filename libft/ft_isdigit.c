/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:34:42 by ichettri          #+#    #+#             */
/*   Updated: 2023/12/05 19:13:38 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The isdigit() function tests for a decimal digit character.  Regardless
     of locale, this includes the following characters only:

     ``0''         ``1''         ``2''         ``3''         ``4''
     ``5''         ``6''         ``7''         ``8''         ``9''

RETURN VALUES
     The isdigit() and isnumber() functions return zero if the character tests
     false and return non-zero if the character tests true.

*/
// #include <ctype.h>
// #include <stdio.h>

int	ft_isdigit(int c)
{
	int	i;

	if (c >= 48 && c <= 57)
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
// 	char d;

// 	d = '2';
// 	printf("%d\n", ft_isdigit(d));
// 	printf("%d\n", isdigit(d));
// 	return (0);
// }
