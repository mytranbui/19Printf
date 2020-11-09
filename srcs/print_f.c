/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:41:38 by mbui              #+#    #+#             */
/*   Updated: 2020/11/04 11:40:59 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libftprintf.h"

// static long double	find_size(long double value, int base)
// {
// 	int	len;

// 	len = 0;
// 	while (value)
// 	{
// 		len++;
// 		value /= base;
// 	}
// 	return (len);
// }

// char				*ft_ldtoa_base(long double value, int base, char x)
// {
// 	char	*ret;
// 	char	*str_base;
// 	int		len;
// 	int		sign;

// 	sign = 0;
// 	str_base = "0123456789abcdef";
// 	x == 'X' ? str_base = "0123456789ABCDEF" : str_base;
// 	len = find_size(value, base);
// 	if (base < 2 || base > 16)
// 		return (0);
// 	if (value == 0)
// 		return ("0");
// 	(base == 10 && value < 0) ? sign = 1 && len++ : len;
// 	value < 0 ? value = -value : value;
// 	ret = (char *)malloc(sizeof(char) * (len + 1));
// 	ret[len] = '\0';
// 	sign ? (ret[0] = '-') : 0;
// 	while (value)
// 	{
// 		ret[--len] = str_base[value % base];
// 		value /= base;
// 	}
// 	return (ret);
// }

char	*ft_lltoa_base(long long n, int base)
{
	char	*s;
	long	nb;
	int		len;

	len = 1;
	n < 0 ? ++len : 0;
	nb = n < 0 ? -n : n;
	while (nb >= base)
	{
		nb /= base;
		++len;
	}
	s = (char*)malloc(sizeof(char) * (len + 1));
	s[len] = '\0';
	n < 0 ? *s = '-' : 0;
	n < 0 ? n = -n : 0;
	while (n >= base)
	{
		s[--len] = n % base < 10 ? (n % base) + 48 : (n % base) + 55;
		n /= base;
	}
	s[--len] = n % base < 10 ? (n % base) + 48 : (n % base) + 55;
	return (s);
}

char	*roundup(long double n, char *str_flt)
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
			{
				str_flt[i] = '0';
				if (i == 0)
				{
					if (!(str_flt = ft_strjoin_free("1", str_flt, 2)))
							return (NULL);
					boolean = 1;
				}
			}
			else
			{
				str_flt[i]++;
				boolean = 1;
			}
			i--;
		}
	return (str_flt);
}

char	*get_int(long double n, t_print *p)
{
	char	*s;
	char	*str_dot;
	int		len;

	// if (n == 9223372036854775807)
	// 	s = ft_strdup("9223372036854775808");
	// if (!(s = ft_lltoa_base(n, 10)))
	// 	return (0);
	if (!(s = ft_itoa_base(n, 10, 'x')))
		return (0);
	// printf("{sint=%s}",s);
	 //printf("{n=%f}",n);
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

char	*get_flt(long double n, t_print *p)
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
	if (!(str_flt = ft_strjoin_free(str_int, str_dec, 2)))
		return (NULL);
	str_flt = roundup(n, str_flt);
	return (str_flt);
}

void	print_result_f(char *s, t_print *p)
{
	ft_putstr(s);
	p->ret += ft_strlen(s);
}

void	print_f2(long double arg, int len, int bigger_len, t_print *p)
{
	if (p->flg.space && !p->flg.plus && arg >= 0)
	{
		ft_putchar(' ');
		p->ret++;
	}
	//else if (arg == 0 && )
	if (!p->flg.minus)
	{
		if (p->flg.zero)
			putsign(arg, p);
		padding_ze_sp(bigger_len, p);
		if (!p->flg.zero)
			putsign(arg, p);
		padding_zero(len, p);
	}
}

void	print_f(long double arg, t_print *p)
{
	int		len;
	int		bigger_len;
	char	*str_flt;

	//printf("{arg=%Lf}",arg);
	//str_flt = (arg == -0) ? ft_strdup("-0.000000") : get_flt(ft_ldabs(arg), p);
	str_flt = get_flt(ft_ldabs(arg), p);
	len = ft_strlen(str_flt);
	bigger_len = ft_max(len, p->pres);
	(arg < 0 || (p->flg.plus && arg >= 0)) ? len++ && bigger_len++ : len;
	(p->flg.plus == 0 && arg >= 0) ? len++ : len;
	(p->flg.space && p->flg.plus == 0 && arg >= 0) ? bigger_len++ : bigger_len;
	print_f2(arg, len, bigger_len, p);
	if (!p->flg.minus)
		print_result_f(str_flt, p);
		//print_result(str_flt, tmp_pres, p);
	else
	{
		putsign(arg, p);
		padding_zero(len, p);
		//print_result(str_flt, tmp_pres, p);
		print_result_f(str_flt, p);
		padding_space(bigger_len, p);
	}
	free_strprint(&str_flt);
}

// (arg < 0 || (p->flg.plus && arg >= 0)) ? p->width-- : p->width;
// 	(arg == 0 && p->pres > 0) ? p->pres-- : p->pres;
// 	(arg == 0 && p->pres == -1) ? p->width-- : p->width;
// 	(p->flg.space && !p->flg.plus && arg >= 0) ? p->width-- : p->width;
