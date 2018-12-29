/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 17:18:12 by myarovoy          #+#    #+#             */
/*   Updated: 2017/11/02 17:18:14 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*s_cpy;
	int		i;
	int		k;

	k = 0;
	i = 0;
	s_cpy = (char*)s;
	while (s_cpy[i])
		i++;
	while (i > 0 && s_cpy[i] != c)
		i--;
	if (s_cpy[i] != c)
		return (NULL);
	while (k < i)
	{
		s_cpy++;
		k++;
	}
	return (s_cpy);
}
