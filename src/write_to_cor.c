/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_cor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <myarovoy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:01:50 by myarovoy          #+#    #+#             */
/*   Updated: 2018/11/13 18:01:51 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_write_to_cor_file(t_asm *file)
{
	int		fd;

	if (PREFIX_PRG == file->f_size)
		return (0);
	if ((fd = open(file->file_name, O_CREAT | O_WRONLY | O_TRUNC, 0666)) == -1)
		return (0);
	if (file->flag == 1)
		ft_print_cong();
	ft_printf("Writing output program to %s\n", file->file_name);
	write(fd, file->file, file->f_size);
	close(fd);
	return (1);
}

int		ft_write_to_buffer(t_asm *file, void *src, size_t size)
{
	size_t	i;
	size_t	k;
	char	*ptr;

	if (PREFIX_PRG + BOT_MAX_SIZE <= file->f_size + size)
	{
		ft_dprintf(2, "ERROR: champ too big\n");
		return (0);
	}
	k = 0;
	ptr = (char *)src;
	i = file->f_size;
	size += file->f_size;
	while (i < size)
		file->file[i++] = ptr[k++];
	file->f_size = size;
	return (1);
}

void	ft_write_to_position(t_asm *file, void *src, size_t pos, size_t b_size)
{
	size_t	i;
	char	*ptr;

	ptr = (char*)src;
	i = 0;
	while (i < b_size)
		file->file[pos++] = ptr[i++];
}

void	ft_bit_offset(char **cmd, int *num)
{
	int		i;

	i = -1;
	while (cmd[++i])
	{
		if (ft_strchr(cmd[i], 'r') && !ft_strchr(cmd[i], ':'))
			*num |= 1;
		else if (ft_strchr(cmd[i], '%'))
			*num |= 2;
		else
			*num |= 3;
		*num = *num << 2;
	}
	*num = (*num << (3 - i) * 2);
}

int		ft_fill_codage(t_op op, char *c_line, t_asm *file)
{
	char	**cmd;
	int		num;

	num = 0;
	cmd = ft_strsplit(c_line, ',');
	if (op.codage == 0)
	{
		ft_free_mem(cmd);
		return (1);
	}
	ft_bit_offset(cmd, &num);
	if (!ft_write_to_buffer(file, &num, 1))
	{
		ft_free_mem(cmd);
		return (0);
	}
	ft_free_mem(cmd);
	return (1);
}
