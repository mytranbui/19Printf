/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf_final1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <tjuzen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:50:50 by tjuzen            #+#    #+#             */
/*   Updated: 2020/09/14 11:52:20 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"
#include <limits.h>
#include <float.h>
#include <math.h>

int	main()
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




	/*
	//
	//
	// MAIN 0
	//
	*/

	// printf("\n");

	/*
	**  S
	*/









	printf("--------------------\n");
	printf("STRING\n");
	printf("--------------------\n");
	printf("\n");

	 	printf("|%s|\n", "Salut");
	  ft_printf("|%s|\n", "Salut");

	 	printf("|%.2s|\n", "Salut");
	  ft_printf("|%.2s|\n", "Salut");

		 printf("|%-45.s|\n", "Salut");
	  ft_printf("|%-45.s|\n", "Salut");

	 	printf("|%45.10s|\n", "Salut");
	  ft_printf("|%45.10s|\n", "Salut");

	 	printf("|%-2s|\n", "Hola hola");
	  ft_printf("|%-2s|\n", "Hola hola");

	 	printf("|%s|\n", NULL);
	  ft_printf("|%s|\n", NULL);

	 	printf("|%.145s|\n", "La vie est belle");
	  ft_printf("|%.145s|\n", "La vie est belle");

	 	printf("|%45.10s|\n", "Salut");
	  ft_printf("|%45.10s|\n", "Salut");
	printf("--------------------\n");
	printf("STRING TEST\n");
	printf("--------------------\n");
	printf("\n");
	 (ft_printf("Coucou = %s %.5s %.6s %.7s %.s %.0s %.s %.1s %5s %4s %6s %7s %8s, coucou\n", "Coucou", "Coucou", "Coucou", "Coucou", "Coucou","Coucou","Coucou","Coucou","Coucou","Coucou","Coucou","Coucou","Coucou"));
	    (printf("Coucou = %s %.5s %.6s %.7s %.s %.0s %.s %.1s %5s %4s %6s %7s %8s, coucou\n", "Coucou", "Coucou", "Coucou", "Coucou", "Coucou","Coucou","Coucou","Coucou","Coucou","Coucou","Coucou","Coucou","Coucou"));
	 printf("\n");
	(ft_printf("Salut = %.3s coucou %.3s haha\n", "bite", "chien"));
	   (printf("Salut = %.3s coucou %.3s haha\n", "bite", "chien"));
	printf("\n");
	(ft_printf("Coucou = %5.5s %5.6s %5.7s %6.6s %6.5s %7.s %1.s %5.15s %30.s, coucou\n", "Coucou","Coucou","Coucou","Coucou","Coucou","Coucou","Coucou","Coucou","Coucou"));
	   (printf("Coucou = %5.5s %5.6s %5.7s %6.6s %6.5s %7.s %1.s %5.15s %30.s, coucou\n", "Coucou","Coucou","Coucou","Coucou","Coucou","Coucou","Coucou","Coucou","Coucou"));
	printf("\n");
//	(ft_printf("Coucou = %*.*s, coucou\n", 20, 0, "Coucou"));
//	   (printf("Coucou = %*.*s, coucou\n", 20, 0, "Coucou"));
	printf("\n");
	(ft_printf("Coucou =  coucou\n"));
	   (printf("Coucou =  coucou\n"));
	printf("\n");
	(ft_printf("Coucou = %% coucou\n"));
	   (printf("Coucou = %% coucou\n"));

	/*
	** C, P and %%
	*/
	printf("--------------------\n");
	printf("C, P AND %% TEST\n");
	printf("--------------------\n");
	printf("\n");
	printf("\n");
	(ft_printf("Coucou = %c\n", 'w'));
	   (printf("Coucou = %c\n", 'w'));
	printf("\n");
	(ft_printf("Coucou = %c\n", '\0'));
	   (printf("Coucou = %c\n", '\0'));
	printf("\n");
	(ft_printf("Coucou = %c\n", (char)0xff11ff11));
	   (printf("Coucou = %c\n", (char)0xff11ff11));
	printf("\n");
	(ft_printf("Coucou = %c\n", -21));
	   (printf("Coucou = %c\n", -21));
	printf("\n");
	(ft_printf("Coucou = %-15c\n", 'w'));
	   (printf("Coucou = %-15c\n", 'w'));
	printf("\n");
	(ft_printf("Coucou = %4c\n", 'w'));
	   (printf("Coucou = %4c\n", 'w'));
	printf("\n");
	(ft_printf("^.^/%+0hhi^.^/\n", 1457223722));
	   (printf("^.^/%+0hhi^.^/\n", 1457223722));
	printf("\n");
	(ft_printf("Coucou = %0+hhi\n", 1592161129));
	   (printf("Coucou = %0+hhi\n", 1592161129));
	printf("\n");
	(ft_printf("Coucou = %----24p et %2p et aussi %12p\n", &a, &b, NULL));
	   (printf("Coucou = %----24p et %2p et aussi %12p\n", &a, &b, NULL));
	printf("\n");
	(ft_printf("Coucou = %#% % .5% %----24p et %5% %2p et aussi %12p %%%%%%\n", &a, &b, NULL));
	   (printf("Coucou = %#% % .5% %----24p et %5% %2p et aussi %12p %%%%%%\n", &a, &b, NULL));
	printf("\n");
}
