/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:41:38 by mbui              #+#    #+#             */
/*   Updated: 2020/09/21 13:31:58 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	convert_f(va_list ap, t_print *p)
{
	printf("\nconvert_f\n");
	intmax_t	n;
	char		*s;
	int		len[3];

	n = va_arg(ap, double);
//	printf("{n=%ji}",n);
//	s = ft_itoa_base(n, 10, 'x');
//	printf("{s=%s}",s);
//	len[0] = ft_strlen(s);
	len[0] = ft_intlen(n);
	len[1] = len[2] = p->pres;
	(len[0] > len[1]) ? len[1] = len[0] : len[1];
	if (p->flg.minus == 0)
	{
		while (p->width-- - len[1] > 0)
			(p->flg.zero && p->pres == -1) ? ft_putchar('0') : ft_putchar(' ');
		while (p->pres-- - len[0] > 0)
			ft_putchar('0');
	//	(len[2] == 0 && *s == '0') ? ft_putchar(' ') : ft_putstr(s);
		(len[2] == 0 && *s == '0') ? ft_putchar(' ') : ft_putnbr(n);
	}
	else
	{
		while (p->pres-- - len[0] > 0)
			ft_putchar('0');
	//	(len[2] == 0 && *s == '0') ? ft_putchar(' ') : ft_putstr(s);
		(len[2] == 0 && *s == '0') ? ft_putchar(' ') : ft_putnbr(n);
		while (p->width-- - len[1] > 0)
			ft_putchar(' ');
	}
}
