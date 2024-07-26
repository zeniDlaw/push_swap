/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:56:08 by ichettri          #+#    #+#             */
/*   Updated: 2023/12/05 19:52:32 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
		The bzero() function writes n zeroed bytes to the string s.  If n is
		zero, bzero() does nothing.
*/

// #include <stdio.h>
#include <stdlib.h>

// #include <strings.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*p;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}

// int	main(void)
// {
// 	int j;
// 	int	s[] = {1, 2, 3, 4, 5};
// 	int	s1[] = {1, 2, 3, 4, 5};

// 	j = 0;
// 	ft_bzero(s1, 4);
// 	bzero(s, 4);
// 	while(s[j] != '\0')
// 		printf("%d",s1[j]);
// 		j++;

// 	return (0);
// }
