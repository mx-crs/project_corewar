/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_task.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <myarovoy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:39:14 by myarovoy          #+#    #+#             */
/*   Updated: 2018/11/10 15:39:15 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_take_num(char *cmd)
{
	int		i;
	int		k;

	k = 0;
	i = 0;
	while (cmd[k] && !ISDIGIT(cmd[k]))
		k++;
	i = ft_atoi(cmd + k - ((k > 0 && cmd[k - 1] == '-') ? 1 : 0));
	return (i);
}

int		ft_clear_data(t_asm *file)
{
	int		i;
	char	*tmp;

	i = 0;
	while (file->in_file[i])
	{
		if ((file->in_file[i] == '#' || file->in_file[i] == ';') &&
										!ft_is_string(file, i))
		{
			while (file->in_file[i] != '\n')
				file->in_file[i++] = ' ';
		}
		i++;
	}
	if (!ft_get_name(file) || !ft_get_comment(file))
		return (0);
	tmp = ft_clear_spaces(file->in_file);
	file->in_file_n = ft_strsplit(tmp, '\n');
	free(tmp);
	return (1);
}

int		ft_get_task(t_asm *file, int fd)
{
	char	*g_str;
	char	*tmp;
	char	*tmp2;

	g_str = NULL;
	get_next_line(fd, &g_str);
	tmp = ft_strjoin(g_str, "\n");
	free(g_str);
	while (get_next_line(fd, &g_str) == 1)
	{
		tmp2 = ft_strjoin(tmp, g_str);
		free(tmp);
		tmp = ft_strjoin(tmp2, "\n");
		free(tmp2);
		free(g_str);
	}
	if (!tmp || !ft_strstr(tmp, ".name") || !ft_strstr(tmp, ".comment"))
		return (0);
	file->in_file = ft_strdup(tmp);
	free(tmp);
	if (!ft_clear_data(file))
		return (0);
	return (1);
}

void	ft_free_mem(char **tmp)
{
	int		i;

	i = 0;
	if (tmp)
	{
		while (tmp[i])
			free(tmp[i++]);
		free(tmp);
	}
}

int		ft_fill_input_file(t_asm *file, char **av, int ac)
{
	int		i;
	int		len;
	int		fd;
	char	*tmp;

	i = ac - 1;
	len = ft_strlen(av[i]) - 1;
	if (((fd = open(av[i], O_RDONLY)) == -1) ||
		(av[i][len] != 's' || (len > 0 && av[i][len - 1] != '.')) || len < 3)
	{
		ft_dprintf(2, "Can't read source file \"%s\" ", av[i]);
		return (0);
	}
	tmp = ft_strndup(av[i], ft_strlen(av[i]) - 2);
	file->file_name = ft_strjoin(tmp, ".cor");
	free(tmp);
	if (!ft_get_task(file, fd))
		return (0);
	close(fd);
	return (1);
}
