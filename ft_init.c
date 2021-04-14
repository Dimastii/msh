//
// Created by Cloyster Veeta on 4/4/21.
//

#include "main.h"

void		init_cnd(t_cmd *cmd)
{
	cmd->create = 0;
	cmd->mode = -1;
	cmd->tokens = malloc(sizeof(char **));
	cmd->tokens[0] = NULL;
}

void		init_cmds(t_cmd **cmds)
{
	int i;

	i = 0;
	while (i < 3)
	{
//		cmds[i]->create = 0;
//		cmds[i]->mode = -1;
//		cmds[i]->tokens = malloc(sizeof(char **));
//		cmds[i]->tokens[0] = NULL;
//		cmds[i]->cmd = NULL;
		i++;
	}

}
