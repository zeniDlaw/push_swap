/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:28:09 by ichettri          #+#    #+#             */
/*   Updated: 2023/12/18 16:53:50 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

size_t	ft__strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_putstr(char *s)
{
	int		count;
	char	*str;

	count = 0;
	str = s;
	if (str == NULL)
	{
		str = "(null)";
	}
	count += write(1, str, ft__strlen(str));
	return (count);
}
