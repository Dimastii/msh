//
// Created by Cloyster Veeta on 4/22/21.
//
#include "minishell.h"

//void		end_cmd(char **str,)
//{
//	(*str)++;
//	i = 0;
//
//	if (cmd->tokens[0])
//		stdexec(cmd, fd_out);
//	if (fd_out != 0)
//		fd_out = 0;
//	ft_freecol(cmd->tokens);
//	cmd->tokens = NULL;
//	init_cnd(cmd);
//	while (ft_isspace(**str))
//		(*str)++;
//	while(fd_arr[i] != 0)
//	{
//		close(fd_arr[i]);
//		i++;
//	}
//	i = 0;
//}

void		detect_spec(char **str, t_cmd *cmd, char ***envp)
{
	static int fd_out;
	static int fd_arr[100];
	static int i;

	if (**str == '|')
	{
		(*str)++;
		fd_arr[i++] = exec_pepe(str, *cmd, fd_out, envp);
		fd_out = fd_arr[i - 1];
		ft_freecol(cmd->tokens);
		cmd->tokens = NULL;
		init_cnd(cmd);
		while (ft_isspace(**str))
			(*str)++;
	}
	else if (**str == ';')
	{
//		(*str)++;
//		i = 0;
//
//		if (cmd->tokens[0])
//			stdexec(cmd, fd_out);
//		if (fd_out != 0)
//			fd_out = 0;
//		ft_freecol(cmd->tokens);
//		cmd->tokens = NULL;
//		init_cnd(cmd);
//		while (ft_isspace(**str))
//			(*str)++;
//		while(fd_arr[i] != 0)
//		{
//			close(fd_arr[i]);
//			i++;
//		}
		end_cmd();
		i = 0;
	}
	else if (**str == '\0')
	{
		if (cmd->tokens[0])
			stdexec(cmd, fd_out);
		if (fd_out != 0)
			fd_out = 0;
		ft_freecol(cmd->tokens);
		cmd->tokens = NULL;
		init_cnd(cmd);

		i = 0;
		while(fd_arr[i] != 0)
		{
			wait(0);
			close(fd_arr[i]);
			i++;
		}
	}
}