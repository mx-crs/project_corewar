/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_buff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:08:18 by myarovoy          #+#    #+#             */
/*   Updated: 2018/06/01 16:08:19 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int		ft_buff_init(t_buff *buff, size_t end)
{
	if (!buff || !end)
		return (-1);
	buff->len = 0;
	buff->end = end;
	if ((buff->data = ft_memalloc(sizeof(char) * buff->end)) == NULL)
		return (-1);
	return (0);
}

void	ft_buff_nappend(t_buff *buff, char *newdata, size_t n)
{
	size_t newlen;

	newlen = n;
	if (buff->end < buff->len + newlen)
		ft_buff_resize(buff, buff->len + newlen);
	ft_memcpy(buff->data + buff->len, newdata, newlen);
	buff->len += newlen;
}

void	ft_buff_append(t_buff *buff, char *newdata)
{
	size_t newlen;

	newlen = ft_strlen(newdata);
	if (buff->end < buff->len + newlen)
		ft_buff_resize(buff, buff->len + newlen);
	ft_memcpy(buff->data + buff->len, newdata, newlen);
	buff->len += newlen;
}

void	ft_buff_resize(t_buff *buff, size_t min)
{
	size_t	size;

	if (!(buff->data))
		ft_buff_init(buff, min);
	size = buff->end;
	while (size < min)
		size *= 2;
	buff->data = (char *)ft_recalloc(buff->data, buff->len, size);
	buff->end = size;
}

void	ft_buff_free(t_buff *buff)
{
	if (buff->data && buff->end > 0)
	{
		free(buff->data);
		buff->data = NULL;
	}
}
