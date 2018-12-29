/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_symbol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 02:53:51 by myarovoy          #+#    #+#             */
/*   Updated: 2018/06/03 02:53:52 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_insert_symbol(char **s1, char *s2)
{
	char *str;
	char *s1cpy;
	char *new;

	if (!s1 || !s2)
		return ;
	new = ft_strnew(ft_strlen(*s1) + ft_strlen(s2) + 1);
	str = new;
	s1cpy = *s1;
	while (*s2)
		*str++ = *s2++;
	while (*s1cpy)
		*str++ = *s1cpy++;
	*str = '\0';
	free(*s1);
	*s1 = new;
}
