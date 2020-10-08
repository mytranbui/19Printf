/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:39:00 by mbui              #+#    #+#             */
/*   Updated: 2020/09/25 12:10:09 by mbui             ###   ########.fr       */
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

int		parse_flags(t_print *p/*,const char **fmt*/, int i)
{
	while (p->fmt[i] != '\0' && istype(p->fmt[i]) == 0)
	{
		(p->fmt[i] == '+') ? p->flg.plus = 1 && i++ : p->flg.plus;
		(p->fmt[i] == '-') ? p->flg.minus = 1 && i++ : p->flg.minus;
		(p->fmt[i] == ' ') ? p->flg.space = 1 && i++ : p->flg.space;
		(p->fmt[i] == '#') ? p->flg.hash = 1 && i++ : p->flg.hash;
		(p->fmt[i] == '0') ? p->flg.zero = 1 && i++ : p->flg.zero;
		i = get_width_pres(p, i);
		if (p->fmt[i] == 'h' && p->fmt[i + 1] == 'h' && p->flg.h == 0)
		{
			p->flg.h = 2;
			i += 2;
		}
		if (p->fmt[i] == 'l' && p->fmt[i + 1] == 'l' && p->flg.l == 0)
		{
			p->flg.l = 2;
			i += 2;
		}
		(p->fmt[i] == 'h' && p->fmt[i + 1] != 'h' && p->flg.h == 0) ?
		p->flg.h = 1 && i++ : p->flg.h;
		(p->fmt[i] == 'l' && p->fmt[i + 1] != 'l' && p->flg.l == 0) ?
		p->flg.l = 1 && i++ : p->flg.l;
		(p->fmt[i] == 'L') ? p->flg.maj_l = 1 & i++ : p->flg.maj_l;
	}
	printf("plus=%d | minus=%d | zero=%d | space=%d | hash=%d | width=%d | pres=%d | h=%d | l=%d | L=%d\n", p->flg.plus, p->flg.minus, p->flg.zero, p->flg.space, p->flg.hash, p->width, p->pres, p->flg.h, p->flg.l, p->flg.maj_l);
	//	printf("{fmt[i]=%c}",p->fmt[i]);
	return (i);
}

/*int		convert_hhll(t_print *p)
  {
  if (p->flg.h == 1)
  }
  */
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
