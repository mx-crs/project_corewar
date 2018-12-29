/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 13:16:47 by myarovoy          #+#    #+#             */
/*   Updated: 2017/11/03 13:16:49 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_hay_forward(char *hay, char *needle, int i, int k)
{
	if (k == (int)ft_strlen(needle))
	{
		i = i - k;
		while (i > 0)
		{
			hay++;
			i--;
		}
	}
	else
		hay = NULL;
	return (hay);
}

char			*ft_strnstr(const char *haystack,
				const char *needle, size_t len)
{
	char	*hay;
	char	*needle_c;
	int		i;
	int		k;

	k = 0;
	i = -1;
	hay = (char*)haystack;
	needle_c = (char*)needle;
	while (hay[++i] != '\0' && i < (int)len)
	{
		while (hay[i] == needle_c[k] && i < (int)len && hay[i] != '\0')
		{
			i++;
			k++;
		}
		if (k != (int)ft_strlen(needle_c))
		{
			i = i - k;
			k = 0;
		}
		else
			break ;
	}
	return (ft_hay_forward(hay, needle_c, i, k));
}
