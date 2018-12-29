/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 12:14:13 by myarovoy          #+#    #+#             */
/*   Updated: 2017/11/01 12:16:33 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	int				i;
	unsigned char	c1;

	s1 = (unsigned char*)s;
	c1 = (unsigned char)c;
	i = 0;
	while (n--)
	{
		if (*s1 == c1)
			return (s1);
		s1++;
		i++;
	}
	return (NULL);
}
