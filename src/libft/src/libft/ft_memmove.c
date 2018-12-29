/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 05:15:04 by myarovoy          #+#    #+#             */
/*   Updated: 2017/10/29 05:19:30 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	int		i;

	s = (char*)src;
	d = (char*)dst;
	i = 0;
	if (s < d)
	{
		while ((int)--len >= 0)
			d[len] = s[len];
	}
	else
	{
		while (i < (int)len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
