/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 23:08:44 by cveeta            #+#    #+#             */
/*   Updated: 2020/11/04 15:56:21 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		len;
	const char	*sr;

	if (!dst && !src)
		return (0);
	sr = src;
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	while (--dstsize && *sr)
	{
		*(dst++) = *(sr++);
	}
	*dst = '\0';
	return (len);
}
