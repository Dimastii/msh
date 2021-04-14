/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:33:54 by cveeta            #+#    #+#             */
/*   Updated: 2020/10/29 14:59:43 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int symbol)
{
	char *str;
	char sb;

	sb = (char)symbol;
	str = (char*)string;
	while (*str)
	{
		if (*str == sb)
			return (str);
		str++;
	}
	return ((*str == sb) ? str : NULL);
}
