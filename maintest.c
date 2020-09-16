/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2020/01/20 09:26:22 by mbui              #+#    #+#             */
/*   Updated: 2020/09/15 10:45:46 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libftprintf.h"
#include <stdio.h>

int ft_printf(const char *format, ...);

int main(void)
{
	char			c = 'X';
	char			*s = "bonjour j'ai faim";
	int	i = -2147483648; //kkdi
	//unsigned int	nb = 4294967296; //kkx kko
	unsigned int	nb = 0; //kko kkx
	//unsigned int	nb = 4294967296;
//	unsigned int	nb = 458;
//	int		i = -2147483648;
	//int		i = 2147483648; //kk on that number + & -
//	int		i = 2147483648;
	//int		i =-0;
int		*p = &i;
//	int 	nb = -1564312;

	printf("\n-----CHAR-----\n"); //(-, 0?, width)
	// single flag
/*	ft_printf("%+c||\n", c);
	printf("%+c||\n", c);
	ft_printf("% c||\n", c);
	printf("% c||\n", c);
	ft_printf("%#c||\n", c);
	printf("%#c||\n", c);
	ft_printf("%.5c||\n", c);
	printf("%.5c||\n", c);
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
*/	printf("%0#5+c||\n", c);
	ft_printf("%0#5+c||\n", c);
	printf("%#05c||\n", c);
	ft_printf("%#05c||\n", c);
	printf("%0#05c||\n", c);
	ft_printf("%0#05c||\n", c);
	printf("%0#05c||\n", NULL);
	ft_printf("%0#05c||\n", NULL);
	printf("%c||\n", NULL);
	ft_printf("%c||\n", NULL);

/*	printf("\n-----STRING-----\n"); //(-, 0?, width, pres)
	// single flag
	ft_printf("||%+s||\n", s);
	printf("||%+s||\n", s);
	ft_printf("||%0s||\n", s);
	printf("||%0s||\n", s);
	ft_printf("||% s||\n", s);
	printf("||% s||\n", s);
	ft_printf("||%#s||\n", s);
	printf("||%#s||\n", s);
	ft_printf("||%-s||\n", s);
	printf("||%-s||\n", s);
	ft_printf("||%5s||\n", s);
	printf("||%5s||\n", s);
	ft_printf("||%50s||\n", s);
	printf("||%50s||\n", s);
	ft_printf("||%.5s||\n", s);
	printf("||%.5s||\n", s);
	ft_printf("||%.50s||\n", s);
	printf("||%.50s||\n", s);
	// multiple flags
	ft_printf("||%0+50.50s||\n", s);
	printf("expected result:\n%0+50.50s||\n", s);
	ft_printf("||%0-50.5s||\n", s);
	printf("expected result:\n%0-50.5s||\n", s);
	ft_printf("||%-10s||\n", s);
	printf("expected result:\n%-10s||\n", s);
	ft_printf("||%08.s||\n", s);
	printf("expected result:\n%08.s||\n", s);
	ft_printf("||%8.s||\n", s);
	printf("expected result:\n%8.s||\n", s);
	ft_printf("||%018.s||\n", s);
	printf("expected result:\n%018.s||\n", s);
	ft_printf("||%-08.s||\n", s);
	printf("expected result:\n%-08.s||\n", s);
	ft_printf("||%0-+18.4s||\n",4 s);
	printf("expected result:\n%0-+18.4s||\n", s);
	ft_printf("||%0-+18.60s||\n", s);
	printf("expected result:\n%0-+18.60s||\n", s);
printf("%0#05s||\n", NULL);
ft_printf("%0#05s||\n", NULL);
printf("%s||\n", NULL);
ft_printf("%s||\n", NULL);
*/
/*	printf("\n-----POINTER-----\n"); //(-, width, pres?)
	// single flag
	ft_printf("||%+p||\n", NULL);
	printf("||%+p||\n", NULL);
	ft_printf("||%0p||\n", NULL);
	printf("||%0p||\n", NULL);
	ft_printf("||% p||\n", NULL);
	printf("||% p||\n", NULL);
	ft_printf("||%#p||\n", NULL);
	printf("||%#p||\n", NULL);
	ft_printf("||%-p||\n", NULL);
	printf("||%-p||\n", NULL);
	ft_printf("||%5p||\n", NULL);
	printf("||%5p||\n", NULL);
	ft_printf("||%50p||\n", NULL);
	printf("||%50p||\n", NULL);
	ft_printf("||%.5p||\n", NULL);
	printf("||%.5p||\n", NULL);
	ft_printf("||%.50p||\n", NULL);
	printf("||%.50p||\n", NULL);
	// multiple flags
	ft_printf("||%- 100.50p||\n", NULL);
	printf("||%- 100.50p||\n", NULL);
	ft_printf("||% 100.50p||\n", NULL);
	printf("||% 100.50p||\n", NULL);
	ft_printf("||%-050p||\n", NULL);
	printf("||%-050p||\n", NULL);
	ft_printf("||%0+50.50p||\n", NULL);
	printf("||%0+50.50p||\n", NULL);
	ft_printf("||%0-50.5p||\n", NULL);
	printf("||%0-50.5p||\n", NULL);
	ft_printf("||%-10p||\n", NULL);
	printf("||%-10p||\n", NULL);
	ft_printf("||%08.p||\n", NULL);
	printf("||%08.p||\n", NULL);
	ft_printf("||%8.p||\n", NULL);
	printf("||%8.p||\n", NULL);
	ft_printf("||%018.p||\n", NULL); //0-
	printf("||%018.p||\n", NULL);
	ft_printf("||%-08.p||\n", NULL); //0-
	printf("||%-08.p||\n", NULL);
	ft_printf("||%0-+18.4p||\n", NULL);
	printf("||%0-+18.4p||\n", NULL);
	ft_printf("||%0-+18.60p||\n", NULL);
	printf("||%0-+18.60p||\n", NULL);
	ft_printf("||%33.44p||\n", NULL);
	printf("||%33.44p||\n", NULL);
	ft_printf("||%0-+ 12.2p||\n", NULL);
	printf("||%0-+ 12.2p||\n", NULL);
	ft_printf("||%015.p||\n", NULL); //0-
	printf("||%015.p||\n", NULL);
	ft_printf("||%+- 011p||\n", NULL);
	printf("||%+- 011p||\n", NULL);
	ft_printf("%0#05p||\n", NULL);
	printf("%0#05p||\n", NULL);
	ft_printf("%0#5p||\n", NULL);
	printf("%0#5p||\n", NULL);
	ft_printf("%#05p||\n", NULL);
	printf("%#05p||\n", NULL);
	ft_printf("%p||\n", NULL);
	printf("%p||\n", NULL);
*/
	printf("\n-----SIGNED INT-----\n"); //(+, - , ' ', 0 , width, pres)
	// single flag
	printf("%+i||\n", i);
 	ft_printf("%+i||\n", i);
	printf("%0i||\n", i);
  	ft_printf("%0i||\n", i);
	printf("% i||\n", i);
  	ft_printf("% i||\n", i);
	printf("%#i||\n", i);
	ft_printf("%#i||\n", i);
	printf("%-i||\n", i);
	ft_printf("%-i||\n", i);
	printf("%5i||\n", i);
  	ft_printf("%5i||\n", i);
	printf("%50i||\n", i);
	ft_printf("%50i||\n", i);
	printf("%.5i||\n", i);
 	ft_printf("%.5i||\n", i);
	printf("%.50i||\n", i);
  	ft_printf("%.50i||\n", i);
/*	printf("%hi||\n", i);
 	ft_printf("%hi`||\n", i);
	printf("%hhi||\n", i);
 	ft_printf("%hhi||\n", i);
	printf("%li||\n", i);
 	ft_printf("%li||\n", i);
	printf("%lli||\n", i);
 	ft_printf("%lli||\n", i);
*/	// multiple flags
	printf("%- 100.50i||\n", i);
  	ft_printf("%- 100.50i||\n", i);
	printf("% +100.50i||\n", i);
  	ft_printf("% +100.50i||\n", i);
	printf("%-050i||\n", i);
  	ft_printf("%-050i||\n", i);
	printf("%0+50.50i||\n", i);
  	ft_printf("%0+50.50i||\n", i);
	printf("%0-+050.5i||\n", i);
  	ft_printf("%0-+050.5i||\n", i);
	printf("%0-+050.8i||\n", i);
  	ft_printf("%0-+050.8i||\n", i);
	printf("%-10i||\n", i);
	ft_printf("%-10i||\n", i);
	printf("%08.i||\n", i);
  	ft_printf("%08.i||\n", i); // 0 width8 pres0
	printf("%8.i||\n", i);
 	ft_printf("%8.i||\n", i); // width8 pres0
	printf("%018.i||\n", i);
 	ft_printf("%018.i||\n", i); // 0 width18 pres0
	printf("%-08.i||\n", i);
 	ft_printf("%-08.i||\n", i); // -0 width8 pres0
	printf("%0-+18.60i||\n", i);
	ft_printf("%0-+18.60i||\n", i);
	printf("%0-+ 12.2i||\n", i);
	ft_printf("%0-+ 12.2i||\n", i);
	printf("%015.i||\n", i);
	ft_printf("%015.i||\n", i); //replace 0 by null // 0 width15 pres0
	printf("%+- 011.i||\n", i);
	ft_printf("%+- 011.i||\n", i);

/*	printf("\n-----UNSIGNED OCTAL-----\n"); //(-, 0, #, )
	printf("%+o||\n", nb);
	ft_printf("%+o||\n", nb);
	printf("%0o||\n", nb);
	ft_printf("%0o||\n", nb);
	printf("% o||\n", nb);
	ft_printf("% o||\n", nb);
	printf("%#o||\n", nb);
	ft_printf("%#o||\n", nb);
	printf("%-o||\n", nb);
	ft_printf("%-o||\n", nb);
	printf("%5o||\n", nb);
	ft_printf("%5o||\n", nb);
	printf("%50o||\n", nb);
	ft_printf("%50o||\n", nb);
	printf("%.5o||\n", nb);
	ft_printf("%.5o||\n", nb);
	printf("%.50o||\n", nb);
	ft_printf("%.50o||\n", nb);
	// multiple flags
	printf("%- 100.50o||\n", nb);
  	ft_printf("%- 100.50o||\n", nb);
	printf("% +100.50o||\n", nb);
  	ft_printf("% +100.50o||\n", nb);
	printf("%-050o||\n", nb);
  	ft_printf("%-050o||\n", nb);
	printf("%0+50.50o||\n", nb);
  	ft_printf("%0+50.50o||\n", nb);
	printf("%0-+050.5o||\n", nb);
  	ft_printf("%0-+050.5o||\n", nb);
	printf("%0-+050.8o||\n", nb);
  	ft_printf("%0-+050.8o||\n", nb);
	printf("%-10o||\n", nb);
	ft_printf("%-10o||\n", nb);
	printf("%08.o||\n", nb);
  	ft_printf("%08.o||\n", nb);
	printf("%8.o||\n", nb);
 	ft_printf("%8.o||\n", nb);
	printf("%#018.o||\n", nb);
 	ft_printf("%0#18.o||\n", nb); //0-
	printf("%- 08.o||\n", nb);
 	ft_printf("%- 08.o||\n", nb);
	printf("%0-+18.60o||\n", nb);
	ft_printf("%0-+18.60o||\n", nb);
	printf("%0-+# 12.2o||\n", nb);
	ft_printf("%0-+# 12.2o||\n", nb); //0-
	printf("%015.o||\n", nb);
	ft_printf("%015.o||\n", nb);
	printf("%+- 011o||\n", nb);
	ft_printf("%+- 011o||\n", nb);
	printf("% -018.30o||\n", nb);
	ft_printf("% -018.30o||\n", nb);
	printf("%-050o||\n", nb);
	ft_printf("%-050o||\n", nb);
	printf("%-0# 50o||\n", nb);
	ft_printf("%-0# 50o||\n", nb); //sp-
	printf("%0# 45o||\n", nb);
	ft_printf("%0# 45o||\n", nb); //0-
	printf("%0 18o||\n", nb);
	ft_printf("%0 18o||\n", nb);
	printf("%0# 40.o||\n", nb);
	ft_printf("%0# 40.o||\n", nb); //0-
	printf("%0# 40.60o||\n", nb);
	ft_printf("%0# 40.60o||\n", nb); //0-
*/
/*	printf("\n-----UNSIGNED INT-----\n"); //(-, 0, #, )
	// single flag
	printf("%+u||\n", nb);
	ft_printf("%+u||\n", nb);
	printf("%0u||\n", nb);
	ft_printf("%0u||\n", nb);
	printf("% u||\n", nb);
	ft_printf("% u||\n", nb);
	printf("%#u||\n", nb);
	ft_printf("%#u||\n", nb);
	printf("%-u||\n", nb);
	ft_printf("%-u||\n", nb);
	printf("%5u||\n", nb);
	ft_printf("%5u||\n", nb);
	printf("%50u||\n", nb);
	ft_printf("%50u||\n", nb);
	printf("%.5u||\n", nb);
	ft_printf("%.5u||\n", nb);
	printf("%.50u||\n", nb);
	ft_printf("%.50u||\n", nb);
	// multiple flags
	printf("%- 100.50u||\n", nb);
  	ft_printf("%- 100.50u||\n", nb);
	printf("% +100.50u||\n", nb);
  	ft_printf("% +100.50u||\n", nb);
	printf("%-050u||\n", nb);
  	ft_printf("%-050u||\n", nb);
	printf("%0+50.50u||\n", nb);
  	ft_printf("%0+50.50u||\n", nb);
	printf("%0-+050.5u||\n", nb);
  	ft_printf("%0-+050.5u||\n", nb);
	printf("%0-+050.8u||\n", nb);
  	ft_printf("%0-+050.8u||\n", nb);
	printf("%-10u||\n", nb);
	ft_printf("%-10u||\n", nb);
	printf("%08.u||\n", nb);
  	ft_printf("%08.u||\n", nb);
	printf("%8.u||\n", nb);
 	ft_printf("%8.u||\n", nb);
	printf("%#018.u||\n", nb);
 	ft_printf("%0#18.u||\n", nb);
	printf("%- 08.u||\n", nb);
 	ft_printf("%- 08.u||\n", nb);
	printf("%0-+18.60u||\n", nb);
	ft_printf("%0-+18.60u||\n", nb);
	printf("%0-+# 12.2u||\n", nb);
	ft_printf("%0-+# 12.2u||\n", nb);
	printf("%015.u||\n", nb);
	ft_printf("%015.u||\n", nb);
	printf("%+- 011u||\n", nb);
	ft_printf("%+- 011u||\n", nb);
	printf("% -018.30u||\n", nb);
	ft_printf("% -018.30u||\n", nb);
	printf("%-050u||\n", nb);
	ft_printf("%-050u||\n", nb);
	printf("%-0# 50u||\n", nb);
	ft_printf("%-0# 50u||\n", nb);
	printf("%0# 45u||\n", nb);
	ft_printf("%0# 45u||\n", nb);
	printf("%0 18u||\n", nb);
	ft_printf("%0 18u||\n", nb);
	printf("%0# 40.u||\n", nb);
	ft_printf("%0# 40.u||\n", nb);
	printf("%0# 40.60u||\n", nb);
	ft_printf("%0# 40.60u||\n", nb);
*/
/*	printf("\n-----UNSIGNED HEX-----\n"); //(-, 0, #, )
	// single flag
	printf("%+x||\n", nb);
	ft_printf("%+x||\n", nb);
	printf("%0x||\n", nb);
	ft_printf("%0x||\n", nb);
	printf("% x||\n", nb);
	ft_printf("% x||\n", nb);
	printf("%#x||\n", nb);
	ft_printf("%#x||\n", nb); //ok
	printf("%-x||\n", nb);
	ft_printf("%-x||\n", nb);
	printf("%5x||\n", nb);
	ft_printf("%5x||\n", nb);
	printf("%50x||\n", nb);
	ft_printf("%50x||\n", nb);
	printf("%.5x||\n", nb);
	ft_printf("%.5x||\n", nb);
	printf("%.50x||\n", nb);
	ft_printf("%.50x||\n", nb);
	// multiple flags
	printf("%- 100.50x||\n", nb);
  	ft_printf("%- 100.50x||\n", nb);
	printf("% +100.50x||\n", nb);
  	ft_printf("% +100.50x||\n", nb);
	printf("%-050x||\n", nb);
  	ft_printf("%-050x||\n", nb);
	printf("%0+50.50x||\n", nb);
  	ft_printf("%0+50.50x||\n", nb);
	printf("%0-+050.5x||\n", nb);
  	ft_printf("%0-+050.5x||\n", nb);
	printf("%0-+050.8x||\n", nb);
  	ft_printf("%0-+050.8x||\n", nb);
	printf("%-10x||\n", nb);
	ft_printf("%-10x||\n", nb);
	printf("%08.x||\n", nb);
  	ft_printf("%08.x||\n", nb);
	printf("%8.x||\n", nb);
 	ft_printf("%8.x||\n", nb);
	printf("%#018.x||\n", nb);
 	ft_printf("%0#18.x||\n", nb); //no
	printf("%- 08.x||\n", nb);
 	ft_printf("%- 08.x||\n", nb);
	printf("%0-+18.60x||\n", nb);
	ft_printf("%0-+18.60x||\n", nb);
	printf("%0-+# 12.2x||\n", nb);
	ft_printf("%0-+# 12.2x||\n", nb); //no
	printf("%015.x||\n", nb);
	ft_printf("%015.x||\n", nb);
	printf("%+- 011x||\n", nb);
	ft_printf("%+- 011x||\n", nb);
	printf("% -018.30x||\n", nb);
	ft_printf("% -018.30x||\n", nb);
	printf("%-050x||\n", nb);
	ft_printf("%-050x||\n", nb);
	printf("%-0# 50X||\n", nb);
	ft_printf("%-0# 50X||\n", nb); //no
	printf("%0# 45X||\n", nb);
	ft_printf("%0# 45X||\n", nb);
	printf("%0 18X||\n", nb);
	ft_printf("%0 18X||\n", nb);
	printf("%0# 40.X||\n", nb);
	ft_printf("%0# 40.X||\n", nb); //no
	printf("%0# 40.60X||\n", nb);
	ft_printf("%0# 40.60X||\n", nb); //ok
	printf("%0# 45.40X||\n", nb);
	ft_printf("%0# 45.40X||\n", nb); //no width > pres
	printf("%0# 30.30X||\n", nb);
	ft_printf("%0# 30.30X||\n", nb); //ok
*/
	printf("\n-----PERCENTS-----\n"); //(-,0,width) xpres x# x' '?
	// single flag
/*	printf("%+%||\n");
	ft_printf("%+%||\n");
	printf("%0%||\n");
	ft_printf("%0%||\n");
	printf("% %||\n");
	ft_printf("% %||\n");
	printf("%#%||\n");
	ft_printf("%#%||\n"); //ok
	printf("%-%||\n");
	ft_printf("%-%||\n");
*/	printf("%#0 5%||\n");
	ft_printf("%#0 5%||\n");
/*	printf("%.5%||\n");
	ft_printf("%.5%||\n");
	// multiple flags
	printf("%- 100.50%||\n");
	ft_printf("%- 100.50%||\n");
	printf("% +100.50%||\n");
	ft_printf("% +100.50%||\n");
	printf("%-050%||\n");
	ft_printf("%-050%||\n");
	printf("%0+50.50%||\n");
	ft_printf("%0+50.50%||\n");
	printf("%0-+050.5%||\n");
	ft_printf("%0-+050.5%||\n");
	printf("%0-+050.8%||\n");
	ft_printf("%0-+050.8%||\n");
	printf("%-10%||\n");
	ft_printf("%-10%||\n");
	printf("%08.%||\n");
	ft_printf("%08.%||\n");
	printf("%8.%||\n");
	ft_printf("%8.%||\n");
	printf("%#018.%||\n");
	ft_printf("%0#18.%||\n"); //no
	printf("%- 08.%||\n");
	ft_printf("%- 08.%||\n");
	printf("%0-+18.60%||\n");
	ft_printf("%0-+18.60%||\n");
	printf("%0-+# 12.2%||\n");
	ft_printf("%0-+# 12.2%||\n"); //no
	printf("%015.%||\n");
	ft_printf("%015.%||\n");
	printf("%+- 011%||\n");
	ft_printf("%+- 011%||\n");
	printf("% -018.30%||\n");
	ft_printf("% -018.30%||\n");
	printf("%-050%||\n");
	ft_printf("%-050%||\n");
	printf("%-0# 50%||\n");
	ft_printf("%-0# 50%||\n"); //no
	printf("%0# 45%||\n");
	ft_printf("%0# 45%||\n");
	printf("%0 18%||\n");
	ft_printf("%0 18%||\n");
	printf("%0# 40.%||\n");
	ft_printf("%0# 40.%||\n"); //no
	printf("%0# 40.60%||\n");
	ft_printf("%0# 40.60%||\n"); //ok
	printf("%0# 45.40%||\n");
	ft_printf("%0# 45.40%||\n"); //no width > pres
	printf("%0# 30.30%||\n");
	ft_printf("%0# 30.30%||\n"); //ok*/
/*	ft_printf("caca%0dpopo%+d", 45, 89);
	 ft_printf("\n--string=%s\n--sign=%%\n--num=%d\n--num2=%d\n--sign2=%%\n--sign3=%%\n--numi=%i\n--char=%c\n--num3=%d\n--address=%p\n--hex=%x\n--HEX=%X\n",s,100,-7852,23534, 'c', 45, &c,4364873,61534);
	 printf("SOLUTION:\n--string=%s--sign=%%--num=%d--num2=%d--sign2=%%--sign3=%%--numi=%i--char=%c--num3=%d--address=%p--hex=%x--HEX=%X\n",s,100,-7852,23534, 'c', 45, &c,4364873,61534);
	 printf("uint=%ld\n",4294967295);
	ft_printf("\n%+0dpopodpo%-d\n", 78,-50);
		printf("\n%+0dpopodpo%-d\n", 78,-50);
	ft_printf("\n%-25p||\n", p);
	printf("\n%-25p||\n", p);
		ft_printf("%14+d||\n", 123456789);
		printf("%14+d||\n", 123456789);
*/	return (0);
}
