/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:58:12 by ichettri          #+#    #+#             */
/*   Updated: 2023/12/22 22:12:20 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
// #include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	print_format(char sp, va_list ap)
{
	int	count;

	count = 0;
	if (sp == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (sp == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (sp == 'd' || sp == 'i')
		count += ft_putnbr(va_arg(ap, int), 10, 'x');
	else if (sp == 'u')
		count += ft_putnbr(va_arg(ap, unsigned int), 10, 'x');
	else if (sp == 'x')
		count += ft_putnbr(va_arg(ap, unsigned int), 16, 'x');
	else if (sp == 'X')
		count += ft_putnbr(va_arg(ap, unsigned int), 16, 'X');
	else if (sp == 'p')
		count += ft_voidhex(va_arg(ap, void *));
	else
		count += write(1, &sp, 1);
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		count;
	int		i;

	va_start(ap, fmt);
	count = 0;
	i = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			i++;
			count = count + print_format((fmt[i]), ap);
		}
		else
		{
			count += write(1, &fmt[i], 1);
		}
		i++;
	}
	va_end(ap);
	return (count);
}

// int	main(void)
// {
// 	int	rez;
// 	int	rez1;

// 	rez = ft_printf("%x\n",-390);
// 	rez1 = ft_printf("%x\n",-390);
// 	printf("the count  is  %d\n", rez);
// 	printf("%d\n", rez1);
// 	return (0);
// }
