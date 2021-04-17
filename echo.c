#include "minishell.h"

void		exec_echo(t_cmd	*cmd)
{
	int i;
	int flag;

	flag = 0;
	i = 1;
	while (cmd->tokens[i])
	{
		if (ft_strncmp(cmd->tokens[1], "-n", ft_strlen(cmd->tokens[1])) == 0 && flag == 0)
		{
			flag = 1;
			while (ft_strncmp(cmd->tokens[i], "-n", ft_strlen(cmd->tokens[i])) == 0)
			{
				i++;
			}
		}
		write(1, cmd->tokens[i], ft_strlen(cmd->tokens[i]));
		write(1, " ", 1);
		i++;
	}
	if (!flag)
		write(1, "\n", 1);
}
