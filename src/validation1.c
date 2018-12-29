/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <myarovoy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:36:51 by myarovoy          #+#    #+#             */
/*   Updated: 2018/12/03 19:36:52 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_get_argc(char **argv)
{
	int		i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int		ft_detect_arg_mode(char chr)
{
	if (chr == 'r')
		return (1);
	else if (chr == '%')
		return (2);
	else if (chr == '-' || chr == '+' || ISDIGIT(chr) || chr == ':')
		return (4);
	return (0);
}

int		ft_detect_arg_free_return(char **tmp, int ret)
{
	free(*tmp);
	return (ret);
}
