/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:05:33 by cveeta            #+#    #+#             */
/*   Updated: 2020/10/28 20:36:06 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *memptr, size_t num)
{
	unsigned char	*ptr;

	ptr = (unsigned char*)memptr;
	while (num)
	{
		*ptr = '\0';
		ptr++;
		num--;
	}
}
