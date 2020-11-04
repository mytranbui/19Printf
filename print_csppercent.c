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


/*
** '0' ignored when '-' is present
** ' ' ignored when '+' is present
*/

/*
** %c: undefined behavior with +, 0, ' ', # and precision
*/

void	convert_c(va_list ap, t_print *p)
{
	long long	c;

	c = va_arg(ap, long long);
	if (p->flg.minus)
		ft_putchar(c);
	padding_ze_sp(1, p);
	if (!p->flg.minus)
		ft_putchar(c);
}

void	convert_percent(va_list ap, t_print *p)
{
	long long	c;

	c = (char)va_arg(ap, long long);
	if (p->flg.minus)
		ft_putchar('%');
	padding_ze_sp(1, p);
	if (!p->flg.minus)
		ft_putchar('%');
}

/*
** %s: undefined behavior with +, 0, ' ', #
*/

void	convert_s(va_list ap, t_print *p)
{
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
		padding_ze_sp(len, p);
		if (!p->flg.minus)
			write(1, s, len);
	}
}

/*
** %p: undefined behavior with +, 0, ' ', # and precision
** line 102: +2 is the len of the prefix "0x"
*/

void	convert_p2(int len, int bigger_len, t_print *p)
{
	while (p->width-- - bigger_len > 0 && (p->flg.zero == 0 ||
				(p->pres == 0 && p->flg.zero)))
		ft_putchar(' ');
	ft_putstr("0x");
	while (p->width-- - bigger_len > -1 && p->flg.zero && p->pres == -1)
		ft_putchar('0');
	padding_zero(len, p);
}

void	convert_p(va_list ap, t_print *p)
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
		convert_p2(len, bigger_len, p);
		(*s == '0' && tmp_pres == 0) ? s = NULL : ft_putstr(s);
	}
	else
	{
		ft_putstr("0x");
		padding_zero(len, p);
		(*s == '0' && tmp_pres == 0) ? s = NULL : ft_putstr(s);
		padding_space(bigger_len, p);
	}
	free_strprint(&s);
}
