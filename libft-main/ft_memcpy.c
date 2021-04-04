/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:03:38 by cveeta            #+#    #+#             */
/*   Updated: 2020/11/04 15:12:11 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t num)
{
	unsigned long	*dst1;
	unsigned long	*src1;
	unsigned char	*d;
	unsigned char	*s;

	if (!src && !dst)
		return (NULL);
	dst1 = dst;
	src1 = (unsigned long*)src;
	while (num / sizeof(long) >= 1)
	{
		*(dst1++) = *(src1++);
		num = num - sizeof(long);
	}
	d = (unsigned char*)dst1;
	s = (unsigned char*)src1;
	while (num)
	{
		*d = *s;
		d++;
		s++;
		num--;
	}
	return (dst);
}
