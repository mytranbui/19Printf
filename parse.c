/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:39:00 by mbui              #+#    #+#             */
/*   Updated: 2020/10/14 15:42:00 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		istype(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o'
			|| c == 'u' || c == 'x' || c == 'X' || c == 'f' || c == '%');
}

int		get_width_pres(t_print *p, int i)
{
	if (ft_isdigit(p->fmt[i]))
	{
		p->width = ft_atoi(&p->fmt[i]);
		while (ft_isdigit(p->fmt[i]))
			i++;
		//    if (p->fmt[i++] == '*')
		//      p->width = (va_arg(ap, int);
	}
	if (p->fmt[i] == '.')
	{
		i++;
		p->pres = ft_atoi(&p->fmt[i]);
		while (ft_isdigit(p->fmt[i]))
			i++;
		//if (p->fmt[i++] == '*')
		//  p->pres = (va_arg(ap, int);
	}
	return (i);
}

int		parse_flags2(t_print *p, int i)
{
	while (p->fmt[i] != '\0' && istype(p->fmt[i]) == 0)
	{
		if (p->fmt[i] == 'h' && p->fmt[i + 1] == 'h' && p->flg.h == 0)
			p->flg.h = 2;
		if (p->fmt[i] == 'l' && p->fmt[i + 1] == 'l' && p->flg.l == 0)
			p->flg.l = 2;
		if (p->fmt[i] == 'h' && p->fmt[i + 1] != 'h' && p->flg.h == 0)
			p->flg.h = 1;
		if (p->fmt[i] == 'l' && p->fmt[i + 1] != 'l' && p->flg.l == 0)
			p->flg.l = 1;
		if (p->fmt[i] == 'L' && p->flg.maj_l == 0)
			p->flg.maj_l = 1;
		i++;
	}
	printf("h=%d | l=%d | L=%d\n", p->flg.h, p->flg.l, p->flg.maj_l);
	return (i);
}

int		parse_flags(t_print *p/*,const char **fmt*/, int i)
{
	//printf("PARSE\n");
	while (p->fmt[i] != '\0' && istype(p->fmt[i]) == 0 &&
	(!ft_isdigit(p->fmt[i]) || p->fmt[i] == '0'))
	{
		if (p->fmt[i] == '+' && p->flg.plus == 0)
			p->flg.plus = 1;
		if (p->fmt[i] == '-' && p->flg.minus == 0)
			p->flg.minus = 1;
		if (p->fmt[i] == ' ' && p->flg.space == 0)
			p->flg.space = 1;
		if (p->fmt[i] == '#' && p->flg.hash == 0)
			p->flg.hash = 1;
		if (p->fmt[i] == '0' && p->flg.zero == 0)
			p->flg.zero = 1;
		i++;
	}
	printf("{fmt[i]=%c}",p->fmt[i]);
	if (ft_isdigit(p->fmt[i]))
		i = get_width_pres(p, i);
	if (p->fmt[i] == 'h' || p->fmt[i] == 'l' || p->fmt[i] == 'L')
		i = parse_flags2(p, i);
	//printf("plus=%d | minus=%d | zero=%d | space=%d | hash=%d | width=%d | pres=%d | h=%d | l=%d | L=%d\n", p->flg.plus, p->flg.minus, p->flg.zero, p->flg.space, p->flg.hash, p->width, p->pres, p->flg.h, p->flg.l, p->flg.maj_l);
	printf("plus=%d | minus=%d | zero=%d | space=%d | hash=%d | width=%d | pres=%d\n", p->flg.plus, p->flg.minus, p->flg.zero, p->flg.space, p->flg.hash, p->width, p->pres);
	//	printf("{fmt[i]=%c}",p->fmt[i]);
	p->type = p->fmt[i];
	printf("TYPE=%c\n", p->type);
	return (i);
}

/* For diouxX
** h	>>	short (unsigned) int
** hh	>>	(unsigned) char
** l	>>	long (unsigned) int
** ll	>>	long long (unsigned) int
** for f
** l	>>	no diff in printf but scanf it's a double
** L	>>	long (unsigned) double
*/

/*intmax_t	convert_hhll(va_list ap, t_print *p)
{
	//type	s;
	intmax_t	s;
	//intmax_t s;

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
	return (s);
}*/

t_print	*init_flags(t_print *p)
{
	p->width = 0;
	p->pres = -1;
	p->flg.plus = 0;
	p->flg.minus = 0;
	p->flg.space = 0;
	p->flg.zero = 0;
	p->flg.hash = 0;
	p->flg.h = 0;
	p->flg.l = 0;
	p->flg.maj_l = 0;
	return (p);
}

int		conversion(va_list ap, char c, t_print *p)/*, char c, int i)*/
{
	if (c == 'c')
		convert_c(ap, p);
	if (c == 's')
		convert_s(ap, p);
	if (c == 'p')
		convert_p(ap, p);
	if (c == 'd' || c == 'i')
		convert_di(ap, p);
	if (c == 'o')
		convert_o(ap, p);
	if (c == 'u')
		convert_u(ap, p);
	if (c == 'x' || c == 'X')
		convert_x(ap, c, p);
	if (c == 'f')
		convert_f(ap, p);
	if (c == '%')
		convert_percent(ap, p);
	return (1);
}
