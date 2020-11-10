/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 10:59:47 by mbui              #+#    #+#             */
/*   Updated: 2020/11/10 14:51:01 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static long long	find_size(long long value, int base)
{
	int	len;

	len = 0;
	while (value)
	{
		len++;
		value /= base;
	}
	return (len);
}

char				*ft_itoa_base(long long value, int base, char x)
{
	char	*ret;
	char	*str_base;
	int		len;
	int		sign;

	sign = 0;
	str_base = "0123456789abcdef";
	x == 'X' ? str_base = "0123456789ABCDEF" : str_base;
	len = find_size(value, base);
	if (base < 2 || base > 16)
		return (0);
	if (value == 0)
		return ("0");
	(base == 10 && value < 0) ? sign = 1 && len++ : len;
	value < 0 ? value = -value : value;
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ret[len] = '\0';
	sign ? (ret[0] = '-') : 0;
	while (value)
	{
		ret[--len] = str_base[value % base];
		value /= base;
	}
	return (ret);
}
*/
static	long long	nlen(long long value, int base)
{
	int				count;
	count = 0;
	while (value)
	{
		count++;
		value /= base;
	}
	return (count);
}
static	char		*pick_size(char c)
{
	if (c == 'x')
		return ("0123456789abcdef");
	else if (c == 'X')
		return ("0123456789ABCDEF");
	return (NULL);
}
char				*ft_itoa_base(long long value, int base, char x)
{
	char			*str_base;
	char			*dst;
	int				len;
	int				sign;
	sign = 0;
	str_base = pick_size(x);
	len = nlen(value, base);
	if (base < 2 || base > 16)
		return (NULL);
	if (value == 0)
		return (ft_strdup("0"));
	(base == 10 && value < 0) ? sign = 1 && len++ : sign;
	value < 0 ? value = -value : value;
	if (!(dst = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	sign ? dst[0] = '-' : 0;
	dst[len] = '\0';
	while (value)
	{
		dst[--len] = str_base[value % base];
		value /= base;
	}
	return (dst);
}
