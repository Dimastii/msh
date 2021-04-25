#include "minishell.h"

void	error(char *str)
{
	printf("%s\n", str);
	exit (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	size_t			j;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	j = 0;
	if (!ss1 || !ss2)
		return (-1);
	while (ss1[i] != '\0' && ss2[j] != '\0')
	{
		if (ss1[i] != ss2[j])
			return (ss1[i] - ss2[j]);
		j++;
		i++;
	}
	return (ss1[i] - ss2[j]);
}

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}
