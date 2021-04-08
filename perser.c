//
// Created by Cloyster Veeta on 3/27/21.
//

#include "main.h"

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
	if (c == ';' || c == '|' || c == '>' || c == '<' || c == '\0')
		return (1);
	return (0);
}

void			check_tocken(char **token)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if ((*token)[0] == '"' && (*token)[ft_strlen(*token) - 1] == '"')
	{
		count = ft_count_c(*token, '"');
		if (count % 2 == 0) {
			*token = ft_isolating(*token, '"');///тут лик
//			free(*token);
		}
	}
}

void  detect_token(char **str, t_cmd *cmd)
{
	char *tocken;
	char *tmp;
	char *fre;
	tocken = ft_strdup("");
	while (ft_isspace(**str))
		(*str)++;
	while (**str != ' ' && !(isspec(**str)) && **str)
	{
		if (**str == '"' || **str == '\'')
		{

			(*str)++;
			if ((tmp = ft_strchrifnepred(*str, *(*str - 1))))
			{
				fre = tocken;
				tocken = ft_strjoin(tocken, ft_substr(*str, 0, tmp - *str));
				*str = tmp + 1;
				free(fre);
			}
			else
			{
				if (*tocken)
				{
					fre = tocken;
					tocken = ft_strdup("");
					free(fre);
				}
				printf("ERROR\n");
			}
		}
		else
		{
			if (**str == '\\')
			{
				fre = tocken;
				tocken = ft_strjoins(tocken, *(*str + 1));
				(*str) = (*str) + 2;
				free(fre);
			}
			while (**str != '"' && **str != '\'' && **str != ' ' && **str && !isspec(**str))
			{
				if (**str != '$') {
					fre = tocken;
					tocken = ft_strjoins(tocken, **str);
					free(fre);
					(*str)++;
				}
				else
				{
					char *glob;
					(*str)++;
					glob = ft_strdup("");
					while (**str != '"' && **str != '\'' && **str != ' ' && **str && !isspec(**str))
					{
						glob = ft_strjoins(glob, **str);//лик
						(*str)++;
					}
//					printf("HEHE %d\n", ft_strncmp(glob, "USER", 4));
					if (/*check_glob(glob)==1*/ft_strncmp(glob, "USER", 10) == 0)
					{
						tocken = ft_strjoin(tocken, "cveeta");//лик
					}
					/* функция которая принимает строку и проверяет все символы
					 * от $ до (**str != '"' && **str != '\'' && **str != ' ' && **str && !isspec(**str))
					 * и если находит такую переменную окружения то
					 * джоинит значение переменной к токену и передвигает указатель на конец имени
					 * найденной переменной
					 * иначе (если не находит такую переменную окружения)
					 * то
					 * передвигает указатель не джоиня токен
					 * */
				}
			}
			///пока str не ковычка или не пробел мы tok concat;
		}
	}
	if (tocken[0] != '\0')
		cmd->tokens = ft_coljoins(cmd->tokens, tocken);///лик
	else
		free(tocken);
}

void  detect_token1(char **str, t_cmd *cmd)
{
	char *token;

	while (ft_isspace(**str) && **str != ';')
		(*str)++;
	token = ft_strdup("");
	while (**str != ';' && !(ft_isspace(**str)) && **str)//добавить проверку и на другие спецсимволы
	{
		token = ft_strjoins(token,**str);
		(*str)++;
	}
	if (*token)
	{
		check_tocken(&token);
//		exit(0);
		cmd->tokens = ft_coljoins(cmd->tokens, token);
	}
}


void		allocate_cmd(t_cmd **cmds, t_cmd cmd)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (cmds[i]->create == 0) {
			cmds[i]->create = 1;
			cmds[i]->cmd = cmd.cmd;
			cmds[i]->mode = cmd.mode;
			return;
		}
			i++;
	}
}

void		detect_spec(char **str, t_cmd **cmds, t_cmd *cmd, char ***envp)
{
    if (**str == '|')
    {
        ///add (s_cmd cmd) in (s_cmd loop[3])
		allocate_cmd(cmds, *cmd);
	}
	if (**str == ';')
	{
		(*str)++;
		printf(" is ;\n");
		allocate_cmd(cmds, *cmd);
		ft_printcol(cmd->tokens);

		if (cmd->tokens[0])
			stdexec(cmd, envp);

		free(cmd->tokens);
		cmd->tokens = NULL;
		init_cnd(cmd);
		return;
	}
	if (**str == '\0')
	{
		printf(" is \\0\n");

		allocate_cmd(cmds, *cmd);
		ft_printcol(cmd->tokens);

		if (cmd->tokens[0])
			stdexec(cmd, envp);
		free(cmd->tokens);
		cmd->tokens = NULL;
		init_cnd(cmd);
		return;
	}

}

void		add_cmd(t_cmd *cmds, int mode, void (*cmd) (char *, char **, char ***))
{
	cmds->create = 1;
	cmds->cmd = cmd;
	cmds->mode = mode;
}

int			detect_cmd(char **str, t_cmd *cmd)
{
    while (!isspec(**str)) {
    	detect_token(str, cmd);
    }
    add_cmd(cmd, 1, &exec_ls);
    return 1;
}


void lets_pars(char *str_original, t_cmd **cmds, char ***envp)
{
    char *str;

	t_cmd cmd;

	init_cnd(&cmd);
	str = str_original;
	while (*str)
	{
		while (ft_isspace(*str))
			str++;
		if (detect_cmd(&str, &cmd))
		{
			detect_spec(&str, cmds, &cmd, envp);
		}
	}
}