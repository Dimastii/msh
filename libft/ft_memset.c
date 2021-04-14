/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:04:00 by cveeta            #+#    #+#             */
/*   Updated: 2020/11/03 21:19:27 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *memptr, int val, size_t num)
{
	unsigned char	*ptr;
	unsigned char	temp;

	ptr = (unsigned char *)memptr;
	temp = (unsigned char)val;
	while (num--)
	{
		*(unsigned char *)memptr = temp;
		memptr++;
	}
	return (ptr);
}
