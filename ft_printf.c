/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 14:59:34 by mbui              #+#    #+#             */
/*   Updated: 2020/10/16 16:09:42 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


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

	i = 0;
	if (!(p = (t_print*)ft_memalloc(sizeof(t_print))))
		return (-1);
	va_start(ap, format);
	p->fmt = format;
	while (p->fmt[i])
	{
		if (p->fmt[i] == '%')
		{
			i++;
			p = init_flags(p);
			i = parse(ap, p, i);
			conversion(ap, p);
		}
		else
			i += ft_putstr_len_percent(&p->fmt[i]);
		i++;
	}
	va_end(ap);
	free_print(&p, 1);
	return (1);
}
//memalloc protect needed?
//else
//	ft_putendl("not implemented or undefined");

//free p bwtween %
//fail itoa -> free p then exit
