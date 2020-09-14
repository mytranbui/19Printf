/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:05:52 by mbui              #+#    #+#             */
/*   Updated: 2020/09/14 11:04:41 by mbui             ###   ########.fr       */
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
    t_flag		flg;
}				t_print;

int	ft_printf(const char *format, ...);
#endif
