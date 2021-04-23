#include "minishell.h"

void	exec_echo(t_cmd	*cmd)
{
	int	i;
	int	flag;

	flag = 0;
	i = 1;
	while (cmd->tkn[i])
	{
		if (ft_strncmp(cmd->tkn[1], "-n", ft_strlen(cmd->tkn[1])) == 0 && flag == 0)
		{
			flag = 1;
			while (ft_strncmp(cmd->tkn[i], "-n", ft_strlen(cmd->tkn[i])) == 0)
			{
				i++;
			}
		}
		write(1, cmd->tkn[i], ft_strlen(cmd->tkn[i]));
		write(1, " ", 1);
		i++;
	}
	if (!flag)
		write(1, "\n", 1);
	exit (0);
}
