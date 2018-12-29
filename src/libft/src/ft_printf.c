/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 13:16:00 by myarovoy          #+#    #+#             */
/*   Updated: 2018/04/02 13:16:02 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int		len;
	char	*str;

	if (!format || !*format)
		return (0);
	va_start(ap, format);
	len = ft_eng_printf(&str, format, ap);
	write(1, str, len);
	free(str);
	va_end(ap);
	return (len);
}

int		ft_eng_printf(char **str, const char *format, va_list ap)
{
	if (*format == '\0')
		*str = ft_strnew(0);
	if (!str || !format || !*format)
		return (0);
	if (ft_strchr(format, '%') == NULL)
	{
		if ((*str = ft_strdup(format)) == NULL)
			return (-1);
		return (ft_strlen(*str));
	}
	return (ft_hndl_printf(str, format, ap));
}

int		ft_snprintf(char *str, size_t size, const char *format, ...)
{
	int		len;
	char	*tmp;
	va_list ap;

	if (!str || !format)
		return (0);
	va_start(ap, format);
	len = ft_eng_printf(&tmp, format, ap);
	if (size == 0)
		return (len);
	else if (size - 1 == 0)
		str[0] = '\0';
	ft_strncpy(str, tmp, size - 1);
	free(tmp);
	va_end(ap);
	return (len);
}

int		ft_sprintf(char *str, const char *format, ...)
{
	int		len;
	char	*tmp;
	va_list ap;

	if (!str || !format)
		return (0);
	va_start(ap, format);
	len = ft_eng_printf(&tmp, format, ap);
	ft_strcpy(str, tmp);
	free(tmp);
	va_end(ap);
	return (len);
}

int		ft_dprintf(int fd, const char *format, ...)
{
	int		len;
	char	*tmp;
	va_list ap;

	if (!format || !*format || fd < 0)
		return (0);
	va_start(ap, format);
	len = ft_eng_printf(&tmp, format, ap);
	write(fd, tmp, len);
	free(tmp);
	va_end(ap);
	return (len);
}
