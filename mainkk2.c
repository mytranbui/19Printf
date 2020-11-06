/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainkk2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 22:01:16 by mbui              #+#    #+#             */
/*   Updated: 2020/11/06 14:52:31 by mbui             ###   ########.fr       */
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
	// printf("--------------------\n");
	// printf("UN PEU DE TOUT\n");
	// printf("--------------------\n");
	// printf("\n");
	// a = (ft_printf("test %-7c %007d %-10.2s!!\n", 0xd777, 0x45, "〻"));
	// b =    (printf("test %-7c %007d %-10.2s!!\n", 0xd777, 0x45, "〻"));
	// printf("a=%d\n", a);
	// printf("b=%d\n", b);
	// a = (ft_printf("%-+-12.7dt%0 4i %04.2% et %c titi\n", 125, 124, 256));
	// b =    (printf("%-+-12.7dt%0 4i %04.2% et %c titi\n", 125, 124, 256));
	// printf("a=%d\n", a);
	// printf("b=%d\n", b);
	// a = (ft_printf("%--.4u et %#o %#012o %1c\n", -12, 0, 0, 95));
	// b =    (printf("%--.4u et %#o %#012o %1c\n", -12, 0, 0, 95));
	// printf("a=%d\n", a);
	// printf("b=%d\n", b);
	// a =  ft_printf ("ft_printf9  :|%-0#5f|%-0#5.3f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 0,0,0,0,0);
	// b = printf ("printf9     :|%-0#5f|%-0#5.3f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 0,0,0,0,0);
	// printf("a=%d\n", a);
	// printf("b=%d\n", b);
	// a =  ft_printf ("ft_printf7  :|%-#5f|%-#5.3f|%-#5.1f|%-#5.0f|%-#5.f|\n", 0,0,0,0,0);
	// b = printf ("printf7     :|%-#5f|%-#5.3f|%-#5.1f|%-#5.0f|%-#5.f|\n", 0,0,0,0,0);
	// printf("a=%d\n", a);
	// printf("b=%d\n", b);

	printf("FLOAT\n");
	a =  ft_printf ("ft_printf1  :|%5f|%5.3f|%5.1f|%5.0f|%5.f|\n", 0,0,0,0,0);
	b =  printf ("printf1     :|%5f|%5.3f|%5.1f|%5.0f|%5.f|\n", 0,0,0,0,0);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	a = ft_printf ("ft_printf2  :|% 5f|% 5.3f|% 5.1f|% 5.0f|% 5.f|\n", 0,0,0,0,0);
	b =  printf ("printf2     :|% 5f|% 5.3f|% 5.1f|% 5.0f|% 5.f|\n", 0,0,0,0,0);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	a = ft_printf ("ft_printf3  :|% +5f|% +5.3f|% +5.1f|% +5.0f|% +5.f|\n", 0,0,0,0,0);
	b = printf ("printf2     :|% +5f|% +5.3f|% +5.1f|% +5.0f|% +5.f|\n", 0,0,0,0,0);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	a = ft_printf ("ft_printf5  :|%05f|%05.3f|%05.1f|%05.0f|%05.f|\n", 0,0,0,0,0);
	b =  printf ("printf5     :|%05f|%05.3f|%05.1f|%05.0f|%05.f|\n", 0,0,0,0,0);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	a = ft_printf ("ft_printf6  :|%#5f|%#5.3f|%#5.1f|%#5.0f|%#5.f|\n", 0,0,0,0,0);
	b = printf ("printf6     :|%#5f|%#5.3f|%#5.1f|%#5.0f|%#5.f|\n", 0,0,0,0,0);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	a = ft_printf ("ft_printf8  :|%0#5f|%0#5.3f|%0#5.1f|%0#5.0f|%0#5.f|\n", 0,0,0,0,0);
	b = printf ("printf8     :|%0#5f|%0#5.3f|%0#5.1f|%0#5.0f|%0#5.f|\n", 0,0,0,0,0);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	a = ft_printf ("|% 05f|% 05.3f|% 05.1f|% 05.0f|% 05.f|\n", 0,0,-854,4587,0);
	b =   printf ("|% 05f|% 05.3f|% 05.1f|% 05.0f|% 05.f|\n",   0,0,-854,4587,0);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	a = ft_printf ("ft_printf4  :|%+-5f|%+-5.3f|%+-5.1f|%+-5.0f|%+-5.f|\n", 0,0,0,0,0);
	b = printf ("printf4     :|%+-5f|%+-5.3f|%+-5.1f|%+-5.0f|%+-5.f|\n", 0,0,0,0,0);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	a = ft_printf ("ft_printf4  :||%+-5.3f|%+-5.1f|%+-5.0f|%+-5.f|\n",0,0,0,0);
	b = printf ("printf4     :||%+-5.3f|%+-5.1f|%+-5.0f|%+-5.f|\n",0,0,0,0);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	a = ft_printf ("ft_printf4  :|%+-5f||\n",0);
	b = printf ("printf4     :|%+-5f||\n",0);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	// printf("--------------------\n");
	// printf("FLOAT NO MINUS\n");
	// printf("--------------------\n");
	// a = (ft_printf("Coucou float %+#1.f %.0f %1.f %.2f %.3f %.4f %.5f\n", 5.32, 530.66, 530.66, 530.66, 530.66, 530.66, 530.66));
	// b =    (printf("Coucou float %+#1.f %.0f %1.f %.2f %.3f %.4f %.5f\n", 5.32, 530.66, 530.66, 530.66, 530.66, 530.66, 530.66));
	// printf("a=%d\n", a);
	// printf("b=%d\n", b);
	// a = (ft_printf("Coucou float %# 15.10f %15.0f %5.1f %2.2f %2.3f %3.6f %.5f\n", -5.32, -530.66, 530.66, -530.66, 530.66, -530.66, 530.66));
	// b =    (printf("Coucou float %# 15.10f %15.0f %5.1f %2.2f %2.3f %3.6f %.5f\n", -5.32, -530.66, 530.66, -530.66, 530.66, -530.66, 530.66));
	// printf("a=%d\n", a);
	// printf("b=%d\n", b);
	// a = (ft_printf("Coucou float %#.15f %#15.0f %.1f %.2f %.3f %.4f %.5f\n", 5.12345678912345678912, (double)-0, 530.66, 530.66, -530.66, 530.66, 530.66));
	// b =    (printf("Coucou float %#.15f %#15.0f %.1f %.2f %.3f %.4f %.5f\n", 5.12345678912345678912, (double)-0, 530.66, 530.66, -530.66, 530.66, 530.66));
	// printf("a=%d\n", a);
	// printf("b=%d\n", b);
	// a = (ft_printf("Coucou float %+15f %+15f %2.1f %3.2f %7.3f %.4f %.5f\n", -6.12345678912345678912, 536.66, 536.66, -536.66, 536.66, 536.66, 536.66));
	// b =    (printf("Coucou float %+15f %+15f %2.1f %3.2f %7.3f %.4f %.5f\n", -6.12345678912345678912, 536.66, 536.66, -536.66, 536.66, 536.66, 536.66));
	// printf("a=%d\n", a);
	// printf("b=%d\n", b);
	// a = (ft_printf("%#15.3f|\n", (double)-0));
	// b =    (printf("%#15.3f|\n", (double)-0));
	// printf("a=%d\n", a);
	// printf("b=%d\n", b);
	// a = (ft_printf("%-#15.3f|\n", (double)-0));
	// b =    (printf("%-#15.3f|\n", (double)-0));
	// printf("a=%d\n", a);
	// printf("b=%d\n", b);
	return (0);
}
