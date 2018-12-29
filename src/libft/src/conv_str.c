/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 16:01:37 by myarovoy          #+#    #+#             */
/*   Updated: 2018/05/31 16:01:38 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	ft_conv_string(t_buff *buff, t_flag *flag, va_list ap)
{
	char *str;
	char *tmp;

	if (flag->len == l)
	{
		ft_conv_wstring(buff, flag, ap);
		return ;
	}
	tmp = va_arg(ap, char *);
	if (!tmp)
		str = ft_null_string(flag);
	else
		str = ft_strdup(tmp);
	ft_hndl_prec(flag, &str);
	ft_hndl_padd(flag, &str);
	ft_buff_append(buff, str);
	free(str);
}

char	*ft_null_string(t_flag *flag)
{
	char *tmp;

	if (flag->prec >= 1 || flag->prec == -1)
	{
		tmp = ft_strdup("(null)");
		if (flag->prec > 6)
			tmp[6] = '\0';
		else
			tmp[(flag->prec == -1) ? 6 : flag->prec] = '\0';
	}
	else
		tmp = ft_strdup("");
	return (tmp);
}
