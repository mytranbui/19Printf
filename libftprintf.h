/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:05:52 by mbui              #+#    #+#             */
/*   Updated: 2020/09/24 15:52:04 by mbui             ###   ########.fr       */
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
    const char	*fmt;
	int			width;
    int			pres;
    char        type;
    t_flag		flg;
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
#endif
