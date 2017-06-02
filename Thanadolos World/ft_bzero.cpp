#include "Globals.h"
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char*)s;
	while (n)
	{
		*tmp++ = '\0';
		n--;
	}
}