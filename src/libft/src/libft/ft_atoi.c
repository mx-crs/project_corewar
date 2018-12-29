/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 13:06:06 by myarovoy          #+#    #+#             */
/*   Updated: 2017/11/04 13:06:07 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_atoi(const char *str)
{
	unsigned long int	res;
	int					i;
	int					minus;

	res = 0;
	i = 0;
	minus = 1;
	while ((str[i] >= 8 && str[i] < 14) ||
			str[i] >= 127 || str[i] == 32)
		i++;
	if (str[i++] == '-')
		minus = -1;
	else if (str[--i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		if (res >= 9223372036854775807 && minus == 1)
			return (-1);
		else if (res > 9223372036854775807 && minus == -1)
			return (0);
		i++;
	}
	return (res * minus);
}
