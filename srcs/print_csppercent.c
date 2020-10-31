/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csppercent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 09:38:25 by mbui              #+#    #+#             */
/*   Updated: 2020/10/20 15:30:57 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

/*
** '0' ignored when '-' is present
** ' ' ignored when '+' is present
*/

/*
** %c: undefined behavior with +, 0, ' ', # and precision
*/

void	print_c(va_list ap, t_print *p)
{
	long long	c;

	c = va_arg(ap, long long);
	if (p->flg.minus)
		ft_putchar(c);
	padding_ze_sp(1, p);
	if (!p->flg.minus)
		ft_putchar(c);
	p->ret++;
}

void	print_percent(t_print *p)
{
	if (p->flg.minus)
		ft_putchar('%');
	padding_ze_sp(1, p);
	if (!p->flg.minus)
		ft_putchar('%');
	p->ret++;
}

/*
** %s: undefined behavior with +, 0, ' ', #
*/

void	print_s(va_list ap, t_print *p)
{
	char	*s;
	int		len;

	s = va_arg(ap, char *);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (p->pres != -1 && p->pres < len)
		len = p->pres;
	if (p->flg.minus)
		write(1, s, len);
	padding_ze_sp(len, p);
	if (!p->flg.minus)
		write(1, s, len);
	p->ret += len;
}

/*
** %p: undefined behavior with +, 0, ' ', # and precision
** line 102: +2 is the len of the prefix "0x"
*/

void	print_p2(int len, int bigger_len, t_print *p)
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

void	print_p(va_list ap, t_print *p)
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
		print_result(s, tmp_pres, p);
	}
	else
	{
		putprefix(0, p);
		padding_zero(len, p);
		print_result(s, tmp_pres, p);
		padding_space(bigger_len, p);
	}
	free_strprint(&s);
}

// void	print_p(va_list ap, t_print *p)
// {
// 	char	*s;
// 	int		len;
// 	int		bigger_len;
// 	int		tmp_pres;

// printf("lol");
// 	if (!(s = ft_itoa_base(va_arg(ap, long long), 16, 'x')))
// 		free_print(&p, 2);
// 		printf("lol");
// 	len = ft_strlen(s);
// 	tmp_pres = p->pres;
// 	(*s == '0' && tmp_pres == 0) ? p->width++ : p->width;
// 	bigger_len = (len > p->pres) ? len + 2 : p->pres + 2;
// 	if (!p->flg.minus)
// 	{
// 		print_p2(len, bigger_len, p);
// 		printf("lol");
// 		(*s == '0' && tmp_pres == 0) ? s = NULL : ft_putstr(s);
// 		printf("lol");
// 	}
// 	else
// 	{
// 		putprefix(0, p);
// 		padding_zero(len, p);
// 		(*s == '0' && tmp_pres == 0) ? s = NULL : ft_putstr(s);
// 		padding_space(bigger_len, p);
// 	}
// 	printf("lol");
// 	if (s)
// 	{
// 		printf("{ret=%d}", p->ret);
// 		p->ret += len;
// 		printf("{ret=%d}", p->ret);
// 	}
// 	free_strprint(&s);
// }