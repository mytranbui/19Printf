/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 16:11:13 by mbui              #+#    #+#             */
/*   Updated: 2020/10/28 23:30:28 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	putprefix(char *s, t_print *p)
{
	if (p->flg.hash && *s != '0')
	{
		(p->type == 'x') ? ft_putstr("0x") : ft_putstr("0X");
		if (p->type == 'o')
			ft_putchar('0');
	}
}

// void	putsign(int n, t_print *p)
// {

// 	if (p->type == 'd' || p->type == 'i')
// 	{
// 		if (p->flg.plus && n >= 0)
// 			ft_putchar('+');
// 		else if (n < 0 && p->pres != -1)
// 			ft_putchar('-');
// 	}
// 	else if (!p->flg.minus)
// 	{
// 		if (p->flg.plus && n >= 0)
// 			ft_putchar('+');
// 		else if (n < 0 && p->flg.zero == 0)
// 			ft_putchar('-');
// 	}
// 	// if (p->type == 'f' && !p->flg.minus)
// 	// {
// 	// 	if (p->flg.plus && n >= 0)
// 	// 		ft_putchar('+');
// 	// 	else if (n < 0 && p->flg.zero == 0)
// 	// 		ft_putchar('-');
// 	// }
// 	else
// 	{
// 		if (p->flg.plus && n >= 0)
// 			ft_putchar('+');
// 		else if (n < 0)
// 			ft_putchar('-');
// 	}
// }

void	putsign(int n, t_print *p)
{
	if (p->flg.plus && n >= 0)
		ft_putchar('+');
	else if (!p->flg.minus && n < 0)
	{
		if (!p->flg.zero && p->type == 'f')
			ft_putchar('-');
		else if ((p->pres != -1 || !p->flg.zero) && (p->type == 'd' || p->type == 'i'))
			ft_putchar('-');
	}
	else if (n < 0)
		ft_putchar('-');
}

// void	putsign(int n, t_print *p, int minus)
// {
// 	if (p->flg.plus && n >= 0)
// 		ft_putchar('+');
// 	else if (!p->flg.minus && n < 0)
// 	{
// 		if (p->flg.zero && p->pres == -1 && minus == 0)
// 			ft_putchar('-');
// 		else if (!p->flg.zero && p->type == 'f')
// 	 		ft_putchar('-');
// 		else if ((p->pres != -1 || !p->flg.zero) && (p->type == 'd' || p->type == 'i') && minus == 1)
// 			ft_putchar('-');
// 	}
// 	else if (n < 0)
// 		ft_putchar('-');
// }

void	padding_zero(int len, t_print *p)
{
	while (p->pres-- - len > 0)
		ft_putchar('0');
}

void	padding_space(int len, t_print *p)
{
	while (p->width-- - len > 0)
		ft_putchar(' ');
}

void	padding_ze_sp(int len, t_print *p)
{
	if (p->type == 'c' || p->type == 's' || p->type == '%' || p->type == 'f')
		while (p->width-- - len > 0)
			ft_putchar((p->flg.zero && !p->flg.minus) ? '0' : ' ');
	else if (p->type == 'o' || p->type == 'u' ||
			p->type == 'x' || p->type == 'X' || p->type == 'd' || p->type == 'i')
		while (p->width-- - len > 0 && !p->flg.minus)
			ft_putchar((p->flg.zero && p->pres == -1) ? '0' : ' ');
}
