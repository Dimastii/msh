//
// Created by Cloyster Veeta on 4/23/21.
//
#include "minishell.h"

char	*brute_force(char **str, char *cmd)
{
	char		*path;
	char		*fre_str;
	struct stat	buff;
	char		*fre;

	path = NULL;
	fre_str = *str;
	path = *str;
	*str = ft_strchr(*str, ':');
	while (*str)
	{
		**str = '\0';
		(*str)++;
		path = ft_strjoins(path, '/');
		path = ft_freeline(path, ft_strjoin(path, cmd));
		if (lstat(path, &buff) == 0 && buff.st_mode & S_IFREG)
		{
			free(fre_str);
			return (path);
		}
		path = ft_freeline(path, *str);
		*str = ft_strchr(*str, ':');
	}
	free(fre_str);
	return (NULL);
}

char	*findbin(char *cmd)
{
	char		*str;
	char		*ret;
	struct stat	buff;

	if (lstat(cmd, &buff) == 0 &&  buff.st_mode & S_IFREG)
	{
		return (cmd);
	}
	str = ft_strdup(check_glob("PATH"));
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
	return (NULL);
}
