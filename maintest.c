/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2020/01/20 09:26:22 by mbui              #+#    #+#             */
/*   Updated: 2020/09/13 14:42:20 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libftprintf.h"
#include <stdio.h>

int ft_printf(const char *format, ...);

int main(void)
{
	char	c = 'X';
	char	*s = "bonjour j'ai faim";
	int		i = 4252;
	int		*p = &i;
	int 	nb = -1564312;

	// Char (-, 0?, width)
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
	printf("expected result:\n%-10c||\n", c);
	ft_printf("%08.c||\n", c);
	printf("expected result:\n%08.c||\n", c);
	ft_printf("%0-18.4c||\n", c);
	printf("expected result:\n%0-18.4c||\n", c);
	ft_printf("%0-+18.60c||\n", c);
	printf("expected result:\n%0-+18.60c||\n", c);
*/
	// String (-, 0?, width, pres)
	// single flag
/*	ft_printf("%+s||\n", s);
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
	printf("expected result:\n%0+50.50s||\n", s);
	ft_printf("%0-50.5s||\n", s);
	printf("expected result:\n%0-50.5s||\n", s);
	ft_printf("%-10s||\n", s);
	printf("expected result:\n%-10s||\n", s);
	ft_printf("%08.s||\n", s);
	printf("expected result:\n%08.s||\n", s);
	ft_printf("%8.s||\n", s);
	printf("expected result:\n%8.s||\n", s);
	ft_printf("%018.s||\n", s);
	printf("expected result:\n%018.s||\n", s);
	ft_printf("%-08.s||\n", s);
	printf("expected result:\n%-08.s||\n", s);
	ft_printf("%0-+18.4s||\n", s);
	printf("expected result:\n%0-+18.4s||\n", s);
	ft_printf("%0-+18.60s||\n", s);
	printf("expected result:\n%0-+18.60s||\n", s);
*/
	// Pointer(-, width, pres?)
	// single flag
/*	ft_printf("%+p||\n", p);
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
	printf("expected result:\n%- 100.50p||\n", p);
	ft_printf("% 100.50p||\n", p);
	printf("expected result:\n% 100.50p||\n", p);
	ft_printf("%-050p||\n", p);
	printf("expected result:\n%-050p||\n", p);
	ft_printf("%0+50.50p||\n", p);
	printf("expected result:\n%0+50.50p||\n", p);
	ft_printf("%0-50.5p||\n", p);
	printf("expected result:\n%0-50.5p||\n", p);
	ft_printf("%-10p||\n", p);
	printf("expected result:\n%-10p||\n", p);
	ft_printf("%08.p||\n", p);
	printf("expected result:\n%08.p||\n", p);
	ft_printf("%8.p||\n", p);
	printf("expected result:\n%8.p||\n", p);
	ft_printf("%018.p||\n", p);
	printf("expected result:\n%018.p||\n", p);
	ft_printf("%-08.p||\n", p);
	printf("expected result:\n%-08.p||\n", p);
	ft_printf("%0-+18.4p||\n", p);
	printf("expected result:\n%0-+18.4p||\n", p);
	ft_printf("%0-+18.60p||\n", p);
	printf("expected result:\n%0-+18.60p||\n", p);
	ft_printf("%33.44p||\n", p);
	printf("expected result:\n%33.44p||\n", p);
	ft_printf("%0-+ 12.2p||\n", p);
	printf("expected result:\n%0-+ 12.2p||\n", p);
	ft_printf("%015.p||\n", p);
	printf("expected result:\n%015.p||\n", p);
	ft_printf("%+- 011p||\n", p);
	printf("expected result:\n%+- 011p||\n", p);
*/
	// Signed Decimal Integer (+, - , ' ', 0 , width, pres)
	// single flag
/*	ft_printf("%+i||\n", i);
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
	ft_printf("%- 100.50i||\n", i);
  	printf("expected result:\n%- 100.50i||\n", i);
	ft_printf("% +100.50i||\n", i);
  	printf("expected result:\n% +100.50i||\n", i);
	ft_printf("%-050i||\n", i);
  	printf("expected result:\n%-050i||\n", i);
	ft_printf("%0+50.50i||\n", i);
  	printf("expected result:\n%0+50.50i||\n", i);
	ft_printf("%0-+050.5i||\n", i);
  	printf("expected result:\n%0-+050.5i||\n", i);
	ft_printf("%0-+050.8i||\n", i);
  	printf("expected result:\n%0-+050.8i||\n", i);
	ft_printf("%-10i||\n", i);
	printf("expected result:\n%-10i||\n", i);
	ft_printf("%08.i||\n", i);
  	printf("expected result:\n%08.i||\n", i);
	ft_printf("%8.i||\n", i);
 	printf("expected result:\n%8.i||\n", i);
	ft_printf("%018.i||\n", i);
 	printf("expected result:\n%018.i||\n", i);
	ft_printf("%-08.i||\n", i);
 	printf("expected result:\n%-08.i||\n", i);
	ft_printf("%0-+18.60i||\n", i);
	printf("expected result:\n%0-+18.60i||\n", i);
	ft_printf("%0-+ 12.2i||\n", i);
	printf("expected result:\n%0-+ 12.2i||\n", i);
	ft_printf("%015.i||\n", i);
	printf("expected result:\n%015.i||\n", i);
	ft_printf("%+- 011i||\n", i);
	printf("expected result:\n%+- 011i||\n", i);
*/
	// Unsigned hexadecimal(-, 0, #, )
	// single flag
	ft_printf("%+x||\n", nb);
	printf("%+x||\n", nb);
	ft_printf("%0x||\n", nb);
	printf("%0x||\n", nb);
	ft_printf("% x||\n", nb);
	printf("% x||\n", nb);
	ft_printf("%#x||\n", nb);
	printf("%#x||\n", nb);
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
  	printf("expected result:\n%- 100.50x||\n", nb);
	ft_printf("% +100.50x||\n", nb);
  	printf("expected result:\n% +100.50x||\n", nb);
	ft_printf("%-050x||\n", nb);
  	printf("expected result:\n%-050x||\n", nb);
	ft_printf("%0+50.50x||\n", nb);
  	printf("expected result:\n%0+50.50x||\n", nb);
	ft_printf("%0-+050.5x||\n", nb);
  	printf("expected result:\n%0-+050.5x||\n", nb);
	ft_printf("%0-+050.8x||\n", nb);
  	printf("expected result:\n%0-+050.8x||\n", nb);
	ft_printf("%-10x||\n", nb);
	printf("expected result:\n%-10x||\n", nb);
	ft_printf("%08.x||\n", nb);
  	printf("expected result:\n%08.x||\n", nb);
	ft_printf("%8.x||\n", nb);
 	printf("expected result:\n%8.x||\n", nb);
	ft_printf("%#018.x||\n", nb);
 	printf("expected result:\n%0#18.x||\n", nb);
	ft_printf("%- 08.x||\n", nb);
 	printf("expected result:\n%- 08.x||\n", nb);
	ft_printf("%0-+18.60x||\n", nb);
	printf("expected result:\n%0-+18.60x||\n", nb);
	ft_printf("%0-+# 12.2x||\n", nb);
	printf("expected result:\n%0-+# 12.2x||\n", nb);
	ft_printf("%015.x||\n", nb);
	printf("expected result:\n%015.x||\n", nb);//0->sp
	ft_printf("%+- 011x||\n", nb);
	printf("expected result:\n%+- 011x||\n", nb);
	ft_printf("% -018.30x||\n", nb);
	printf("expected result:\n% -018.30x||\n", nb);
	ft_printf("%-050x||\n", nb);
	printf("expected result:\n%-050x||\n", nb);
	ft_printf("%-0# 50X||\n", nb);
	printf("expected result:\n%-0# 50X||\n", nb);
	ft_printf("%0# 45X||\n", nb);
	printf("expected result:\n%0# 45X||\n", nb);//kk
	ft_printf("%0 18X||\n", nb);
	printf("expected result:\n%0 18X||\n", nb);//kk
	ft_printf("%0# 40.X||\n", nb);
	printf("expected result:\n%0# 40.X||\n", nb);//0->sp
	ft_printf("%0# 40.60X||\n", nb);
	printf("expected result:\n%0# 40.60X||\n", nb);

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
