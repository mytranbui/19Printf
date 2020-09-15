/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:28:09 by mbui              #+#    #+#             */
/*   Updated: 2020/09/15 11:18:15 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_putstr_len(const char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	write(1, str, i);
	return (i);
}

/*
** %c: undefined behavior with +, 0, ' ', # and presion
** '0' ignored when '-' is present
*/

void	convert_c(va_list ap, t_print *p)
{
//	printf("\nconvert_c\n");
	long long	c;

	c = (char)va_arg(ap, long long);
	if (p->flg.minus)
		ft_putchar(c);
	while (p->width-- > 1)
		(p->flg.zero && p->flg.minus == 0) ? ft_putchar('0') : ft_putchar(' ');
	if (!p->flg.minus)
		ft_putchar(c);
}

/*
** %s: undefined behavior with +, 0, ' ', #
** '0' ignored when '-' is present
*/

void	convert_s(va_list ap, t_print *p)
{
//	printf("\nconvert_s\n");
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
		(p->flg.zero && p->flg.minus == 0) ? ft_putchar('0') : ft_putchar(' ');
	if (!p->flg.minus)
		write(1, s, len);
	}
}

/*
** %p: undefined behavior with +, 0, ' ', # and presion
** '0' ignored when '-' is present
*/

void	convert_p(va_list ap, t_print *p)
{
//	printf("\nconvert_p\n");
	char	*s;
	int		len[2];

	s = ft_itoa_base(va_arg(ap, long long), 16, 'x');
	len[0] = ft_strlen(s);//+2; //+0x
	len[1] = p->pres;
	(len[0] > p->pres) ? len[1] = len[0] : len[1];
	if (p->flg.minus == 0)
	{
		while (p->width-- - len[1] > 2)//0)
			ft_putchar(' ');
		ft_putstr("0x");
		while (p->pres-- - len[0] > 0)//-2)
			ft_putchar('0');
		ft_putstr(s);
	}
	else
	{
		ft_putstr("0x");
		while (p->pres-- - len[0] > 0)//-2)
			ft_putchar('0');
		ft_putstr(s);
		while (p->width-- - len[1]  > 2)// 0)
			ft_putchar(' ');
	}
}

/*
** hash have no effect on d and i
** %d & %i: undefined behavior with #
** '0' ignored when '-' is present
** ' ' ignored when '+' is present
*/

//floor?? floor(log10(abs(int))) + 1
//should be added to libft
int		ft_intlen(int n)
{
	int	log;

	log = 0;
	while (n >= 10)
	{
		n /= 10;
		log++;
	}
	log++;
	return (log);
}

/*
** Since 2147483648 is greater than INT_MAX, then abs(-2147483648) is undefined
*/

//all ok except 2147483648
void	convert_di(va_list ap, t_print *p)
{
//	printf("\nconvert_di\n");
	int		n;
	int		len[3];

	n = ft_atoi(ft_itoa_base(va_arg(ap, long long), 10, 'x'));
	len[0] = ft_intlen(ft_abs(n));
	len[1] = len[2] = p->pres;
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
		else if (n < 0 && n != -2147483648)
			ft_putchar('-');
		while (p->pres-- - len[0] > -1)
			ft_putchar('0');
		(len[2] == 0 && n == 0) ? ft_putchar(' ') : ft_putnbr(ft_abs(n));
	}
	else
	{
		if (p->flg.plus && n >= 0)
			ft_putchar('+');
		else if (n < 0 && n != -2147483648)
			ft_putchar('-');
		while (p->pres-- - len[0] > -1) //why? -1 ??
			ft_putchar('0');
		(len[2] == 0 && n == 0) ? ft_putchar(' ') : ft_putnbr(ft_abs(n));
	while (p->width-- - len[1] > 0)
			ft_putchar(' ');
	}
//	printf("{n =%d}", n);
//	printf("{abs(n) =%d}", abs(n));
//	printf("{len= %d}", len[0]);
//	printf("{len[1] = %d}", len[1]);
//	printf("{len[2] = %d}", len[2]);
//	printf("{printed spaces=%d}\n", i);
}

/*
** %o: undefined behavior with '+', ' '
** '0' ignored when '-' is present
** ' ' ignored when '+' is present
*/
//0 4294967296 not ok
void	convert_o(va_list ap, t_print *p)
{
//	printf("\nconvert_o\n");
	char	*s;
	int		len[3];

	s = ft_itoa_base(va_arg(ap, long long), 8, 'x');
	len[0] = ft_strlen(s);
	len[1] = len[2] = p->pres;
	(p->flg.hash) ? len[0]++ : len[0];
//	(p->flg.hash && *s != '0') ? len[0]++ : len[0];
	(len[0] > len[1]) ? len[1] = len[0] : len[1];
	if (p->flg.minus == 0)
	{
		while (p->width-- - len[1] > 0)
			(p->flg.zero && p->pres == -1) ? ft_putchar('0') : ft_putchar(' ');
		if (p->flg.hash && *s != '0')
			ft_putchar('#');
		//	(*s != '0') ? ft_putchar('Z') : ft_putchar('B');
		//	(*s == '0') ? ft_putchar('Z') : len[0]--;
		while (p->pres-- - len[0] > 0)
			ft_putchar('0');
		(len[2] == 0 && *s == '0') ? ft_putchar(' ') : ft_putstr(s);
	}
	else
	{
		while (p->pres-- - len[0] > 0)
			ft_putchar('0');
		if (p->flg.hash && *s != '0')
			ft_putchar('#');
		//	(*s != '0') ? ft_putchar('z') : len[1]--;
		//	(*s == '0') ? ft_putchar('0') : ft_putchar('A');
		(len[2] == 0 && *s == '0') ? ft_putchar(' ') : ft_putstr(s);
	//	if (p->pres != 0)
	//		ft_putstr(s);
		while (p->width-- - len[1] > 0)
			ft_putchar(' ');
	}
}

/*
** %u: undefined behavior with// '+', ' ', '#'
** '#' has no effect on %u
** '0' ignored when '-' is present
** ' ' ignored when '+' is present
*/
//okok
void	convert_u(va_list ap, t_print *p)
{
//	printf("\nconvert_u\n");
	char	*s;
	int		len[3];

	s = ft_itoa_base(va_arg(ap, long long), 10, 'x');
//	s = ft_itoa_base(va_arg(ap, unsigned int), 10, 'x');
	len[0] = ft_strlen(s);
	len[1] = len[2] = p->pres;
	(len[0] > len[1]) ? len[1] = len[0] : len[1];
	if (p->flg.minus == 0)
	{
		while (p->width-- - len[1] > 0)
			(p->flg.zero && p->pres == -1) ? ft_putchar('0') : ft_putchar(' ');
		while (p->pres-- - len[0] > 0)
			ft_putchar('0');
		(len[2] == 0 && *s == '0') ? ft_putchar(' ') : ft_putstr(s);
	}
	else
	{
		while (p->pres-- - len[0] > 0)
			ft_putchar('0');
		(len[2] == 0 && *s == '0') ? ft_putchar(' ') : ft_putstr(s);
		while (p->width-- - len[1] > 0)
			ft_putchar(' ');
	}
}

/*
** %x & %X: undefined behavior with +, '0' and ' '
** '0' ignored when '-' is present
*/

void	convert_x(va_list ap, char c,  t_print *p)
{
//	printf("\nconvert_x\n");
	char	*s;
	int		len[3];

	s = ft_itoa_base(va_arg(ap, long long), 16, c);
	len[0] = ft_strlen(s);
	len[1] = len[2] = p->pres;
	(len[0] > len[1]) ? len[1] = len[0] : len[1];
	(p->flg.hash) ? len[1] +=2 : len[1];
	if (p->flg.minus == 0)
	{
		while (p->width-- - len[1] > 0)
			(p->flg.zero && p->pres == -1) ? ft_putchar('0') : ft_putchar(' ');
		if (p->flg.hash)
			(c == 'x') ? ft_putstr("0x") : ft_putstr("0X");
		while (p->pres-- - len[0] > 0)
			ft_putchar('0');
		(len[2] == 0 && *s == '0') ? ft_putchar(' ') : ft_putchar('O'); //ft_putstr(s);
	}
	else
	{
		if (p->flg.hash)
			(c == 'x') ? ft_putstr("0x") : ft_putstr("0X");
		while (p->pres-- - len[0] > 0)
			ft_putchar('0');
		(len[2] == 0 && *s == '0') ? ft_putchar(' ') :  ft_putchar('O'); //ft_putstr(s);
		while (p->width-- - len[1]  > 0)
			ft_putchar(' ');
	}
}

//%% with pres width!!

int		conversion(va_list ap, char c, t_print *p)/*, char c, int i)*/
{
	if (c == 'c')
		convert_c(ap, p);
	if (c == 's')
		convert_s(ap, p);
	if (c == 'p')
		convert_p(ap, p);
	if (c == 'd' || c == 'i')
		convert_di(ap, p);
	if (c == 'o')
		convert_o(ap, p);
	if (c == 'u')
		convert_u(ap, p);
	if (c == 'x' || c == 'X')
		convert_x(ap, c, p);
//	if (c == 'f')
//		convert_f(ap, p);
	if (c == '%')
		ft_putchar('%');
	return (1);
}

int		istype(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o'
			|| c == 'u' || c == 'x' || c == 'X' || c == 'f' || c == '%');
}

int		get_width(t_print *p, int i)
{
	if (ft_isdigit(p->fmt[i]))
	{
		p->width = ft_atoi(&p->fmt[i]);
		while (ft_isdigit(p->fmt[i]))
			i++;
	}
	return (i);
}

int		get_pres(t_print *p, int i)
{
	if (p->fmt[i] == '.')
	{
		i++;
		p->pres = ft_atoi(&p->fmt[i]);
		while (ft_isdigit(p->fmt[i]))
			i++;
	}
	return (i);
}

int		parse_flags(t_print *p/*,const char **fmt*/, int i)
{
	while (p->fmt[i] && istype(p->fmt[i]) == 0)
	{
		(p->fmt[i] == '+') ? p->flg.plus = 1 && i++ : p->flg.plus;
		(p->fmt[i] == '-') ? p->flg.minus = 1 && i++ : p->flg.minus;
		(p->fmt[i] == ' ') ? p->flg.space = 1 && i++ : p->flg.space;
		(p->fmt[i] == '0') ? p->flg.zero = 1 && i++ : p->flg.zero;
		(p->fmt[i] == '#') ? p->flg.hash = 1 && i++ : p->flg.hash;
		(p->fmt[i] == 'h') ? p->flg.h++ && i++ : p->flg.h;
		(p->fmt[i] == 'l') ? p->flg.l++ && i++ : p->flg.l;
	//	(ft_isdigit(p->fmt[i])) ? i = get_width(p, i) : i;
	//	(p->fmt[i] == '.') ? i = get_pres(p, i) : i;
		i = get_width(p, i);
		i = get_pres(p, i);
	}
//	printf("\n---recap---\n");
//	printf("plus=%d | minus=%d | zero=%d | space=%d | hash=%d | width=%d | pres=%d| h=%d | l=%d\n", p->flg.plus, p->flg.minus, p->flg.zero, p->flg.space, p->flg.hash, p->width, p->pres, p->flg.plus, p->flg.minus);
	return (i);
}

t_print	*init_flags(t_print *p)
{
	p->width = 0;
	p->pres = -1;
	p->flg.plus = 0;
	p->flg.minus = 0;
	p->flg.space = 0;
	p->flg.zero = 0;
	p->flg.hash = 0;
	p->flg.h = 0;
	p->flg.l = 0;
	p->flg.maj_l = 0;
	return (p);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_print	*p;
	int		i;
	//	int l;
	//	char c;
	i = 0;
	if (!(p = (t_print*)ft_memalloc(sizeof(t_print))))
		return (-1);
	p = init_flags(p);
	va_start(ap, format);
	p->fmt = format;
	//parse(ap, );
	while (p->fmt[i])
	{
		if (p->fmt[i] == '%')
		{
			i++;
			p = init_flags(p);
			i = parse_flags(p, i);
		//	printf("\n=== where I am at : %c ===\n", p->fmt[i]);
			conversion(ap, p->fmt[i], p);
		}
		//else
		//	ft_putendl("not implemented or undefined");
		else
		{
			i += ft_putstr_len(&p->fmt[i]);
			i--;
		}
		i++;
	}
	va_end(ap);
	return (1);
}
