/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 20:05:08 by myarovoy          #+#    #+#             */
/*   Updated: 2017/11/02 20:05:10 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_is_needle(int *i1, int *k1, char *needle_c, char *hay)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (hay[i] != '\0' && k != (int)ft_strlen(needle_c))
	{
		while (hay[i] == needle_c[k] && needle_c[k] != '\0')
		{
			if (hay[i] != '\0')
				i++;
			k++;
		}
		if (k < (int)ft_strlen(needle_c))
		{
			i = i - k;
			k = 0;
		}
		else
			break ;
		i++;
	}
	*i1 = i;
	*k1 = k;
}

char			*ft_strstr(const char *haystack, const char *needle)
{
	char	*hay;
	char	*needle_c;
	int		i;
	int		k;

	needle_c = (char*)needle;
	hay = (char*)haystack;
	i = 0;
	k = 0;
	ft_is_needle(&i, &k, needle_c, hay);
	if (k == (int)ft_strlen(needle_c))
	{
		i = i - k;
		while (i > 0)
		{
			hay++;
			i--;
		}
	}
	else
		return (NULL);
	return (hay);
}
