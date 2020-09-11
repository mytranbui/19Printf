/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 09:26:22 by mbui              #+#    #+#             */
/*   Updated: 2020/09/08 09:07:07 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libftprintf.h"
#include <stdio.h>

int main(void)
{
	char c = 'X';
	char *str = "bonjour";
	int nb = -1564312;
	unsigned short unb = +562;
	printf("%d-\n",unb);
	printf("%hu\n",unb);
	printf("%-05.1d\n",unb);
	printf("%d0\n",unb);
	printf("%#o\n",unb);
	printf("%s",str);
	return (0);
}
