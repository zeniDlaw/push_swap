/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:13:26 by ichettri          #+#    #+#             */
/*   Updated: 2023/12/05 19:22:35 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Counts the number of nodes in a list.

Return value: The length of the list.
*/

#include "libft.h"
// #include <stdio.h>
#include <stdlib.h>

int	ft_lstsize(t_list *lst)
{
	t_list	*ptr;
	int		count;

	count = 0;
	if (lst != NULL)
	{
		ptr = NULL;
		ptr = lst;
		while (ptr != NULL)
		{
			count++;
			ptr = ptr->next;
		}
	}
	return (count);
}
