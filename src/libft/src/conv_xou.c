/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_xou.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 15:53:37 by myarovoy          #+#    #+#             */
/*   Updated: 2018/06/01 15:53:38 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void		ft_hndl_oux(char **str, t_flag *flag)
{
	if (flag->fl & ZER && flag->prec == 0)
		flag->fl ^= ZER;
	if (flag->prec == 0 && !ft_strcmp(*str, "0"))
		**str = '\0';
	ft_hndl_prec_num(flag, str);
	if (flag->fl & ZER && flag->spec == 'p')
	{
		flag->wid = MAX(flag->wid - 2, 0);
		ft_hndl_padd(flag, str);
	}
	else if (flag->fl & ZER && flag->fl & HSH && (S_X(flag->spec)
														|| flag->spec == 'b'))
	{
		flag->wid = MAX(flag->wid - 2, 0);
		ft_hndl_padd(flag, str);
	}
	ft_hndl_prefix(flag, str);
	if (!(flag->fl & ZER && flag->fl & HSH && (S_X(flag->spec)
								|| flag->spec == 'p' || flag->spec == 'b')))
		ft_hndl_padd(flag, str);
	ft_toupper_x(*str, flag->spec);
}

void		ft_hndl_prefix(t_flag *flag, char **str)
{
	char *tmp;

	if (!(SXO(flag->spec) || flag->spec == 'p' || flag->spec == 'b'))
		return ;
	tmp = ft_strdup(*str);
	if (flag->spec == 'p')
		ft_insert_symbol(&tmp, "0x");
	else if (flag->fl & HSH)
	{
		if (flag->spec == 'b' && ft_strcmp("0", *str) &&
														ft_strcmp("\0", *str))
			ft_insert_symbol(&tmp, "0b");
		else if (S_X(flag->spec) && ft_strcmp("0", *str) &&
														ft_strcmp("\0", *str))
			ft_insert_symbol(&tmp, "0x");
		else if (S_O(flag->spec) && **str != '0')
			ft_insert_symbol(&tmp, "0");
	}
	free(*str);
	*str = tmp;
}

void		ft_toupper_x(char *str, char spec)
{
	if (spec != 'X')
		return ;
	while (*str)
	{
		if (ISALPHA(*str))
			*str = TOUPPER(*str);
		str++;
	}
}

uintmax_t	ft_oux_len(char length, va_list ap)
{
	if (length == hh)
		return ((unsigned char)va_arg(ap, int));
	if (length == h)
		return ((unsigned short)va_arg(ap, int));
	if (length == l)
		return (va_arg(ap, unsigned long));
	if (length == ll)
		return (va_arg(ap, unsigned long long));
	if (length == j)
		return (va_arg(ap, uintmax_t));
	if (length == z)
		return (va_arg(ap, size_t));
	return (va_arg(ap, unsigned int));
}
