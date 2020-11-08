/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 16:11:13 by mbui              #+#    #+#             */
/*   Updated: 2020/11/03 21:25:30 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libftprintf.h"

int		ft_putstr_len_percent(const char *str, t_print *p)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	//  printf("{STRi=%d}", p->ret);
	p->ret += i;
	//  printf("{STRi=%d}", p->ret);
	// printf("{STRret=%d}", p->ret);
	write(1, str, i);
	i--;
	return (i);
}

void	free_strprint(char **s)
{
	if (**s != '0')
		ft_strdel(s);
	s = NULL;
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

void	print_result(char *s, int pres, t_print *p)
{
	if (p->type == 'f')
	{
		ft_putstr(s);
		p->ret += ft_strlen(s);
	}
	else if (p->type == 'o' && (*s != '0' || pres != 0 || p->flg.hash))
	{
		ft_putstr(s);
		p->ret += ft_strlen(s);
	}
	else if (*s != '0' || pres != 0)
	{
		ft_putstr(s);
		p->ret += ft_strlen(s);
	}
}

// void	print_result(intmax_t arg, char *s, int pres, t_print *p)
// {
// 	 if (p->type == 'f')
// 	{
// 		ft_putstr(s);
// 		p->ret += ft_strlen(s);
// 	}
// 	else if ((p->type == 'd' || p->type == 'i') && (arg != 0 || pres != 0))
// 	{
// 		if (arg == -9223372036854775807 - 1)
// 			ft_putstr("9223372036854775808");
// 		else
// 			ft_putnbrmax(ft_intmaxabs(arg));
// 		p->ret += (arg == 0) ? 1 : ft_intlen(ft_intmaxabs(arg));
// 	}
// 	else if (p->type == 'o' && (*s != '0' || pres != 0 || p->flg.hash))
// 	{
// 		ft_putstr(s);
// 		p->ret += ft_strlen(s);
// 	}
// 	else if ((p->type == 'p' || p->type == 'u' || p->type == 'x'
// 				|| p->type == 'X') && (*s != '0' || pres != 0))
// 	{
// 		ft_putstr(s);
// 		p->ret += ft_strlen(s);
// 	}
// }