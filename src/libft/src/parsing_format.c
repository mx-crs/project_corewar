/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 14:02:46 by myarovoy          #+#    #+#             */
/*   Updated: 2018/06/01 14:02:47 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int		ft_check_len(const char **format, t_flag *flag)
{
	int			i;
	const char	len_arr[] = "hhlljz";

	i = 0;
	if (ISLENMOD(**format))
	{
		i = ft_is_there_chr(**format, len_arr);
		if (i == 0)
		{
			if (*(*format + 1) == 'h')
				++*format;
			else
				i = 1;
		}
		if (i == 2)
			i = (*(*format + 1) == 'l') ? 3 : 2;
		flag->len = MAX(i, flag->len);
		++*format;
		return (1);
	}
	return (0);
}

int		ft_check_wid(const char **format, t_flag *flag, va_list ap)
{
	int num;

	num = 0;
	if (**format == '*')
	{
		flag->wid = va_arg(ap, int);
		if (flag->wid < 0)
		{
			if (!(flag->fl & MIN))
				flag->fl ^= MIN;
			flag->wid = flag->wid * -1;
		}
		++(*format);
		return (1);
	}
	if (!ISDIGIT(**format))
		return (0);
	while (ISDIGIT(**format))
	{
		num = num * 10 + (**format - '0');
		++(*format);
	}
	flag->wid = num;
	return (1);
}

int		ft_check_prec(const char **format, t_flag *flag, va_list ap)
{
	int num;

	num = 0;
	if (**format != '.')
		return (0);
	flag->pset = 1;
	++(*format);
	if (**format == '*')
	{
		flag->prec = va_arg(ap, int);
		if (flag->prec < -1)
			flag->prec = -1;
		++(*format);
		return (1);
	}
	while (ISDIGIT(**format))
	{
		num = num * 10 + (**format - '0');
		++(*format);
	}
	flag->prec = num;
	return (1);
}

int		ft_check_fl(const char **format, t_flag *flag)
{
	size_t		i;
	const char	flags[] = "-+ 0#";

	i = 0;
	while (flags[i] != **format && flags[i])
		i++;
	if (flags[i])
	{
		flag->fl = flag->fl | (1 << i);
		(*format)++;
		return (1);
	}
	return (0);
}
