//
// Created by Cloyster Veeta on 4/22/21.
//
#include "minishell.h"

char	*check_glob(char *glob, char **envp)
{
	int		i;
	char	*value;

	i = 0;
	value = NULL;
	while (envp[i])
	{
		if (!value)
		{
			value = ft_strnstr(envp[i], glob, ft_strlen(glob));
		}
		else
			return (value + ft_strlen(glob) + 1);
		i++;
	}
	return (value);
}

void	search_glob(char **str, char **tocken, char const *tmp, char **envp)
{
	char	*glob;
	char	*value;

	value = NULL;
	(*str)++;
	glob = ft_strdup("");
	while (*str != tmp && **str != ' ' && **str && !isspec(**str))
	{
		glob = ft_freeline(glob, ft_strjoins(glob, **str));
		(*str)++;
	}
	value = check_glob(glob, envp);
	if (value)
	{
		*tocken = ft_freeline(*tocken, ft_strjoin(*tocken, value));
	}
}
