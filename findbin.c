//
// Created by Cloyster Veeta on 4/23/21.
//
#include "minishell.h"

char	*brute_force(char **str, char *cmd)
{
	char *path;
	char *fre_str;
	struct stat buff;
	char *fre;

	path = NULL;
	fre_str = *str;
	path = *str;
	while ((*str = ft_strchr(*str, ':')))
	{
		**str = '\0';
		(*str)++;
		path = ft_strjoins(path, '/');
		path = ft_freeline(path, ft_strjoin(path, cmd));
		if (stat(path, &buff) == 0)
		{
			free(fre_str);
			return (path);
		}
		fre = path;
		path = *str;
		free(fre);
	}
	free(fre_str);
	return (NULL);
}

char	*findbin(char *cmd, char **envp)
{
	char *str;
	char *ret;
	struct stat buff;

	if (stat(cmd, &buff) == 0)
	{
		return (cmd);
	}
	str = ft_strdup(check_glob("PATH", envp));
	if (str)
	{
		ret = brute_force(&str, cmd);
		if (ret)
			return (ret);
	}
	else
	{
		printf(" А где PATH то?\n");
	}
	return NULL;
}
