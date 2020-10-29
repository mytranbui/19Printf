/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:41:38 by mbui              #+#    #+#             */
/*   Updated: 2020/10/28 22:28:00 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

char	*roundup(double n, char *str_flt)
{
	char	last_num;
	int		dec;
	int		i;
	int		boolean;

	boolean = 0;
	n *= 10;
	dec = (unsigned long long)n;
	dec %= 10;
	last_num = dec + 48;
	i = ft_strlen(str_flt) - 1;
	if (last_num >= '5')
		while (boolean == 0 && str_flt[i])
		{
			(str_flt[i] == '.') ? i-- : i;
			if (str_flt[i] == '9')
				str_flt[i] = '0';
			else
			{
				str_flt[i]++;
				boolean = 1;
			}
			i--;
		}
	return (str_flt);
}

char	*get_int(double n, t_print *p)
{
	char	*s;
	char	*str_dot;
	int		len;

	if (!(s = ft_itoa_base(n, 10, 'x')))
		return (0);
	len = ft_strlen(s);
	str_dot = NULL;
	if (p->pres != 0 || p->flg.hash != 0)
	{
		if (!(str_dot = ft_strnew(len + 1)))
			return (0);
		str_dot = ft_strcpy(str_dot, s);
		str_dot[len] = '.';
	}
	return (!str_dot ? s : str_dot);
}

char	*get_flt(double n, t_print *p)
{
	char	*str_int;
	char	*str_dec;
	char	*str_flt;
	int		dec;
	int		i;

	i = 0;
	(p->pres == -1) ? p->pres = 6 : p->pres;
	if (!(str_int = get_int(n, p)))
		return (0);
	if (!(str_dec = ft_strnew(p->pres + 1)))
		return (0);
	while (p->pres > 0)
	{
		n *= 10;
		dec = (unsigned long long)n;
		n -= dec;
		dec %= 10;
		str_dec[i] = dec + 48;
		i++;
		p->pres--;
	}
	str_flt = ft_strjoin_free(str_int, str_dec, 2);
	str_flt = roundup(n, str_flt);
	return (str_flt);
}

void	print_f2(long double arg, int bigger_len, int len, t_print *p)
{
	if (arg < 0 && p->flg.zero)
		ft_putchar('-');
	padding_ze_sp(bigger_len, p);
	putsign(arg, p);
	padding_zero(len, p);
}

void	print_f(long double arg, t_print *p)
{
	int		len;
	int		bigger_len;
	int		tmp_pres;
	char	*str_flt;

	str_flt = get_flt(ft_dabs(arg), p);
	len = ft_strlen(str_flt);
	tmp_pres = p->pres;
	bigger_len = (len > p->pres) ? len : p->pres;
	(arg < 0 || (p->flg.plus && arg >= 0)) ? len++ && bigger_len++ : len;
	(p->flg.plus == 0 && arg >= 0) ? len++ : len;
	(p->flg.space && p->flg.plus == 0 && arg >= 0) ? bigger_len++ : bigger_len;
	if (p->flg.space && p->flg.plus == 0 && arg >= 0)
		ft_putchar(' ');
	if (p->flg.minus == 0)
	{
		print_f2(arg, bigger_len, len, p);
		(arg == 0 && tmp_pres == 0) ? ft_putchar(' ') : ft_putstr(str_flt);
	}
	else
	{
		putsign(arg, p);
		padding_zero(len, p);
		(arg == 0 && tmp_pres == 0) ? ft_putchar(' ') : ft_putstr(str_flt);
		padding_space(bigger_len, p);
	}
}
