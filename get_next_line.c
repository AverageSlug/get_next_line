/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaurids <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:15:54 by nlaurids          #+#    #+#             */
/*   Updated: 2020/02/18 18:14:50 by nlaurids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_memcat(char *line, char rest[BUFFER_SIZE + 1])
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(temp = malloc(sizeof(char) * (ft_strlen(line) + ft_strlen(rest)
						+ 1))))
		return (NULL);
	while (line[i])
	{
		temp[i] = line[i];
		i++;
	}
	free(line);
	while (rest[j] && rest[j] != '\n')
	{
		temp[i] = rest[j];
		i++;
		j++;
	}
	temp[i] = '\0';
	return (temp);
}

int		ft_reader(int fd, char buf[BUFFER_SIZE + 1],
		char rest[BUFFER_SIZE + 1])
{
	int		r;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((r = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[r] = '\0';
		while (buf[i])
		{
			rest[j] = buf[i];
			i++;
			j++;
		}
		rest[j] = '\0';
	}
	if (r > 0)
		return (1);
	if (r == 0)
		return (0);
	return (-1);
}

void	ft_completeline(char **line, char rest[BUFFER_SIZE + 1])
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	*line = ft_memcat(*line, rest);
	while (rest[i] && rest[i] != '\n')
		i++;
	if (rest[i] == '\n')
		i++;
	while (rest[i])
	{
		rest[j] = rest[i];
		i++;
		j++;
	}
	rest[j] = '\0';
}

int		ft_checkifendofline(char rest[BUFFER_SIZE + 1])
{
	int		i;

	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (rest[i] == '\n')
		return (1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	rest[OPEN_MAX][BUFFER_SIZE + 1];
	int			ret;

	if (fd >= OPEN_MAX || fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!(*line = malloc(sizeof(char))))
		return (-1);
	**line = '\0';
	while (!ft_checkifendofline(rest[fd]))
	{
		ft_completeline(line, rest[fd]);
		ret = ft_reader(fd, buf, rest[fd]);
		if (ret < 0)
			return (-1);
		if (ret == 0)
			return (0);
	}
	ft_completeline(line, rest[fd]);
	return (1);
}
