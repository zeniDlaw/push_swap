/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:05:31 by ichettri          #+#    #+#             */
/*   Updated: 2023/12/05 19:21:03 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Returns the last node of the list.*/

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node;

	if (lst == NULL)
		return (NULL);
	node = lst;
	while (node->next != NULL)
	{
		node = node->next;
	}
	return (node);
}

// int main()
// {
//     t_list *c;
//     ft_lstadd_front(&c, ft_lstnew("Hello"));
//      ft_lstadd_front(&c, ft_lstnew("my"));
//       ft_lstadd_front(&c, ft_lstnew("baby"));
//     return(0);
// }