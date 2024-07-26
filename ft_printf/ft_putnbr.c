/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:29:27 by ichettri          #+#    #+#             */
/*   Updated: 2023/12/22 14:28:04 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

int	ft_caphex(long n, int base)
{
	int		count;
	char	*sym1;

	count = 0;
	sym1 = "0123456789ABCDEF";
	if (n < 0)
	{
		count = 1;
		write (1, "-", 1);
		return (count += ft_caphex(-n, base) + count);
	}
	else if (n < base)
	{
		return (ft_putchar(sym1[n]) + count);
	}
	else
	{
		count += ft_caphex(n / base, base);
		return (count + ft_caphex(n % base, base));
	}
}

int	ft_putnbr(long n, int base, char hex)
{
	int		count;
	char	*sym;

	count = 0;
	sym = "0123456789abcdef";
	if (hex == 'X')
		return (ft_caphex(n, base));
	if (n < 0)
	{
		count = 1;
		write(1, "-", 1);
		return (count += ft_putnbr(-n, base, 'x' + 1));
	}
	else if (n < base)
	{
		return (count + ft_putchar(sym[n]));
	}
	else
	{
		count += ft_putnbr(n / base, base, 'x');
		return (count + ft_putnbr(n % base, base, 'x'));
	}
}
