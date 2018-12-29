/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_task2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <myarovoy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:16:56 by myarovoy          #+#    #+#             */
/*   Updated: 2018/11/22 15:16:57 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_is_string(t_asm *file, int i)
{
	int		l;
	int		s;

	s = 0;
	l = i;
	while (l >= 0 && file->in_file[l] != '\n')
	{
		if (file->in_file[l] == '"' && s++)
			break ;
		l--;
	}
	l = i;
	while (file->in_file[l] != '\n')
	{
		if (file->in_file[l] == '"' && s++)
			break ;
		l++;
	}
	if (s != 2)
		return (0);
	return (1);
}

int		ft_filled_line(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] > 32)
			return (1);
	}
	return (0);
}

int		ft_shift_header(char *str)
{
	int		i;
	int		k;

	k = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '.')
		{
			k++;
			while (str[i] && str[i] != '"')
				i++;
			i++;
			while (str[i] && str[i] != '"')
				i++;
		}
		if (k == 2)
			break ;
	}
	return (i + 2);
}

void	ft_fill_tmp(char *tmp, char **tmp_n, char **tmp_ws)
{
	int		i[4];

	i[0] = 0;
	i[1] = -1;
	i[2] = 0;
	i[3] = -1;
	while (tmp_n[++(i[3])])
	{
		if (!ft_filled_line(tmp_n[i[3]]))
			continue ;
		tmp_ws = ft_strsplit_ws(tmp_n[i[3]]);
		while (tmp_ws[++(i[1])])
		{
			while (tmp_ws[i[1]][i[2]])
				tmp[(i[0])++] = tmp_ws[i[1]][(i[2])++];
			if (tmp_ws[(i[1]) + 1])
				tmp[(i[0])++] = ' ';
			else
				tmp[(i[0])++] = '\n';
			i[2] = 0;
		}
		i[1] = -1;
		ft_free_mem(tmp_ws);
	}
	tmp[i[0]] = '\0';
}

char	*ft_clear_spaces(char *line)
{
	char	*tmp;
	char	**tmp_n;
	char	**tmp_ws;

	tmp_ws = NULL;
	tmp = (char*)malloc(sizeof(char) * ft_strlen(line) + 1);
	tmp_n = ft_strsplit(line + ft_shift_header(line), '\n');
	ft_fill_tmp(tmp, tmp_n, tmp_ws);
	ft_free_mem(tmp_n);
	return (tmp);
}
