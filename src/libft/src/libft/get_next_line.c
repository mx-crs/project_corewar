/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 14:22:20 by myarovoy          #+#    #+#             */
/*   Updated: 2017/12/20 14:22:22 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_malloc_again(char *line, int i)
{
	char	*tmp;

	if (!line)
	{
		tmp = ft_strnew(i);
		return (tmp);
	}
	tmp = ft_strnew(ft_strlen(line) + i);
	ft_strcpy(tmp, line);
	ft_strdel(&line);
	return (tmp);
}

int		ft_fill_line(char *save, char **line)
{
	char	*tmp;
	int		n;

	if ((tmp = ft_strchr(save, '\n')))
	{
		*line = ft_malloc_again(*line, tmp - save);
		ft_strncat(*line, save, tmp - save);
		ft_memmove(save, tmp + 1, ft_strlen(tmp));
		return (1);
	}
	if ((n = ft_strlen(save)))
	{
		*line = ft_malloc_again(*line, n);
		ft_strncat(*line, save, n);
		*save = '\0';
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char		*save[MAX_FD];
	int				res;

	if (fd < 0 || fd >= MAX_FD || !(line)
	|| BUFF_SIZE < 1 || (!save[fd] && !(save[fd] = ft_strnew(BUFF_SIZE))))
		return (-1);
	*line = NULL;
	if (ft_fill_line(save[fd], line))
		return (1);
	while ((res = read(fd, save[fd], BUFF_SIZE)) > 0)
	{
		save[fd][res] = '\0';
		if (ft_fill_line(save[fd], line))
			return (1);
	}
	if (*line)
		return (1);
	ft_strdel(&save[fd]);
	if (res < 0)
		return (-1);
	return (0);
}
