/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 18:47:26 by myarovoy          #+#    #+#             */
/*   Updated: 2018/05/30 18:47:27 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

t_conv g_conv_tbl[] =
{
	{'i', &ft_conv_num},
	{'d', &ft_conv_num},
	{'D', &ft_conv_num},
	{'o', &ft_conv_octal},
	{'O', &ft_conv_octal},
	{'x', &ft_conv_hex},
	{'X', &ft_conv_hex},
	{'u', &ft_conv_unsign},
	{'U', &ft_conv_unsign},
	{'s', &ft_conv_string},
	{'S', &ft_conv_wstring},
	{'c', &ft_conv_chr},
	{'C', &ft_conv_chr},
	{'p', &ft_conv_hex},
	{'b', &ft_conv_binary},
	{'%', &ft_conv_percent}
};

void	ft_do_conv(t_buff *buff, t_flag *flag, va_list ap)
{
	int i;

	i = -1;
	while (++i < SPECS)
	{
		if (flag->spec == g_conv_tbl[i].spec)
		{
			g_conv_tbl[i].f(buff, flag, ap);
			return ;
		}
	}
	ft_conv_percent(buff, flag, ap);
}

int		ft_hndl_printf(char **ret, const char *format, va_list ap)
{
	t_flag		flag;
	t_buff		buff;
	size_t		i;

	ft_flag_init(&flag);
	if (ft_buff_init(&buff, ft_strlen(format) + 50) == -1)
		return (-1);
	while (*format)
	{
		i = 0;
		while (format[i] && format[i] != '%')
			i++;
		ft_buff_nappend(&buff, (char*)format, i);
		format += i;
		if (*format == '%')
		{
			if (*(++format) == 0)
				break ;
			ft_fill_spec(&buff, &format, &flag, ap);
		}
		ft_flag_init(&flag);
	}
	*ret = ft_strndup(buff.data, buff.len);
	ft_buff_free(&buff);
	return (buff.len);
}

void	ft_fill_spec(t_buff *buff, const char **format,
													t_flag *flag, va_list ap)
{
	if (**format == '{')
		if (ft_handle_colors(buff, format) == 1)
			return ;
	while (1)
	{
		if (ft_check_fl(format, flag))
			continue ;
		if (ft_check_wid(format, flag, ap))
			continue ;
		if (ft_check_prec(format, flag, ap))
			continue ;
		if (ft_check_len(format, flag))
			continue ;
		if (**format == '\0')
			return ;
		flag->spec = *(*format)++;
		break ;
	}
	ft_do_conv(buff, flag, ap);
}

void	ft_conv_percent(t_buff *buff, t_flag *flag, va_list ap)
{
	char *str;

	(void)ap;
	str = ft_strnew(1);
	*str = flag->spec;
	ft_hndl_padd(flag, &str);
	ft_buff_append(buff, str);
	free(str);
}

void	ft_flag_init(t_flag *flag)
{
	flag->spec = 'N';
	flag->len = -1;
	flag->wid = 0;
	flag->prec = -1;
	flag->fl = 0;
	flag->pset = 0;
}
