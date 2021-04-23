//
// Created by Cloyster Veeta on 4/22/21.
//
#include "minishell.h"

void	check_token(char *token, int redir, t_cmd *cmd)
{
	int		fd_redir;

	if (*token)
	{
		if (redir == 2)
		{
			fd_redir = open(token, O_RDONLY);
			cmd->fd_read = fd_redir;
		}
		else if (redir == 1)
		{
			fd_redir = open(token, O_CREAT | O_TRUNC | O_WRONLY, 0644);
			cmd->fd_write = fd_redir;
		}
		else if (redir == 3)
		{
			fd_redir = open(token, O_WRONLY | O_APPEND);
			cmd->fd_write = fd_redir;
		}
		else
		{
			cmd->tokens = ft_coljoins(cmd->tokens, token);
		}
	}
}

void	detect_token(char **str, t_cmd *cmd)
{
	char	*token;
	char	*tmp;
	int		redir;

	redir = -1;
	token = ft_strdup("");
	while (ft_isspace(**str))
		(*str)++;
	while (**str != ' ' && !(isspec(**str)) && **str)
	{
		if (**str == '"' || **str == '\'')
		{
			this_quote(str, &token, &tmp);
		}
		else
		{
			this_not_quote(str, &token, &redir, &tmp);
		}
	}
	check_token(token, redir, cmd);
	free(token);
}
