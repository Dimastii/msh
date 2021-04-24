/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:40:42 by cveeta            #+#    #+#             */
/*   Updated: 2020/11/04 18:57:23 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*strr;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = malloc(len + 1)))
		return (NULL);
	strr = str;
	while (*s1)
		*strr++ = *s1++;
	while (*s2)
		*strr++ = *s2++;
	*strr = '\0';
	return (str);
}

char	*ft_strjoins(char const *s1, char const s2)
{
	char	*str;
	char	*strr;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + 1;
	if (!(str = malloc(len + 1)))
		return (NULL);
	strr = str;
	while (*s1)
		*strr++ = *s1++;
	*strr++ = s2;
	*strr = '\0';
	return (str);
}
