/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:22:40 by mbui              #+#    #+#             */
/*   Updated: 2020/10/16 17:02:45 by mbui             ###   ########.fr       */
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

intmax_t	convert_arg_di(va_list ap, t_print *p)
{
	intmax_t	arg;

	arg = 0;
	if (p->type == 'd' || p->type == 'i')
	{
		if (p->flg.h == 1)
			arg = (short int)va_arg(ap, int);
		else if (p->flg.h == 2)
			arg = (char)va_arg(ap, int);
		else if (p->flg.l == 1)
			arg = (long int)va_arg(ap, long int);
		else if (p->flg.l == 2)
			arg = (long long int)va_arg(ap, long long int);
		else
			arg = (int)va_arg(ap, int);
	}
	return (arg);
}

uintmax_t	convert_arg_ouxxf(va_list ap, t_print *p)
{
	uintmax_t	arg;

	arg = 0;
	if (p->type == 'o' || p->type == 'u' || p->type == 'x' || p->type == 'X')
	{
		if (p->flg.h == 1)
			arg = (unsigned short int)va_arg(ap, unsigned int);
		else if (p->flg.h == 2)
			arg = (unsigned char)va_arg(ap, unsigned int);
		else if (p->flg.l == 1)
			arg = (unsigned long int)va_arg(ap, unsigned long int);
		else if (p->flg.l == 2)
			arg = (unsigned long long int)va_arg(ap, unsigned long long int);
		else
			arg = (unsigned long long int)va_arg(ap, unsigned long long);
	}
	if (p->flg.maj_l == 1 && p->type == 'f')
		arg = va_arg(ap, long double);
	else if (p->type == 'f')
		arg = va_arg(ap, double);
	return (arg);
}
