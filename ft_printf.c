/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 14:59:34 by mbui              #+#    #+#             */
/*   Updated: 2020/09/24 15:25:19 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

//memalloc protect needed?
int ft_printf(const char *format, ...)
{
	va_list	ap;
	t_print	*p;
	int		i;
	//	int l;
	//	char c;
	i = 0;
	if (!(p = (t_print*)ft_memalloc(sizeof(t_print))))
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
