/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:49:33 by myarovoy          #+#    #+#             */
/*   Updated: 2017/11/07 13:49:34 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_if_neg(int *n, int *neg)
{
	if (*n < 0)
	{
		*n *= -1;
		*neg = 1;
	}
}

static	void	ft_print(int len, char *res, int neg)
{
	if (neg)
		res[0] = '-';
	len++;
	while (res[len] != '\0')
	{
		write(1, &res[len], 1);
		len++;
	}
}

void			ft_putnbr(int n)
{
	char	res[50];
	int		len;
	int		n_c;
	int		neg;

	neg = 0;
	len = 1;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	ft_if_neg(&n, &neg);
	n_c = n;
	while (n /= 10)
		len++;
	len += neg;
	res[len] = '\0';
	while (len--)
	{
		res[len] = n_c % 10 + '0';
		n_c /= 10;
	}
	ft_print(len, res, neg);
}
