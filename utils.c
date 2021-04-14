//
// Created by Cloyster Veeta on 4/7/21.
//

#include "minishell.h"

char	*ft_strchrifnepred(const char *string, int symbol, int flag)
{
	char *str;
	char sb;

	sb = (char)symbol;
	str = (char*)string;
	while (*str)
	{
		if (flag)
		{
			if (*str == sb && *(str - 1) != '\\')
				return (str);
		}
		if (!flag)
		{
			if (*str == sb)
				return (str);
		}
		str++;
	}
	return ((*str == sb) ? str : NULL);
}
