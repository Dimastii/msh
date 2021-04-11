//
// Created by Cloyster Veeta on 4/5/21.
//

#include "libft.h"

size_t ft_count_c(char *token, char c)
{
	int i;
	size_t count;

	i = 0;
	count = 0;
	while (i < ft_strlen(token))
	{
		if (token[i] == c)
		{
			count++;
		}
		i++;
	}
	return (count);
}

char *ft_isolating(char *token, char c)
{
	int i;
	char *strr;
	char *str;

	i = 0;
	strr = malloc(sizeof(char *) * (ft_strlen(token) - ft_count_c(token, c)));
	str = strr;
	while (i < ft_strlen(token))
	{
		if (token[i] != c)
			*str++ = token[i];
		i++;
	}
	return (strr);
}
