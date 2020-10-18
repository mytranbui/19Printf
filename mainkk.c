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

#include "libftprintf.h"
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
	ft_printf("|%o|%#o|%#o|%#5o|%#5.2o|%.o|\n", 42, 42, 0, 42, 0, 0);
	printf("|%o|%#o|%#o|%#5o|%#5.2o|%.o|\n", 42, 42, 0, 42, 0, 0);
	return (0);
}
