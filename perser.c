//
// Created by Cloyster Veeta on 3/27/21.
//

#include "main.h"

int		ft_isspace(int c)
{
    c = (unsigned char)c;
    if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
        || c == ' ' || c == ';')
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

	tocken = ft_strdup("");
	while (ft_isspace(**str))
		(*str)++;
	while (**str != ' ')
	{
		if (**str == '"' || **str == '\'')
		{
			ft_strchr(*str, **str);
			///token concat;
		}
		else///иначе это токен без кавычек
		{
			///пока str не ковычка или не пробел мы tok concat;
		}
	}
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
//	while (!(ft_isspace(**str)) && **str)
//		(*str)++;
//	**str = '\0';
    if (**str == '|')
    {
        ///add (s_cmd cmd) in (s_cmd loop[3])
		allocate_cmd(cmds, *cmd);
	}
	if (**str == ';')
	{
		(*str)++;
		allocate_cmd(cmds, *cmd);
		ft_printcol(cmd->tokens);
//		int pid = fork();
//
//		if (pid == 0) {
//			execve("/bin/ls", cmd->tokens, *envp);
//		}
//		else if (pid < 0)
//		{
//			//принт еррор
//		}
//		else
//		{
//			wait(NULL);
//		}
		free(cmd->tokens);
		cmd->tokens = NULL;
		init_cnd(cmd);
		return;
	}
	if (**str == '\0')
	{
		allocate_cmd(cmds, *cmd);
		//exec_cmds(cmds);
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
    char *str_enter;
	char *cmd_;
    str_enter = *str;


//    if (ft_strncmp("ls\0", str_enter, 3) == 0 || ft_strncmp("ls;", str_enter, 3) == 0 || ft_strncmp("ls|", str_enter, 3) == 0 || ft_strncmp("ls>", str_enter, 3) == 0)
//    {
		while (**str != ';' && **str != '\0')
			detect_token(str, cmd);
		add_cmd(cmd, 1, &exec_ls);
        return 1;
//    }
    else
        return 0;
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
			printf("cmd find with columns:\n");

			detect_spec(&str, cmds, &cmd, envp);
		}
	}
}