/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainkk2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 22:01:16 by mbui              #+#    #+#             */
/*   Updated: 2020/11/05 22:06:51 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/libftprintf.h"
#include <stdio.h>
#include <limits.h>

int ft_printf(const char *format, ...);

int main(void)
{
	int a;
	int b;

	a = 0;
	b = 0;
	printf("--------------------\n");
	printf("OCTAL\n");
	printf("--------------------\n");
	printf("\n");//1
	a =      printf ("printf1     :|%5o|%5.3o|%5.1o|%5.0o|%5.o|\n", 1,1,1,1,1);
	b =  ft_printf ("ft_printf1  :|%5o|%5.3o|%5.1o|%5.0o|%5.o|\n", 1,1,1,1,1);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	a =      printf ("printf2     :|%#5o|%#5.3o|%#5.2o|%#5.0o|%#5.o|\n", 1,1,10,1,1);
	b = ft_printf ("ft_printf2  :|%#5o|%#5.3o|%#5.2o|%#5.0o|%#5.o|\n", 1,1,10,1,1);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	a =      printf ("printf3     :|%#5o|%#6.2o|%#5.1o|%#5.0o|%#5.o|\n", 1,1,1,1,1);
	b = ft_printf ("ft_printf3  :|%#5o|%#6.2o|%#5.1o|%#5.0o|%#5.o|\n", 1,1,1,1,1);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	a =      printf ("printf4     :|%0#5o|%0#5.3o|%0#5.1o|%0#5.0o|%0#5.o|\n", 1,1,1,1,1);
	b = ft_printf ("ft_printf4  :|%0#5o|%0#5.3o|%0#5.1o|%0#5.0o|%0#5.o|\n", 1,1,1,1,1);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	a =      printf ("printf5     :|%0#5o|%0#5.3o|%0#5.1o|%0#5.0o|%0#5.o|\n", 1,1,1,1,1);
	b = ft_printf ("ft_printf5  :|%0#5o|%0#5.3o|%0#5.1o|%0#5.0o|%0#5.o|\n", 1,1,1,1,1);
    printf("a=%d\n", a);
	printf("b=%d\n", b);

	printf("--------------------\n");
	printf("OCTAL MINUS\n");
	printf("--------------------\n");
	printf("\n");//1

	a =      printf ("printf1     :|%-5o|%-5.3o|%-5.1o|%-5.0o|%-5.o|\n", 1,1,1,1,1);
	b = ft_printf ("ft_printf1  :|%-5o|%-5.3o|%-5.1o|%-5.0o|%-5.o|\n", 1,1,1,1,1);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	a =      printf ("printf2     :|%-#5o|%-#5.3o|%-#5.1o|%-#5.0o|%-#5.o|\n", 1,1,1,1,1);
	b = ft_printf ("ft_printf2  :|%-#5o|%-#5.3o|%-#5.1o|%-#5.0o|%-#5.o|\n", 1,1,1,1,1);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	a =      printf ("printf3     :|%-#5o|%-#5.3o|%-#5.1o|%-#5.0o|%-#5.o|\n", 1,1,1,1,1);
	b = ft_printf ("ft_printf3  :|%-#5o|%-#5.3o|%-#5.1o|%-#5.0o|%-#5.o|\n", 1,1,1,1,1);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	a =      printf ("printf4     :|%0#5o|%0#5.3o|%0#5.1o|%0#5.0o|%0#5.o|\n", 1,1,1,1,1);
	b = ft_printf ("ft_printf4  :|%0#5o|%0#5.3o|%0#5.1o|%0#5.0o|%0#5.o|\n", 1,1,1,1,1);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	a =      printf ("printf5     :|%-0#5o|%-0#5.3o|%-0#5.1o|%-0#5.0o|%-0#5.o|\n", 1,1,1,1,1);
	b = ft_printf ("ft_printf5  :|%-0#5o|%-0#5.3o|%-0#5.1o|%-0#5.0o|%-0#5.o|\n", 1,1,1,1,1);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
    return (0);
}
