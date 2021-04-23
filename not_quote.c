//
// Created by Cloyster Veeta on 4/22/21.
//
#include "minishell.h"

int 	redir_(char **str, char **tocken, int *redir, int mode)
{
	if (!(**tocken))
	{
		**str = ' ';
		while (ft_isspace(**str))
			(*str)++;
		*redir = mode;
		return (1);
	}
	else
	{
		--(*str);
		**str = ' ';
	}
	return (0);
}

int		double_redir(char **str, char **tocken, int *redir)
{
	if (!(**tocken))
	{
		**str = ' ';
		*(*str + 1) = ' ';
		while (ft_isspace(**str))
			(*str)++;
		*redir = 3;
		return (1);
	}
	else
	{
		--(*str);
		**str = ' ';
	}
	return (0);
}

void 	this_not_quote(char **str, char **tocken, int *redir, char **tmp)
{
	while (**str && **str != '"' && **str != '\'' && **str != ' ' && !isspec(**str))
	{
		if (**str == '\\')
		{
			if (!(*(*str + 1)))
			{
				(*str)++;
				continue;
			}
			*tocken = ft_freeline(*tocken,ft_strjoins(*tocken, *(*str + 1)));
			(*str) = (*str) + 2;
		}
		else if (**str == '>' && *(*str + 1) == '>')
		{
			if (double_redir(str, tocken, redir))
				break;
		}
		else if (**str == '>')
		{
			if (redir_(str, tocken, redir, 1))
				break;
		}
		else if (**str == '<')
		{
			if (redir_(str, tocken, redir, 2))
				break;
		}
		else if (**str == '$')
		{
			search_glob(str, tocken, *tmp, g_envp);
		}
		else
		{
			*tocken = ft_freeline(*tocken,ft_strjoins(*tocken, **str));
			(*str)++;
		}
	}
}