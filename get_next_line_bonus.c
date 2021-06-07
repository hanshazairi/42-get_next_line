/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 01:09:54 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/06/08 01:10:03 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	ft_read(int fd, char *buf, char **factory)
{
	int		i;
	char	*tmp;

	if (!factory[fd] || !ft_strchr(factory[fd], '\n'))
	{
		i = read(fd, buf, BUFFER_SIZE);
		while (i > 0)
		{
			buf[i] = 0;
			if (!factory[fd])
				factory[fd] = ft_substr(buf, 0, i);
			else
			{
				tmp = factory[fd];
				factory[fd] = ft_strjoin(tmp, buf);
				free(tmp);
			}
			if (ft_strchr(buf, '\n'))
				break ;
			i = read(fd, buf, BUFFER_SIZE);
		}
	}
	free(buf);
}

static int	ft_process(int fd, char **line, char **factory)
{
	int		i;
	int		j;
	char	*tmp;

	if (!factory[fd])
	{
		*line = ft_substr("", 0, 0);
		return (0);
	}
	if (!ft_strchr(factory[fd], '\n'))
	{
		*line = ft_substr(factory[fd], 0, ft_strlen(factory[fd]));
		free(factory[fd]);
		factory[fd] = 0;
		return (0);
	}
	i = ft_strlen(factory[fd]);
	j = ft_strlen(ft_strchr(factory[fd], '\n'));
	*line = ft_substr(factory[fd], 0, i - j);
	tmp = factory[fd];
	factory[fd] = ft_substr(ft_strchr(factory[fd], '\n'), 1, j);
	free(tmp);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*factory[OPEN_MAX];

	buf = malloc(BUFFER_SIZE + 1);
	if (BUFFER_SIZE < 1 || fd == -1 || !line || !buf || read(fd, buf, 0) == -1)
	{
		free(buf);
		return (-1);
	}
	ft_read(fd, buf, factory);
	return (ft_process(fd, line, factory));
}
