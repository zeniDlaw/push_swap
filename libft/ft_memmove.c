/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:45:38 by ichettri          #+#    #+#             */
/*   Updated: 2023/12/05 20:14:47 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The memmove() function copies len bytes from string src to string dst.
     The two strings may overlap; the copy is always done in a non-destructive
     manner.
	
RETURN VALUES
     The memmove() function returns the original value of dst.
*/

#include <stdlib.h>
// #include <string.h>

static void	condition(char *st1, char *st2, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		st1[i] = st2[i];
		i++;
	}
}

void	*ft_memmove(void *str1, const void *str2, int n)
{
	char	*st1;
	char	*st2;

	st1 = (char *)str1;
	st2 = (char *)str2;
	if (st1 == NULL && st2 == NULL)
		return (NULL);
	if (st1 < st2)
	{
		condition(st1, st2, n);
	}
	else
	{
		while (n > 0)
		{
			st1[n - 1] = st2[n - 1];
			n--;
		}
	}
	return (str1);
}

// int	main(void)
// {
// 	char	str[20] = "Hello world";
// 	char	buffer[20];

// 	ft_memmove(buffer, str + 7, 7);
// 	// memmove(buffer, str + 7, 7);
// 	printf("Copied substring %s\n", buffer);
// 	return (0);
// }
