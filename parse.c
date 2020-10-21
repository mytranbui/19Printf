/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:39:00 by mbui              #+#    #+#             */
/*   Updated: 2020/10/16 17:50:50 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		get_width_pres(va_list ap, t_print *p, int i)
{
	if (ft_isdigit(p->fmt[i]))
	{
		p->width = ft_atoi(&p->fmt[i]);
		while (ft_isdigit(p->fmt[i]))
			i++;
	}
	else if (p->fmt[i] == '*')
	{
		p->width = va_arg(ap, int);
		i++;
	}
	if (p->fmt[i] == '.')
	{
		i++;
		p->pres = ft_atoi(&p->fmt[i]);
		while (ft_isdigit(p->fmt[i]))
			i++;
		if (p->fmt[i] == '*')
		{
			p->pres = va_arg(ap, int);
			i++;
		}
	}
	return (i);
}

int		parse_size(t_print *p, int i)
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
	return (i);
}

int		parse_flags(va_list ap, t_print *p, int i)
{
	while (p->fmt[i] != '\0' && !istype(p->fmt[i]) && (!ft_isdigit(p->fmt[i])
	|| p->fmt[i] == '0') && p->fmt[i] != '.' && p->fmt[i] != '*' &&
	 !issize(p->fmt[i]))
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
	i = get_width_pres(ap, p, i);
//	if (p->fmt[i] == 'h' || p->fmt[i] == 'l' || p->fmt[i] == 'L')
	i = parse_size(p, i);
	printf("plus=%d | minus=%d | zero=%d | space=%d | hash=%d | width=%d | pres=%d | h=%d | l=%d | L=%d\n", p->flg.plus, p->flg.minus, p->flg.zero, p->flg.space, p->flg.hash, p->width, p->pres, p->flg.h, p->flg.l, p->flg.maj_l);
	//	printf("{fmt[i]=%c}",p->fmt[i]);
	p->type = p->fmt[i];
//	printf("TYPE=%c\n", p->type);
	return (i);
}

int		conversion(va_list ap, t_print *p)
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
		convert_o(convert_arg_ouxx(ap, p), p);
	else if (p->type == 'u')
		convert_u(convert_arg_ouxx(ap, p), p);
	else if (p->type == 'x' || p->type == 'X')
		convert_x(convert_arg_ouxx(ap, p), p);
	else if (p->type == 'f')
		convert_f(convert_arg_f(ap, p), p);
	else if (p->type == '%')
		convert_percent(ap, p);
	return (1);
}
