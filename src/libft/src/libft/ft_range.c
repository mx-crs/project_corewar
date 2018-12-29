/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:44:30 by myarovoy          #+#    #+#             */
/*   Updated: 2017/11/08 13:44:31 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int *res;
	int i;

	i = 0;
	if (max <= min)
		return (0);
	res = (int*)malloc(sizeof(int) * (max - min + 1));
	while (min + i < max)
	{
		res[i] = min + i;
		i++;
	}
	res[i] = 0;
	return (res);
}
