/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 08:56:51 by mbui              #+#    #+#             */
/*   Updated: 2020/10/23 08:57:02 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../incs/libftprintf.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>

int ft_printf(const char *format, ...);

//hex kk when negative nb

int main(void)
{
	char			c = 'X';
	char			*s = "sandwiches are unexpectedly good when you're hungry";
//	int	i = -2147483648; //kkdi
//	int	i = -43125345; //4294967295
	//unsigned int	nb = 4294967296; //kkx kko
//	unsigned int	nb = 4294967296; //kko kkx
unsigned int	nb = 78879;
//	unsigned int	nb = 458;
	int		i = 0;
	//int		i = 2147483648; //kk on that number + & -
//	int		i = 2147483648;
	//int		i =-0;
//	float f = 5323.1468;
//int		*p = &i;
unsigned int *p= &nb;
	short		h = 697;
	long		l = 697;
	long long	m = 697;
//	float		f = 12548645487.15; //kk on first dec '6' instead of '0'
	float	f = -260893.3607;

//	int 	nb = -1564312;

/*	// single flag
	ft_printf("%+c%-5c||\n", c, 'g');
	printf("%+c%-5c||\n", c, 'g');
	ft_printf("%+c||\n", c);
	printf("%+c||\n", c);
	ft_printf("% c||\n", c);
	printf("% c||\n", c);
	ft_printf("%#c||\n", c);
	printf("%#c||\n", c);
	ft_printf("%.5clol||\n", c);
	printf("%.5clol||\n", c);
	ft_printf("%0c||\n", c);
	printf("%0c||\n", c);
	ft_printf("%-c||\n", c);
	printf("%-c||\n", c);
	ft_printf("%10c||\n", c);
	printf("%10c||\n", c);
	// multiple flags
	ft_printf("%-10c||\n", c);
	printf("%-10c||\n", c);
	ft_printf("%08.c||\n", c);
	printf("%08.c||\n", c);
	ft_printf("%0-18.4c||\n", c);
	printf("%0-18.4c||\n", c);
	ft_printf("%0-+18.60c||\n", c);
	printf("%0-+18.60c||\n", c);
	ft_printf("%0#5+c||\n", c);
	printf("%0#5+c||\n", c);
	ft_printf("%#05c||\n", c);
	printf("%#05c||\n", c);
	ft_printf("%0#05c||\n", c);
	printf("%0#05c||\n", c);
	ft_printf("%0#05c||\n", NULL);
	printf("%0#05c||\n", NULL);
	ft_printf("%c||\n", NULL);
	printf("%c||\n", NULL);
	ft_printf("%c||\n", nan);
	printf("%c||\n", nan);

	printf("\n-----STRING-----\n"); //(-, 0?, width, pres) //ok null ok
	// single flag
	ft_printf("%+s||\n", s);
	printf("%+s||\n", s);
	ft_printf("%0s||\n", s);
	printf("%0s||\n", s);
	ft_printf("% s||\n", s);
	printf("% s||\n", s);
	ft_printf("%#s||\n", s);
	printf("%#s||\n", s);
	ft_printf("%-s||\n", s);
	printf("%-s||\n", s);
	ft_printf("%5s||\n", s);
	printf("%5s||\n", s);
	ft_printf("%50s||\n", s);
	printf("%50s||\n", s);
	ft_printf("%.5s||\n", s);
	printf("%.5s||\n", s);
	ft_printf("%.50s||\n", s);
	printf("%.50s||\n", s);
	// multiple flags
	ft_printf("%0+50.50s||\n", s);
	printf("%0+50.50s||\n", s);
	ft_printf("%0-50.5s||\n", s);
	printf("%0-50.5s||\n", s);
	ft_printf("%-10s||\n", s);
	printf("%-10s||\n", s);
	ft_printf("%08.s||\n", s);
	printf("%08.s||\n", s);
	ft_printf("%8.s||\n", s);
	printf("%8.s||\n", s);
	ft_printf("%018.s||\n", s);
	printf("%018.s||\n", s);
	ft_printf("%-08.s||\n", s);
	printf("%-08.s||\n", s);
	ft_printf("%0-+18.4s||\n", s);
	printf("%0-+18.4s||\n", s);
	ft_printf("%0-+18.60s||\n", s);
	printf("%0-+18.60s||\n", s);
ft_printf("%0#05s||\n", NULL);
printf("%0#05s||\n", NULL);
ft_printf("%s||\n", NULL);
printf("%s||\n", NULL);

	printf("\n-----POINTER-----\n"); //(-, width, pres?) //ok null ok
	// single flag
	ft_printf("%+p||\n", p);
	printf("%+p||\n", p);
	ft_printf("%0p||\n", p);
	printf("%0p||\n", p);
	ft_printf("% p||\n", p);
	printf("% p||\n", p);
	ft_printf("%#p||\n", p);
	printf("%#p||\n", p);
	ft_printf("%-p||\n", p);
	printf("%-p||\n", p);
	ft_printf("%5p||\n", p);
	printf("%5p||\n", p);
	ft_printf("%50p||\n", p);
	printf("%50p||\n", p);
	ft_printf("%.5p||\n", p);
	printf("%.5p||\n", p);
	ft_printf("%.50p||\n", p);
	printf("%.50p||\n", p);
	// multiple flags
	ft_printf("%- 100.50p||\n", p);
	printf("%- 100.50p||\n", p);
	ft_printf("% 100.50p||\n", p);
	printf("% 100.50p||\n", p);
	ft_printf("%-050p||\n", p);
	printf("%-050p||\n", p);
	ft_printf("%0+50.50p||\n", p);
	printf("%0+50.50p||\n", p);
	ft_printf("%0-50.5p||\n", p);
	printf("%0-50.5p||\n", p);
	ft_printf("%-10p||\n", p);
	printf("%-10p||\n", p);
	ft_printf("%08.p||\n", p); //0-
	printf("%08.p||\n", p);
	ft_printf("%8.p||\n", p); //0-
	printf("%8.p||\n", p);
	ft_printf("%018p||\n", p);
	printf("%018p||\n", p);
	ft_printf("%-08.p||\n", p); ///sp miss
	printf("%-08.p||\n", p);
	ft_printf("%08.p||\n", p); ///sp miss
	printf("%08.p||\n", p);
	ft_printf("%0-+18.4p||\n", p);
	printf("%0-+18.4p||\n", p);
	ft_printf("%0-+18.60p||\n", p);
	printf("%0-+18.60p||\n", p);
	ft_printf("%33.44p||\n", p);
	printf("%33.44p||\n", p);
	ft_printf("%0-+ 12.2p||\n", p);
	printf("%0-+ 12.2p||\n", p);
	ft_printf("%015.p||\n", p); //0-
	printf("%015.p||\n", p);
	ft_printf("%15.p||\n", p);//0-
	printf("%15.p||\n", p);
	ft_printf("%015p||\n", p);
	printf("%015p||\n", p);
	ft_printf("%15p||\n", p);
	printf("%15p||\n", p);
	ft_printf("%+- 011p||\n", p);
	printf("%+- 011p||\n", p);
	ft_printf("%0#05p||\n", p);
	printf("%0#05p||\n", p);
	ft_printf("%0#5p||\n", p);
	printf("%0#5p||\n", p);
	ft_printf("%#05p||\n", p);
	printf("%#05p||\n", p);
	ft_printf("%p||\n", p);
	printf("%p||\n", p);

	printf("\n-----SIGNED INT-----\n"); //(+, - , ' ', 0 , width, pres)
	// single flag
	ft_printf("%+i||\n", i);
 	printf("%+i||\n", i);
	ft_printf("%0i||\n", i);
  	printf("%0i||\n", i);
	ft_printf("% i||\n", i);
  	printf("% i||\n", i);
	ft_printf("%#i||\n", i);
	printf("%#i||\n", i);
	ft_printf("%-i||\n", i);
	printf("%-i||\n", i);
	ft_printf("%5i||\n", i);
  	printf("%5i||\n", i);
	ft_printf("%50i||\n", i);
	printf("%50i||\n", i);
	ft_printf("%.5i||\n", i);
 	printf("%.5i||\n", i);
	ft_printf("%.50i||\n", i);
  	printf("%.50i||\n", i);
	// multiple flags
	ft_printf("% +100.50i||\n", i);
  	printf("% +100.50i||\n", i);
	ft_printf("%-050i||\n", i);
  	printf("%-050i||\n", i);
	ft_printf("%0+50.50i||\n", i);
  	printf("%0+50.50i||\n", i);
	ft_printf("%0-+050.5i||\n", i);
  	printf("%0-+050.5i||\n", i);
	ft_printf("%0-+050.8i||\n", i);
  	printf("%0-+050.8i||\n", i);
	ft_printf("%-10i||\n", i);
	printf("%-10i||\n", i);
	ft_printf("%08.i||\n", i);
  	printf("%08.i||\n", i); // 0 width8 pres0
	ft_printf("%018.i||\n", i);
 	printf("%018.i||\n", i);
	 // -0 width8 pres0
	ft_printf("%0-+18.60i||\n", i);
	printf("%0-+18.60i||\n", i);
	ft_printf("%0-+ 12.2i||\n", i);
	printf("%0-+ 12.2i||\n", i);
	ft_printf("%015.i||\n", i);
	printf("%015.i||\n", i); //replace 0 by null // 0 width15 pres0
	
	 ft_printf("%+-011.1i||\n", i); //sp+
	printf("%+-011.1i||\n", i);
	ft_printf("%+- 100.50i||\n", i);
  	printf("%+- 100.50i||\n", i);
	ft_printf("%05d||\n", i);
  	printf("%05d||\n", i);
	ft_printf("%07d||\n", i);
  	printf("%07d||\n", i);
	ft_printf("%8.i||\n", i);
 	printf("%8.i||\n", i);
	ft_printf("%015.i||\n", i);
	printf("%015.i||\n", i);
	ft_printf("%-08.i||\n", i);
 	printf("%-08.i||\n", i);
	ft_printf("%+- 011.i||\n", i); //kk
	printf("%+- 011.i||\n", i);
	ft_printf("%+ 011.i||\n", i);
	printf("%+ 011.i||\n", i);
	ft_printf("%8.5d||\n", i);
	printf("%8.5d||\n", i);
	ft_printf("%-8.5d||\n", i);
	printf("%-8.5d||\n", i);

	printf("\n-----UNSIGNED OCTAL-----\n");
	ft_printf("%+o||\n", nb);
	printf("%+o||\n", nb);
	ft_printf("%0o||\n", nb);
	printf("%0o||\n", nb);
	ft_printf("% o||\n", nb);
	printf("% o||\n", nb);
	ft_printf("%#o||\n", nb);
	printf("%#o||\n", nb);
	ft_printf("%-o||\n", nb);
	printf("%-o||\n", nb);
	ft_printf("%5o||\n", nb);
	printf("%5o||\n", nb);
	ft_printf("%50o||\n", nb);
	printf("%50o||\n", nb);
	ft_printf("%.5o||\n", nb);
	printf("%.5o||\n", nb);
	ft_printf("%.50o||\n", nb);
	printf("%.50o||\n", nb);
	// multiple flags
	ft_printf("%- 100.50o||\n", nb);
  	printf("%- 100.50o||\n", nb);
	ft_printf("% +100.50o||\n", nb);
  	printf("% +100.50o||\n", nb);
	ft_printf("%-050o||\n", nb);
  	printf("%-050o||\n", nb);
	ft_printf("%0+50.50o||\n", nb);
  	printf("%0+50.50o||\n", nb);
	ft_printf("%0-+050.5o||\n", nb);
  	printf("%0-+050.5o||\n", nb);
	ft_printf("%0-+050.8o||\n", nb);
  	printf("%0-+050.8o||\n", nb);
	ft_printf("%-10o||\n", nb);
	printf("%-10o||\n", nb);
	ft_printf("%08.o||\n", nb);
  	printf("%08.o||\n", nb);
	ft_printf("%8.o||\n", nb);
 	printf("%8.o||\n", nb);
	ft_printf("%-0#18.o||\n", nb);
	printf("%-0#18.o||\n", nb); //0-
	ft_printf("%- 08.o||\n", nb);
 	printf("%- 08.o||\n", nb);
	ft_printf("%0-+18.60o||\n", nb);
	printf("%0-+18.60o||\n", nb);
	ft_printf("%015.o||\n", nb);
	printf("%015.o||\n", nb);
	ft_printf("%+- 011o||\n", nb);
	printf("%+- 011o||\n", nb);
	ft_printf("%0 18o||\n", nb);
	printf("%0 18o||\n", nb);
	ft_printf("% -018.30o||\n", nb);
	printf("% -018.30o||\n", nb);
	ft_printf("%-050o||\n", nb);
	printf("%-050o||\n", nb);

	ft_printf("%0# 40.o||\n", nb);
	printf("%0# 40.o||\n", nb); //0-
	
	ft_printf("%-0#18.o||\n", nb);
	printf("%-0#18.o||\n", nb);
	
	ft_printf("%0-+# 12.2o||\n", nb);
	printf("%0-+# 12.2o||\n", nb); //0-
	ft_printf("%-0# 50o||\n", nb);
	printf("%-0# 50o||\n", nb); //sp-
	ft_printf("%0# 45o||\n", nb);
	printf("%0# 45o||\n", nb); //0-
	ft_printf("%0# 40.o||\n", nb);
	printf("%0# 40.o||\n", nb);
	ft_printf("%0# 40.60o||\n", nb);
	printf("%0# 40.60o||\n", nb);
	ft_printf("%#5o|\n", 1);
	printf("%#5o|\n", 1);
	ft_printf("%#.2o|\n", 1);
	printf("%#.2o|\n", 1);

	printf("\n-----UNSIGNED INT-----\n"); //(-, 0, #, )
	// single flag
	ft_printf("%+u||\n", nb);
	printf("%+u||\n", nb);
	ft_printf("%0u||\n", nb);
	printf("%0u||\n", nb);
	ft_printf("% u||\n", nb);
	printf("% u||\n", nb);
	ft_printf("%#u||\n", nb);
	printf("%#u||\n", nb);
	ft_printf("%-u||\n", nb);
	printf("%-u||\n", nb);
	ft_printf("%5u||\n", nb);
	printf("%5u||\n", nb);
	ft_printf("%50u||\n", nb);
	printf("%50u||\n", nb);
	ft_printf("%.5u||\n", nb);
	printf("%.5u||\n", nb);
	ft_printf("%.50u||\n", nb);
	printf("%.50u||\n", nb);
	// multiple flags
	ft_printf("%- 100.50u||\n", nb);
  	printf("%- 100.50u||\n", nb);
	ft_printf("% +100.50u||\n", nb);
  	printf("% +100.50u||\n", nb);
	ft_printf("%-050u||\n", nb);
  	printf("%-050u||\n", nb);
	ft_printf("%0+50.50u||\n", nb);
  	printf("%0+50.50u||\n", nb);
	ft_printf("%0-+050.5u||\n", nb);
  	printf("%0-+050.5u||\n", nb);
	ft_printf("%0-+050.8u||\n", nb);
  	printf("%0-+050.8u||\n", nb);
	ft_printf("%-10u||\n", nb);
	printf("%-10u||\n", nb);
	ft_printf("%08.u||\n", nb);
  	printf("%08.u||\n", nb);
	ft_printf("%8.u||\n", nb);
 	printf("%8.u||\n", nb);
	ft_printf("%#018.u||\n", nb);
 	printf("%0#18.u||\n", nb);
	ft_printf("%- 08.u||\n", nb);
 	printf("%- 08.u||\n", nb);
	ft_printf("%0-+18.60u||\n", nb);
	printf("%0-+18.60u||\n", nb);
	ft_printf("%0-+# 12.2u||\n", nb);
	printf("%0-+# 12.2u||\n", nb);
	ft_printf("%015.u||\n", nb);
	printf("%015.u||\n", nb);
	ft_printf("%+- 011u||\n", nb);
	printf("%+- 011u||\n", nb);
	ft_printf("% -018.30u||\n", nb);
	printf("% -018.30u||\n", nb);
	ft_printf("%-050u||\n", nb);
	printf("%-050u||\n", nb);
	ft_printf("%-0# 50u||\n", nb);
	printf("%-0# 50u||\n", nb);
	ft_printf("%0# 45u||\n", nb);
	printf("%0# 45u||\n", nb);
	ft_printf("%0 18u||\n", nb);
	printf("%0 18u||\n", nb);
	ft_printf("%0# 40.u||\n", nb);
	printf("%0# 40.u||\n", nb);
	ft_printf("%0# 40.60u||\n", nb);
	printf("%0# 40.60u||\n", nb);

	printf("\n-----UNSIGNED HEX-----\n"); //(-, 0, #, )
	// single flag
	ft_printf("%+x||\n", nb);
	printf("%+x||\n", nb);
	ft_printf("%0x||\n", nb);
	printf("%0x||\n", nb);
	ft_printf("% x||\n", nb);
	printf("% x||\n", nb);
	ft_printf("%#x||\n", nb);
	printf("%#x||\n", nb); //ok
	ft_printf("%-x||\n", nb);
	printf("%-x||\n", nb);
	ft_printf("%5x||\n", nb);
	printf("%5x||\n", nb);
	ft_printf("%50x||\n", nb);
	printf("%50x||\n", nb);
	ft_printf("%.5x||\n", nb);
	printf("%.5x||\n", nb);
	ft_printf("%.50x||\n", nb);
	printf("%.50x||\n", nb);
	// multiple flags
	ft_printf("%- 100.50x||\n", nb);
  	printf("%- 100.50x||\n", nb);
	ft_printf("% +100.50x||\n", nb);
  	printf("% +100.50x||\n", nb);
	ft_printf("%-050x||\n", nb);
  	printf("%-050x||\n", nb);
	ft_printf("%0+50.50x||\n", nb);
  	printf("%0+50.50x||\n", nb);
	ft_printf("%0-+050.5x||\n", nb);
  	printf("%0-+050.5x||\n", nb);
	ft_printf("%0-+050.8x||\n", nb);
  	printf("%0-+050.8x||\n", nb);
	ft_printf("%-10x||\n", nb);
	printf("%-10x||\n", nb);
	ft_printf("%08.x||\n", nb);
  	printf("%08.x||\n", nb);
	ft_printf("%8.x||\n", nb);
 	printf("%8.x||\n", nb);
	ft_printf("%- 08.x||\n", nb);
 	printf("%- 08.x||\n", nb);
	ft_printf("%0-+18.60x||\n", nb);
	printf("%0-+18.60x||\n", nb);
	ft_printf("%015.x||\n", nb);
	printf("%015.x||\n", nb);
	ft_printf("%+- 011x||\n", nb);
	printf("%+- 011x||\n", nb);
	ft_printf("% -018.30x||\n", nb);
	printf("% -018.30x||\n", nb);
	ft_printf("%-050x||\n", nb);
	printf("%-050x||\n", nb);
	ft_printf("%0 18X||\n", nb);
	printf("%0 18X||\n", nb);
	ft_printf("%0# 40.60X||\n", nb);
	printf("%0# 40.60X||\n", nb); //ok
	ft_printf("%0# 30.30X||\n", nb);
	printf("%0# 30.30X||\n", nb); //ok
	ft_printf("%0# 45X||\n", nb);
	printf("%0# 45X||\n", nb);      //0x not in the right place
	ft_printf("%0# 40.X||\n", nb);
	printf("%0# 40.X||\n", nb); //no
	ft_printf("%#018.x||\n", nb);
 	printf("%0#18.x||\n", nb); //no
	ft_printf("%0-+# 12.2x||\n", nb);
	printf("%0-+# 12.2x||\n", nb); //no
	ft_printf("%-0# 50X||\n", nb);
	printf("%-0# 50X||\n", nb); //no
	ft_printf("%0# 45.40X||\n", nb);
	printf("%0# 45.40X||\n", nb); //no width > pres
	ft_printf("%0# 40.45X||\n", nb);
	printf("%0# 40.45X||\n", nb);

	printf("\n-----PERCENTS-----\n"); //(-,0,width) xpres x# x' '?
	// single flag
	ft_printf("%+%||\n");
	printf("%+%||\n");
	ft_printf("%0%||\n");
	printf("%0%||\n");
	ft_printf("% %||\n");
	printf("% %||\n");
	ft_printf("%#%||\n");
	printf("%#%||\n"); //ok
	ft_printf("%-%||\n");
	printf("%-%||\n");
	ft_printf("%#0 5%||\n");
	printf("%#0 5%||\n");
	ft_printf("%.5%||\n");
	printf("%.5%||\n");
	// multiple flags
	ft_printf("%- 100.50%||\n");
	printf("%- 100.50%||\n");
	ft_printf("% +100.50%||\n");
	printf("% +100.50%||\n");
	ft_printf("%-050%||\n");
	printf("%-050%||\n");
	ft_printf("%0+50.50%||\n");
	printf("%0+50.50%||\n");
	ft_printf("%0-+050.5%||\n");
	printf("%0-+050.5%||\n");
	ft_printf("%0-+050.8%||\n");
	printf("%0-+050.8%||\n");
	ft_printf("%-10%||\n");
	printf("%-10%||\n");
	ft_printf("%08.%||\n");
	printf("%08.%||\n");
	ft_printf("%8.%||\n");
	printf("%8.%||\n");
	ft_printf("%#018.%||\n");
	printf("%0#18.%||\n"); //no
	ft_printf("%- 08.%||\n");
	printf("%- 08.%||\n");
	ft_printf("%0-+18.60%||\n");
	printf("%0-+18.60%||\n");
	ft_printf("%0-+# 12.2%||\n");
	printf("%0-+# 12.2%||\n"); //no
	ft_printf("%015.%||\n");
	printf("%015.%||\n");
	ft_printf("%+- 011%||\n");
	printf("%+- 011%||\n");
	ft_printf("% -018.30%||\n");
	printf("% -018.30%||\n");
	ft_printf("%-050%||\n");
	printf("%-050%||\n");
	ft_printf("%-0# 50%||\n");
	printf("%-0# 50%||\n"); //no
	ft_printf("%0# 45%||\n");
	printf("%0# 45%||\n");
	ft_printf("%0 18%||\n");
	printf("%0 18%||\n");
	ft_printf("%0# 40.%||\n");
	printf("%0# 40.%||\n"); //no
	ft_printf("%0# 40.60%||\n");
	printf("%0# 40.60%||\n"); //ok
	ft_printf("%0# 45.40%||\n");
	printf("%0# 45.40%||\n"); //no width > pres
	ft_printf("%0# 0.30%||\n");
	printf("%0# 0.30%||\n"); //ok

*/		printf("\n-----FLOAT-----\n"); //(-, 0, #, )
		// single flag
		ft_printf("%+f||\n", f);
		printf("%+f||\n", f);
		ft_printf("%0f||\n", f);
		printf("%0f||\n", f);
		ft_printf("% f||\n", f);
		printf("% f||\n", f);
		ft_printf("%#f||\n", f);
		printf("%#f||\n", f); //ok
		ft_printf("%-f||\n", f);
		printf("%-f||\n", f);
		ft_printf("%5f||\n", f);
		printf("%5f||\n", f);
		ft_printf("%50f||\n", f);
		printf("%50f||\n", f);
		ft_printf("%.5f||\n", f);
		printf("%.5f||\n", f);
		ft_printf("%.50f||\n", f);
		printf("%.50f||\n", f);
		// multiple flags
		ft_printf("%- 100.50f||\n", f);
	  	printf("%- 100.50f||\n", f);
		ft_printf("% +100.50f||\n", f);
	  	printf("% +100.50f||\n", f);
		ft_printf("%0+50.50f||\n", f);
	  	printf("%0+50.50f||\n", f);

		ft_printf("%-10f||\n", f);
		printf("%-10f||\n", f);
		ft_printf("%08.f||\n", f);
	  	printf("%08.f||\n", f);
		ft_printf("%8.f||\n", f);
	 	printf("%8.f||\n", f);
		ft_printf("%#018.f||\n", f);
	 	printf("%0#18.f||\n", f); //no
		 //no
		ft_printf("%015.f||\n", f);
		printf("%015.f||\n", f);


		ft_printf("%0# 45f||\n", f);
		printf("%0# 45f||\n", f);
		ft_printf("%0 18f||\n", f);
		printf("%0 18f||\n", f);
		ft_printf("%0# 40.f||\n", f);
		printf("%0# 40.f||\n", f); //no
		ft_printf("%0# 40.60f||\n", f);
		printf("%0# 40.60f||\n", f); //ok
		ft_printf("%0# 45.40f||\n", f);
		printf("%0# 45.40f||\n", f); //no width > pres
		ft_printf("%0# 30.30f||\n", f);
		printf("%0# 30.30f||\n", f);
		ft_printf("%.f||\n", f);
		printf("%.f||\n", f);
		ft_printf("%.2f||\n", f);
		printf("%.2f||\n", f);
		ft_printf("%.f||\n", (float)12);
		printf("%.f||\n", (float)12);
		ft_printf("%-050f||\n", f);
	  	printf("%-050f||\n", f);
		ft_printf("%0-+050.5f||\n", f);
		  printf("%0-+050.5f||\n", f);
		ft_printf("%0-+050.8f||\n", f);
  	printf("%0-+050.8f||\n", f);
		ft_printf("% -018.30f||\n", f);
		printf("% -018.30f||\n", f);
		ft_printf("%-050f||\n", f);
		printf("%-050f||\n", f);
		ft_printf("%-0# 50f||\n", f);
		printf("%-0# 50f||\n", f);
		ft_printf("%- 08.f||\n", f);
	 	printf("%- 08.f||\n", f);
		ft_printf("%0-+18.60f||\n", f);
		printf("%0-+18.60f||\n", f);
		ft_printf("%0-+# 12.2f||\n", f);
		printf("%0-+# 12.2f||\n", f);
		ft_printf("%+- 011f||\n", f);
		printf("%+- 011f||\n", f);
		ft_printf("%+030f||\n", f);
		printf("%+030f||\n", f);
// int a;
// int b;
// a = 0;
// b = 0;
// a = printf ("printf9     :|%-0#5f|%-0#5.3f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 0,0,0,0,0);
// printf("a=%d\n", a);
// a =  ft_printf ("ft_printf9  :|%-0#5f|%-0#5.3f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 0,0,0,0,0);
// printf("a=%d\n", a);
// a = printf ("printf7     :|%-#5f|%-#5.3f|%-#5.1f|%-#5.0f|%-#5.f|\n", 0,0,0,0,0);
// printf("a=%d\n", a);
// a =  ft_printf ("ft_printf7  :|%-#5f|%-#5.3f|%-#5.1f|%-#5.0f|%-#5.f|\n", 0,0,0,0,0);
// printf("a=%d\n", a);
//  printf("FLOAT\n");

// a =  printf ("printf1     :|%5f|%5.3f|%5.1f|%5.0f|%5.f|\n", 0,0,0,0,0);
// a =  ft_printf ("ft_printf1  :|%5f|%5.3f|%5.1f|%5.0f|%5.f|\n", 0,0,0,0,0);

// a =  printf ("printf2     :|% 5f|% 5.3f|% 5.1f|% 5.0f|% 5.f|\n", 0,0,0,0,0);
// a = ft_printf ("ft_printf2  :|% 5f|% 5.3f|% 5.1f|% 5.0f|% 5.f|\n", 0,0,0,0,0);

// a = printf ("printf2     :|% +5f|% +5.3f|% +5.1f|% +5.0f|% +5.f|\n", 0,0,0,0,0);
// a = ft_printf ("ft_printf3  :|% +5f|% +5.3f|% +5.1f|% +5.0f|% +5.f|\n", 0,0,0,0,0);



// a =  printf ("printf5     :|%05f|%05.3f|%05.1f|%05.0f|%05.f|\n", 0,0,0,0,0);
// a = ft_printf ("ft_printf5  :|%05f|%05.3f|%05.1f|%05.0f|%05.f|\n", 0,0,0,0,0);

// a = printf ("printf6     :|%#5f|%#5.3f|%#5.1f|%#5.0f|%#5.f|\n", 0,0,0,0,0);
// a = ft_printf ("ft_printf6  :|%#5f|%#5.3f|%#5.1f|%#5.0f|%#5.f|\n", 0,0,0,0,0);

// a = printf ("printf8     :|%0#5f|%0#5.3f|%0#5.1f|%0#5.0f|%0#5.f|\n", 0,0,0,0,0);
// a = ft_printf ("ft_printf8  :|%0#5f|%0#5.3f|%0#5.1f|%0#5.0f|%0#5.f|\n", 0,0,0,0,0);

//  a =   printf ("|% 05f|% 05.3f|% 05.1f|% 05.0f|% 05.f|\n",   0,0,-854,4587,0);
// a = ft_printf ("|% 05f|% 05.3f|% 05.1f|% 05.0f|% 05.f|\n", 0,0,-854,4587,0);
// printf("\n");

// a = printf ("printf4     :|%+-5f|%+-5.3f|%+-5.1f|%+-5.0f|%+-5.f|\n", 0,0,0,0,0);
// a = ft_printf ("ft_printf4  :|%+-5f|%+-5.3f|%+-5.1f|%+-5.0f|%+-5.f|\n", 0,0,0,0,0);

// printf("FLOAT\n");

// a = printf ("printf1     :|%-5.3f|%-5.2f|%-5.1f|%-5.0f|%-5.f|\n", 999.999,999.999,999.999,999.999,999.999);
// a = ft_printf ("ft_printf1  :|%-5.3f|%-5.2f|%-5.1f|%-5.0f|%-5.f|\n", 999.999,999.999,999.999,999.999,999.999);

// a = printf ("printf2     :|%- 5f|%- 5.3f|%- 5.1f|%- 5.0f|%- 5.f|\n", 999.999,999.999,999.999,999.999,999.999);
// a = ft_printf ("ft_printf2  :|%- 5f|%- 5.3f|%- 5.1f|%- 5.0f|%- 5.f|\n", 999.999,999.999,999.999,999.999,999.999);
// //3
// a = printf ("printf3     :|%- +5f|%- +5.3f|%- +5.1f|%- +5.0f|%- +5.f|\n", 999.999,999.999,999.999,999.999,999.999);
// a = ft_printf ("ft_printf3  :|%- +5f|%- +5.3f|%- +5.1f|%- +5.0f|%- +5.f|\n", 999.999,999.999,999.999,999.999,999.999);
// //4
// a = printf ("printf4     :|%+-5f|%+-5.3f|%+-5.1f|%+-5.0f|%+-5.f|\n", 999.999,999.999,999.999,999.999,999.999);
// a = ft_printf ("ft_printf4  :|%+-5f|%+-5.3f|%+-5.1f|%+-5.0f|%+-5.f|\n", 999.999,999.999,999.999,999.999,999.999);
// //5
// a = printf ("printf5     :|%-05f|%-05.3f|%-05.1f|%-05.0f|%-05.f|\n", 999.999,999.999,999.999,999.999,999.999);
// a = ft_printf ("ft_printf5  :|%-05f|%-05.3f|%-05.1f|%-05.0f|%-05.f|\n", 999.999,999.999,999.999,999.999,999.999);
// //6
// a = printf ("printf6     :|%-#5f|%-#5.3f|%-#5.1f|%-#5.0f|%-#5.f|\n", 999.999,999.999,999.999,999.999,999.999);
// a = ft_printf ("ft_printf6  :|%-#5f|%-#5.3f|%-#5.1f|%-#5.0f|%-#5.f|\n", 999.999,999.999,999.999,999.999,999.999);
// //7
// a = printf ("printf7     :|%-#5f|%-#5.3f|%-#5.1f|%-#5.0f|%-#5.f|\n", 999.999,999.999,999.999,999.999,999.999);
// a = ft_printf ("ft_printf7  :|%-#5f|%-#5.3f|%-#5.1f|%-#5.0f|%-#5.f|\n", 999.999,999.999,999.999,999.999,999.999);
// // //9
// a = printf ("printf9         :|%-0#5f|%-0#5.11f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.10,999.10,999.10,999.10,999.10,999.10,999.10,999.10,999.10,999.10,999.10,999.10,999.10);
// a = ft_printf ("ft_printf9      :|%-0#5f|%-0#5.11f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.10,999.10,999.10,999.10,999.10,999.10,999.10,999.10,999.10,999.10,999.10,999.10,999.10);


// //
// a = printf ("printf8         :|%-.2f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.999,999.999,999.999,999.999,999.999,999.999,999.999,999.999,999.999,999.999,999.999,999.999,999.999);
// a = ft_printf ("ft_printf8      :|%-.2f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.999,999.999,999.999,999.999,999.999,999.999,999.999,999.999,999.999,999.999,999.999,999.999,999.999);
// //9
// a = printf ("printf10        :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.9,999.9,999.9,999.9,999.9,999.9,999.9,999.9,999.9,999.9,999.9,999.9,999.9);
// a = ft_printf ("ft_printf10     :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.9,999.9,999.9,999.9,999.9,999.9,999.9,999.9,999.9,999.9,999.9,999.9,999.9);
// // //9
// a = printf ("printf11        :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.8,999.8,999.8,999.8,999.8,999.8,999.8,999.8,999.8,999.8,999.8,999.8,999.8);
// a = ft_printf ("ft_printf11     :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.8,999.8,999.8,999.8,999.8,999.8,999.8,999.8,999.8,999.8,999.8,999.8,999.8);
// // //9
// a = printf ("printf12        :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.7,999.7,999.7,999.7,999.7,999.7,999.7,999.7,999.7,999.7,999.7,999.7,999.7);
// a = ft_printf ("ft_printf12     :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.7,999.7,999.7,999.7,999.7,999.7,999.7,999.7,999.7,999.7,999.7,999.7,999.7);
// //9
// a = printf ("printf13        :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.6,999.6,999.6,999.6,999.6,999.6,999.6,999.6,999.6,999.6,999.6,999.6,999.6);
// a = ft_printf ("ft_printf13     :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.6,999.6,999.6,999.6,999.6,999.6,999.6,999.6,999.6,999.6,999.6,999.6,999.6);
// //9
//  a =   printf ("printf14        :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.5,999.5,999.5,999.5,999.5,999.5,999.5,999.5,999.5,999.5,999.5,999.5,999.5);
// a = ft_printf ("ft_printf14     :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.5,999.5,999.5,999.5,999.5,999.5,999.5,999.5,999.5,999.5,999.5,999.5,999.5);
// // //9


// a = printf ("printf15        :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.4,999.4,999.4,999.4,999.4,999.4,999.4,999.4,999.4,999.4,999.4,999.4,999.4);
// a = ft_printf ("ft_printf15     :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.4,999.4,999.4,999.4,999.4,999.4,999.4,999.4,999.4,999.4,999.4,999.4,999.4);
// //9
// a = printf ("printf16        :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%0-#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.3,999.3,999.3,999.3,999.3,999.3,999.3,999.3,999.3,999.3,999.3,999.3,999.3);
// a = ft_printf ("ft_printf16     :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.3,999.3,999.3,999.3,999.3,999.3,999.3,999.3,999.3,999.3,999.3,999.3,999.3);
// //9
// a = printf ("printf17        :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.2,999.2,999.2,999.2,999.2,999.2,999.2,999.2,999.2,999.2,999.2,999.2,999.2);
// a = ft_printf ("ft_printf17     :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.2,999.2,999.2,999.2,999.2,999.2,999.2,999.2,999.2,999.2,999.2,999.2,999.2);
// //9
//  a =   printf ("printf18        :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.1,999.1,999.1,999.1,999.1,999.1,999.1,999.1,999.1,999.1,999.1,999.1,999.1);
// a = ft_printf ("ft_printf18     :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.1,999.1,999.1,999.1,999.1,999.1,999.1,999.1,999.1,999.1,999.1,999.1,999.1);
// //9
//  a =   printf ("printf19        :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.,999.,999.,999.,999.,999.,999.,999.,999.,999.,999.,999.,999.);
// a = ft_printf ("ft_printf19     :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.,999.,999.,999.,999.,999.,999.,999.,999.,999.,999.,999.,999.);
// //
//   a =  printf ("printf20        :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.0,999.0,999.0,999.0,999.0,999.0,999.0,999.0,999.0,999.0,999.0,999.0,999.0);
// a = ft_printf ("ft_printf20     :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.0,999.0,999.0,999.0,999.0,999.0,999.0,999.0,999.0,999.0,999.0,999.0,999.0);

//  a =   printf ("printf21        :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0-#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.9999999,999.9999999,999.9999999,999.9999999,999.9999999,999.9999999,999.9999999,999.9999999,999.9999999,999.9999999,999.9999999,999.9999999,999.9999999);
// a = ft_printf ("ft_printf21     :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0-#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.9999999,999.9999999,999.9999999,999.9999999,999.9999999,999.9999999,999.9999999,999.9999999,999.9999999,999.9999999,999.9999999,999.9999999,999.9999999);

// a = printf ("printf22        :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.8999999,999.8999999,999.8999999,999.8999999,999.8999999,999.8999999,999.8999999,999.8999999,999.8999999,999.8999999,999.8999999,999.8999999,999.8999999);
// a = ft_printf ("ft_printf22     :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.8999999,999.8999999,999.8999999,999.8999999,999.8999999,999.8999999,999.8999999,999.8999999,999.8999999,999.8999999,999.8999999,999.8999999,999.8999999);

// a = printf ("printf23        :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.7999999,999.7999999,999.7999999,999.7999999,999.7999999,999.7999999,999.7999999,999.7999999,999.7999999,999.7999999,999.7999999,999.7999999,999.7999999);
// a = ft_printf ("ft_printf23     :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.7999999,999.7999999,999.7999999,999.7999999,999.7999999,999.7999999,999.7999999,999.7999999,999.7999999,999.7999999,999.7999999,999.7999999,999.7999999);
// //
// a = printf ("printf24        :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.6999999,999.6999999,999.6999999,999.6999999,999.6999999,999.6999999,999.6999999,999.6999999,999.6999999,999.6999999,999.6999999,999.6999999,999.6999999);
// a = ft_printf ("ft_printf24     :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.6999999,999.6999999,999.6999999,999.6999999,999.6999999,999.6999999,999.6999999,999.6999999,999.6999999,999.6999999,999.6999999,999.6999999,999.6999999);

// a = printf ("printf25        :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.5999999,999.5999999,999.5999999,999.5999999,999.5999999,999.5999999,999.5999999,999.5999999,999.5999999,999.5999999,999.5999999,999.5999999,999.5999999);
// a = ft_printf ("ft_printf25     :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.5999999,999.5999999,999.5999999,999.5999999,999.5999999,999.5999999,999.5999999,999.5999999,999.5999999,999.5999999,999.5999999,999.5999999,999.5999999);

// a = printf ("printf26        :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.4999999,999.4999999,999.4999999,999.4999999,999.4999999,999.4999999,999.4999999,999.4999999,999.4999999,999.4999999,999.4999999,999.4999999,999.4999999);
// a = ft_printf ("ft_printf26     :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.4999999,999.4999999,999.4999999,999.4999999,999.4999999,999.4999999,999.4999999,999.4999999,999.4999999,999.4999999,999.4999999,999.4999999,999.4999999);

// a = printf ("printf27        :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.3999999,999.3999999,999.3999999,999.3999999,999.3999999,999.3999999,999.3999999,999.3999999,999.3999999,999.3999999,999.3999999,999.3999999,999.3999999);
// a = ft_printf ("ft_printf27     :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.3999999,999.3999999,999.3999999,999.3999999,999.3999999,999.3999999,999.3999999,999.3999999,999.3999999,999.3999999,999.3999999,999.3999999,999.3999999);

// a = printf ("printf28        :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.2999999,999.2999999,999.2999999,999.2999999,999.2999999,999.2999999,999.2999999,999.2999999,999.2999999,999.2999999,999.2999999,999.2999999,999.2999999);
// a = ft_printf ("ft_printf28     :|%-0#5f|%-0#5.10f|%-0#5.9f|%-0#5.8f|%-0#5.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.2999999,999.2999999,999.2999999,999.2999999,999.2999999,999.2999999,999.2999999,999.2999999,999.2999999,999.2999999,999.2999999,999.2999999,999.2999999);

// a = printf ("printf29        :|%-#15f|%-0#15.10f|%-0#15.9f|%-0#15.8f|%-0#12.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.1999999,999.1999999,999.1999999,999.1999999,999.1999999,999.1999999,999.1999999,999.1999999,999.1999999,999.1999999,999.1999999,999.1999999,999.1999999);
// a = ft_printf ("ft_printf29     :|%-#15f|%-0#15.10f|%-0#15.9f|%-0#15.8f|%-0#12.7f|%-0#5.6f|%-0#5.5f|%-0#5.4f|%-0#5.3f|%-0#5.2f|%-0#5.1f|%-0#5.0f|%-0#5.f|\n", 999.1999999,999.1999999,999.1999999,999.1999999,999.1999999,999.1999999,999.1999999,999.1999999,999.1999999,999.1999999,999.1999999,999.1999999,999.1999999);


// a = printf ("printf5     :|%-f|\n", 0.0001);
// a = ft_printf ("printf5     :|%-f|\n", 0.0001);

// //
// a = printf("flt value     :   %f\n",  (float)1844674407370955161.1844674407370955161);
// a = ft_printf("flt value     :   %f\n",  (float)1844674407370955161.1844674407370955161);

// a = printf("%f\n", 9999999999999999999.0);
// a = ft_printf("%f\n", 9999999999999999999.0);

// a = printf("%.2f\n", 82.135);
// a = ft_printf("%.2f\n", 82.135);
// a = printf("%.3f\n", 484187171.1235);
// a = ft_printf("%.3f\n", 484187171.1235);

// a = printf("%f\n", -0.0);
// a = ft_printf("%f\n", -0.0);
 /*ft_printf("%i||\n", i);
 printf("%i||\n", i);
 ft_printf("%hi||\n", h);
 printf("%hi||\n", h);
 ft_printf("%hhi||\n", c);
 printf("%hhi||\n", c);
 ft_printf("%li||\n", l);
 printf("%li||\n", l);
 ft_printf("%llli||\n", m);
 printf("%llli||\n", m);
 ft_printf("%lli||\n", m);
 printf("%lli||\n", m);
 ft_printf("%2L25li||\n", m);
 printf("%2L25li||\n", m);
 ft_printf("%hx||\n", 587);
 printf("%hx||\n", 587);
 ft_printf("%hx||\n", h);
 printf("%hx||\n", h);
ft_printf("%0-+ .o|\n", 0);
printf("%0-+ .o|\n", 0);
ft_printf("%#.o|\n",0);
printf("%#.o|\n",0);
ft_printf("|%-o|%-#o|%-#o|%#-5o|%#-5.2o|%-.o|\n", 42, 42, 0, 42, 0, 0);
printf("|%-o|%-#o|%-#o|%#-5o|%#-5.2o|%-.o|\n", 42, 42, 0, 42, 0, 0);
ft_printf("|%-0#5.o|%-0#5.3o|%-.o|%-.0o|%-#.o|\n",   0,0,0,0,0);
printf("|%-0#5.o|%-0#5.3o|%-.o|%-.0o|%-#.o|\n", 0,0,0,0,0);
printf("\nUNSIGNED\n");
ft_printf ("%+5.1u|\n", LONG_MAX);
printf ("%+5.1lu|\n", LONG_MAX);
ft_printf ("%-+5.1u|\n",LONG_MAX);
printf ("%-+5.1u|\n", LONG_MAX);
ft_printf ("%+5.1u|\n", 922337203685477580);
printf ("%+5.1u|\n", 922337203685477580);
printf("\nHEXA\n");
ft_printf("Salxt %08.4x et  %.1x %#5.11x %5.17x %#.4x\n", 11, 12, 13, 14, 14);
printf("Salxt %08.4x et  %.1x %#5.11x %5.17x %#.4x\n", 11, 12, 13, 14, 14);
ft_printf("xSalut %08.4x et %#08x %.1x %#5.11x %5.17x %#.4x\n", 0, 0, 0, 0, 0, 0);
printf("xSalut %08.4x et %#08x %.1x %#5.11x %5.17x %#.4x\n", 0, 0, 0, 0, 0, 0);
ft_printf("xSalxt %-10.4x %#08x %-#5.20x %-5.30x %-#.4x %#8x\n", 0, 5, 0, 0, 0, 60000000);
printf("xSalxt %-10.4x %#08x %-#5.20x %-5.30x %-#.4x %#8x\n", 0, 5, 0, 0, 0, 60000000);
ft_printf("mee:%#5x|\n", 0);
printf ("you:%#5x|\n",0);
ft_printf("%# 40u|\n", 0);
printf("%# 40u|\n", 0);
ft_printf ("printf2     :|%#5x|%#5.3x|%#5.1x|%#5.0x|%#5.x|\n", 1,1,1,1,1);
printf ("ft_printf2  :|%#5x|%#5.3x|%#5.1x|%#5.0x|%#5.x|\n", 1,1,1,1,1);
ft_printf ("printf2     :|%#5x|%#5.3x|%#5.1x|%#5.0x|%#5.x|\n", 0,0,0,0,0);
printf ("ft_printf2  :|%#5x|%#5.3x|%#5.1x|%#5.0x|%#5.x|\n", 0,0,0,0,0);
ft_printf("SalXt %-#.3X %#-8.4X et  %-.1X %-#5.11X %-5.17X %-#.4X\n", 10, 11, 12, 13, 14, 14);
printf("SalXt %-#.3X %#-8.4X et  %-.1X %-#5.11X %-5.17X %-#.4X\n", 10, 11, 12, 13, 14, 14);
ft_printf("ici ici XSalXt %-10.4X %#08X %-#5.20X %-5.30X %-#.4X %#8X %#08X\n", 0, 5, 0, 0, 0, 42, 42);
printf("ici ici XSalXt %-10.4X %#08X %-#5.20X %-5.30X %-#.4X %#8X %#08X\n", 0, 5, 0, 0, 0, 42, 42);
ft_printf("%010d\n", -42);
printf("%010d\n", -42);
printf("%15f",1.123456);
	ft_printf("caca%0dpopo%+d", 45, 89);
	 ft_printf("\n--string=%s\n--sign=%%\n--num=%d\n--num2=%d\n--sign2=%%\n--sign3=%%\n--numi=%i\n--char=%c\n--num3=%d\n--address=%p\n--hex=%x\n--HEX=%X\n",s,100,-7852,23534, 'c', 45, &c,4364873,61534);
	 printf("SOLUTION:\n--string=%s--sign=%%--num=%d--num2=%d--sign2=%%--sign3=%%--numi=%i--char=%c--num3=%d--address=%p--hex=%x--HEX=%X\n",s,100,-7852,23534, 'c', 45, &c,4364873,61534);
	 printf("uint=%ld\n",4294967295);
	ft_printf("\n%+0dpopodpo%-d\n", 78,-50);
		printf("\n%+0dpopodpo%-d\n", 78,-50);
	ft_printf("\n%-25p||\n", p);
	printf("\n%-25p||\n", p);
		ft_printf("%14+d||\n", 123456789);
		printf("%14+d||\n", 123456789);
		ft_printf ("ft_printf2:|%#5x||\n", 1);
		printf ("printf2   :|%#5x||\n", 1);
	unsigned short y = 587;
	ft_printf("%hx||\n", y);
	printf("%hx||\n", y);

 ft_printf("%07d||\n", -55);
 printf("%07d||\n", -55);
ft_printf("%010.5d||\n", -216);
printf("%010.5d||\n", -216);
ft_printf("%07d||\n", 55);
printf("%07d||\n", 55);
ft_printf("%010.5d||\n", 216);
printf("%010.5d||\n", 216);
ft_printf("%*i||\n", -14, 94827);
printf("%*i||\n", -14, 94827);
ft_printf("%0*i||\n", -7, -54);
printf("%0*i||\n", -7, -54);*/
	return (0);
}