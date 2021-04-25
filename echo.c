#include "minishell.h"

void	exec_echo(t_cmd	*c)
{
	int	i;
	int	flag;

	flag = 0;
	i = 1;
	while (c->tkn[i])
	{
		if (ft_strncmp(c->tkn[1], "-n", ft_strlen(c->tkn[1])) == 0 && flag == 0)
		{
			flag = 1;
			while (ft_strncmp(c->tkn[i], "-n", ft_strlen(c->tkn[i])) == 0)
			{
				i++;
			}
		}
		write(1, c->tkn[i], ft_strlen(c->tkn[i]));
		write(1, " ", 1);
		i++;
	}
	if (!flag)
		write(1, "\n", 1);
	exit (0);
}
