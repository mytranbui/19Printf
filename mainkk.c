/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2020/01/20 09:26:22 by mbui              #+#    #+#             */
/*   Updated: 2020/10/16 17:11:20 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/libftprintf.h"
#include <stdio.h>
#include <limits.h>

int ft_printf(const char *format, ...);

int main(void)
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	int f = 0;
	int g = 0;
	int h = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;
	int m = 0;
	int n = 0;
	int o = 0;
	int p = 0;
	int q = 0;
	int r = 0;
	int s = 0;
	int t = 0;
	int u = 0;
	int v = 0;
	int w = 0;
	int x = 0;
	int y = 0;
	int z = 0;
	long long test_conv = LONG_MAX;
	long long test_conv_neg = LONG_MIN;
	unsigned long test_conv_u = ULONG_MAX;

	ft_printf("%----24p et %2p et aussi %12p|\n", &a, &b, NULL);
	printf("%----24p et %2p et aussi %12p|\n", &a, &b, NULL);
	printf("\n");
	ft_printf("Coucou = %#% % .5% %----24p et %5% %2p et aussi %12p %%%%%%\n", &a, &b, NULL);
	printf("Coucou = %#% % .5% %----24p et %5% %2p et aussi %12p %%%%%%\n", &a, &b, NULL);



 ft_printf ("ft_printf4  :|%07p|%07p|%07p|%07p|%07p|\n", 0,0,0,0,0);
 printf ("printf4     :|%07p|%07p|%07p|%07p|%07p|\n", 0,0,0,0,0);
 ft_printf ("ft_printf4  :|%07p|%07p|%07p|%07p|%07p|\n", 1,1,1,1,1);
 printf ("printf4     :|%07p|%07p|%07p|%07p|%07p|\n", 1,1,1,1,1);
 ft_printf ("ft_printf4  :|%07p|%07p|%07p|%07p|%07p|\n", 999,999,999,999,999);
 printf ("printf4     :|%07p|%07p|%07p|%07p|%07p|\n", 999,999,999,999,999);
 ft_printf ("ft_printf4  :|%06p|%06p|%06p|%06p|%06p|\n", 999,999,999,999,999);
 printf ("printf4     :|%06p|%06p|%06p|%06p|%06p|\n", 999,999,999,999,999);



	ft_printf("ft_printf5 : %010i-\n", -10);
	printf( "printf5    : %010i-\n", -10);
	ft_printf("ft_printf7 : %+#10.4i-\n", 0);
	printf( "printf7    : %+#10.4i-\n", 0);
	ft_printf("ft_printf8 : %+-10.4i-\n", 0);
    printf("printf8    : %+-10.4i-\n", 0);
    ft_printf("ft_printf9 : %+010.4i-\n", 0);
    printf( "printf9    : %+010.4i-\n", 0);
	ft_printf("ft_printf11 : %+-5.3i-\n", 0);
      printf( "printf11    : %+-5.3i-\n", 0);

	ft_printf("Coucou float %-#15.1f\n", -0);
  	printf("Coucou float %-#15.1f\n", -0);
  	printf("\n");
	ft_printf("Coucou float %f\n", -0.0);
  	printf("Coucou float %f\n", -0.0);
	printf("\n");
	ft_printf("%05d\n", -42);
	printf("%05d\n", -42);
	printf("\n");
	ft_printf("%0+5d\n", -42);
	printf("%0+5d\n", -42);

	ft_printf("%04p||\n", 0);
	printf("%04p||\n", 0);
	ft_printf("|%o|%#o|%#o|%#5o|%#5.2o|%o|\n", 42, 42, 89, 42, 89, 00);
	printf("|%o|%#o|%#o|%#5o|%#5.2o|%o|\n", 42, 42, 89, 42, 89, 00);
	ft_printf("|%#o|%#o|%#5o|%#5.2o|%.o|%o|%o|%o|%o|%o|\n", 42, 42, 42, 42, 42, 42, 42,42,42,42);
	printf("|%#o|%#o|%#5o|%#5.2o|%.o|%o|%o|%o|%o|%o|\n", 42, 42, 42, 42, 42, 42, 42,42,42,42);
	ft_printf("|%#u|%#u|%#5u|%#5.2u|%.u|%u|%u|%u|%u|%u|\n", 42, 42, 42, 42, 42, 42, 42,42,42,42);
	printf("|%#u|%#u|%#5u|%#5.2u|%.u|%u|%u|%u|%u|%u|\n", 42, 42, 42, 42, 42, 42, 42,42,42,42);
	ft_printf("|%#d|%#d|%#5d|%#5.2d|%.d|%d|%d|%d|%d|%d|\n", 42, 42, 42, 42, 42, 42, 42,42,42,42);
	printf("|%#d|%#d|%#5d|%#5.2d|%.d|%d|%d|%d|%d|%d|\n", 42, 42, 42, 42, 42, 42, 42,42,42,42);

	printf("\n");
	ft_printf("|%#c|%#c|%#5c|%#5.2c|%.c|%c|%c|%c|%c|%c|\n", 42, 42, 42, 42, 42, 42, 42,42,42,42);
	printf("|%#c|%#c|%#5c|%#5.2c|%.c|%c|%c|%c|%c|%c|\n", 42, 42, 42, 42, 42, 42, 42,42,42,42);
	ft_printf("|%#s|%#s|%#5s|%#5.2s|%.s|%s|%s|%s|%s|%s|\n", "42", "42", "42", "42", "42", "42", "42","42","42","42");
	printf("|%#s|%#s|%#5s|%#5.2s|%.s|%s|%s|%s|%s|%s|\n", "42", "42", "42", "42", "42", "42", "42","42","42","42");
	ft_printf("|%#p|%#p|%#5p|%#5.2p|%.p|%p|%p|%p|%p|%p|\n", &b, &b, &b, &b, &b, &b, &b,&b,&b,&b);
	printf("|%#p|%#p|%#5p|%#5.2p|%.p|%p|%p|%p|%p|%p|\n", &b, &b, &b, &b, &b, &b, &b,&b,&b,&b);
	ft_printf("|%#d|%#d|%#5d|%#5.2d|%.d|%d|%d|%d|%d|%d|\n", 42, 42, 42, 42, 42, 42, 42,42,42,42);
	printf("|%#d|%#d|%#5d|%#5.2d|%.d|%d|%d|%d|%d|%d|\n", 42, 42, 42, 42, 42, 42, 42,42,42,42);
	ft_printf("|%#o|%#o|%#5o|%#5.2o|%.o|%o|%o|%o|%o|%o|\n", 42, 42, 42, 42, 42, 42, 42,42,42,42);
	printf("|%#o|%#o|%#5o|%#5.2o|%.o|%o|%o|%o|%o|%o|\n", 42, 42, 42, 42, 42, 42, 42,42,42,42);
	ft_printf("|%#u|%#u|%#5u|%#5.2u|%.u|%u|%u|%u|%u|%u|\n", 42, 42, 42, 42, 42, 42, 42,42,42,42);
	printf("|%#u|%#u|%#5u|%#5.2u|%.u|%u|%u|%u|%u|%u|\n", 42, 42, 42, 42, 42, 42, 42,42,42,42);
	ft_printf("|%#x|%#x|%#5x|%#5.2x|%.x|%x|%x|%x|%x|%x|\n", 42, 42, 42, 42, 42, 42, 42,42,42,42);
	printf("|%#x|%#x|%#5x|%#5.2x|%.x|%x|%x|%x|%x|%x|\n", 42, 42, 42, 42, 42, 42, 42,42,42,42);
	ft_printf("|%#f|%#f|%#5f|%#5.2f|%.f|%f|%f|%f|%f|%f|\n", 42.42, 42.42, 42.42, 42.42, 42.42, 42.42, 42.42,42.42,42.42,42.42);
	printf("|%#f|%#f|%#5f|%#5.2f|%.f|%f|%f|%f|%f|%f|\n", 42.42, 42.42, 42.42, 42.42, 42.42, 42.42, 42.42,42.42,42.42,42.42);
	printf("\n---TEST---\n");
	ft_printf("|%d|\n", -2147483648);
	printf("|%d|\n", -2147483648);
	printf("\n");
	ft_printf("|%f|\n", -2147483648);
	printf("|%f|\n", -2147483648);
	ft_printf("%05i|\n", 43);
	printf("%05i|\n", 43);
	//o u x KK
	printf("\n");
	ft_printf("%.*s||\n", -3, "hello");
	printf("%.*s||\n", -3, "hello");
	printf("\n");
	ft_printf("%%d 0000042 == |%d|\n", 0000042);
	printf("%%d 0000042 == |%d|\n", 0000042);
	printf("\n");
	ft_printf("Salut %20.12ld this %0 5d % 5d % 4.8i is not a test\n", 0x11ffaa147, 45, 45, 23);
	printf("Salut %20.12ld this %0 5d % 5d % 4.8i is not a test\n", 0x11ffaa147, 45, 45, 23);
	printf("\n");
	ft_printf("%0 5d|\n", 45);
	printf("%0 5d|\n", 45);
	printf("\n");
	ft_printf("% 5d|\n", 45);
	printf("% 5d|\n", 45);
	ft_printf("%+20.12lli|\n", (long long)0x11ffaa141237);
	printf("%+20.12lli|\n", (long long)0x11ffaa141237);
	printf("\n");
	ft_printf("%0+5d|\n", 42);
	printf("%0+5d|\n", 42);
	printf("\n");
	ft_printf("{%05.*d}\n", -15, 42);
	printf("{%05.*d}\n", -15, 42);
	ft_printf("{%*d}\n", -15, 42);
	printf("{%*d}\n", -15, 42);
	printf("\n");
	ft_printf("ultimate2 %*d|%*s|%*x|%*X|%*i|%*u|\n", 1, 5000, 1, "hey", 10, 54700, 1, 300, 100, -55, 1, -60);
	printf("ultimate2 %*d|%*s|%*x|%*X|%*i|%*u|\n", 1, 5000, 1, "hey", 10, 54700, 1, 300, 100, -55, 1, -60);
	printf("\n");
	ft_printf("%*s|%*x|%*X|%*i|%*u|\n", 1, "hey", 10, 54700, 1, 300, 100, -55, 1, -60);
	printf("%*s|%*x|%*X|%*i|%*u|\n", 1, "hey", 10, 54700, 1, 300, 100, -55, 1, -60);
	printf("\n");
	ft_printf("%*x|%*X|%*i|%*u|\n", 10, 54700, 1, 300, 100, -55, 1, -60);
	printf("%*x|%*X|%*i|%*u|\n", 10, 54700, 1, 300, 100, -55, 1, -60);
	// ft_printf("%-.5f %LF\n", 5.00, (long double)5.65);
	// printf("%-.5f %LF\n", 5.00, (long double)5.65);
	printf("\n");
	ft_printf("%+20.12lli|\n", (long long)0x11ffaa141237);
	printf("%+20.12lli|\n", (long long)0x11ffaa141237);
	printf("\n");
	
	a = ft_printf("%5.p|\n",NULL);
	b = printf("%5.p|\n",NULL);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	a = ft_printf("%#08x|\n", 42);
	b = printf("%#08x|\n", 42);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	a = ft_printf("%1$d|\n", 42);
	b = printf("%1$d|\n", 42);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	a = ft_printf("%x", -42);
	b = printf("%x", -42);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	a = ft_printf("%X", -42);
	b = printf("%X", -42);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	a = ft_printf("%ld|\n", LONG_MAX);
	b = printf("%ld|\n", LONG_MAX);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	a = ft_printf("%lld|\n", LLONG_MAX);
	b = printf("%lld|\n", LLONG_MAX);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	a = ft_printf("%o|\n", LONG_MAX);
	b = printf("%o|\n", LONG_MAX);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	a = ft_printf("%#1o|\n", 1);
	b = printf("%#1o|\n", 1);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	
	// a =ft_printf("%|\n");
	// //b = printf("%|\n");
	// printf("a=%d\n", a);
	// printf("b=%d\n", b);
	// a = ft_printf("%5|\n");
	// b = printf("%5");
	// printf("a=%d\n", a);
	// printf("b=%d\n", b);
	// a=ft_printf("%05|\n");
	// b=printf("%05|\n");
	// printf("a=%d\n", a);
	// printf("b=%d\n", b);
	// a=ft_printf("%-05|\n");
	// b=printf("%-05|\n");
	// printf("a=%d\n", a);
	// printf("b=%d\n", b);
	// a=ft_printf("%-.5|\n");
	// b=printf("%-.5|\n");
	// printf("a=%d\n", a);
	// printf("b=%d\n", b);
	// a=ft_printf("%.5|\n");
	// b=printf("%.5|\n");
	// printf("a=%d\n", a);
	// printf("b=%d\n", b);
	// a=ft_printf("%0.5|\n");
	// b=printf("%0.5|\n");
	// printf("a=%d\n", a);
	// printf("b=%d\n", b);
	return (0);
}
