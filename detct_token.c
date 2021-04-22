//
// Created by Cloyster Veeta on 4/22/21.
//
#include "minishell.h"

void	detect_token(char **str, t_cmd *cmd)
{
	char *token;
	char *tmp;
	int redir;
	int fd_redir;

	redir = -1;
	token = ft_strdup("");
	while (ft_isspace(**str))
		(*str)++;
	while (**str != ' ' && !(isspec(**str)) && **str)
	{
		if (**str == '"' || **str == '\'')//если кавычка
		{
			this_quote(str, &token, &tmp);
		}
		else // если не кавычка
		{
			this_not_quote(str, &token, &redir, &tmp);
		}
	}
	if (*token) {
		if (redir == 2)
		{
			fd_redir = open(token,  O_RDONLY);
			cmd->fd_read = fd_redir;
			//отсюда читаем
		}
		else if (redir == 1)
		{
			fd_redir = open(token, O_CREAT | O_TRUNC | O_WRONLY, 0644);
			cmd->fd_write = fd_redir;
			//сюда пишем
		}
		else if (redir == 3)
		{
			fd_redir = open(token, O_WRONLY | O_APPEND);
			cmd->fd_write = fd_redir;
			//сюда дописываем
		}
		else
		{
			cmd->tokens = ft_coljoins(cmd->tokens, token);
		}
	}
	free(token);
}