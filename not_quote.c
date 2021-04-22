//
// Created by Cloyster Veeta on 4/22/21.
//
#include "minishell.h"

void 	this_not_quote(char **str, char **tocken, int *redir, char **tmp)
{
	char *fre;
	while (**str && **str != '"' && **str != '\'' && **str != ' ' && !isspec(**str))
	{//но только в том случае если не наткнёмся на переменную
		if (**str == '\\')//если экран то мы просто джоиним
		{
			if (!(*(*str + 1))) {
				(*str)++;
				continue;
			}
			fre = *tocken;
			*tocken = ft_strjoins(*tocken, *(*str + 1));
			(*str) = (*str) + 2;
			free(fre);
		}//теперь пока это слово мы будем посимвольно джоинить
		else if (**str == '>' && *(*str + 1) == '>')
		{
			if (!(**tocken)) {
				**str = ' ';
				*(*str + 1) = ' ';
				while (ft_isspace(**str))
					(*str)++;
				*redir = 3;
				break;
			} else
			{
				--(*str);
				**str = ' ';
			}
		}
		else if (**str == '>')
		{
			if (!(**tocken)) {
				**str = ' ';
				while (ft_isspace(**str))
					(*str)++;
				*redir = 1;
				break;
			} else
			{
				--(*str);
				**str = ' ';
			}
		}
		else if (**str == '<')
		{
			if (!(**tocken)) {
				**str = ' ';
				while (ft_isspace(**str))
					(*str)++;
				*redir = 2;
				break;
			} else
			{
				--(*str);
				**str = ' ';
			}
		}
		else if (**str == '$') {
			search_glob(str, tocken, *tmp, g_envp);
		}
		else
		{
			fre = *tocken;
			*tocken = ft_strjoins(*tocken, **str);
			free(fre);
			(*str)++;
		}
	}
}