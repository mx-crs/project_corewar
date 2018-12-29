/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padd_prec_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 18:27:51 by myarovoy          #+#    #+#             */
/*   Updated: 2018/06/02 18:27:52 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	ft_hndl_prec(t_flag *flag, char **str)
{
	if (flag->prec == -1)
		return ;
	if (ft_strlen(*str) <= (size_t)flag->prec)
		return ;
	(*str)[flag->prec] = '\0';
}

void	ft_hndl_padd(t_flag *flag, char **str)
{
	char	*tmp;

	if (flag->wid == 0 || ft_strlen(*str) >= (size_t)flag->wid)
		return ;
	tmp = ft_strnew(flag->wid);
	if (flag->fl & MIN)
	{
		ft_strcpy(tmp, *str);
		ft_memset(tmp + ft_strlen(*str), ' ', flag->wid - ft_strlen(*str));
	}
	else
		ft_fill_before_str(flag, str, tmp);
	free(*str);
	*str = tmp;
	return ;
}

void	ft_fill_before_str(t_flag *flag, char **str, char *new)
{
	char pre;

	pre = 0;
	if (flag->fl & ZER)
	{
		pre = (!ISDIGIT((*str)[0]) && flag->spec == 'd') ? (*str)[0] : 0;
		ft_memset(new, '0', flag->wid - ft_strlen(*str) + !!pre);
		if (pre)
		{
			new[0] = pre;
			(*str)[0] = '0';
		}
	}
	else
	{
		ft_memset(new, ' ', flag->wid - ft_strlen(*str));
		if ((flag->fl & PLS) && **str != '-')
			new[flag->wid - ft_strlen(*str)] =
												((*str)[0] == '-') ? '-' : '+';
	}
	ft_strcpy(new + flag->wid - ft_strlen(*str) + !!pre, *str + !!pre);
}

void	ft_hndl_prec_num(t_flag *flag, char **str)
{
	char pre;
	char *tmp;
	char *new;

	tmp = *str;
	if (flag->prec == 0 && !ft_strcmp("0", *str))
	{
		**str = '\0';
		return ;
	}
	flag->prec = (flag->prec == -1) ? 1 : flag->prec;
	if ((size_t)flag->prec < ft_strlen(*str))
		return ;
	pre = (!(ISDIGIT((*str)[0])) && flag->spec == 'd') ? (*str)[0] : 0;
	if (pre)
		++(*str);
	new = ft_strnew(flag->prec + !!pre);
	ft_memset(new + !!pre, '0', flag->prec - ft_strlen(*str));
	ft_strcpy(new + !!pre + flag->prec - ft_strlen(*str), *str);
	if (pre)
		new[0] = pre;
	free(tmp);
	*str = new;
}
