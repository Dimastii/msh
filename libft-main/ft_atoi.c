/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:57:07 by cveeta            #+#    #+#             */
/*   Updated: 2020/11/03 20:54:11 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	unsigned char	*c;
	int				sign;
	int				dig;

	dig = 0;
	sign = 1;
	c = (unsigned char*)str;
	while (*c == ' ' || *c == '\t' || *c == '\n' || *c == '\v' || *c == '\f'
	|| *c == '\r')
		c++;
	if ((*c == '-') || (*c == '+'))
	{
		if (*c == '-')
			sign *= -1;
		c++;
	}
	while (ft_isdigit(*c))
	{
		dig = dig * 10 + *c - '0';
		c++;
	}
	return (dig * sign);
}
