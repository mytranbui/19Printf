/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:05:52 by mbui              #+#    #+#             */
/*   Updated: 2020/10/16 15:33:46 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft/libft.h"
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
	char        type; //unused
	t_flag		flg;
	//int         len;
}				t_print;

int			ft_printf(const char *format, ...);

t_print		*init_flags(t_print *p);
int			parse_flags(va_list ap, t_print *p, int i);
int			parse_size(t_print *p, int i);
int			get_width_pres(va_list ap, t_print *p, int i);
intmax_t	convert_arg_di(va_list ap, t_print *p);
uintmax_t   convert_arg_ouxxf(va_list ap, t_print *p);
int			conversion(va_list ap, t_print *p);

void		convert_c(va_list ap, t_print *p);
void		convert_s(va_list ap, t_print *p);
void		convert_p(va_list ap, t_print *p);
void		convert_di(intmax_t arg, t_print *p);
void		convert_o(uintmax_t arg, t_print *p);
void		convert_u(uintmax_t arg, t_print *p);
void		convert_x(uintmax_t arg, t_print *p);
void		convert_f(intmax_t arg, t_print *p);
void		convert_percent(va_list ap, t_print *p);

int			ft_putstr_len_percent(const char *str);
void		putsign(int n, t_print	*p);
//void	padding_zero(char *s, t_print *p);
void		padding_space(int len, t_print *p);
void		padding_zero(int len, t_print *p);
void		putprefix(char *s, t_print *p);
void		free_print(t_print **p);
void		free_strprint(char **s);
#endif
