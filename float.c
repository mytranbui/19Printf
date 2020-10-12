/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:41:38 by mbui              #+#    #+#             */
/*   Updated: 2020/10/12 15:39:02 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

double	ft_dabs(double x)
{
	return (x < 0) ? x * -1 : x;
}

/*
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
}*/

/*char	*ft_roundup(char *d, char last, int i)
  {
  int boolean;

  boolean = 0;
  i--;
  if (last >= '5')
  {
  while (boolean == 0)
  {
  if (d[i] == '.')
  i--;
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
  */

char	*ft_roundup(double n, char *str_flt)
{
	char	last_num;
	int		dec;
	int		i;
	int		boolean;

	boolean = 0;
	n *= 10;
	dec = (unsigned long long)n;
//	n -= dec;
	dec %= 10;
	last_num = dec + 48;
	i = ft_strlen(str_flt) - 1;
	if (last_num >= '5')
	{
		while (boolean == 0 && str_flt[i])
		{
			if (str_flt[i] == '.')
				i--;
			if (str_flt[i] == '9')
				str_flt[i] = '0';
			else
			{
				str_flt[i]++;
				boolean = 1;
			}
			i--;
		}
	}
	return (str_flt);
}

char	*get_int(double n, t_print *p)
{
	char	*s;
	char	*str_dot;
	int		len;

	s = ft_itoa_base(n, 10, 'x');
	len = ft_strlen(s);
	str_dot = NULL;
	if (p->pres != 0 || p->flg.hash != 0)
	{
		if (!(str_dot = ft_strnew(len + 1)))
			return (0);
		str_dot = ft_strcpy(str_dot, s);
		str_dot[len] = '.';
		//		str_dot[len + 1] = '\0';
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
	str_int = get_int(n, p);
	(p->pres == -1) ? p->pres = 6 : p->pres;
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
	str_flt = ft_roundup(n, str_flt);
	return (str_flt);
}

void	convert_f(va_list ap, t_print *p)
{
	printf("\nconvert_f\n");
	double	n;
	int	dec;
	int		len[3];
	char	*str_flt;

	n = va_arg(ap, double);
	str_flt = get_flt(ft_dabs(n), p);
	len[0] = ft_strlen(str_flt);
	printf("{len[0]=%d}\n", len[0]);
	len[1] = p->pres;
	len[2] = p->pres;
	(n < 0 || (p->flg.plus && n >= 0)) ? len[0]++ && len[1]++ : len[0];
	(len[0] > len[1]) ? len[1] = len[0] : len[1];
	(p->flg.plus == 0 && n >= 0) ? len[0]++ : len[0];
	(p->flg.space && p->flg.plus == 0 && n >= 0) ? len[1]++ : len[1];
	if (p->flg.space && p->flg.plus == 0 && n >= 0)
		ft_putchar(' ');
	if (p->flg.minus == 0)
	{
		if (n < 0 && p->flg.zero)
			ft_putchar('-');
		while (p->width-- - len[1] > 0)
			(p->flg.zero) ? ft_putchar('0') : ft_putchar(' ');
		if (p->flg.plus && n >= 0)
			ft_putchar('+');
		else if (n < 0 && p->flg.zero == 0)
			ft_putchar('-');
		while (p->pres-- - len[0] > -1)
			ft_putchar('0');
		(len[2] == 0 && n == 0) ? ft_putchar(' ') : ft_putstr(str_flt);
	}
	else
	{
		if (p->flg.plus && n >= 0)
			ft_putchar('+');
		else if (n < 0)
			ft_putchar('-');
		while (p->pres-- - len[0] > -1)
			ft_putchar('0');
		(len[2] == 0 && n == 0) ? ft_putchar(' ') : ft_putstr(str_flt);
		while (p->width-- - len[1] > 0)
			ft_putchar(' ');
	}
}
