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

int 	baffle(char **s, char **tokn)
{
	if (!(*(*s + 1)))
	{
		(*s)++;
		return (1);
	}
	*tokn = ft_freeline(*tokn, ft_strjoins(*tokn, *(*s + 1)));
	(*s) = (*s) + 2;
	return (0);
}

void 	this_not_quote(char **s, char **tokn, int *redir, char **tmp)
{
	while (**s && **s != '"' && **s != '\'' && **s != ' ' && !isspec(**s))
	{
		if (**s == '\\' && baffle(s, tokn))
		{
//			if (!(*(*s + 1)))
//			{
//				(*s)++;
//				continue ;
//			}
//			*tokn = ft_freeline(*tokn, ft_strjoins(*tokn, *(*s + 1)));
//			(*s) = (*s) + 2;
			continue ;
		}
		else if (**s == '>' && *(*s + 1) == '>' && double_redir(s, tokn, redir))
			break ;
		else if (**s == '>' && redir_(s, tokn, redir, 1))
			break ;
		else if (**s == '<' && redir_(s, tokn, redir, 2))
			break ;
		else if (**s == '$')
			search_glob(s, tokn, *tmp, g_envp);
		else
		{
			*tokn = ft_freeline(*tokn, ft_strjoins(*tokn, **s));
			(*s)++;
		}
	}
}
