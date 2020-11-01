/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:01:57 by mbui              #+#    #+#             */
/*   Updated: 2020/10/28 21:17:20 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

/*
** %u: undefined behavior with// '+', ' ', '#' ('#' has no effect)
*/

void	print_u(uintmax_t arg, t_print *p)
{
	char	*s;
	int		len;
	int		bigger_len;
	int		tmp_pres;

	//s = ft_itoa_base(va_arg(ap, unsigned int), 10, 'x');
	if (!(s = ft_utoa_base(arg, 10, 'x')))
		free_print(&p, 2);
	len = ft_strlen(s);
	tmp_pres = p->pres;
	bigger_len = (len > p->pres) ? len : p->pres;
	(*s == '0' && !tmp_pres) ? p->width++ : p->width;
	if (!p->flg.minus)
	{
		padding_ze_sp(bigger_len, p);
		padding_zero(len, p);
		print_result(0, s, tmp_pres, p);
	}
	else
	{
		padding_zero(len, p);
		print_result(0, s, tmp_pres, p);
		padding_space(bigger_len, p);
	}
	free_strprint(&s);
}
