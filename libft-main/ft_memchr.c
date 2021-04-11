/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 22:09:37 by cveeta            #+#    #+#             */
/*   Updated: 2020/11/03 21:12:16 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*st;
	unsigned char	ch;

	st = (unsigned char*)s;
	ch = (unsigned char)c;
	while (n--)
	{
		if (*st == ch)
		{
			return (st);
		}
		st++;
	}
	return (NULL);
}
