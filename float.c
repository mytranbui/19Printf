/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:41:38 by mbui              #+#    #+#             */
/*   Updated: 2020/09/28 16:25:29 by mbui             ###   ########.fr       */
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

/*double	ft_round(double x)
{

}
*/

void	get_float(double n)
{
	double	dec;
	double	tmp;

	dec = n - (int)n;
	printf("{dec=%f}", dec);
	(p->pres == -1) ? p->pres == 6 : p->pres;
	while (dec)
	{
		tmp = dec;
		dec = tmp * 10;
	}
}

void	convert_f(va_list ap, t_print *p)
{
	printf("\nconvert_f\n");
	uintmax_t	v;
	float	n;
	int		len[3];

	n = va_arg(ap, double);
	get_float(n);
	printf("{n=%f}", n);
	//	v = ft_itoa_base(n, 2, 'x');
	//	printf("{v=%ju}", v);
	len[0] = ft_intlen(ft_abs(n));
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
		(len[2] == 0 && n == 0) ? ft_putchar(' ') : ft_putnbr(ft_abs(n));
	}
	else
	{
		if (p->flg.plus && n >= 0)
			ft_putchar('+');
		else if (n < 0)// && n != -2147483648)
			ft_putchar('-');
		while (p->pres-- - len[0] > -1) //why? -1 ??
			ft_putchar('0');
		(len[2] == 0 && n == 0) ? ft_putchar(' ') : ft_putnbr(ft_abs(n));
		while (p->width-- - len[1] > 0)
			ft_putchar(' ');
	}
}
