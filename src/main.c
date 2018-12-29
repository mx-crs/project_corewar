/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <myarovoy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:53:52 by myarovoy          #+#    #+#             */
/*   Updated: 2018/11/09 14:53:53 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_usage(void)
{
	ft_printf("Usage: ./asm [-h] <sourcefile.s>\n");
	ft_printf("       -h: Surprise :)\n");
}

int		ft_fill_core_struct(t_asm *file, char **av, int ac)
{
	if (!ft_fill_input_file(file, av, ac))
	{
		ft_dprintf(2, "ERROR\n");
		return (0);
	}
	if (!ft_fill_core(file))
	{
		ft_dprintf(2, "ERROR\n");
		return (0);
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_asm	file;

	if (ac < 2)
	{
		ft_usage();
		return (1);
	}
	if (!ft_fill_core_struct(&file, av, ac))
		return (1);
	return (0);
}
