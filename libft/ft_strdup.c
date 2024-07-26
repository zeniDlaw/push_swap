/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:32:24 by ichettri          #+#    #+#             */
/*   Updated: 2023/12/05 19:41:22 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The strdup() function allocates sufficient memory for a copy of the
string s1, does the copy, and returns a pointer to it.  The pointer may
subsequently be used as an argument to the function free(3).
*/

// #include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char			*des;
	unsigned int	len;

	len = 0;
	while (src[len] != '\0')
		len++;
	des = (char *)malloc(sizeof(*des) * (len + 1));
	if (des == NULL)
		return (NULL);
	len = 0;
	while (src[len] != '\0')
	{
		des[len] = src[len];
		len++;
	}
	des[len] = '\0';
	return (des);
}

// int	main(void)
// {
// 	char	source[] = "bdasbdudbaudbdsddsadadadawd";
// 	char	*target;

// 	target = ft_strdup(source);
// 	printf("%s", target);
// 	return (0);
// }
