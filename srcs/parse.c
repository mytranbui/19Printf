/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:39:00 by mbui              #+#    #+#             */
/*   Updated: 2020/10/28 22:18:30 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

/*
** '0' ignored when '-' is present
** ' ' ignored when '+' is present
*/

int	get_flag(t_print *p, int i)
{
	while (isflag(p->fmt[i]) && p->fmt[i])
	{
		if (p->fmt[i] == '+')
			p->flg.plus = 1;
		else if (p->fmt[i] == '-')
			p->flg.minus = 1;
		else if (p->fmt[i] == ' ')
			p->flg.space = 1;
		else if (p->fmt[i] == '#')
			p->flg.hash = 1;
		else if (p->fmt[i] == '0')
			p->flg.zero = 1;
		i++;
	}
	if (p->flg.minus)
		p->flg.zero = 0;
	if (p->flg.plus)
		p->flg.space = 0;
	return (i);
}

int	get_size(t_print *p, int i)
{
	while (issize(p->fmt[i]) && p->fmt[i])
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

int	get_wildcard(va_list ap, t_print *p, int i)
{
	int	n;

	n = va_arg(ap, int);
	if (p->fmt[i] == '*')
		if (n < 0)
			p->flg.minus = 1;
	return (n);
}

int	get_width_pres(va_list ap, t_print *p, int i)
{
	if (ft_isdigit(p->fmt[i]))
	{
		p->width = ft_atoi(&p->fmt[i]);
		while (ft_isdigit(p->fmt[i]))
			i++;
	}
	else if (p->fmt[i] == '*')
	{
		p->width = ft_abs(get_wildcard(ap, p, i));
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
			p->pres = get_wildcard(ap, p, i);
			(p->pres < -1) ? p->pres = -1 : p->pres;
			i++;
		}
	}
	return (i);
}

int	parse(va_list ap, t_print *p, int i)
{
	while (!istype(p->fmt[i]) && p->fmt[i] != '\0')
	{
		i = get_flag(p, i);
		i = get_width_pres(ap, p, i);
		i = get_size(p, i);
		// if (!isflag(p->fmt[i]) || !ft_isdigit(p->fmt[i]) || !issize(p->fmt[i]) ||
		//  p->fmt[i] != '.' || p->fmt[i] != '*')
		// 	i++;
	}
	//printf("plus=%d | minus=%d | zero=%d | space=%d | hash=%d | width=%d | pres=%d | h=%d | l=%d | L=%d\n", p->flg.plus, p->flg.minus, p->flg.zero, p->flg.space, p->flg.hash, p->width, p->pres, p->flg.h, p->flg.l, p->flg.maj_l);
	//	printf("{fmt[i]=%c}",p->fmt[i]);
	p->type = p->fmt[i];
	return (i);
}
