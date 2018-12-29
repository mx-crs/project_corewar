/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:05:26 by myarovoy          #+#    #+#             */
/*   Updated: 2017/11/07 15:05:27 by myarovoy         ###   ########.fr       */
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

static	void	ft_print(int len, char *res, int neg, int *fd)
{
	if (neg)
		res[0] = '-';
	len++;
	while (res[len] != '\0')
	{
		write(*fd, &res[len], 1);
		len++;
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	char	res[50];
	int		len;
	int		neg;
	int		n_c;

	neg = 0;
	len = 1;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
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
	ft_print(len, res, neg, &fd);
}
