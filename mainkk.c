/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainkk.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:05:07 by mbui              #+#    #+#             */
/*   Updated: 2020/11/10 18:07:56 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/libftprintf.h"
#include <stdio.h>

int main()
{
	int a = 0;
	int b = 0;

	a = ft_printf("% Z|\n", 123);
	b = printf("% Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("%#Z|\n", 123);
	b = printf("%#Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("%-Z|\n", 123);
	b = printf("%-Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("%+Z|\n", 123);
	b = printf("%+Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("%0Z|\n", 123);
	b = printf("%0Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("%3Z|\n", 123);
	b = printf("%3Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("%10Z|\n", 123);
	b = printf("%10Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("%.Z|\n", 123);
	b = printf("%.Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("%.0Z|\n", 123);
	b = printf("%.0Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("%.3Z|\n", 123);
	b = printf("%.3Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("%.10Z|\n", 123);
	b = printf("%.10Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("% #Z|\n", 123);
	b = printf("% #Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("% -Z|\n", 123);
	b = printf("% -Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("% +Z|\n", 123);
	b = printf("% +Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("%#-Z|\n", 123);
	b = printf("%#-Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("%#+Z|\n", 123);
	b = printf("%#+Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("%-+Z|\n", 123);
	b = printf("%-+Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("%+0Z|\n", 123);
	b = printf("%+0Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("%03Z|\n", 123);
	b = printf("%03Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("%010Z|\n", 123);
	b = printf("%010Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("% #-Z|\n", 123);
	b = printf("% #-Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("% -+Z|\n", 123);
	b = printf("% -+Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("%#-+Z|\n", 123);
	b = printf("%#-+Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("%-+0Z|\n", 123);
	b = printf("%-+0Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("%+03Z|\n", 123);
	b = printf("%+03Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("%+010Z|\n", 123);
	b = printf("%+010Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("% #-+Z|\n", 123);
	b = printf("% #-+Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("%#-+0Z|\n", 123);
	b = printf("%#-+0Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("%-+03Z|\n", 123);
	b = printf("%-+03Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("%-+010Z|\n", 123);
	b = printf("%-+010Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("% #-+0Z|\n", 123);
	b = printf("% #-+0Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("%#-+03Z|\n", 123);
	b = printf("%#-+03Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("%#-+010Z|\n", 123);
	b = printf("%#-+010Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("% #-+03Z|\n", 123);
	b = printf("% #-+03Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("% #-+010Z|\n", 123);
	b = printf("% #-+010Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	a = ft_printf("% Z|\n", 123);
	b = printf("% Z|\n", 123);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	printf("a=%d|\n", a);
	printf("b=%d|\n", b);
	return (0);
}
