//
// Created by Cloyster Veeta on 3/27/21.
//
#include "minishell.h"

int	detect_cmd(char **str, t_cmd *cmd)
{
	while (!isspec(**str))
	{
		detect_token(str, cmd);
	}
	return (1);
}

void	lets_pars(char **str, char ***envp)
{
	t_cmd	cmd;

	init_cnd(&cmd);
	while (**str)
	{
		while (ft_isspace(**str))
			(*str)++;
		detect_cmd(str, &cmd);
		detect_spec(str, &cmd, envp);
	}
}
