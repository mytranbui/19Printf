/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:39:00 by mbui              #+#    #+#             */
/*   Updated: 2020/09/23 10:12:25 by mbui             ###   ########.fr       */
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
		(p->fmt[i] == 'h' && p->fmt[i + 1] != 'h' && p->flg.h == 0) ? p->flg.h = 1 && i++ : p->flg.h;
		(p->fmt[i] == 'l' && p->fmt[i + 1] != 'l' && p->flg.l == 0) ? p->flg.l = 1 && i++ : p->flg.l;
		(p->fmt[i] == 'L') ? p->flg.maj_l = 1 & i++: p->flg.maj_l;
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

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_print	*p;
	int		i;
	//	int l;
	//	char c;
	i = 0;
	if (!(p = (t_print*)ft_memalloc(sizeof(t_print)))) //protect not needed?
		return (-1);
	p = init_flags(p);
	va_start(ap, format);
	p->fmt = format;
	//parse(ap, );
	while (p->fmt[i])
	{
		if (p->fmt[i] == '%')
		{
			i++;
			p = init_flags(p);
			i = parse_flags(p, i);
		//	i = parse_type(p,i);
		//	printf("\n=== where I am at : %c ===\n", p->fmt[i]);
	//		convert_hhll(ap, p->fmt[i], p);
			conversion(ap, p->fmt[i], p);
		}
		//else
		//	ft_putendl("not implemented or undefined");
		else
		{
			i += ft_putstr_len(&p->fmt[i]);
			i--;
		}
		i++;
	}
	va_end(ap);
	return (1);
}
