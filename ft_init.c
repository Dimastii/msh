//
// Created by Cloyster Veeta on 4/4/21.
//

#include "minishell.h"

void	init_cnd(t_cmd *cmd)
{
	cmd->tkn = malloc(sizeof(char *));
	cmd->tkn[0] = NULL;
	cmd->fd_read = 0;
	cmd->fd_write = 1;
}
