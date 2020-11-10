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

static int	set_size_array(int number, int base, int is_negative)
{
	int size_array;
	size_array = 0;
	if (is_negative == 0)
		while (number > 0)
		{
			number /= base;
			size_array++;
		}
	else
		while (number < 0)
		{
			number /= base;
			size_array++;
		}
	return (size_array + is_negative);
}
static void	convert(char *nbr, int number, int base, int is_negative)
{
	int length;
	length = set_size_array(number, base, is_negative);
	if (is_negative == 0)
		while (number > 0)
		{
			if (number % base >= 10)
				nbr[length - 1] = ((number % base) + 'a') - 10;
			else
				nbr[length - 1] = (number % base) + 48;
			number /= base;
			length--;
		}
	else
		while (number < 0)
		{
			if (((number % base) * -1) >= 10)
				nbr[length - 1] = (((number % base) * -1) + 'a') - 10;
			else
				nbr[length - 1] = ((number % base) * -1) + 48;
			number /= base;
			length--;
		}
	if (is_negative == 1)
		nbr[0] = '-';
}
char		*ft_itoa_base2(int number, int base)
{
	char	*nbr;
	int		length;
	int		is_negative;
	is_negative = 0;
	if (number == 0)
		return (ft_strdup("0"));
	if (base < 2)
		return (NULL);
	if (number < 0)
		is_negative = 1;
	length = set_size_array(number, base, is_negative);
	if ((nbr = ft_strnew(length)) == NULL)
		return (NULL);
	convert(nbr, number, base, is_negative);
	return (nbr);
}

char	*roundup(long double n, char *str_flt)
{
	char	last_num;
	int		i;
	int		boolean;

	boolean = 0;
	n *= 10;
	last_num = (unsigned long long)n % 10 + 48;
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

	if (!(s = ft_itoa_base2(n, 10)))
		return (NULL);
	// if (!(s = ft_itoa_base((long long)n, 10, 'x')))
	// 	return (NULL);
	str_dot = NULL;
	// printf("{p=%p}\n", s);
	// printf("{s=%s}\n", s);
	// printf("{s=%d}\n", s[0]);
	if (p->pres != 0 || p->flg.hash != 0)
	{
		// ft_putendl("LOL");
		// printf("{p=%p}\n", s);
		// printf("{s=%s}\n", s);
		if (!(str_dot = ft_strjoin_free(s, ".", 1)))
		{

			//ft_strdel(&s);
			return (NULL);
		}
		// ft_putendl("HOHO");
		// printf("{p=%p}\n", s);
		// printf("{s=%s}\n", s);
			//ft_strdel(&s);
		return (str_dot);
	}
	return (s);
	//if (s)
	//	ft_strdel(&s);
	//return (!str_dot ? s : str_dot);
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
		return (NULL);
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
	if (!(str_flt = ft_strjoin_free(str_int, str_dec, 3)))
		return (NULL);
	if (str_int)
		printf("intE");
	if (!str_int)
		printf("intXX");
	if (str_dec)
		printf("decE");
	if (!str_dec)
		printf("decXX");
	str_flt = roundup(n, str_flt);
	return (str_flt);
}

void	print_f2(long double arg, int len, int bigger_len, t_print *p)
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

void	print_f(long double arg, t_print *p)
{
	int		len;
	int		bigger_len;
	char	*str_flt;

	str_flt = get_flt(ft_ldabs(arg), p);
	len = ft_strlen(str_flt);
	bigger_len = ft_max(len, p->pres);
	(arg < 0 || (p->flg.plus && arg >= 0)) ? len++ && bigger_len++ : len;
	(p->flg.plus == 0 && arg >= 0) ? len++ : len;
	(p->flg.space && p->flg.plus == 0 && arg >= 0) ? bigger_len++ : bigger_len;
	print_f2(arg, len, bigger_len, p);
	if (!p->flg.minus)
		print_result(str_flt, 0, p);
	else
	{
		putsign(arg, p);
		padding_zero(len, p);
		print_result(str_flt, 0, p);
		padding_space(bigger_len, p);
	}
	ft_strdel(&str_flt);
}