//
// Created by Cloyster Veeta on 4/4/21.
//

#include "minishell.h"

void		init_cnd(t_cmd *cmd)
{
	cmd->tokens = malloc(sizeof(char **));
	cmd->tokens[0] = NULL;
	cmd->fd_read = 0;
	cmd->fd_write = 1;
}
