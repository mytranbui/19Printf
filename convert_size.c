/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:22:40 by mbui              #+#    #+#             */
/*   Updated: 2020/10/14 16:48:49 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** For diouxX
** h	>>	short (unsigned) int
** hh	>>	(unsigned) char
** l	>>	long (unsigned) int
** ll	>>	long long (unsigned) int
** For f
** l	>>	no diff with printf but with scanf it's a double
** L	>>	long (unsigned) double
*/

intmax_t	convert_hhll_di(va_list ap, t_print *p)
{
	intmax_t	s;

	if (p->type == 'd' || p->type == 'i')
	{
		if (p->flg.h == 1)
			s = (short int)va_arg(ap, short int);
		else if (p->flg.h == 2)
			s = (char)va_arg(ap, int);
		else if (p->flg.l == 1)
			s = (long int)va_arg(ap, long int);
		else if (p->flg.l == 2)
			s = (long long int)va_arg(ap, long long int);
		else
			s = (int)va_arg(ap, int);
	}
}

uintmax_t	convert_hhll_ouxx(va_list ap, t_print *p)
{
	if (p->type == 'o' || p->type == 'u' || p->type == 'x' || p->type == 'X')
	{
		if (p->flg.h == 1)
			s = (unsigned short int)va_arg(ap, unsigned short int);
		else if (p->flg.h == 2)
			s = (unsigned char)va_arg(ap, unsigned char);
		else if (p->flg.l == 1)
			s = (unsigned long int)va_arg(ap, unsigned long int);
		else if (p->flg.l == 2)
			s = (unsigned long long int)va_arg(ap, unsigned long long int);
		else
			s = (unsigned long long int)va_arg(ap, unsigned long long);
	}
	if (p->flg.maj_l == 1 && p->type == 'f')
		s = va_arg(ap, long double);
    else if (p->type == 'f')
        s = va_arg(ap, double);
	return (s);
}
