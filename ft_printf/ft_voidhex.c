/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_voidhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:58:35 by ichettri          #+#    #+#             */
/*   Updated: 2023/12/18 16:25:27 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_voidhex(void *ptr)
{
	unsigned long	p;
	char			*hex;
	char			str[20];
	int				i;
	int				c;

	p = (unsigned long)ptr;
	hex = "0123456789abcdef";
	i = 0;
	c = 0;
	if (p == 0)
		return (c += write(1, "0x0", 3));
	while (p != 0)
	{
		str[i++] = hex[p % 16];
		p /= 16;
	}
	c += write(1, "0x", 2);
	while (--i >= 0)
		c += write(1, &str[i], 1);
	return (c);
}
