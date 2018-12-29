/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 05:38:27 by myarovoy          #+#    #+#             */
/*   Updated: 2017/10/29 06:07:23 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, \
const void *restrict src, int c, size_t n)
{
	char	*d;
	char	*s;
	int		i;

	i = 0;
	d = (char*)dst;
	s = (char*)src;
	while (i < (int)n)
	{
		if (s[i] == c)
		{
			d[i] = s[i];
			return (&d[i + 1]);
		}
		d[i] = s[i];
		i++;
	}
	return (NULL);
}
