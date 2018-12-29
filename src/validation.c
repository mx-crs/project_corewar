/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <myarovoy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:35:34 by myarovoy          #+#    #+#             */
/*   Updated: 2018/12/03 19:35:35 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_detect_arg_whitespace(char *tmp)
{
	int		i;

	i = -1;
	while (tmp[++i])
	{
		if (WHITESPACE(tmp[i]))
			return (0);
	}
	return (1);
}

int		ft_detect_arg(char *arg)
{
	char	*tmp;
	int		i;
	int		chr;

	tmp = ft_strtrim(arg);
	if (!ft_detect_arg_whitespace(tmp))
		return (ft_detect_arg_free_return(&tmp, 0));
	i = 1;
	chr = tmp[0];
	if (tmp[0] == '%' && tmp[i] == ':')
		return (ft_detect_arg_free_return(&tmp, 2));
	if (tmp[i] == '-' || tmp[i] == '+')
		i++;
	if ((tmp[0] == '+' || tmp[1] == '+') &&
								ft_atoi(tmp + ((ISDIGIT(tmp[1])) ? 0 : 1)) == 0)
		return (ft_detect_arg_free_return(&tmp, 0));
	while (tmp[i])
	{
		if (!ISDIGIT(tmp[i++]) && tmp[0] != ':')
			return (ft_detect_arg_free_return(&tmp, 0));
	}
	free(tmp);
	return (ft_detect_arg_mode(chr));
}

int		ft_compare_args(int arg_set, int arg)
{
	if (arg == 1 && (arg_set == 1 || arg_set == 3 ||
					arg_set == 5 || arg_set == 7))
		return (1);
	else if (arg == 2 && (arg_set == 2 || arg_set == 3 ||
					arg_set == 6 || arg_set == 7))
		return (1);
	else if (arg == 4 && (arg_set == 4 || arg_set == 5 ||
					arg_set == 6 || arg_set == 7))
		return (1);
	return (0);
}

int		ft_valid_arg(char **argv, int argc, int cmd_n)
{
	int		i;

	i = 0;
	if (g_op_tab[cmd_n].n_args != argc)
		return (0);
	while (i < argc)
	{
		if (!ft_compare_args(g_op_tab[cmd_n].args[i], ft_detect_arg(argv[i])))
			return (0);
		i++;
	}
	return (1);
}

int		ft_detect_cmd_free_return(char **cmd, int ret)
{
	ft_free_mem(cmd);
	return (ret);
}
