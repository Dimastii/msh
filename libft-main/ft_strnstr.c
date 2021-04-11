/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:27:42 by cveeta            #+#    #+#             */
/*   Updated: 2020/11/04 18:07:55 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char			*biig;
	const char		*litle;

	if (!big && !little)
		return (NULL);
	biig = (char *)big;
	litle = (const char *)little;
	if (!ft_strlen(litle))
		return (char *)big;
	while (*biig && len--)
	{
		if (ft_strlen(litle) <= len + 1)
			if (!(ft_strncmp(biig, litle, ft_strlen(litle))))
				return (biig);
		biig++;
	}
	return (NULL);
}
