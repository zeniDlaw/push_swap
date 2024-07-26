/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:02:15 by ichettri          #+#    #+#             */
/*   Updated: 2023/12/05 17:33:52 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
strlcpy() copies up to dstsize - 1 characters from the string src to dst,
     NUL-terminating the result if dstsize is not 0.
*/

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

int	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		if (dstsize > 0)
			dst[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}

// int	main(void)
// {
// 	char	dub[11];
// 	int		len1;
// 	int		len;
// 	char	ori[] = "HelloWorld";

// 	dub[11] = 'a';
// 	// len = ft_strlcpy(dub, "lorem ipsum dolor sit amet", 15);
// 	len1 = strlcpy(dub, "lorem", 15);
// 	printf("Copied: %s\n", dub);
// 	printf("Length: %d\n", len1);
// 	return (0);
// }
