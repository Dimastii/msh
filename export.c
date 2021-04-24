#include "minishell.h"

char	*find_arg(char *pos_eq)
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

void 	add_env2(char *str, char **arg, char **var, char ***f_glob)
{
	while (*str != '=' && *str)
		*arg = ft_freeline(*arg, ft_strjoins(*arg, *str++));
	*f_glob = ret_glob(*arg);
	if (*f_glob)
	{
		**f_glob = ft_freeline(**f_glob, ft_strdup(*arg));
		if (*str == '=')
		{
			**f_glob = ft_freeline(**f_glob, ft_strjoins(**f_glob, *str++));
			*var = find_arg(str);
			**f_glob = ft_freeline(**f_glob, ft_strjoin(**f_glob, *var));
			free(*var);
		}
	}
	else
	{
		if (*str == '=')
		{
			*arg = ft_freeline(*arg, ft_strjoins(*arg, *str++));
			*var = find_arg(str);
			*arg = ft_freeline(*arg, ft_strjoin(*arg, *var));
			free(*var);
		}
		g_envp = ft_coljoins(g_envp, *arg);
	}
}

void 	add_env(char *str, t_cmd cmd)
{
	char	*arg;
	char	**found_glob;
	char	*var;

	arg = ft_strdup("");
	if (ft_isalpha(*str))
		add_env2(str, &arg, &var, &found_glob);
	else
		write(cmd.fd_write, "invalid var", 12);
	free(arg);
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
	int	i;

	i = 1;
	if (!cmd->tkn[i])
		show_env(*cmd);
	while (cmd->tkn[i])
	{
		add_env(cmd->tkn[i], *cmd);
		i++;
	}
}
