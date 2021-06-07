/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:46:56 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/06/07 16:34:58 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_read(int fd, char *buf, char **factory)
{
	int		i;
	char	*tmp;

	if (!*factory || !ft_strchr(*factory, '\n'))
	{
		i = read(fd, buf, BUFFER_SIZE);
		while (i > 0)
		{
			buf[i] = 0;
			if (!*factory)
				*factory = ft_strdup(buf);
			else
			{
				tmp = *factory;
				*factory = ft_strjoin(tmp, buf);
				free(tmp);
			}
			if (ft_strchr(buf, '\n'))
				break ;
			i = read(fd, buf, BUFFER_SIZE);
		}
	}
	free(buf);
}

int	ft_process(char **line, char **factory)
{
	int		i;
	int		j;
	char	*tmp;

	if (!*factory)
	{
		*line = ft_strdup("");
		return (0);
	}
	if (!ft_strchr(*factory, '\n'))
	{
		*line = ft_strdup(*factory);
		free(*factory);
		*factory = 0;
		return (0);
	}
	i = ft_strlen(*factory);
	j = ft_strlen(ft_strchr(*factory, '\n'));
	*line = ft_substr(*factory, 0, i - j);
	tmp = *factory;
	*factory = ft_strdup(ft_strchr(tmp, '\n') + 1);
	free(tmp);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*factory;

	buf = malloc(BUFFER_SIZE + 1);
	if (BUFFER_SIZE < 1 || fd == -1 || !line || !buf || read(fd, buf, 0) == -1)
	{
		free(buf);
		return (-1);
	}
	ft_read(fd, buf, &factory);
	return (ft_process(line, &factory));
}
