/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_label1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <myarovoy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:38:54 by myarovoy          #+#    #+#             */
/*   Updated: 2018/11/21 20:38:55 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_add_new_label_in(t_asm *file, char *l_name,
											int l_pos_sub, int l_size)
{
	t_label_in	*tmp;

	tmp = file->label_in;
	if (!file->label_in)
	{
		file->label_in = malloc(sizeof(t_label_in));
		file->label_in->l_name = ft_strdup(l_name);
		file->label_in->l_size = l_size;
		file->label_in->l_pos = file->f_size;
		file->label_in->l_pos_sub = l_pos_sub;
		file->label_in->l_reserved = 0;
		file->label_in->next = NULL;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = malloc(sizeof(t_label_in));
		tmp->next->l_name = ft_strdup((l_name));
		tmp->next->l_size = l_size;
		tmp->next->l_pos = file->f_size;
		tmp->next->l_pos_sub = l_pos_sub;
		file->label_in->l_reserved = 0;
		tmp->next->next = NULL;
	}
}

void	ft_add_new_label_out(t_asm *file, char *l_name)
{
	t_label_out	*tmp;

	tmp = file->label_out;
	if (!file->label_out)
	{
		file->label_out = malloc(sizeof(t_label_out));
		file->label_out->l_name = ft_strdup(l_name);
		file->label_out->l_pos = file->f_size;
		file->label_out->next = NULL;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = malloc(sizeof(t_label_out));
		tmp->next->l_name = ft_strdup((l_name));
		tmp->next->l_pos = file->f_size;
		tmp->next->next = NULL;
	}
}
