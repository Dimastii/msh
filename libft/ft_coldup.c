#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	**ft_coldup(char **c)
{
	char	**col;
	int		i;

	i = 0;
	col = malloc(sizeof(char *) * ft_collen(c) + 1);
	if (!col)
		return (NULL);
	while (c[i])
	{
		col[i] = ft_strdup(c[i]);
		i++;
	}
	col[i] = NULL;
	return (col);
}
