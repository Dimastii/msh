#include "../minishell.h"

size_t	ft_strcpy(char *dest, const char *src)
{
	size_t	i;
	int		j;

	j = 0;
	i = 0;
	if (dest == NULL || src == NULL)
		return (0);
	while (src[j] != '\0')
		j++;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (j);
}

void	set_remainder(char **remainder, char *temp, int flag)
{
	char	*fre;

	if (flag)
	{
		*temp = '\0';
		fre = *remainder;
		*remainder = ft_strdup(++temp);
		free(fre);
	}
	else
	{
		fre = *remainder;
		*remainder = NULL;
		free(fre);
	}
}

char	*check_remainder(char *remainder, char **line)
{
	char	*tmp;

	tmp = NULL;
	if (remainder)
	{
		tmp = ft_strchr(remainder, '\n');
		if (tmp)
		{
			*tmp = '\0';
			*line = ft_strdup(remainder);
			ft_strcpy(remainder, ++tmp);
		}
		else
			*line = ft_strdup(remainder);
	}
	else
		*line = ft_strdup("");
	return (tmp);
}

int	get_next_line(int fd, char **line)
{
	static char	*remainder;
	char		*temp;
	size_t		r_bytes;
	char		*buff;

	buff = (char *)malloc(20 + 1);
	if (fd < 0 || !line || (read(fd, 0, 0) == -1) || !buff)
		return (-1);
	*line = NULL;
	temp = check_remainder(remainder, line);
	r_bytes = read(fd, buff, 20);
	while (!temp && r_bytes)
	{
		buff[r_bytes] = '\0';
		temp = ft_strchr(buff, '\n');
		if (temp)
			set_remainder(&remainder, temp, 1);
		*line = ft_freeline(*line, ft_strjoin(*line, buff));
	}
	free(buff);
	if (temp)
		return (1);
	set_remainder(&remainder, temp, 0);
	return (0);
}
