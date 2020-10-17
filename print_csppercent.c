/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csppercent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 09:38:25 by mbui              #+#    #+#             */
/*   Updated: 2020/10/16 17:49:57 by mbui             ###   ########.fr       */
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

void	convert_c(va_list ap, t_print *p)
{
	//printf("\nconvert_c\n");
	long long	c;

	c = va_arg(ap, long long);
	if (p->flg.minus)
		ft_putchar(c);
	while (p->width-- - 1 > 0)
		(p->flg.zero && !p->flg.minus) ? ft_putchar('0') : ft_putchar(' ');
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
	while (p->width-- - 1 > 0)
		(p->flg.zero && !p->flg.minus) ? ft_putchar('0') : ft_putchar(' ');
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
** %p: undefined behavior with +, 0, ' ', # and precision
*/

/*
** p->width -=2 because of length of s + the prefix '0x'
*/

void	convert_p(va_list ap, t_print *p)
{
	//printf("\nconvert_p\n");
	char	*s;
    int     len;
    int     bigger_len;
	int		tmp_pres;

	if (!(s = ft_itoa_base(va_arg(ap, long long), 16, 'x')))
	 		free_print(&p, 2);
	//s = ft_itoa_base(va_arg(ap, long long), 16, 'x');
	len = ft_strlen(s);
	bigger_len = p->pres;
	tmp_pres = p->pres;
	(*s == '0' && tmp_pres == 0) ? p->width++ : p->width;
    //p->width -= 2;
	(len > p->pres) ? bigger_len = len : bigger_len;
	bigger_len += 2;
	if (p->flg.minus == 0)
	{
		//printf("HIHI");
	//	printf("{width= %d & len =%d}", p->width, bigger_len);
		while (p->width-- - bigger_len > 0 && (p->flg.zero == 0 ||
					(p->pres == 0 && p->flg.zero)))
			ft_putchar(' ');
		ft_putstr("0x");
	//	printf("{width= %d & len =%d}", p->width, bigger_len);
		while (p->width-- - bigger_len > -1 && p->flg.zero && p->pres == -1)
			ft_putchar('0');
		padding_zero(len, p);
		(*s == '0' && tmp_pres == 0) ? s = NULL : ft_putstr(s);
	}
	else
	{
		//printf("LOL");
		ft_putstr("0x");
		padding_zero(len, p);
		(*s == '0' && tmp_pres == 0) ? s = NULL : ft_putstr(s);
		padding_space(bigger_len, p);
	}
	free_strprint(&s);
}
