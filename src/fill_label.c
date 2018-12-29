/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_label.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <myarovoy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:37:21 by myarovoy          #+#    #+#             */
/*   Updated: 2018/11/21 20:37:22 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_fill_in_label(t_asm *file, t_label_in *l_in, t_label_out *l_out)
{
	int		num;

	num = l_out->l_pos - l_in->l_pos_sub;
	num = (l_in->l_size == 0) ? ft_reverse_endian(num) :
								ft_reverse_endian_two(num);
	ft_write_to_position(file, &num, l_in->l_pos, (l_in->l_size == 0) ? 4 : 2);
	l_in->l_reserved = 1;
}

int		ft_fill_labels(t_asm *file)
{
	t_label_in	*l_in;
	t_label_out	*l_out;

	l_in = file->label_in;
	while (l_in)
	{
		l_out = file->label_out;
		while (l_out)
		{
			if (!ft_strcmp(l_in->l_name, l_out->l_name))
				ft_fill_in_label(file, l_in, l_out);
			l_out = l_out->next;
		}
		l_in = l_in->next;
	}
	l_in = file->label_in;
	while (l_in)
	{
		if (l_in->l_reserved != 1)
			return (0);
		l_in = l_in->next;
	}
	return (1);
}

int		ft_cmd_is_label(char *cmd, t_asm *file)
{
	int		i;
	char	*label_out;

	i = 0;
	label_out = NULL;
	if (cmd[0] == ':')
		return (0);
	while (cmd[i] && cmd[i] != ':')
	{
		if (cmd[i] == ' ')
			return (0);
		i++;
	}
	if ((i > 0 && cmd[i - 1] == '%' && cmd[i] == ':') || cmd[i] != ':')
		return (0);
	if (i > 0 && cmd[i] == ':')
		label_out = ft_strndup(cmd, i);
	if (cmd[i] && cmd[i + 1] == ' ')
		i += 2;
	else
		i++;
	ft_add_new_label_out(file, label_out);
	free(label_out);
	return (i);
}

int		ft_take_label_in(t_asm *file, char *cmd, int l_pos_sub, int cmd_n)
{
	char	*l_name;
	char	*l_name_c;
	int		term;

	term = 0;
	if (!(l_name = ft_strchr(cmd, ':')))
		return (0);
	l_name++;
	while (l_name[term] && l_name[term] > 32)
	{
		if (!ft_strchr(LABEL_CHARS, l_name[term]))
			return (-1);
		term++;
	}
	l_name_c = ft_strndup(l_name, term);
	ft_add_new_label_in(file, l_name_c, l_pos_sub,
	(ft_strchr(cmd, '%')) ? g_op_tab[cmd_n].l_size : 1);
	free(l_name_c);
	return (1);
}
