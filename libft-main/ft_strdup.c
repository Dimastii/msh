/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:38:20 by cveeta            #+#    #+#             */
/*   Updated: 2020/11/03 21:31:21 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*strret;

	if (!(str = malloc(ft_strlen(s) + 1)))
		return (NULL);
	strret = str;
	while (*s)
		*str++ = *s++;
	*str = '\0';
	return (strret);
}
