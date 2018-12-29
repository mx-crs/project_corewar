/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 19:41:17 by myarovoy          #+#    #+#             */
/*   Updated: 2017/11/01 19:41:28 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	int		i;
	int		k;
	char	*s2_cpy;

	k = 0;
	i = 0;
	s2_cpy = (char*)s2;
	while (s1[i])
		i++;
	while (s2[k] != '\0')
	{
		s1[i] = s2_cpy[k];
		i++;
		k++;
	}
	s1[i] = '\0';
	return (s1);
}
