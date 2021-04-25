#include "libft.h"

void	ft_freestr(char *str)
{
	free(str);
}

void	ft_freecol(char **col)
{
	size_t	len;

	len = 0;
	while (col[len])
	{
		ft_freestr(col[len]);
		len++;
	}
	free(col);
}
