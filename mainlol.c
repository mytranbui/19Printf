#include <stdio.h>

int		istype(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o'
			|| c == 'u' || c == 'x' || c == 'X' || c == 'f' || c == '%');
}

int	str(char *s)
{
int i;

i = 0;
  while (!istype(s[i]) && s[i])
{
printf("{%c}\n", s[i]);
i++;
}
printf("[i=%d]\n",i);
printf("{end=%c}\n", s[i]);
return (i);
}

int	main(void)
{
 str("23jp");
 str("23j");
return (0);
}
