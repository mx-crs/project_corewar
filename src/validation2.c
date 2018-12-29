/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <myarovoy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:38:48 by myarovoy          #+#    #+#             */
/*   Updated: 2018/12/03 19:38:49 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_shift_comment(t_asm *file)
{
	int		i;

	i = 0;
	while (file->in_file[i])
	{
		if (file->in_file[i] == ' ' && !ft_is_string(file, i))
		{
			while (file->in_file[i] != '\n')
				i++;
		}
		if (file->in_file[i] != ' ' && file->in_file[i] != '\n')
			break ;
		i++;
	}
	return (i);
}

int			ft_iter_n_c(int *n_c, char nc)
{
	if (nc == 'n')
		n_c[0]++;
	if (nc == 'c')
		n_c[1]++;
	return ((nc == 'n') ? 5 : 8);
}

int			ft_shift_comment_name(int *i, char *in_file)
{
	while (in_file[*i] && in_file[*i] != '"')
	{
		if (!(WHITESPACE(in_file[*i])))
			return (-1);
		(*i)++;
	}
	if (in_file[*i] == '"')
		(*i)++;
	while (in_file[*i] && in_file[*i] != '"')
		(*i)++;
	return (1);
}

int			ft_valid_name_comment(t_asm *file)
{
	int		i;
	int		n_c[2];

	n_c[0] = 0;
	n_c[1] = 0;
	i = ft_shift_comment(file);
	while (file->in_file[i])
	{
		if (file->in_file[i] == '.' &&
			(!ft_strncmp(file->in_file + i, ".name", 5) ||
			!ft_strncmp(file->in_file + i, ".comment", 8)))
		{
			i += ft_iter_n_c(n_c, file->in_file[i + 1]);
			if (ft_shift_comment_name(&i, file->in_file) == -1)
				return (0);
		}
		else if (file->in_file[i] == '.' &&
			(ft_strncmp(file->in_file + i, ".name", 5) &&
			ft_strncmp(file->in_file + i, ".comment", 8)))
			return (0);
		if (n_c[0] > 1 || n_c[1] > 1)
			return (0);
		i++;
	}
	return (1);
}

void		ft_iter_until_pnt(t_asm *file, int *i, char chr)
{
	while (file->in_file[++(*i)])
	{
		if (file->in_file[*i] == '.' && file->in_file[*i + 1] == chr)
			break ;
	}
	while (file->in_file[*i] && file->in_file[*i] != '"')
		(*i)++;
}
