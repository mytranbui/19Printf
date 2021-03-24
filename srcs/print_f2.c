/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:41:38 by mbui              #+#    #+#             */
/*   Updated: 2020/11/17 17:52:58 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libftprintf.h"

/*
** last_num of s = (unsigned long long)n % 10 + 48
*/

static int					ft_len(long double n)
{
	int i;

	i = (n < 0);
	(n <= 0) ? n *= -1 : 0;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static unsigned long long	ft_ten_power(int i)
{
	unsigned long long power;

	power = 1;
	while (i >= 0)
	{
		power *= 10;
		i--;
	}
	return (power);
}

void						ft_roundup(char *str, long double n, int precision)
{
	long long	nb;
	int			tmp_pres;
	int			i;
	int			ret;
	char		c;

	i = ft_len(n);
	n = n - (long long)n;
	nb = (long long)(n * ft_ten_power(precision));
	tmp_pres = precision;
	ret = (ft_llabs(nb % 10) > 4);
	while (precision >= 0)
	{
		c = '0' + ft_llabs(nb % 10) + ret;
		if (c > '9')
			c = '0';
		else
			ret = 0;
		str[i + precision-- + 2] = c;
		nb = ft_llabs(nb / 10);
	}
	str[i + tmp_pres + 2] = '\0';
}

char						*ft_dtoa(long double n, int precision)
{
	char		*str;
	int			i;
	int			tmp_pres;
	long long	nb;

	nb = (long long)n;
	precision = (precision == -1) ? 6 : precision;
	tmp_pres = precision;
	if (!(str = ft_strnew(ft_len(n) + precision + 1)))
		return (NULL);
	i = ft_len(n);
	str[i + 1] = (precision == 0) ? '\0' : '.';
	while (i >= 0)
	{
		str[i--] = '0' + ft_llabs(nb % 10);
		nb = ft_llabs(nb / 10);
	}
	i = ft_len(n);
	(n < 0) ? str[0] = '-' : 0;
	ft_roundup(str, n, tmp_pres);
	return (str);
}

static void	print_f2(long double arg, int len, int bigger_len, t_print *p)
{
	if (p->flg.space && !p->flg.plus && arg >= 0)
	{
		ft_putchar(' ');
		p->ret++;
	}
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

void		print_f(long double arg, t_print *p)
{
	int		len;
	int		bigger_len;
	char	*s;

	s = ft_dtoa(arg, p->pres);
	len = ft_strlen(s);
	bigger_len = ft_max(len, p->pres);
	(arg < 0 || (p->flg.plus && arg >= 0)) ? len++ && bigger_len++ : len;
	(p->flg.plus == 0 && arg >= 0) ? len++ : len;
	(p->flg.space && p->flg.plus == 0 && arg >= 0) ? bigger_len++ : bigger_len;
	print_f2(arg, len, bigger_len, p);
	if (!p->flg.minus)
		print_result(s, 0, p);
	else
	{
		putsign(arg, p);
		padding_zero(len, p);
		print_result(s, 0, p);
		padding_space(bigger_len, p);
	}
	ft_strdel(&s);
}
