#include "libft.h"
#include <stdio.h>

int	*ft_intdup(const int *src, size_t len)
{
	int	*dst;

	if (!(dst = (int*)malloc(len * sizeof(int))))
	return (NULL);
	ft_memcpy(dst, src, len * sizeof(int));
	return(dst);
}

int main()
{
int s;
int b;

b = 65;
s = 78;

b = *ft_intdup(&s, 2);
printf("%d", b);
return (0);
}
