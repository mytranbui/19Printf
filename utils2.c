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

//kk
/*unsigned int	ft_absu(int value)
  {
  return (value < 0) ? -((unsigned int)value) : (unsigned int)value;
  }
 */
