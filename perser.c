//
// Created by Cloyster Veeta on 3/27/21.
//

#include "minishell.h"

int		ft_isspace(int c)
{
    c = (unsigned char)c;
    if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
        || c == ' ')
        return (1);
    return (0);
}

int 	isspec(int c)
{
	c = (unsigned char)c;
	if (c == ';' || c == '|' || c == '\0')
		return (1);
	return (0);
}

char	*check_glob(char *glob, char **envp) {
	int i;
	char *value;
	i = 0;

	value = NULL;
	while (envp[i])
	{
		if (!value) {
			value = ft_strnstr(envp[i], glob, ft_strlen(glob));
		}
		else
			return (value + ft_strlen(glob) + 1);
		i++;
	}
	return value;
}

void	search_glob(char **str, char **tocken, char const *tmp, char **envp)
{
	char *glob;
	char *value;
	char *fre;

	value = NULL;
	(*str)++;
	glob = ft_strdup("");
	while (*str != tmp && **str != ' ' && **str && !isspec(**str))
	{//тут мы ищем переменную в строке
		fre = glob;
		glob = ft_strjoins(glob, **str);//лик
		free(fre);
		fre = NULL;
		(*str)++;
	}//в этом условии будет поиск по глобальным переменным
	if ((value = check_glob(glob, envp)))
	{
		fre = *tocken;
		*tocken = ft_strjoin(*tocken, value);
		free(fre);
		fre = NULL;
	}
}

void	detect_token(char **str, t_cmd *cmd, char **envp)
{
	char *tocken;
	char *tmp;
	char *fre;
	int flag;
	int redir;
	tocken = ft_strdup("");
	while (ft_isspace(**str))
		(*str)++;
	while (**str != ' ' && !(isspec(**str)) && **str)
	{
		if (**str == '"' || **str == '\'')//если кавычка
		{
			if (**str == '"')
				flag = 1;
			else
				flag = 0;
			(*str)++;//находим есть ли вообще такая же закрывающаа скобка
			if ((tmp = ft_strchrifnepred(*str, *(*str - 1), flag)))
			{
				while (*str != tmp)//если есть то пока мы до неё не дойжем то будем джоинить
				{
					if (**str == '\\' && flag)//если экран то мы просто джоиним скипая экран
					{
						if (!(*(*str + 1))) {
							(*str)++;
							continue;
						}
						fre = tocken;
						tocken = ft_strjoins(tocken, *(*str + 1));
						(*str) = (*str) + 2;
						free(fre);
					}
					else if (**str != '$' || !flag) {// обычный случай
						fre = tocken;
						tocken = ft_strjoins(tocken, **str);
						(*str)++;
						free(fre);
					}
					else// необычный случай (если переменная)
					{
						search_glob(str, &tocken, tmp, envp);
					}
				}
				(*str)++;
			}
			else
			{
				if (*tocken)
				{
					fre = tocken;
					tocken = ft_strdup("");
					free(fre);
				}
				printf("Мультилайн \n");
			}
		}
		else // если не кавычка
		{
			while (**str && **str != '"' && **str != '\'' && **str != ' ' && !isspec(**str))
			{//но только в том случае если не наткнёмся на переменную
				if (**str == '\\')//если экран то мы просто джоиним
				{
					if (!(*(*str + 1))) {
						(*str)++;
						continue;
					}
					fre = tocken;
					tocken = ft_strjoins(tocken, *(*str + 1));
					(*str) = (*str) + 2;
					free(fre);
				}//теперь пока это слово мы будем посимвольно джоинить
				else if (**str == '>')
				{
					redir = 1;
					(*str)++;
				}
				else if (**str == '<')
				{
					redir = 2;
					(*str)++;
				}
				else if (**str == '$') {
					search_glob(str, &tocken, tmp, envp);
				}
				else
				{
					fre = tocken;
					tocken = ft_strjoins(tocken, **str);
					free(fre);
					(*str)++;
				}
			}
		}
	}
	int fd_redir;
	if (*tocken) {
		if (redir == 1)
		{
			fd_redir = open(tocken, O_CREAT | O_RDWR | O_APPEND , 0644);
			//меняем фд на выход
		}
		else if (redir == 2)
		{
			fd_redir = open(tocken, O_CREAT | O_RDWR | O_APPEND , 0644);
//			dup(fd_redir, 0);
			//меняем фд на вход
		}
		else
		{
			cmd->tokens = ft_coljoins(cmd->tokens, tocken);///лик
		}
	}
	free(tocken);
}

void		detect_spec(char **str, t_cmd *cmd, char ***envp)
{
	static int fd_out;
	static int fd_arr[100];
	static int i;


    if (**str == '|')
    {
		(*str)++;
		fd_arr[i++] = exec_pepe(str, *cmd, fd_out, envp);
		ft_freecol(cmd->tokens);
		cmd->tokens = NULL;
		init_cnd(cmd);
		while (ft_isspace(**str))
			(*str)++;
    }
    else if (**str == ';')
	{
		(*str)++;
		i = 0;
		while(fd_arr[i] != 0)
		{
			close(fd_arr[i]);
			i++;
		}
		if (cmd->tokens[0])
			stdexec(cmd, envp, fd_out);
		if (fd_out != 0)
			fd_out = 0;
		ft_freecol(cmd->tokens);
		cmd->tokens = NULL;
		init_cnd(cmd);
		while (ft_isspace(**str))
			(*str)++;
	}
    else if (**str == '\0')
	{
		if (cmd->tokens[0])
			stdexec(cmd, envp, fd_out);
		else
		{
			//тет команды
		}
		if (fd_out != 0)
			fd_out = 0;
		ft_freecol(cmd->tokens);
		cmd->tokens = NULL;
		init_cnd(cmd);

		i = 0;
		while(fd_arr[i] != 0)
		{
			wait(0);
			close(fd_arr[i]);
			i++;
		}
	}
}

void		add_cmd(t_cmd *cmds, int mode, void (*cmd) (char *, char **, char ***))
{
	cmds->create = 1;
	cmds->mode = mode;
}

int			detect_cmd(char **str, t_cmd *cmd, char **envp)
{
	while (!isspec(**str))
	{
		detect_token(str, cmd, envp);
	}
	return 1;
}


void	lets_pars(char **str, char ***envp)
{
	t_cmd cmd;

	init_cnd(&cmd);
	while (**str)
	{
		while (ft_isspace(**str))
			str++;
		if (detect_cmd(str, &cmd, *envp))
		{
			detect_spec(str, &cmd, envp);
		}
	}
}