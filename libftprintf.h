/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:05:52 by mbui              #+#    #+#             */
/*   Updated: 2020/10/13 11:14:19 by mbui             ###   ########.fr       */
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
    int	h;//0 1h 2hh
    int	l;//0 1l 2ll
    int	maj_l;
}				t_flag;

typedef struct	s_print
{
//	va_list		ap;
    const char	*fmt; //unused
	int			width;
    int			pres;
    char        type; //unused
    t_flag		flg;
    //int         len;
}				t_print;

int	    ft_printf(const char *format, ...);
t_print	*init_flags(t_print *p);
int		parse_flags(t_print *p/*,const char **fmt*/, int i);
int		conversion(va_list ap, char c, t_print *p);

void	convert_c(va_list ap, t_print *p);
void	convert_s(va_list ap, t_print *p);
void	convert_p(va_list ap, t_print *p);
void	convert_di(va_list ap, t_print *p);
void	convert_o(va_list ap, t_print *p);
void	convert_u(va_list ap, t_print *p);
void	convert_x(va_list ap, char c, t_print *p);
void	convert_f(va_list ap, t_print *p);
void	convert_percent(va_list ap, t_print *p);

int     ft_putstr_len_percent(const char *str);
void	putsign(int n, t_print	*p);
//void	padding_zero(char *s, t_print *p);
void	padding_space(int len, t_print *p);
void	padding_zero(int len, t_print *p);
void	putprefix(char c, char *s, t_print *p);
#endif
