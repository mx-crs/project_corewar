/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 12:20:51 by myarovoy          #+#    #+#             */
/*   Updated: 2018/06/03 12:20:53 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft.h"

# define SPECS 18
# define SXO(x) ((S_X(x)) || (S_O(x)))
# define S_X(x) (((unsigned)x | 32) - 97 == 23u)
# define S_O(x) (((unsigned)x | 32) - 97 == 14u)
# define S_D(x) (((unsigned)x | 32) - 97 == 3u)
# define S_U(x) (((unsigned)x | 32) - 97 == 20u)
# define ISLENMOD(x) (x == 'h' || x == 'l' || x == 'j' || x == 'z')

typedef enum	e_len
{
	hh,
	h,
	l,
	ll,
	j,
	z
}				t_len;

typedef struct	s_buff
{
	size_t		len;
	size_t		end;
	char		*data;
}				t_buff;

typedef enum	e_fl
{
	MIN = 1 << 0,
	PLS = 1 << 1,
	SPC = 1 << 2,
	ZER = 1 << 3,
	HSH = 1 << 4
}				t_fl;

typedef struct	s_flag
{
	char		fl;
	char		len;
	char		spec;
	int			wid;
	int			prec;
	int			pset:1;
}				t_flag;

typedef struct	s_conv
{
	char spec;
	void (*f)(t_buff *, t_flag *, va_list);
}				t_conv;

int				ft_printf(const char *format, ...);
int				ft_eng_printf(char **ret, const char *format, va_list ap);
int				ft_sprintf(char *str, const char *format, ...);
int				ft_snprintf(char *str, size_t size, const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_hndl_printf(char **ret, const char *format, va_list ap);
void			ft_fill_spec(t_buff *buff, const char **format,
													t_flag *flag, va_list ap);
void			ft_do_conv(t_buff *buff, t_flag *flag, va_list ap);
void			ft_flag_init(t_flag *flag);
void			ft_conv_percent(t_buff *buff, t_flag *flag, va_list ap);
int				ft_buff_init(t_buff *buff, size_t init_cap);
void			ft_buff_append(t_buff *buff, char *newdata);
void			ft_buff_resize(t_buff *buff, size_t min);
void			ft_buff_nappend(t_buff *buff, char *newdata, size_t n);
void			ft_buff_free(t_buff *buff);
int				ft_check_fl(const char **format, t_flag *flag);
int				ft_check_wid(const char **format, t_flag *flag, va_list ap);
int				ft_check_prec(const char **format, t_flag *flag, va_list ap);
int				ft_check_len(const char **format, t_flag *flag);
void			ft_hndl_prec_num(t_flag *flag, char **str);
void			ft_hndl_prec(t_flag *flag, char **str);
void			ft_hndl_padd(t_flag *flag, char **str);
void			ft_fill_before_str(t_flag *flag, char **str, char *new);
void			ft_conv_chr(t_buff *buff, t_flag *flag, va_list ap);
void			ft_null(t_buff *buff, char *str);
int				ft_wchar(char **str, va_list ap);
int				ft_cnt_b(wchar_t chr);
void			ft_wchar_conv(wchar_t chr, char *str);
void			ft_conv_num(t_buff *buff, t_flag *flag, va_list ap);
void			ft_conv_octal(t_buff *buff, t_flag *flag, va_list ap);
void			ft_conv_hex(t_buff *buff, t_flag *flag, va_list ap);
void			ft_conv_unsign(t_buff *buff, t_flag *flag, va_list ap);
intmax_t		ft_integer_len(char length, va_list ap);
void			ft_conv_string(t_buff *buff, t_flag *flag, va_list ap);
char			*ft_null_string(t_flag *flag);
void			ft_conv_wstring(t_buff *buff, t_flag *flag, va_list ap);
char			*ft_wstrtostr(wchar_t *wstr);
void			ft_wstr_prec(t_flag *flag, wchar_t *str);
size_t			ft_wstringlen(wchar_t *str);
wchar_t			*ft_wstringdup(wchar_t *str);
void			ft_hndl_oux(char **str, t_flag *flag);
void			ft_toupper_x(char *str, char spec);
void			ft_hndl_prefix(t_flag *flag, char **str);
uintmax_t		ft_oux_len(char length, va_list ap);
void			ft_conv_binary(t_buff *buff, t_flag *flag, va_list ap);
int				ft_handle_colors(t_buff *buff, const char **format);

#endif
