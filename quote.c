//
// Created by Cloyster Veeta on 4/22/21.
//
#include "minishell.h"

void	find_close(char **str, char **tocken, char **tmp, int flag)
{
	while (*str != *tmp)
	{
		if (**str == '\\' && flag)
		{
			if (!(*(*str + 1)))
			{
				(*str)++;
				continue ;
			}
			*tocken = ft_freeline(*tocken, ft_strjoins(*tocken, *(*str + 1)));
			(*str) = (*str) + 2;
		}
		else if (**str != '$' || !flag)
		{
			*tocken = ft_freeline(*tocken, ft_strjoins(*tocken, **str));
			(*str)++;
		}
		else
		{
			search_glob(str, tocken, *tmp, g_envp);
		}
	}
	(*str)++;
}

void	this_quote(char **str, char **tocken, char **tmp)
{
	int		flag;
	char	*fre;

	if (**str == '"')
		flag = 1;
	else
		flag = 0;
	(*str)++;
	*tmp = ft_strchrifnepred(*str, *(*str - 1), flag);
	if (*tmp)
	{
		find_close(str, tocken, tmp, flag);
	}
	else
	{
		if (*tocken)
		{
			fre = *tocken;
			*tocken = ft_strdup("");
			free(fre);
		}
		printf("Мультилайн \n");
	}
}
