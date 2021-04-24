#include "libft.h"
#include <stdlib.h>

char	**ft_coljoins(char **s1, char const *s2)
{
	char	**strr;
	size_t	len;

	if (!s2)
		return (NULL);
	len = ft_collen(s1) + 1;
	if (!(strr = malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	len = 0;
	while (s1[len])
	{
		strr[len] = ft_strdup(s1[len]);
		len++;
	}
	strr[len] = ft_strdup(s2);
	strr[len + 1] = NULL;
	ft_freecol(s1);
	return (strr);
}