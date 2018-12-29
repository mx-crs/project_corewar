/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 19:22:14 by myarovoy          #+#    #+#             */
/*   Updated: 2017/11/04 19:22:15 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s1;
	int		i;
	char	*s_c;

	i = 0;
	s_c = (char*)s;
	if (!s)
		return (NULL);
	s1 = (char*)malloc(sizeof(char) * (int)ft_strlen(s_c) + 1);
	if (s1)
	{
		while (i < (int)ft_strlen((char*)s))
		{
			s1[i] = f(i, s_c[i]);
			i++;
		}
		s1[i] = '\0';
	}
	else
		s1 = NULL;
	return (s1);
}
