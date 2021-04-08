//
// Created by Cloyster Veeta on 4/7/21.
//

#include "main.h"

char	*ft_strchrifnepred(const char *string, int symbol)
{
	char *str;
	char sb;

	sb = (char)symbol;
	str = (char*)string;
	while (*str)
	{
		if (*str == sb && *(str - 1) != '\\')
			return (str);
//		if ()
		str++;
	}
	return ((*str == sb) ? str : NULL);
}
