/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainkk3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 13:23:30 by mbui              #+#    #+#             */
/*   Updated: 2020/11/10 13:33:23 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/libftprintf.h"

int main(void)
{
	int a = 0;
	int b = 0;

	printf("POP\n");
	a =  ft_printf ("ft_printf9  :|%-0#5f|%-0#5.3f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 76,1,1,1,1);
	b = printf ("printf9     :|%-0#5f|%-0#5.3f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 76,1,1,1,1);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	a =  ft_printf ("ft_printf7  :|%-#5f|%-#5.3f|%-#5.1f|%-#5.0f|%-#5.f|\n", 0,0,0,0,0);
	b = printf ("printf7     :|%-#5f|%-#5.3f|%-#5.1f|%-#5.0f|%-#5.f|\n", 0,0,0,0,0);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
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
    a = ft_printf("%f\n", 9999999999999999999.0); //kk
	b = printf("%f\n", 9999999999999999999.0);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	a = ft_printf("%f\n", -0.0); //kk-?
	b = printf("%f\n", -0.0);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
    int papa;
    papa = ((16 * 16 * 16 * 16 * 16 * 16) + 1);
	a =ft_printf("#18 %+0.0p\n", papa);
	b = printf("#18 %+0.0p\n", papa);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	a = ft_printf("#2 %d %d %d\n", 542); //kk
	b = printf("#2 %d %d %d\n", 542);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	a = (ft_printf("Coucou float %-#15.1f\n", -0));
	b =    (printf("Coucou float %-#15.1f\n", -0));
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	a = (ft_printf("Coucou float %f\n", -0.0)); //kk-?
	b =    (printf("Coucou float %f\n", -0.0));
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	return (0);
}
