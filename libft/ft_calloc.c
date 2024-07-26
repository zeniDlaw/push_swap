/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:17:21 by ichettri          #+#    #+#             */
/*   Updated: 2023/12/05 19:08:54 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 The calloc() function contiguously allocates enough space for count
     objects that are size bytes of memory each and returns a pointer to the
     allocated memory.  The allocated memory is filled with bytes of value
     zero
RETURN VALUES
     If successful, calloc(), return a pointer to allocated memory.  If there
     is an error, they return a NULL pointer and set errno to ENOMEM.
*/

#include "libft.h"
// #include <stdio.h>
#include <stdlib.h>

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == 0)
		return (ptr);
	ft_bzero(ptr, count * size);
	return (ptr);
}

// int	main(void)
// {
// 	size_t num_elements = 10;
// 	size_t element_size = sizeof(int);

// 	int *myArray = (int *)calloc(num_elements, element_size);

// 	if (myArray != NULL)
// 	{
// 		for (size_t i = 0; i < num_elements; i++)
// 		{
// 			printf("myArray[%zu] = %d\n", i, myArray[i]);
// 		}
// 		free(myArray);
// 	}
// 	else
// 	{
// 		printf("Memory allocation failed\n");
// 	}
// 	return (0);
// }
