//
// Created by Cloyster Veeta on 4/23/21.
//

#include "minishell.h"

char	*find_arg(char	*pos_eq)
{
	char	*arg;

	arg = ft_strdup("\"");
	while (*pos_eq)
	{
		arg = ft_freeline(arg, ft_strjoins(arg, *pos_eq));
		pos_eq++;
	}
	arg = ft_freeline(arg, ft_strjoins(arg, '\"'));
	return (arg);
}

void 	add_env(char *str, t_cmd cmd)
{
	char	*pos_eq;
	char	*arg;
	if (ft_isalpha(*str))
	{
		pos_eq = ft_strchr(str, '=');
		if (pos_eq)
		{
			arg = find_arg(pos_eq + 1);
		}
		else
			arg = str;
		g_envp = ft_coljoins(g_envp, arg);
//		ft_printcol(g_envp);
	}
	else
		write(cmd.fd_write, "invalid var", 12);
//		printf("invalid var \"%s\"\n", str);
}

void 	show_env(t_cmd cmd)
{
	char	**env;
	int		i;

	i = 0;
	env = g_envp;
	while (env[i])
	{
		write(cmd.fd_write, "declare -x ", 11);
		write(cmd.fd_write, env[i], ft_strlen(env[i]));
		write(cmd.fd_write, "\n", 1);
		++i;
	}
}

void	exec_export(t_cmd *cmd)
{
	int i;
//	char *var;

	i = 1;
	if (!cmd->tkn[i])
	{
		show_env(*cmd);
	}
	while (cmd->tkn[i])
	{
		add_env(cmd->tkn[i], *cmd);
		i++;
	}
}