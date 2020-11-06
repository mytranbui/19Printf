/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:22:04 by mbui              #+#    #+#             */
/*   Updated: 2020/11/06 14:26:59 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** %p: undefined behavior with +, 0, ' ', # and precision
** line 102: +2 is the len of the prefix "0x"
*/

static void	print_p2(int len, int bigger_len, t_print *p)
{
	while (p->width-- - bigger_len > 0 && (!p->flg.zero ||
				(p->pres == 0 && p->flg.zero)))
	{
		ft_putchar(' ');
		p->ret++;
	}
	putprefix(0, p);
	while (p->width-- - bigger_len > -1 && p->flg.zero && p->pres == -1)
	{
		ft_putchar('0');
		p->ret++;
	}
	padding_zero(len, p);
}

void		print_p(va_list ap, t_print *p)
{
	char	*s;
	int		len;
	int		bigger_len;
	int		tmp_pres;

	if (!(s = ft_itoa_base(va_arg(ap, long long), 16, 'x')))
		free_print(&p, 2);
	len = ft_strlen(s);
	tmp_pres = p->pres;
	(*s == '0' && tmp_pres == 0) ? p->width++ : p->width;
	bigger_len = (len > p->pres) ? len + 2 : p->pres + 2;
	if (!p->flg.minus)
	{
		print_p2(len, bigger_len, p);
		print_result(0, s, tmp_pres, p);
	}
	else
	{
		putprefix(0, p);
		padding_zero(len, p);
		print_result(0, s, tmp_pres, p);
		padding_space(bigger_len, p);
	}
	free_strprint(&s);
}
