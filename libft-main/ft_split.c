/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 19:01:22 by cveeta            #+#    #+#             */
/*   Updated: 2020/11/05 19:01:52 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

static void			free_tabs(char **words, size_t i)
{
	while (i--)
		if (&(words[i]) && *&(words[i]))
		{
			free(*&(words[i]));
			*&(words[i]) = NULL;
		}
	free(words);
}

static int			lines(char const *s, char c)
{
	int	i;
	int	j;

	j = 0;
	i = -1;
	while (s[++i])
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			j++;
	return (j);
}

static int			tabs(char **ar, char *t, char c)
{
	int		i;
	int		j;

	j = 0;
	while (*t)
	{
		i = 0;
		while (*(t + i) != c && *(t + i))
			++i;
		if (i > 0)
		{
			if (!(ar[j++] = ft_substr(t, 0, i)))
			{
				free_tabs(ar, j);
				return (0);
			}
			t = t + i - 1;
		}
		t++;
	}
	return (0);
}

char				**ft_split(char const *s, char c)
{
	char	**ar;
	char	*t;
	int		j;

	if (!s)
		return (NULL);
	j = lines(s, c);
	t = (char *)s;
	ar = (char**)malloc((j + 1) * sizeof(char*));
	if (!ar)
		return (NULL);
	ar[j] = NULL;
	tabs(ar, t, c);
	return (ar);
}
