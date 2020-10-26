/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:28:09 by mbui              #+#    #+#             */
/*   Updated: 2020/10/26 18:32:07 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <limits.h>

/*
** %d & %i: undefined behavior with # (no effect)
*/

/*
** Since 2147483648 is greater than INT_MAX, then abs(-2147483648) is undefined
*/

void	convert_di(intmax_t arg, t_print *p)
{
	int			len;
	int			bigger_len;
	int			tmp_pres;

	len = ft_intlen(ft_dabs(arg));
	tmp_pres = p->pres;
	bigger_len = (len > p->pres) ? len : p->pres;
	(arg < 0 || (p->flg.plus && arg >= 0)) ? len++ && bigger_len++ : len;
	(p->flg.plus == 0 && arg >= 0) ? len++ : len;
	(p->flg.space && p->flg.plus == 0 && arg >= 0) ? bigger_len++ : bigger_len;
	(arg == 0) ? len++ && bigger_len++ : len;
	(arg == 0 && p->width > 0 && p->pres > 0 && !p->flg.plus) ? bigger_len-- : bigger_len;
	//(arg == 0 && !p->flg.plus && p->pres >= 0) ? bigger_len-- : bigger_len;
	//(arg == 0 && !tmp_pres && p->flg.plus) ? bigger_len++ : bigger_len;
	len--;
	if (p->flg.space && p->flg.plus == 0 && arg >= 0)
		ft_putchar(' ');
	if (!p->flg.minus)
	{
		if (arg < 0 && p->flg.zero && p->pres == -1)
			ft_putchar('-');
		padding_ze_sp(bigger_len, p);
		putsign(arg, p);
		padding_zero(len, p);
		(arg == 0 && tmp_pres == 0) ? ft_putchar(' ') : ft_putnbrmax(ft_dabs(arg));
	}
	else
	{
		putsign(arg, p);
		padding_zero(len, p);
		(arg == 0 && tmp_pres == 0) ? ft_putchar(' ') : ft_putnbrmax(ft_dabs(arg));
		padding_space(bigger_len, p);
	}
}

/*
** %o: undefined behavior with '+', ' '
*/

void	convert_o(uintmax_t arg, t_print *p)
{
	char	*s;
	int		len;
	int		bigger_len;
	int		tmp_pres;

	if (!(s = ft_utoa_base(arg, 8, 'x')))
		free_print(&p, 2);
	len = ft_strlen(s);
	tmp_pres = p->pres;
	(p->flg.hash) ? len++ : len;
	(p->flg.hash && *s == '0') ? len-- : len;
	bigger_len = (len > p->pres) ? len : p->pres;
	if (*s == '0' && !tmp_pres && !p->flg.hash && !p->width)
		return ;
	if (!p->flg.minus)
	{
		padding_ze_sp(bigger_len, p);
		if (p->flg.hash && *s != '0')
			ft_putchar('0');
		padding_zero(len, p);
		(*s == '0' && !tmp_pres && !p->flg.hash) ? ft_putchar(' ') : ft_putstr(s);
	}
	else
	{
		padding_zero(len, p);
		if (p->flg.hash && *s != '0')
			ft_putchar('0');
		(*s == '0' && !tmp_pres && !p->flg.hash) ? ft_putchar(' ') : ft_putstr(s);
		padding_space(bigger_len, p);
	}
	free_strprint(&s);
}

/*
** %u: undefined behavior with// '+', ' ', '#' ('#' has no effect)
*/

void	convert_u(uintmax_t arg, t_print *p)
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
	if (!p->flg.minus)
	{
		padding_ze_sp(bigger_len, p);
		padding_zero(len, p);
		(*s == '0' && tmp_pres == 0) ? ft_putchar(' ') : ft_putstr(s);
	}
	else
	{
		padding_zero(len, p);
		(*s == '0' && tmp_pres == 0) ? ft_putchar(' ') : ft_putstr(s);
		padding_space(bigger_len, p);
	}
	free_strprint(&s);
}

/*
** %x & %X: undefined behavior with +, '0' and ' '
*/

void	convert_x(uintmax_t arg, t_print *p)
{
	char		*s;
	int			len;
	int			bigger_len;
	int			tmp_pres;

	//s = ft_itoa_base(va_arg(ap, unsigned long long), 16, p->type);
	if (!(s = ft_utoa_base(arg, 16, p->type)))
		free_print(&p, 2);
	len = ft_strlen(s);
	tmp_pres = p->pres;
	bigger_len = (len > p->pres) ? len : p->pres;
	(*s != '0' && p->flg.hash) ? bigger_len += 2 : bigger_len;
	if (!p->flg.minus)
	{
		padding_ze_sp(bigger_len, p);
		// while (p->width-- - bigger_len > 0)// && !p->flg.hash)
		// 	ft_putchar((p->flg.zero && p->pres == -1) ? '0' : ' ');
		putprefix(s, p);
		padding_zero(len, p);
		(*s == '0' && tmp_pres == 0) ? ft_putchar(' ') : ft_putstr(s);
	}
	else
	{
		putprefix(s, p);
		padding_zero(len, p);
		(*s == '0' && tmp_pres == 0) ? ft_putchar(' ') : ft_putstr(s);
		padding_space(bigger_len, p);
	}
	free_strprint(&s);
}
