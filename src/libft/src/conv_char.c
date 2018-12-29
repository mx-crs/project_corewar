/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:43:46 by myarovoy          #+#    #+#             */
/*   Updated: 2018/05/31 17:43:47 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	ft_wchar_conv(wchar_t chr, char *str)
{
	if (chr < (MB_CUR_MAX == 1 ? 0xFF : 0x7F))
		str[0] = (unsigned char)chr;
	else if (chr < (1 << 11))
	{
		str[0] = (unsigned char)((chr >> 6) | 0xC0);
		str[1] = (unsigned char)((chr & 0x3F) | 0x80);
	}
	else if (chr < (1 << 16))
	{
		str[0] = (unsigned char)(((chr >> 12)) | 0xE0);
		str[1] = (unsigned char)(((chr >> 6) & 0x3F) | 0x80);
		str[2] = (unsigned char)((chr & 0x3F) | 0x80);
	}
	else if (chr < (1 << 21))
	{
		str[0] = (unsigned char)(((chr >> 18)) | 0xF0);
		str[1] = (unsigned char)(((chr >> 12) & 0x3F) | 0x80);
		str[2] = (unsigned char)(((chr >> 6) & 0x3F) | 0x80);
		str[3] = (unsigned char)((chr & 0x3F) | 0x80);
	}
}

int		ft_cnt_b(wchar_t chr)
{
	if (chr < (1 << 7))
		return (1);
	else if (chr < (1 << 11))
		return (2);
	else if (chr < (1 << 16))
		return (3);
	else if (chr < (1 << 21))
		return (4);
	return (0);
}

void	ft_null(t_buff *buff, char *str)
{
	int len;
	int i;

	i = -1;
	len = ft_strlen(str);
	while (++i < len)
		if (str[i] == 1)
			str[i] = 0;
	ft_buff_nappend(buff, str, len);
}

int		ft_wchar(char **str, va_list ap)
{
	int		len;
	wchar_t	chr;

	chr = va_arg(ap, wchar_t);
	len = ft_cnt_b(chr);
	*str = ft_strnew(len);
	ft_wchar_conv(chr, *str);
	return (chr == '\0');
}

void	ft_conv_chr(t_buff *buff, t_flag *flag, va_list ap)
{
	int		nul;
	char	*str;
	char	chr;

	if (flag->spec == 'C' || flag->len == l)
	{
		nul = ft_wchar(&str, ap);
		str[0] = (nul) ? nul : str[0];
	}
	else
	{
		chr = va_arg(ap, int);
		str = ft_strnew(1);
		nul = (chr == '\0') ? 1 : 0;
		str[0] = chr + nul;
	}
	ft_hndl_padd(flag, &str);
	if (nul)
		ft_null(buff, str);
	else
		ft_buff_append(buff, str);
	free(str);
}
