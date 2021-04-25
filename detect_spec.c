//
// Created by Cloyster Veeta on 4/22/21.
//
#include "minishell.h"

void	end_cmd(char **str, t_cmd *cmd, int *fd_out, int *fd_arr)
{
	int		i;

	(*str)++;
	i = 0;
	if (cmd->tkn[0])
		stdexec(cmd, *fd_out);
	if (*fd_out != 0)
		*fd_out = 0;
	ft_freecol(cmd->tkn);
	cmd->tkn = NULL;
	while (ft_isspace(**str))
		(*str)++;
	while (fd_arr[i] != 0)
	{
		close(fd_arr[i]);
		i++;
	}
}

void	end_str(t_cmd *cmd, int *fd_out, int *fd_arr)
{
	int		i;

	if (cmd->tkn[0])
		stdexec(cmd, *fd_out);
	if (*fd_out != 0)
		*fd_out = 0;
	ft_freecol(cmd->tkn);
	cmd->tkn = NULL;
	i = 0;
	while (fd_arr[i] != 0)
	{
		wait(0);
		close(fd_arr[i]);
		i++;
	}
}

void	detect_spec(char **str, t_cmd *cmd)
{
	static int	fd_out;
	static int	fd_arr[1000];
	static int	i;

	if (**str == '|')
	{
		(*str)++;
		fd_arr[i++] = exec_pepe(*cmd, fd_out);
		fd_out = fd_arr[i - 1];
		ft_freecol(cmd->tkn);
		cmd->tkn = NULL;
		init_cnd(cmd);
		while (ft_isspace(**str))
			(*str)++;
	}
	else if (**str == ';')
	{
		end_cmd(str, cmd, &fd_out, fd_arr);
		i = 0;
	}
	else if (**str == '\0')
	{
		end_str(cmd, &fd_out, fd_arr);
	}
}
