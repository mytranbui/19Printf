/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:22:40 by mbui              #+#    #+#             */
/*   Updated: 2020/10/21 18:45:06 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

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
		{
			//printf("{sh}");
			arg = (short int)va_arg(ap, int);
		}
		else if (p->flg.h == 2)
		{
			//printf("{ch}");
			arg = (char)va_arg(ap, int);
		}
		else if (p->flg.l == 1)
		{
			//printf("{l}");
			arg = (long int)va_arg(ap, long int);
		}
		else if (p->flg.l == 2)
		{
			//printf("{ll}");
			arg = (long long int)va_arg(ap, long long int);
		}
		else
			arg = (int)va_arg(ap, int);
	}
	return (arg);
}

long double	convert_arg_f(va_list ap, t_print *p)
{
	long double	arg;

	arg = 0;
	if (p->type == 'f')
	{
		if (p->flg.maj_l == 1)
		{
			//printf("{Ld}");
			arg = va_arg(ap, long double);
		}
		else
			arg = (double)va_arg(ap, double);
	}
	return (arg);
}

uintmax_t	convert_arg_oux(va_list ap, t_print *p)
{
	uintmax_t	arg;

	arg = 0;
	if (p->type == 'o' || p->type == 'u' || p->type == 'x' || p->type == 'X')
	{
		if (p->flg.h == 1)
		{
			//printf("{ush}");
			arg = (unsigned short int)va_arg(ap, unsigned int);
		}
		else if (p->flg.h == 2)
		{
			//printf("{uchar}");
			arg = (unsigned char)va_arg(ap, unsigned int);
		}
		else if (p->flg.l == 1)
		{
			//printf("{ul}");
			arg = (unsigned long int)va_arg(ap, unsigned long int);
		}
		else if (p->flg.l == 2)
		{
			//printf("{ull}");
			arg = (unsigned long long int)va_arg(ap, unsigned long long int);
		}
		else
		{
			//printf("{usi}");
			// arg = (unsigned long long int)va_arg(ap, unsigned long long);
			arg = va_arg(ap, unsigned long long);
		}
	}
	return (arg);
}

int			conversion(va_list ap, t_print *p)
{
	if (p->type == 'c')
		convert_c(ap, p);
	else if (p->type == 's')
		convert_s(ap, p);
	else if (p->type == 'p')
		convert_p(ap, p);
	else if (p->type == 'd' || p->type == 'i')
		convert_di(convert_arg_di(ap, p), p);
	else if (p->type == 'o')
		convert_o(convert_arg_oux(ap, p), p);
	else if (p->type == 'u')
		convert_u(convert_arg_oux(ap, p), p);
	else if (p->type == 'x' || p->type == 'X')
		convert_x(convert_arg_oux(ap, p), p);
	else if (p->type == 'f')
		convert_f(convert_arg_f(ap, p), p);
	else if (p->type == '%')
		convert_percent(ap, p);
	return (1);
}