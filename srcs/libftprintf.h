/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 08:56:07 by mbui              #+#    #+#             */
/*   Updated: 2020/10/23 08:56:27 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>

typedef struct	s_flag
{
	int	plus;
	int	minus;
	int	space;
	int	zero;
	int	hash;
	int	h;
	int	l;
	int	maj_l;
}				t_flag;

typedef struct	s_print
{
	//	va_list		ap;
	const char	*fmt;
	int			width;
	int			pres;
	char		type;
	int			ret;
	t_flag		flg;
}				t_print;

int				ft_printf(const char *format, ...);

t_print			*init_flags(t_print *p);
int				parse(va_list ap, t_print *p, int i);
int				get_flag(t_print *p, int i);
int				get_size(t_print *p, int i);
int				get_width_pres(va_list ap, t_print *p, int i);
int				get_pres(va_list ap, t_print *p, int i);

intmax_t		convert_arg_di(va_list ap, t_print *p);
uintmax_t		convert_arg_oux(va_list ap, t_print *p);
long double		convert_arg_f(va_list ap, t_print *p);
int				conversion(va_list ap, t_print *p);

void			print_c(va_list ap, t_print *p);
void			print_s(va_list ap, t_print *p);
void			print_p(va_list ap, t_print *p);
void			print_di(intmax_t arg, t_print *p);
void			print_o(uintmax_t arg, t_print *p);
void			print_u(uintmax_t arg, t_print *p);
void			print_x(uintmax_t arg, t_print *p);
void			print_f(long double arg, t_print *p);
void			print_percent(t_print *p);

int				isflag(char c);
int				istype(char c);
int				issize(char c);

int				ft_putstr_len_percent(const char *str, t_print *p);
void			putprefix(char *s, t_print *p);
void			putsign(intmax_t n, t_print	*p);
// void			putsign(int n, t_print	*p, int minus);
void			padding_space(int len, t_print *p);
void			padding_zero(int len, t_print *p);
void			padding_ze_sp(int len, t_print *p);
void			free_print(t_print **p, int n);
void			free_strprint(char **s);
void			print_result(long double arg, char *s, int pres, t_print *p);
#endif
