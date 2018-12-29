/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:28:33 by myarovoy          #+#    #+#             */
/*   Updated: 2017/11/06 19:28:35 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_if_neg(int *neg, long long int *n)
{
	if (*n < 0)
	{
		*n *= -1;
		*neg = 1;
	}
}

char			*ft_itoa(long long int n)
{
	int					len;
	int					neg;
	char				*res;
	long long int		n_c;

	neg = 0;
	len = 1;
	ft_if_neg(&neg, &n);
	n_c = n;
	while (n /= 10)
		len++;
	len += neg;
	if (!(res = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		res[len] = n_c % 10 + '0';
		n_c /= 10;
	}
	if (neg)
		res[0] = '-';
	return (res);
}
