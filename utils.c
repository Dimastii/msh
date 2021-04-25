//
// Created by Cloyster Veeta on 4/7/21.
//

#include "minishell.h"

char	*ft_freeline(char *fre, char *str)
{
	if (!fre)
	{
		printf("freeline error\n");
		exit(0);
	}
	free(fre);
	fre = NULL;
	return (str);
}

int	ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

int	isspec(int c)
{
	c = (unsigned char)c;
	if (c == ';' || c == '|' || c == '\0')
		return (1);
	return (0);
}

char	*ft_strchrifnepred(const char *string, int symbol, int flag)
{
	char	*str;
	char	sb;

	sb = (char)symbol;
	str = (char *)string;
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
	if (*str == sb)
		return (str);
	else
		return (NULL);
}

char	**ret_glob(char *arg)
{
	int	i;

	i = 0;
	while (g_envp[i])
	{
		if (ft_strnstr(g_envp[i], arg, ft_strlen(g_envp[i])))
			return (&g_envp[i]);
		++i;
	}
	return (NULL);
}
