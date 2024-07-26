/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:30:55 by ichettri          #+#    #+#             */
/*   Updated: 2023/12/05 19:18:56 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Adds the node ’new’ at the beginning of the list.
*/

#include "libft.h"
// #include <stdio.h>
#include <stdlib.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*current;

// 	head = NULL;
// 	node1 = ft_lstnew("NODE 1");
// 	node2 = ft_lstnew("NODE 2");
// 	ft_lstadd_front(&head, node2);
// 	ft_lstadd_front(&head, node1);
// 	current = head;
// 	while (current != NULL)
// 	{
// 		printf("Content: %s\n", (char *)current->content);
// 		current = current->next;  
// 	}
// 	return (0);
// }
