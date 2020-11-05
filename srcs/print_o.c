/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:01:48 by mbui              #+#    #+#             */
/*   Updated: 2020/10/28 21:18:46 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** %o: undefined behavior with '+', ' '
*/

static void	print_result_o(char *s, int pres, t_print *p)
{
	if(*s != '0' || pres != 0 || p->flg.hash)
	{
		ft_putstr(s);
		p->ret += ft_strlen(s);
	}
}

static void	print_o2(char *s, t_print *p, int bigger_len, int pres)
{
	int len;

	len = ft_strlen(s);
	padding_ze_sp(bigger_len, p);
	putprefix(s, p);
	padding_zero(len, p);
	print_result_o(s, pres, p);
}

void		print_o(uintmax_t arg, t_print *p)
{
	char	*s;
	int		len;
	int		bigger_len;
	int		tmp_pres;

	if (!(s = ft_utoa_base(arg, 8, 'x')))
		free_print(&p, 2);
	//printf("{s=%s}",s);
	//printf("{arg=%ju}",arg);
	len = ft_strlen(s);
	tmp_pres = p->pres;
	bigger_len = (len > p->pres) ? len : p->pres;
	p->flg.hash = (*s == '0' && p->pres != 0) ? 0 : p->flg.hash;
	(p->flg.hash && *s == '0') ? p->pres++ : p->pres;
	(p->flg.hash && *s != '0') ? p->width-- : p->width;
	(p->flg.hash && *s != '0' && p->pres > 0) ? p->pres-- : p->pres;
	(*s == '0' && !tmp_pres && !p->flg.hash) ? p->width++ : p->width;
	if (!p->flg.minus)
		print_o2(s, p, bigger_len, tmp_pres);
	else
	{
		padding_zero(len, p);
		putprefix(s, p);
		print_result_o(s, tmp_pres, p);
		padding_space(bigger_len, p);
	}
	free_strprint(&s);
}
