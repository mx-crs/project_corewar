/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_wstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 16:27:57 by myarovoy          #+#    #+#             */
/*   Updated: 2018/05/31 16:27:58 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	ft_conv_wstring(t_buff *buff, t_flag *flag, va_list ap)
{
	char	*str;
	wchar_t *tmp;

	tmp = va_arg(ap, wchar_t *);
	if (!tmp)
		str = ft_null_string(flag);
	else
	{
		tmp = ft_wstringdup(tmp);
		ft_wstr_prec(flag, tmp);
		str = ft_wstrtostr(tmp);
		free(tmp);
	}
	ft_hndl_padd(flag, &str);
	ft_buff_append(buff, str);
	free(str);
}

wchar_t	*ft_wstringdup(wchar_t *str)
{
	wchar_t	*cpy_str;
	size_t	size;

	size = 0;
	while (str[size])
		++size;
	cpy_str = (wchar_t *)malloc(sizeof(wchar_t) * (size + 1));
	if (!cpy_str)
		return (NULL);
	size = 0;
	while (str[size])
	{
		cpy_str[size] = str[size];
		size++;
	}
	cpy_str[size] = '\0';
	return (cpy_str);
}

char	*ft_wstrtostr(wchar_t *wstr)
{
	size_t	i;
	size_t	wi;
	char	*str;

	i = 0;
	wi = 0;
	str = ft_strnew(ft_wstringlen(wstr));
	while (wstr[i])
	{
		ft_wchar_conv(wstr[i], str + wi);
		wi += ft_cnt_b(wstr[i]);
		i++;
	}
	return (str);
}

size_t	ft_wstringlen(wchar_t *str)
{
	size_t i;
	size_t cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		cnt += ft_cnt_b(str[i]);
		i++;
	}
	return (cnt);
}

void	ft_wstr_prec(t_flag *flag, wchar_t *str)
{
	size_t i;
	size_t cnt;

	i = 0;
	cnt = 0;
	if (flag->prec == -1)
		return ;
	if (ft_wstringlen(str) <= (size_t)flag->prec)
		return ;
	while (str[i] && cnt <= (size_t)flag->prec)
	{
		cnt += ft_cnt_b(str[i]);
		i++;
	}
	str[i - 1] = '\0';
}
