/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 16:11:13 by mbui              #+#    #+#             */
/*   Updated: 2020/10/12 17:01:32 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	putsign(int n,t_print *p)
{
	if (p->flg.plus && n >= 0)
		ft_putchar('+');
	else if (n < 0)
		ft_putchar('-');
}

void	padding_zero(int str_len, t_print *p)
{
	//int	len;

	//len = ft_strlen(s);
	while (p->pres-- - str_len > 0)
		ft_putchar('0');
}

void	padding_space(int str_len, t_print *p)
{
	int	len;

	len = p->pres;
	(str_len > p->pres) ? len = str_len : len;
	while (p->width-- - len > 0)
		ft_putchar(' ');
}
