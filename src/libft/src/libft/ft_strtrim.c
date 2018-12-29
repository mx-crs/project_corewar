/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 12:46:44 by myarovoy          #+#    #+#             */
/*   Updated: 2017/11/06 12:46:45 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_str(char *s, int i, int k, int l)
{
	char *s1;

	s1 = ft_strnew(k - i + 1);
	if (s1)
	{
		while (i <= k)
		{
			s1[l] = s[i];
			i++;
			l++;
		}
	}
	else
		return (NULL);
	return (s1);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		k;
	int		l;
	char	*s1;

	if (s)
		k = ft_strlen((char*)s) - 1;
	else
		return (NULL);
	i = 0;
	l = 0;
	if (s)
	{
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		if (s[i] == '\0')
			return (s1 = ft_strnew(0));
		while (s[k] == ' ' || s[k] == '\n' || s[k] == '\t')
			k--;
		s1 = ft_str((char*)s, i, k, l);
	}
	else
		return (NULL);
	return (s1);
}
