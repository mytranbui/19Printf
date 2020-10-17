/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 16:11:13 by mbui              #+#    #+#             */
/*   Updated: 2020/10/16 16:30:41 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_putstr_len_percent(const char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	write(1, str, i);
	i--;
	return (i);
}

void	putsign(int n,t_print *p)
{
	if (p->flg.plus && n >= 0)
		ft_putchar('+');
	else if (n < 0)
		ft_putchar('-');
}

void	padding_zero(int len, t_print *p)
{
	while (p->pres-- - len > 0)
		ft_putchar('0');
}

void	padding_space(int len, t_print *p)
{
	while (p->width-- - len > 0)
		ft_putchar(' ');
}

void	padding_ze_sp(int len, t_print *p)
{
	if (p->flg.minus == 0)
		while (p->width-- - len > 0)
			ft_putchar((p->flg.zero && p->pres == -1) ? '0' : ' ');
}

void	putprefix(char *s, t_print *p)
{
	if (p->flg.hash && *s != '0')
		(p->type == 'x') ? ft_putstr("0x") : ft_putstr("0X");
}

void free_print(t_print **p, int n)
{
		if (p)
		{
			free(*p);
			*p = NULL;
		}
		p = NULL;
	if (n == 2)
		exit(EXIT_FAILURE);
}

//hhmmm?
void free_strprint(char **s)
{
	if (**s != '0')
		ft_strdel(s);
	s = NULL;
}

//kk
/*unsigned int	ft_absu(int value)
  {
  return (value < 0) ? -((unsigned int)value) : (unsigned int)value;
  }
  */
