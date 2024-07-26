/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:33:47 by ichettri          #+#    #+#             */
/*   Updated: 2023/12/05 19:46:07 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
strlcat() appends string src to the end of dst.  It will append at most
     dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless
     dstsize is 0 or the original dst string was longer than dstsize (in prac-
     tice this should not happen as it means that either dstsize is incorrect
     or that dst is not a proper string).

     If the src and dst strings overlap, the behavior is undefined

RETURN VALUES: the strlcpy() and strlcat() functions return the total
     length of the string they tried to create.  For strlcpy() that means the
     length of src.  For strlcat() that means the initial length of dst plus
     the length of src.
*/

#include "libft.h"
// #include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		i;
	int		j;
	size_t	dst_length;
	size_t	src_length;

	src_length = ft_strlen(src);
	dst_length = ft_strlen(dst);
	i = 0;
	j = dst_length;
	if (dst_length < dstsize - 1 && dstsize > 0)
	{
		while (src[i] && dst_length + i < dstsize - 1)
		{
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = 0;
	}
	if (dst_length >= dstsize)
		dst_length = dstsize;
	return (dst_length + src_length);
}

// int	main(void)
// {
// 	char	src[20] = "abcd";
// 	char	dst[11];
// 	int		len1;

// 	dst[11] = 'a';
// 	// len1 = ft_strlcat(dst, "lorem", 15);
// 	// len1 = strlcat(dst, "lorem", 15);
// 	printf("%s\n", dst);
// 	printf("%d\n", len1);
// 	return (0);
// }
