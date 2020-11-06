/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cspercent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 09:38:25 by mbui              #+#    #+#             */
/*   Updated: 2020/11/03 18:26:48 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** %c: undefined behavior with +, 0, ' ', # and precision
*/

void	print_c(va_list ap, t_print *p)
{
	long long	c;

	c = va_arg(ap, long long);
	if (p->flg.minus)
		ft_putchar(c);
	padding_ze_sp(1, p);
	if (!p->flg.minus)
		ft_putchar(c);
	p->ret++;
}

void	print_percent(t_print *p)
{
	if (p->flg.minus)
		ft_putchar('%');
	padding_ze_sp(1, p);
	if (!p->flg.minus)
		ft_putchar('%');
	p->ret++;
}

/*
** %s: undefined behavior with +, 0, ' ', #
*/

void	print_s(va_list ap, t_print *p)
{
	char	*s;
	int		len;

	s = va_arg(ap, char *);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (p->pres != -1 && p->pres < len)
		len = p->pres;
	if (p->flg.minus)
		write(1, s, len);
	padding_ze_sp(len, p);
	if (!p->flg.minus)
		write(1, s, len);
	p->ret += len;
}
