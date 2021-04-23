//
// Created by Cloyster Veeta on 4/22/21.
//
#include "minishell.h"

int	redir_(char **str, char **tocken, int *redir, int mode)
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

int	double_redir(char **str, char **tocken, int *redir)
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

void 	this_not_quote(char **s, char **tocken, int *redir, char **tmp)
{
	while (**s && **s != '"' && **s != '\'' && **s != ' ' && !isspec(**s))
	{
		if (**s == '\\')
		{
			if (!(*(*s + 1)))
			{
				(*s)++;
				continue ;
			}
			*tocken = ft_freeline(*tocken, ft_strjoins(*tocken, *(*s + 1)));
			(*s) = (*s) + 2;
		}
		else if (**s == '>' && *(*s + 1) == '>')
		{
			if (double_redir(s, tocken, redir))
				break ;
		}
		else if (**s == '>')
		{
			if (redir_(s, tocken, redir, 1))
				break ;
		}
		else if (**s == '<' && redir_(s, tocken, redir, 2))
			break ;
		else if (**s == '$')
			search_glob(s, tocken, *tmp, g_envp);
		else
		{
			*tocken = ft_freeline(*tocken, ft_strjoins(*tocken, **s));
			(*s)++;
		}
	}
}
