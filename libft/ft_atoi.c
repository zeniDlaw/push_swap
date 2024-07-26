/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichettri <ichettri@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:48:00 by ichettri          #+#    #+#             */
/*   Updated: 2023/11/24 18:31:01 by ichettri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The atoi() function converts the initial portion of the string pointed to
     by str to int representation.

*/

#include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

// int	main(void)
// {
// 	char	st[] = "00009-98098";
// 	int		result;
//     int     check;

// 	result = ft_atoi(st);
//     check = atoi(st);

//     printf("%d\n", check);
// 	printf("%d\n", result);
// 	return (0);
// }
