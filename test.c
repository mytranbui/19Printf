/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:28:09 by mbui              #+#    #+#             */
/*   Updated: 2020/10/16 17:19:57 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <limits.h>

/*
** '0' ignored when '-' is present
** ' ' ignored when '+' is present
*/

/*
** %d & %i: undefined behavior with # (no effect)
*/

/*
** Since 2147483648 is greater than INT_MAX, then abs(-2147483648) is undefined
*/

//all ok except 2147483648
void	convert_di(intmax_t arg, t_print *p)
{
	char		*s;
	//intmax_t	v;
	int			n;
	int			len;
	int			bigger_len;
	int			tmp_pres;

	//v = va_arg(ap, long long);
	//n = ft_atoi(ft_itoa_base(arg, 10, 'x'));
	if (!(s = ft_itoa_base(arg, 10, 'x')))
		free_print(&p, 2);
	n = ft_atoi(s);
	len = ft_intlen(ft_dabs(arg));
	bigger_len = p->pres;
	tmp_pres = p->pres;
	(n < 0 || (p->flg.plus && n >= 0)) ? len++ && bigger_len++ : len;
	(len > p->pres) ? bigger_len = len : bigger_len;
	p->pres++; // why?
	(p->flg.plus == 0 && n >= 0) ? len++ : len;
	(p->flg.space && p->flg.plus == 0 && n >= 0) ? bigger_len++ : bigger_len;
	if (p->flg.space && p->flg.plus == 0 && n >= 0)
		ft_putchar(' ');
	if (p->flg.minus == 0)
	{
		padding_space(bigger_len, p);
		putsign(n, p);
		padding_zero(len, p);
		//(n == 0 && tmp_pres == 0) ? ft_putchar(' ') : ft_putnbr(ft_abs(arg));
		(n == 0 && tmp_pres == 0) ? ft_putchar(' ') : ft_putnbr(ft_dabs(arg));
	}
	else
	{
		putsign(n, p);
		padding_zero(len, p);
		//(n == 0 && tmp_pres == 0) ? ft_putchar(' ') : ft_putnbr(ft_abs(arg));
		(n == 0 && tmp_pres == 0) ? ft_putchar(' ') : ft_putnbr(ft_dabs(arg));
		padding_space(bigger_len, p);
	}
	free_strprint(&s);
}
//	v = v * (-1);
//	ft_putnbr(2147483647 + 1);
//	ft_putnbr(n * -1);
//	//printf("{v =%ju}", v);
//	//printf("{n =%d}", n);
//	//printf("{abs(n) =%d}", abs(n));
//	//printf("{ft_absu(INT_MIN) =%d}", ft_absu(n));
//	//printf("{len= %d}", len[0]);
//	//printf("{len[0] = %d}", len[0]);
//	//printf("{len[2] = %d}", len[2]);
//	//printf("{printed spaces=%d}\n", i);
//printf("{pres = %d}", p->pres);

/*
** %o: undefined behavior with '+', ' '
*/

void	convert_o(uintmax_t arg, t_print *p)
{
	char	*s;
	int		len;
	int		bigger_len;
	int		tmp_pres;

	//s = ft_itoa_base(va_arg(ap, unsigned long long), 8, 'x');
	if (!(s = ft_itoa_base(arg, 8, 'x')))
		free_print(&p, 2);
	len = ft_strlen(s);
	bigger_len = p->pres;
	tmp_pres = p->pres;
	(p->flg.hash) ? len++ : len;
	(p->flg.hash && *s == '0') ? len-- : len;
	(len > p->pres) ? bigger_len = len : bigger_len;
	if (*s == '0' && !tmp_pres && !p->flg.hash && !p->width)
		return ;
	if (p->flg.minus == 0)
	{
		while (p->width-- - bigger_len > 0)
			ft_putchar((p->flg.zero && p->pres == -1) ? '0' : ' ');
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
	if (!(s = ft_itoa_base(arg, 10, 'x')))
		free_print(&p, 2);
	len = ft_strlen(s);
	tmp_pres = p->pres;
	bigger_len = p->pres;
	(len > p->pres) ? bigger_len = len : bigger_len;
	if (p->flg.minus == 0)
	{
		while (p->width-- - bigger_len > 0)
			ft_putchar((p->flg.zero && p->pres == -1) ? '0' : ' ');
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
	if (!(s = ft_itoa_base(arg, 16, p->type)))
		free_print(&p, 2);
	len = ft_strlen(s);
	tmp_pres = p->pres;
	bigger_len = p->pres;
	(len > p->pres) ? bigger_len = len : bigger_len;
	(*s != '0' && p->flg.hash) ? bigger_len += 2 : bigger_len;
	if (p->flg.minus == 0 && p->pres == -1 && p->flg.hash)
	{
		putprefix(s, p);
		while (p->width-- - bigger_len > 0)
			ft_putchar((p->flg.zero) ? '0' : ' ');
		(*s == '0' && tmp_pres == 0) ? ft_putchar(' ') : ft_putstr(s);
	}
	else if (p->flg.minus == 0)
	{
		while (p->width-- - bigger_len > 0)// && !p->flg.hash)
			ft_putchar((p->flg.zero && p->pres == -1) ? '0' : ' ');
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
