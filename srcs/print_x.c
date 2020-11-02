/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:28:09 by mbui              #+#    #+#             */
/*   Updated: 2020/10/28 21:16:51 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

/*
** %x & %X: undefined behavior with +, '0' and ' '
*/

static void	print_x2(const char *s, t_print *p, int bigger_len, int pres)
{
	int len;

	len = ft_strlen(s);
	if (p->flg.zero && p->pres == -1)
		putprefix(s, p);
	padding_ze_sp(bigger_len, p);
	if (!p->flg.zero || p->pres != -1)
		putprefix(s, p);
	padding_zero(len, p);
	print_result(0, s, pres, p);
}

void		print_x(uintmax_t arg, t_print *p)
{
	char		*s;
	int			len;
	int			bigger_len;
	int			tmp_pres;

	if (!(s = ft_utoa_base(arg, 16, p->type)))
		free_print(&p, 2);
	len = ft_strlen(s);
	tmp_pres = p->pres;
	bigger_len = (len > p->pres) ? len : p->pres;
	(*s != '0' && p->flg.hash) ? p->width -= 2 : p->width;
	(*s == '0' && !tmp_pres) ? p->width++ : p->width;
	if (!p->flg.minus)
		print_x2(s, p, bigger_len, tmp_pres);
	else
	{
		putprefix(s, p);
		padding_zero(len, p);
		print_result(0, s, tmp_pres, p);
		padding_space(bigger_len, p);
	}
	free_strprint(&s);
}
