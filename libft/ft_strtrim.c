/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:53:54 by cveeta            #+#    #+#             */
/*   Updated: 2020/11/05 19:07:58 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static const char		*seek_first(char const *s1, char const *set)
{
	const char		*first;

	first = s1;
	while (ft_strchr(set, *s1) && *s1++)
		first = s1;
	return (first);
}

static const char		*seek_last(char const *s1, char const *set)
{
	const char		*last;
	const char		*chel_ti;

	chel_ti = s1;
	last = s1 + ft_strlen(s1);
	s1 = last - 1;
	while (ft_strchr(set, *s1) && *s1-- && chel_ti != s1)
		last = s1;
	return (last);
}

char					*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	char			*strret;
	const char		*first;
	const char		*last;

	if (!s1)
		return (NULL);
	if (ft_strlen(set) == 0)
		return ((char*)s1);
	first = seek_first(s1, set);
	last = seek_last(s1, set);
	if (first > last)
		return (ft_strdup(""));
	if (!(str = malloc(last - first + 2)))
		return (NULL);
	strret = str;
	while (first <= last)
		*str++ = *first++;
	*str = '\0';
	return (strret);
}
