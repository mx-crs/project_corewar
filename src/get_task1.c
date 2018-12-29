/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_task1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <myarovoy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:42:04 by myarovoy          #+#    #+#             */
/*   Updated: 2018/11/10 15:42:06 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_reverse_endian(int num)
{
	return ((num << 24) |
			(num & 0x0000ff00) << 8 |
			((num & 0x00ff0000) >> 8) |
			((num & 0xff000000) >> 24));
}

short int	ft_reverse_endian_two(short int num)
{
	return ((num & 0xff00) >> 8 | num << 8);
}

int			ft_get_name(t_asm *file)
{
	int		i;
	int		l;

	l = 0;
	i = -1;
	ft_memset(file->header.prog_name, 0, sizeof(file->header.prog_name));
	if (!ft_valid_name_comment(file))
		return (0);
	ft_iter_until_pnt(file, &i, 'n');
	if (file->in_file[i] != '"')
		return (0);
	l = ++i;
	while (file->in_file[i] && file->in_file[i] != '"')
		i++;
	if (i - l > PROG_NAME_LENGTH)
	{
		ft_dprintf(2, "Champion name too long (Max length 128) ");
		return (0);
	}
	i = l;
	l = 0;
	while (file->in_file[i] && file->in_file[i] != '"')
		file->header.prog_name[l++] = file->in_file[i++];
	return (1);
}

int			ft_get_comment(t_asm *file)
{
	int		i;
	int		l;

	l = 0;
	i = -1;
	ft_memset(file->header.comment, 0, sizeof(file->header.comment));
	ft_iter_until_pnt(file, &i, 'c');
	if (file->in_file[i] != '"')
		return (0);
	l = ++i;
	while (file->in_file[i] && file->in_file[i] != '"')
		i++;
	if (i - l > COMMENT_LENGTH)
	{
		ft_dprintf(2, "Champion comment too long (Max length 2048) ");
		return (0);
	}
	i = l;
	l = 0;
	while (file->in_file[i] && file->in_file[i] != '"')
		file->header.comment[l++] = file->in_file[i++];
	return (1);
}

void		ft_fill_header(t_asm *file)
{
	file->f_size = 0;
	file->header.prog_size = 0;
	file->header.magic = COREWAR_EXEC_MAGIC;
}
