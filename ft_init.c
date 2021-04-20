//
// Created by Cloyster Veeta on 4/4/21.
//

#include "minishell.h"

void		init_cnd(t_cmd *cmd)
{
	cmd->create = 0;
	cmd->mode = -1;
	cmd->tokens = malloc(sizeof(char **));
	cmd->tokens[0] = NULL;
}
