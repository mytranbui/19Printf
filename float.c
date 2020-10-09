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
	int	dec;
//	double	tmp;
//	int		len;
//	double	round;//necessary?
//	round = 0.1;
	dec = n - (int)n;
	(p->pres == -1) ? p->pres = 6 : p->pres;
	while (p->pres > 0)
	{
		n *= 10;
		dec = (unsigned long long)n;
		n -= dec;
		dec %= 10;
		//dec = ft_round(dec);
		//ft_putnbr(dec);
		ft_putchar(dec + 48);
		p->pres--;
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
//	dec = ft_round(dec);
	printf("{dec=%.15f}\n", dec);
//	printf("{n=%.15f}\n", n);
//	printf("{round=%.15f}\n", round);
	return (dec);
}

int		ft_putchar_len(char c, int len)
{
//	int	len;

//	len = 0;
	ft_putchar(c);
	len++;
	return (len);
}

int		ft_putstr_len(char *s)//, int len)
{
	int len;

	len = 0;
	while (s != '\0')
	{
		//len = ft_putchar_len(s[len],len);
		ft_putchar(s[len]);
		//s[len]++;
		len++;
	}
	return (len);
}

char	*ft_roundup(char *d, char last, int i)
{
 int boolean;

 boolean = 0;
 i--;
	if (last >= '5')
	{
		while (boolean == 0)
		{
			if (d[i] == '9')
			 d[i] = '0';
			else
			{
		  	d[i]++;
				boolean = 1;
			}
			i--;
		}
	}
	return (d);
}

char		*get_flt(double	n, t_print *p)
{
	int	len;
	int dec;
	char	*s;
	char	*d;
	char* str_dot;
//	double round;
	int i;
	char last;
	char *flt;

	i = 0;
//	round = 0.1;
	s = ft_itoa_base(n, 10, 'x');
	ft_putstr(s);
	len = ft_strlen(s);
//	len = ft_putstr_len(s);//, len);
	//ft_putnbr(n);
	if (dec != 0)
	{
		if (!(str_dot = ft_strnew(len + 1)))
			return (0);
		str_dot = ft_strcpy(str_dot, s);
		str_dot[len] = '.';
		str_dot[len + 1] = '\0';
		//ft_putchar('.');
		printf("{strdot=%s}", str_dot);
//		len++;
	}
	(p->pres == -1) ? p->pres = 6 : p->pres;
	if (!(d = ft_strnew(p->pres + 1)))
		return (0);
	while (p->pres > 0)
	{
		n *= 10;
		dec = (unsigned long long)n;
		n -= dec;
		dec %= 10;
	//	printf("{decdec=%.15d}\n", dec);
		d[i] = dec + 48;
	//	printf("{res=%d}", dec + 48);
//len++;
		i++;
//		round /= 10;
		p->pres--;
	}
	n *= 10;
	dec = (unsigned long long)n;
	n -= dec;
	dec %= 10;
	last = dec + 48;
	d[i] = '\0';
	d = ft_roundup(d, last, i);
	ft_putstr(d);
	if (!str_dot)
		flt = ft_strjoin_free(s, d, 2);
	else
		flt = ft_strjoin_free(str_dot, d, 2);
	printf("{flt=%s}", flt);
//	return (len);
	return (flt);
}

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
	int	dec;
//	int		len_dec;
//	int		len_int;
	int		len[3];
	//int		len;
	char	*str_flt;

	n = va_arg(ap, double);
	//len = ft_putflt(ft_fabs(n), p);
	str_flt = get_flt(ft_fabs(n), p);
	len[0] = ft_strlen(str_flt);
	printf("{len[0]=%d}\n", len[0]);
	//dec = get_decimal(n, p);
/*	len_int = ft_intlen(ft_fabs(n));
	len[0] = len_int + len_dec;
*/len[1] = p->pres;
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
		(len[2] == 0 && n == 0) ? ft_putchar(' ') : ft_putstr(str_flt);
	}
	else
	{
		if (p->flg.plus && n >= 0)
			ft_putchar('+');
		else if (n < 0)// && n != -2147483648)
			ft_putchar('-');
		while (p->pres-- - len[0] > -1) //why? -1 ??
			ft_putchar('0');
		(len[2] == 0 && n == 0) ? ft_putchar(' ') : ft_putstr(str_flt);
		while (p->width-- - len[1] > 0)
			ft_putchar(' ');
		}
}
