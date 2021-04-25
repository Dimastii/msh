/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdaedric <bdaedric@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:36:10 by bdaedric          #+#    #+#             */
/*   Updated: 2021/03/03 17:40:47 by bdaedric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include "../minishell.h"

size_t		ft_strcpy(char *dest, const char *src)
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
		if ((tmp = ft_strchr(remainder, '\n')))
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

int		get_next_line(int fd, char **line)
{
	static char	*remainder;
	char		*temp;
	size_t		r_bytes;
	char		*buff;

	if (fd < 0 || !line || (read(fd, 0, 0) == -1))
		return (-1);
	if (!(buff = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	*line = NULL;
	temp = check_remainder(remainder, line);
	while (!temp && (r_bytes = read(fd, buff, BUFFER_SIZE)))
	{
		buff[r_bytes] = '\0';
		if ((temp = ft_strchr(buff, '\n')))
			set_remainder(&remainder, temp, 1);
		*line = ft_freeline(*line ,ft_strjoin(*line, buff));
	}
	free(buff);
	if (temp)
		return (1);
	set_remainder(&remainder, temp, 0);
	return (0);
}
