/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 16:11:13 by mbui              #+#    #+#             */
/*   Updated: 2020/10/21 18:46:53 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		ft_putstr_len_percent(const char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	write(1, str, i);
	i--;
	return (i);
}

void	free_print(t_print **p, int n)
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

void	free_strprint(char **s)
{
	if (**s != '0')
		ft_strdel(s);
	s = NULL;
}

void	print_result(char *s, int pres, t_print *p)
{
	if (p->type == 'o' && (*s != '0' || pres != 0 || p->flg.hash))
			ft_putstr(s);
	else if (*s != '0' || pres != 0)
			ft_putstr(s);
}