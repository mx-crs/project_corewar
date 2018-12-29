/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <myarovoy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:34:16 by myarovoy          #+#    #+#             */
/*   Updated: 2018/11/21 20:34:17 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_take_cmd_n(char *op)
{
	int		i;
	int		k;
	int		len;

	k = -1;
	i = 0;
	if (!ft_strcmp(op, ""))
		return (-1);
	while (op[++k])
	{
		if (op[k] == ' ' || op[k] == '%')
			break ;
	}
	while (i < CNT_CMD)
	{
		if (k == (len = ft_strlen(g_op_tab[i].name)) &&
			!ft_strncmp(op, g_op_tab[i].name, len))
			return (i);
		i++;
	}
	return (-2);
}

int		ft_fill_core(t_asm *file)
{
	int		tmp;

	ft_fill_header(file);
	tmp = ft_reverse_endian(file->header.magic);
	ft_write_to_buffer(file, &tmp, 4);
	ft_write_to_buffer(file, file->header.prog_name, PROG_NAME_LENGTH);
	tmp = 0;
	ft_write_to_buffer(file, &tmp, 4);
	ft_write_to_buffer(file, &tmp, 4);
	ft_write_to_buffer(file, file->header.comment, COMMENT_LENGTH);
	tmp = 0;
	ft_write_to_buffer(file, &tmp, 4);
	if (!ft_fill_core_with_cmd(file))
		return (0);
	tmp = ft_reverse_endian(file->f_size - PREFIX_PRG);
	ft_write_to_position(file, &tmp, 8 + PROG_NAME_LENGTH, 4);
	if (!ft_write_to_cor_file(file))
		return (0);
	return (1);
}

int		ft_fill_core_with_cmd(t_asm *file)
{
	int		cmd;
	int		l_pos_sub;
	int		label_size;
	int		i;

	i = -1;
	while (file->in_file_n[++i])
	{
		if (ft_strchr(file->in_file_n[i], '.'))
			continue ;
		label_size = ft_cmd_is_label(file->in_file_n[i], file);
		if ((cmd = ft_take_cmd_n(file->in_file_n[i] + label_size)) == -1)
			continue ;
		if (cmd == -2)
			return (0);
		l_pos_sub = file->f_size;
		if (!ft_write_to_buffer(file, &g_op_tab[cmd].n_cmd, 1) ||
			!ft_fill_codage(g_op_tab[cmd], file->in_file_n[i] + label_size +
								ft_strlen(g_op_tab[cmd].name), file))
			return (0);
		if (!ft_take_cmd(cmd, file->in_file_n[i] + label_size +
						ft_strlen(g_op_tab[cmd].name), file, l_pos_sub))
			return (0);
	}
	return (ft_fill_labels(file));
}

int		ft_get_num(t_asm *file, char *cmd, int l_pos_sub, int cmd_n)
{
	int		num;
	int		l_er;

	if ((l_er = ft_take_label_in(file, cmd, l_pos_sub, cmd_n)))
	{
		if (l_er == -1)
			return (-1);
		num = 0;
	}
	else if (ft_strchr(cmd, 'r'))
	{
		num = ft_take_num(cmd);
		if (num > REG_NUMBER || num < 1)
			return (-1);
	}
	else if (ft_strchr(cmd, '%'))
	{
		num = (g_op_tab[cmd_n].l_size == 1) ?
			ft_reverse_endian_two(ft_take_num(cmd)) :
			ft_reverse_endian(ft_take_num(cmd));
	}
	else
		num = ft_reverse_endian_two(ft_take_num(cmd));
	return (num);
}

int		ft_take_cmd(int cmd_n, char *c_line, t_asm *file, int l_pos_sub)
{
	char	**cmd;
	int		i;
	int		num;
	int		er;

	cmd = ft_strsplit(c_line, ',');
	if (!ft_valid_arg(cmd, ft_get_argc(cmd), cmd_n))
		return (ft_detect_cmd_free_return(cmd, 0));
	i = -1;
	while (cmd[++i])
	{
		if ((num = ft_get_num(file, cmd[i], l_pos_sub, cmd_n)) == -1 &&
					ft_take_num(cmd[i]) != -1)
			return (ft_detect_cmd_free_return(cmd, 0));
		if (ft_strchr(cmd[i], '%'))
			er = ft_write_to_buffer(file, &num,
					(g_op_tab[cmd_n].l_size == 0) ? 4 : 2);
		else if (ft_strchr(cmd[i], 'r') && !ft_strchr(cmd[i], ':'))
			er = ft_write_to_buffer(file, &num, 1);
		else
			er = ft_write_to_buffer(file, &num, 2);
		if (!er)
			return (ft_detect_cmd_free_return(cmd, 0));
	}
	return (ft_detect_cmd_free_return(cmd, 1));
}
