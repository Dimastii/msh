/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cveeta <cveeta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 22:52:36 by cveeta            #+#    #+#             */
/*   Updated: 2020/11/03 21:37:55 by cveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../main.h"

size_t		ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void		ft_printcol(char **s)
{
	size_t	len;

	len = 0;
	if (!s) {
		printf("%s\n", "NULL");
		return;
	}
	while (s[len]) {
		printf("%s\n", s[len]);
		len++;
	}
}

size_t		ft_collen(char **s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len]) {
		len++;
	}
	return (len);
}
