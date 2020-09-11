/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:28:09 by mbui              #+#    #+#             */
/*   Updated: 2020/09/11 12:45:34 by mbui             ###   ########.fr       */
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
** %c: undefined behavior with +, 0, ' ', # and precision
** '0' ignored when '-' is present
*/

void	convert_c(va_list ap, t_print *p)
{
	printf("\nconvert_c\n");
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
	printf("\nconvert_s\n");
	char	*s;
	int		len;

	s = va_arg(ap, char *);
	len = ft_strlen(s);
	if (p->precis != -1 && p->precis < len)
		len = p->precis;
	if (p->flg.minus)
		write(1, s, len);
	while (p->width-- - len > 0)
		(p->flg.zero && p->flg.minus == 0) ? ft_putchar('0') : ft_putchar(' ');
	if (!p->flg.minus)
		write(1, s, len);
}

/*
** %p: undefined behavior with +, 0, ' ', # and precision
** '0' ignored when '-' is present
*/

void	convert_p(va_list ap, t_print *p)
{
	printf("\nconvert_p\n");
	char	*s;
	int		len[2];

	s = ft_itoa_base(va_arg(ap, long long), 16, 'x');
	len[0] = ft_strlen(s);//+2; //+0x
	len[1] = p->precis;
	(len[0] > p->precis) ? len[1] = len[0] : len[1];
	if (p->flg.minus == 0)
	{
		while (p->width-- - len[1] > 2)//0)
			ft_putchar(' ');
		ft_putstr("0x");
		while (p->precis-- - len[0] > 0)//-2)
			ft_putchar('0');
		ft_putstr(s);
	}
	else
	{
		ft_putstr("0x");
		while (p->precis-- - len[0] > 0)//-2)
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

void	convert_di(va_list ap, t_print *p)
{
	printf("\nconvert_di\n");
	int		n;
	int		len[2];
	char	*s;

	s = ft_itoa_base(va_arg(ap, long long), 10, 'x');
	n = ft_atoi(s);
	len[0] = ft_intlen(ft_abs(n));
	printf("{len= %d}", len[0]);
	//len[0] = ft_strlen(s);
	(n < 0 || (p->flg.plus && n > 0)) ? len[0]++ : len[0];
	len[1] = p->precis;
	(len[0] > p->precis) ? len[1] = len[0] : len[1];
	printf("intlen=%d\n", len[0]);
	printf("value=%d\n", n);
	if (p->flg.space && p->flg.plus == 0 && n > 0)
	{
			ft_putchar(' ');
			len[1]++;
	}
	if (p->flg.minus == 0)
	{
		while (p->width-- - len[1] > 0)//0)
			ft_putchar(' ');
		if (p->flg.plus && n > 0)
			ft_putchar('+');
		else if (n < 0)
			ft_putchar('-');
		while (p->precis-- - len[0] > -1)//-2)
			ft_putchar('0');
		ft_putnbr(ft_abs(n));
	}
	else
	{
		if (p->flg.plus && n > 0)
			ft_putchar('+');
		else if (n< 0)
			ft_putchar('-');
	    printf("LOL{len= %d}", len[0]);
		while (p->precis-- - len[0] > -1)//-2) //why? -1 ??
			ft_putchar('0');
		ft_putnbr(ft_abs(n));
		while (p->width-- - len[1]  > 0)// 0)
			ft_putchar(' ');
	}
	printf("{len= %d}", len[0]);
//	printf("{len[1] = %d}", len[1]);
//	printf("{printed spaces=%d}\n", i);
}

//ok with positives only
/*void	convert_di(va_list ap, t_print *p)
{
	printf("\nconvert_di\n");
	int		n;
	int		len[2];
	char	*s;

	s = ft_itoa_base(va_arg(ap, long long), 10, 'x');
	n = ft_atoi(s);
	len[0] = ft_strlen(s);
	len[1] = p->precis;
	(len[0] > p->precis) ? len[1] = len[0] : len[1];
	printf("intlen=%d\n", len[0]);
	printf("value=%d\n", n);
	if (p->flg.space && p->flg.plus == 0)
	{
			ft_putchar(' ');
			len[1]++;
	}
	if (p->flg.minus == 0)
	{
		while (p->width-- - len[1] > 0)//0)
			ft_putchar(' ');
		if (p->flg.plus && n > 0)
			ft_putchar('+');
		while (p->precis-- - len[0] > 0)//-2)
			ft_putchar('0');
		ft_putnbr(n);
	}
	else
	{
		if (p->flg.plus && n > 0)
		{
			ft_putchar('+');
			len[1]++;
		}
		while (p->precis-- - len[0] > 0)//-2)
			ft_putchar('0');
		ft_putnbr(n);
		while (p->width-- - len[1]  > 0)// 0)
			ft_putchar(' ');
	}
}*/

/*
** %x & %X: undefined behavior with + and ' '
** '0' ignored when '-' is present
*/

// # : "0x" or "0X"
void	convert_x(va_list ap, char c,  t_print *p)
{
	printf("\nconvert_x\n");
	char		*s;
	int		len[2];

	s = ft_itoa_base(va_arg(ap, long long), 16, c);
	len[0] = ft_strlen(s);
	(p->flg.hash) ? len[0] += 2 : len[0];
	len[1] = p->precis;
	(len[0] > p->precis) ? len[1] = len[0] : len[1];
	if (p->flg.minus == 0)
	{
		printf("|NO MINUS|");
		while (p->width-- - len[1] + 1 > 0 && p->flg.zero == 0)
			ft_putchar(' ');
		if (p->flg.hash)
			(c == 'x') ? ft_putstr("0x") : ft_putstr("0X");
		while (p->precis-- - len[0] > 0 || (p->flg.zero && p->width-- - len[1] + 1 > 0))
			ft_putchar('0');
		ft_putstr(s);
	}
	/*while (p->width - len + 1 > 0)
	{
		(p->flg.zero && p->flg.minus == 0) ? ft_putchar('0') : ft_putchar(' ');
		p->width--;
	}*/
	else
	{
		printf("|YES MINUS|");
		if (p->flg.hash)
			(c == 'x') ? ft_putstr("0x") : ft_putstr("0X");
		while (p->precis-- - len[0] > 0 && p->width--)
			ft_putchar('0');
//		while (p->flg.zero && p->width-- - len[1] + 1 > 0)
//			ft_putchar('0');
		ft_putstr(s);
		while (p->width-- - len[0] + 1 > 0)
			ft_putchar(' ');
	}
	printf("{width=%d\n}", p->width);
}

int		conversion(va_list ap, char c, t_print *p)/*, char c, int i)*/
{
	unsigned int	i;
	//	double d;
	//	void *p;

	if (c == 'c')
		convert_c(ap, p);
	if (c == 's')
		convert_s(ap, p);
	if (c == 'p')
		convert_p(ap, p);
	if (c == 'd' || c == 'i')
		convert_di(ap, p);
	if (c == 'x' || c == 'X')
		convert_x(ap, c, p);
	if (c == 'u')
	{
		i = va_arg(ap, unsigned int);
		//e = (unsigned int)va_arg(ap, long long);
		ft_putnbr(i);
	}
	/*	if (c == 'o')
		{
		e = (unsigned octava_arg(ap, long long);
		ft_putnbr(e);
		}
		if (c == 'f')
		{

		}*/
	if (c == '%')
		ft_putchar('%');
	return (1);
}

int		istype(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o'
			|| c == 'u' || c == 'x' || c == 'X' || c == 'f');
}

int		get_width(t_print *p, int i)
{
	if (ft_isdigit(p->fmt[i]))
	{
		p->width = ft_atoi(&p->fmt[i]);// - 1;
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
		p->precis = ft_atoi(&p->fmt[i]);
		while (ft_isdigit(p->fmt[i]))
			i++;
	}
	return (i);
}

int		parse_flags(t_print *p/*,const char **fmt*/, int i)
{
	while (p->fmt[i] && istype(p->fmt[i]) == 0)
	{
		(p->fmt[i] == '+') ? p->flg.plus = 1 && i++: p->flg.plus;
		(p->fmt[i] == '-') ? p->flg.minus = 1 && i++: p->flg.minus;
		(p->fmt[i] == ' ') ? p->flg.space = 1 && i++: p->flg.space;
		(p->fmt[i] == '0') ? p->flg.zero = 1 && i++: p->flg.zero;
		(p->fmt[i] == '#') ? p->flg.hash = 1 && i++: p->flg.hash;
	//	(ft_isdigit(p->fmt[i])) ? i = get_width(p, i): i;
	//	(p->fmt[i] == '.') ? i = get_pres(p, i): i;
		i = get_width(p, i);
		i = get_pres(p, i);
	}
	printf("\n---recap---\n");
	printf("plus=%d\n", p->flg.plus);
	printf("minus=%d\n", p->flg.minus);
	printf("zero=%d\n", p->flg.zero);
	printf("space=%d\n", p->flg.space);
	printf("hash=%d\n", p->flg.hash);
	printf("width = %d\n", p->width);
	printf("pres = %d\n", p->precis);
	return (i);
}

t_print	*init_flags(t_print *p)
{
	p->width = 0;
	p->precis = -1;
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
			printf("\n==where I am at :%c==\n", p->fmt[i]);
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
