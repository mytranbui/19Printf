/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:28:09 by mbui              #+#    #+#             */
/*   Updated: 2020/10/12 17:30:28 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <limits.h>

int	ft_putstr_len_percent(const char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	write(1, str, i);
	return (i);
}

/*
** '0' ignored when '-' is present
** ' ' ignored when '+' is present
*/

/*
** %c: undefined behavior with +, 0, ' ', # and presion
*/

void	convert_c(va_list ap, t_print *p)
{
	//printf("\nconvert_c\n");
	long long	c;

	c = va_arg(ap, long long);
	if (p->flg.minus)
		ft_putchar(c);
	while (p->width-- - 1 > 0)
		(p->flg.zero && p->flg.minus == 0) ? ft_putchar('0') : ft_putchar(' ');
	if (!p->flg.minus)
		ft_putchar(c);
}

void	convert_percent(va_list ap, t_print *p)
{
	//printf("\nconvert_percent\n");
	long long	c;

	c = (char)va_arg(ap, long long);
	if (p->flg.minus)
		ft_putchar('%');
	while (p->width-- > 1)
		(p->flg.zero && p->flg.minus == 0) ? ft_putchar('0') : ft_putchar(' ');
	if (!p->flg.minus)
		ft_putchar('%');
}

/*
** %s: undefined behavior with +, 0, ' ', #
*/

void	convert_s(va_list ap, t_print *p)
{
	//printf("\nconvert_s\n");
	char	*s;
	int		len;

	s = va_arg(ap, char *);
	if (!s)
		ft_putstr("(null)");
	else
	{
		len = ft_strlen(s);
		if (p->pres != -1 && p->pres < len)
			len = p->pres;
		if (p->flg.minus)
			write(1, s, len);
		while (p->width-- - len > 0)
			(p->flg.zero && !p->flg.minus) ? ft_putchar('0') : ft_putchar(' ');
		if (!p->flg.minus)
			write(1, s, len);
	}
}

/*
** %p: undefined behavior with +, 0, ' ', # and presion
*/

void	convert_p(va_list ap, t_print *p)
{
	//printf("\nconvert_p\n");
	char	*s;
	int		len[2];
	int		tmp_pres;

	s = ft_itoa_base(va_arg(ap, long long), 16, 'x');
	len[0] = ft_strlen(s);//+2; //+0x
	len[1] = p->pres;
	tmp_pres = p->pres;
	(*s == '0' && tmp_pres == 0) ? p->width++ : p->width;
	(len[0] > p->pres) ? len[1] = len[0] : len[1];
	if (p->flg.minus == 0)
	{
		while (p->width-- - len[1] > 2 && (p->flg.zero == 0 ||
					(p->pres == 0 && p->flg.zero)))
			ft_putchar(' ');
		ft_putstr("0x");
		while (p->width-- - len[1] > 1 && p->flg.zero && p->pres == -1)
			ft_putchar('0');
		padding_zero(len[0], p);
		(*s == '0' && tmp_pres == 0) ? s = NULL : ft_putstr(s);
	}
	else
	{
		ft_putstr("0x");
		padding_zero(len[0], p);
		(*s == '0' && tmp_pres == 0) ? s = NULL : ft_putstr(s);
		while (p->width-- - len[1] > 2)// 0)
			ft_putchar(' ');
	}
	ft_strdel(&s);
}

/*
** %d & %i: undefined behavior with # (no effect)
*/
//kk
/*unsigned int	ft_absu(int value)
{
	return (value < 0) ? -((unsigned int)value) : (unsigned int)value;
}
*/
/*
** Since 2147483648 is greater than INT_MAX, then abs(-2147483648) is undefined
*/

//all ok except 2147483648
void	convert_di(va_list ap, t_print *p)
{
	//printf("\nconvert_di\n");
	intmax_t v;
	int		n;
	int		len[2];
	int		tmp_pres;

	v = va_arg(ap, long long);
	n = ft_atoi(ft_itoa_base(v, 10, 'x'));
	len[0] = ft_intlen(ft_abs(v));
	//	//printf("{len[0] = %d}", len[0]);
	len[1] = p->pres;
	tmp_pres = p->pres;
	(n < 0 || (p->flg.plus && n >= 0)) ? len[0]++ && len[1]++ : len[0];
	(len[0] > p->pres) ? len[1] = len[0] : len[1];
	(p->flg.plus == 0 && n >= 0) ? len[0]++ : len[0]; //why ?0+
	//	//printf("intlen=%d\n", len[0]);
	//	//printf("value=%d\n", n);
	(p->flg.space && p->flg.plus == 0 && n >= 0) ? len[1]++ : len[1];
	if (p->flg.space && p->flg.plus == 0 && n >= 0)
		ft_putchar(' ');
	if (p->flg.minus == 0)
	{
		while (p->width-- - len[1] > 0)
			ft_putchar(' ');
		putsign(n, p);
	//	else if (n < 0)// && n != -2147483648)
	//		ft_putchar('-');
		while (p->pres-- - len[0] > -1)
			ft_putchar('0');
		(tmp_pres == 0 && n == 0) ? ft_putchar(' ') : ft_putnbr(ft_abs(v));
	}
	else
	{
		putsign(n, p);
	//	else if (n < 0)// && n != -2147483648)
	//		ft_putchar('-');
		while (p->pres-- - len[0] > -1) //why? -1 ??
			ft_putchar('0');
		(tmp_pres == 0 && n == 0) ? ft_putchar(' ') : ft_putnbr(ft_abs(v));
		while (p->width-- - len[1] > 0)
			ft_putchar(' ');
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
}

/*
** %o: undefined behavior with '+', ' '
*/

void	convert_o(va_list ap, t_print *p)
{
	//printf("\nconvert_o\n");
	char	*s;
	int		len[2];
	int		tmp_pres;

	s = ft_itoa_base(va_arg(ap, unsigned long long), 8, 'x');
	len[0] = ft_strlen(s);
	len[1] = p->pres;
	tmp_pres = p->pres;
	(p->flg.hash) ? len[0]++ : len[0];
	(p->flg.hash && *s == '0') ? len[0]-- : len[0];
	(len[0] > p->pres) ? len[1] = len[0] : len[1];
	if (*s == '0' && p->pres == 0 && !p->width && !p->flg.hash)
		return ;
	if (p->flg.minus == 0)
	{
		while (p->width-- - len[1] > 0)
			(p->flg.zero && p->pres == -1) ? ft_putchar('0') : ft_putchar(' ');
		if (p->flg.hash && *s != '0')
			ft_putchar('0');
		padding_zero(len[0], p);
		(!tmp_pres && *s == '0' && !p->flg.hash) ? ft_putchar(' ') : ft_putstr(s);
	}
	else
	{
		padding_zero(len[0], p);
		if (p->flg.hash && *s != '0')
			ft_putchar('0');
		(!tmp_pres && *s == '0' && !p->flg.hash) ? ft_putchar(' ') : ft_putstr(s);
		while (p->width-- - len[1] > 0)
			ft_putchar(' ');
	}
	if (*s != '0')
		ft_strdel(&s);
}

/*
** %u: undefined behavior with// '+', ' ', '#' ('#' has no effect)
*/

void	convert_u(va_list ap, t_print *p)
{
	//printf("\nconvert_u\n");
	char	*s;
	int		len[2];
	int		tmp_pres;

	s = ft_itoa_base(va_arg(ap, unsigned int), 10, 'x');
	len[0] = ft_strlen(s);
	len[1] = p->pres;
	tmp_pres = p->pres;
	(len[0] > p->pres) ? len[1] = len[0] : len[1];
	if (p->flg.minus == 0)
	{
		while (p->width-- - len[1] > 0)
			(p->flg.zero && p->pres == -1) ? ft_putchar('0') : ft_putchar(' ');
		padding_zero(len[0], p);
		(tmp_pres == 0 && *s == '0') ? ft_putchar(' ') : ft_putstr(s);
	}
	else
	{
		padding_zero(len[0], p);
		(tmp_pres == 0 && *s == '0') ? ft_putchar(' ') : ft_putstr(s);
		while (p->width-- - len[1] > 0)
			ft_putchar(' ');
	}
	if (*s != '0')
		ft_strdel(&s);
}

/*
** %x & %X: undefined behavior with +, '0' and ' '
*/

/*
**len[0] = length of the va_arg
**len[1] = p->pres (or length of va_arg if bigger than p->pres)
**len[2] = tmp of p->pres
*/
void	convert_x(va_list ap, char c, t_print *p)
{
	//printf("\nconvert_x\n");
	char	*s;
	int		len;
	int		bigger_len;
	int		tmp_pres;
	int		leno[2];

	s = ft_itoa_base(va_arg(ap, unsigned long long), 16, c);
	len = ft_strlen(s);
	tmp_pres = p->pres;
	bigger_len = p->pres;
	(len > p->pres) ? bigger_len = len : bigger_len;
	(p->flg.hash && *s != '0') ? bigger_len += 2 : bigger_len;
	if (p->flg.minus == 0 && p->pres == -1 && p->flg.hash)
	{
		putprefix(c, s, p);
		while (p->width-- - bigger_len > 0)
			(p->flg.zero) ? ft_putchar('0') : ft_putchar(' ');
		(tmp_pres == 0 && *s == '0') ? ft_putchar(' ') : ft_putstr(s);
	}
	else if (p->flg.minus == 0)
	{
		while (p->width-- - bigger_len > 0)// && !p->flg.hash)
			(p->flg.zero && p->pres == -1) ? ft_putchar('0') : ft_putchar(' ');
		putprefix(c, s, p);
		padding_zero(len, p);
		(tmp_pres == 0 && *s == '0') ? ft_putchar(' ') : ft_putstr(s);
	}
	else
	{
		putprefix(c, s, p);
		padding_zero(len, p);
		(tmp_pres == 0 && *s == '0') ? ft_putchar(' ') : ft_putstr(s);
		while (p->width-- - bigger_len > 0)
			ft_putchar(' ');
	}
	if (*s != '0')
		ft_strdel(&s);
}
