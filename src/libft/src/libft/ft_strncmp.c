/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 12:44:34 by myarovoy          #+#    #+#             */
/*   Updated: 2017/11/04 12:44:35 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	*s1_c;
	unsigned char	*s2_c;

	i = 0;
	s1_c = (unsigned char*)s1;
	s2_c = (unsigned char*)s2;
	if ((int)n == 0)
		return (0);
	while (s1_c[i] != '\0' && s2_c[i] != '\0' &&
			s1_c[i] == s2_c[i] && i < (int)n - 1)
		i++;
	return (s1_c[i] - s2_c[i]);
}
