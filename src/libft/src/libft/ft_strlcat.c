/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 10:25:46 by myarovoy          #+#    #+#             */
/*   Updated: 2017/11/02 10:25:49 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *restrict dst,
	const char *restrict src, size_t dstsize)
{
	int i;
	int k;
	int l;

	i = ft_strlen(dst);
	k = 0;
	l = 0;
	if (i < (int)dstsize)
		l = i;
	else
		l = (int)dstsize;
	while (src[k] != '\0' && i < (int)dstsize - 1)
	{
		dst[i] = src[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	return (l + ft_strlen(src));
}
