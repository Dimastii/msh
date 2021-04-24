//
// Created by Cloyster Veeta on 4/4/21.
//

#include "libft.h"

void ft_freestr(char *str)
{
	free(str);
}

void ft_freecol(char **col)
{
	size_t	len;

	len = ft_collen(col);
	while (len) {
		len--;
		ft_freestr(col[len]);
	}
	free(col);
}