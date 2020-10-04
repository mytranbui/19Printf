/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:41:38 by mbui              #+#    #+#             */
/*   Updated: 2020/09/29 19:30:58 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

double	ft_pow(double x, double y)
{
	double	tmp;

	while (y != 0)
	{
		x = x * tmp;
		y--;
	}
	return (x);
}

double	ft_round(double x)
{
	return (x - (int)x >= 0.5 ? (int)x + 1 : (int)x);
}

//should be added to libft
double	ft_fabs(double x)
{
	return (x < 0) ? x * -1 : x;
}

double	get_decimal(double n, t_print *p)
{
	printf("\nget_decimal\n");
	double	dec;
	double	tmp;
//	int		len;
	double	round;//necessary?

	round = 0.1;
//	printf("{n=%.15f}", n);
	dec = n - (int)n;
//	printf("{dec=%.15f}", dec);
	(p->pres == -1) ? p->pres = 6 : p->pres;
//	tmp = dec;
	while (p->pres--)
	{
//		printf("\nloop\n");
		tmp = dec;
		dec = tmp * 10;
		round /= 10;
	}
//	printf("{dec=%.15f}\n", dec);
	dec = ft_round(dec);
	printf("{dec=%.15f}\n", dec);
//	printf("{n=%.15f}\n", n);
//	printf("{round=%.15f}\n", round);
	return (dec);
}

void ft_putflt(double	n, double dec)
{
	char	*s;
	char	*d;

	s = ft_itoa_base(n, 10, 'x');
	ft_putstr(s);
	//ft_putnbr(n);
	if (dec != 0)
	{
		ft_putchar('.');
		d = ft_itoa_base(dec, 10, 'x');
ft_putstr(d);
		//ft_putnbr(dec);
	}
}

/*while (p->precision > 0)
{
	ptr->num *= 10;
	ptr->d = (unsigned long long)ptr->num;
	ptr->num -= ptr->d;
	ptr->d %= 10;
	pointer->counter += ft_putchar_len(ptr->d + 48);
	p->precision--;
}*/

/*void	convert_f(va_list ap, t_print *p)
{
	printf("\nconvert_f\n");
	double	n;
	double	dec;
	int		len_dec;
	int		len_int;
	int		len;

	n = va_arg(ap, double);
	dec = get_decimal(n, p);
	len_dec = ft_intlen(dec) + 1; // +1 for the decimal point
	len_int = ft_intlen(ft_fabs(n));
	(dec == 0) ? len_dec = 0 : len_dec;
	len = len_int + len_dec;
	(n < 0 || (p->flg.plus && n >= 0)) ? len++ : len;
	printf("{n=%f}\n", n);
	printf("{len_dec=%d}\n", len_dec);
	printf("{len_int=%d}\n", len_int);
	printf("{len=%d}\n", len);

}*/



void	convert_f(va_list ap, t_print *p)
{
	printf("\nconvert_f\n");
	double	n;
	double	dec;
	int		len_dec;
	int		len_int;
	int		len[3];

	n = va_arg(ap, double);
	dec = get_decimal(n, p);
	len_dec = ft_intlen(dec) + 1; // +1 for the decimal point
	len_int = ft_intlen(ft_fabs(n));
	len[0] = len_int + len_dec;
	len[1] = p->pres;
	len[2] = p->pres;
	(n < 0 || (p->flg.plus && n >= 0)) ? len[0]++ && len[1]++ : len[0];
	(len[0] > len[1]) ? len[1] = len[0] : len[1];
	(p->flg.plus == 0 && n >= 0) ? len[0]++ : len[0]; //why ?0+
	//	printf("intlen=%d\n", len[0]);
	//	printf("value=%d\n", n);
	(p->flg.space && p->flg.plus == 0 && n >= 0) ? len[1]++ : len[1];
	if (p->flg.space && p->flg.plus == 0 && n >= 0)
		ft_putchar(' ');
	if (p->flg.minus == 0)
	{
		while (p->width-- - len[1] > 0)
			ft_putchar(' ');
		if (p->flg.plus && n >= 0)
			ft_putchar('+');
		else if (n < 0)// && n != -2147483648)
			ft_putchar('-');
		while (p->pres-- - len[0] > -1)
			ft_putchar('0');
		(len[2] == 0 && n == 0) ? ft_putchar(' ') : ft_putflt(ft_fabs(n), dec);
	}
	else
	{
		if (p->flg.plus && n >= 0)
			ft_putchar('+');
		else if (n < 0)// && n != -2147483648)
			ft_putchar('-');
		while (p->pres-- - len[0] > -1) //why? -1 ??
			ft_putchar('0');
		(len[2] == 0 && n == 0) ? ft_putchar(' ') : ft_putflt(ft_fabs(n), dec);
		while (p->width-- - len[1] > 0)
			ft_putchar(' ');
	}
}
