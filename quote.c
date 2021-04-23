//
// Created by Cloyster Veeta on 4/22/21.
//
#include "minishell.h"

void 	find_close(char **str, char **tocken, char **tmp, int flag)
{
	while (*str != *tmp)//если есть то пока мы до неё не дойжем то будем джоинить
	{
		if (**str == '\\' && flag)//если экран то мы просто джоиним скипая экран
		{
			if (!(*(*str + 1))) {
				(*str)++;
				continue;
			}
			*tocken = ft_freeline(*tocken, ft_strjoins(*tocken, *(*str + 1)));
			(*str) = (*str) + 2;
		}
		else if (**str != '$' || !flag) {// обычный случай
			*tocken = ft_freeline(*tocken, ft_strjoins(*tocken, **str));
			(*str)++;
		}
		else// необычный случай (если переменная)
		{
			search_glob(str, tocken, *tmp, g_envp);
		}
	}
	(*str)++;
}

void 	this_quote(char **str, char **tocken, char **tmp)
{
	int flag;
	char *fre;

	if (**str == '"')
		flag = 1;
	else
		flag = 0;
	(*str)++;//находим есть ли вообще такая же закрывающаа скобка
	if ((*tmp = ft_strchrifnepred(*str, *(*str - 1), flag)))
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