/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 16:11:13 by mbui              #+#    #+#             */
/*   Updated: 2020/10/19 16:24:35 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	putprefix(char *s, t_print *p)
{
	if (p->flg.hash && *s != '0')
		(p->type == 'x') ? ft_putstr("0x") : ft_putstr("0X");
}

void	putsign(int n, t_print *p)
{
	if (p->type == 'f' && !p->flg.minus)
	{
		if (p->flg.plus && n >= 0)
			ft_putchar('+');
		else if (n < 0 && p->flg.zero == 0)
			ft_putchar('-');
	}
	else
	{
		if (p->flg.plus && n >= 0)
			ft_putchar('+');
		else if (n < 0)
			ft_putchar('-');
	}
}

void	padding_zero(int len, t_print *p)
{
	while (p->pres-- - len > 0)
		ft_putchar('Z');
}

void	padding_space(int len, t_print *p)
{
	while (p->width-- - len > 0)
		ft_putchar('P');
}

void	padding_ze_sp(int len, t_print *p)
{
	if (p->type == 'c' || p->type == 's' || p->type == '%' || p->type == 'f')
		while (p->width-- - len > 0)
			ft_putchar((p->flg.zero && !p->flg.minus) ? '0' : ' ');
	else if (p->type == 'o' || p->type == 'u' ||
	p->type == 'x' || p->type == 'X')
		while (p->width-- - len > 0 && !p->flg.minus)
			ft_putchar((p->flg.zero && p->pres == -1) ? '0' : ' ');
}
