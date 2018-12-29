/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmaxtoa_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 02:48:35 by myarovoy          #+#    #+#             */
/*   Updated: 2018/06/03 02:48:36 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_intmaxtoa_base(uintmax_t value, int8_t base, const char *str)
{
	uintmax_t	i;
	size_t		size;
	char		*ret;

	i = value;
	size = 1;
	while ((i /= base))
		size++;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	ret[size] = '\0';
	i = value;
	ret[--size] = str[i % base];
	while ((i /= base))
		ret[--size] = str[i % base];
	return (ret);
}
