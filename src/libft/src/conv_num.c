/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 14:06:26 by myarovoy          #+#    #+#             */
/*   Updated: 2018/05/31 14:06:27 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void		ft_conv_num(t_buff *buff, t_flag *flag, va_list ap)
{
	intmax_t	num;
	char		*str;

	flag->len = (flag->spec == 'D') ? l : flag->len;
	if (flag->spec == 'i' || flag->spec == 'D')
		flag->spec = 'd';
	num = ft_integer_len(flag->len, ap);
	str = ft_intmaxtoa(num);
	if (flag->prec != -1 && flag->fl & ZER)
		flag->fl ^= ZER;
	*str = (flag->prec == 0 && !ft_strcmp("0", str)) ? '\0' : *str;
	if ((flag->fl & PLS || flag->fl & SPC) && str[0] != '-'
														&& flag->spec == 'd')
	{
		ft_insert_symbol(&str, (flag->fl & SPC) ? " " : "+");
		str[0] = ((flag->fl & PLS)) ? '+' : str[0];
	}
	ft_hndl_prec_num(flag, &str);
	ft_hndl_padd(flag, &str);
	ft_buff_append(buff, str);
	free(str);
}

void		ft_conv_unsign(t_buff *buff, t_flag *flag, va_list ap)
{
	char		*str;
	uintmax_t	uns_num;

	if (flag->spec == 'U')
		flag->len = l;
	uns_num = ft_oux_len(flag->len, ap);
	str = ft_intmaxtoa_base(uns_num, 10, "0123456789");
	ft_hndl_oux(&str, flag);
	ft_buff_append(buff, str);
	free(str);
}

void		ft_conv_hex(t_buff *buff, t_flag *flag, va_list ap)
{
	char		*str;
	uintmax_t	hex_num;

	if (flag->spec == 'p')
		flag->len = j;
	hex_num = ft_oux_len(flag->len, ap);
	str = ft_intmaxtoa_base(hex_num, 16, "0123456789abcdef");
	if (flag->spec == 'p' && flag->fl & ZER && flag->pset)
		flag->fl ^= ZER;
	ft_hndl_oux(&str, flag);
	ft_buff_append(buff, str);
	free(str);
}

void		ft_conv_octal(t_buff *buff, t_flag *flag, va_list ap)
{
	char		*str;
	uintmax_t	oct_num;

	if (flag->spec == 'O')
		flag->len = l;
	oct_num = ft_oux_len(flag->len, ap);
	str = ft_intmaxtoa_base(oct_num, 8, "01234567");
	ft_hndl_oux(&str, flag);
	ft_buff_append(buff, str);
	free(str);
}

intmax_t	ft_integer_len(char length, va_list ap)
{
	if (length == hh)
		return ((signed char)va_arg(ap, int));
	if (length == h)
		return ((short)va_arg(ap, int));
	if (length == l)
		return (va_arg(ap, long));
	if (length == ll)
		return (va_arg(ap, long long));
	if (length == j)
		return (va_arg(ap, intmax_t));
	if (length == z)
		return (va_arg(ap, ssize_t));
	return (va_arg(ap, int));
}
