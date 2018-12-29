/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonuses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 12:42:27 by myarovoy          #+#    #+#             */
/*   Updated: 2018/06/15 12:42:28 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

char		g_colors[16][2][12] =
{
	{"{red}", "\033[31m"},
	{"{green}", "\033[32m"},
	{"{yellow}", "\033[33m"},
	{"{blue}", "\033[34m"},
	{"{magenta}", "\033[35m"},
	{"{cyan}", "\033[36m"},
	{"{white}", "\033[37m"},
	{"{bblack}", "\033[90m"},
	{"{bred}", "\033[91m"},
	{"{bgreen}", "\033[92m"},
	{"{byellow}", "\033[93m"},
	{"{bblue}", "\033[94m"},
	{"{bmagenta}", "\033[95m"},
	{"{bcyan}", "\033[96m"},
	{"{bwhite}", "\033[97m"},
	{"{eoc}", "\033[0m"}
};

void		ft_conv_binary(t_buff *buff, t_flag *flag, va_list ap)
{
	char		*str;
	uintmax_t	bi;

	bi = va_arg(ap, unsigned long long);
	str = ft_intmaxtoa_base(bi, 2, "01");
	ft_hndl_oux(&str, flag);
	ft_buff_append(buff, str);
	free(str);
}

int			ft_handle_colors(t_buff *buff, const char **format)
{
	int	i;

	i = 0;
	while (i < 33)
	{
		if (ft_strnstr(*format, g_colors[i][0], ft_strlen(g_colors[i][0])) != 0)
		{
			ft_buff_append(buff, g_colors[i][1]);
			*format = *format + ft_strlen(g_colors[i][0]);
			return (1);
		}
		++i;
	}
	return (0);
}
