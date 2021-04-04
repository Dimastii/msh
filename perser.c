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

void  detect_token(char **str, t_cmd *cmd)
{
	char *token;
	char **temp_cmd;

	while (ft_isspace(**str) && **str != ';')
		(*str)++;
	temp_cmd = cmd->tokens;
	token = ft_strdup("");
	while (**str != ';' && !(ft_isspace(**str)) && **str)
	{
		token = ft_strjoins(token,**str);
		(*str)++;
	}
	if (*token)
	{
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

void		detect_spec(char **str, t_cmd **cmds, t_cmd *cmd)
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

void		add_cmd(t_cmd *cmds, int mode, void (*cmd) (char *, char **, char **))
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

    while (!(ft_isspace(**str)) && **str)
        (*str)++;
	if (**str != ';')
    	**str = '\0';
	(*str)++;
    if (ft_strncmp("ls\0", str_enter, 3) == 0 || ft_strncmp("ls;", str_enter, 3) == 0 || ft_strncmp("ls|", str_enter, 3) == 0 || ft_strncmp("ls>", str_enter, 3) == 0)
    {
		///add t_cmd
		printf("!__ ls found\n");
		while (**str != ';' && **str != '\0')
			detect_token(str, cmd);
		add_cmd(cmd, 1, &exec_ls);
        return 1;
    }
    else
        return 0;
}


void lets_pars(char *str_original, t_cmd **cmds)
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
			ft_printcol(cmd.tokens);
			detect_spec(&str, cmds, &cmd);
		}
	}
}