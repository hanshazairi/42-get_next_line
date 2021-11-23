/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 01:09:54 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/11/24 00:56:02 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

static void	gnl_read(int fd, char *buf, char **str)
{
	int		i;
	char	*tmp;

	if (!str[fd] || !ft_strchr(str[fd], '\n'))
	{
		i = read(fd, buf, BUFFER_SIZE);
		while (i > 0)
		{
			buf[i] = 0;
			if (!str[fd])
				str[fd] = ft_substr(buf, 0, i);
			else
			{
				tmp = str[fd];
				str[fd] = ft_strjoin(str[fd], buf);
				free(tmp);
			}
			if (ft_strchr(buf, '\n'))
				break ;
			i = read(fd, buf, BUFFER_SIZE);
		}
	}
	free(buf);
}

static char	*gnl_process(int fd, char **str)
{
	int		i;
	int		j;
	char	*ret;
	char	*tmp;

	if (!str[fd])
		return (0);
	if (!ft_strchr(str[fd], '\n'))
	{
		ret = ft_substr(str[fd], 0, ft_strlen(str[fd]));
		free(str[fd]);
		str[fd] = 0;
		return (ret);
	}
	i = ft_strlen(str[fd]);
	j = ft_strlen(ft_strchr(str[fd], '\n'));
	ret = ft_substr(str[fd], 0, i - j + 1);
	tmp = str[fd];
	str[fd] = ft_substr(ft_strchr(str[fd], '\n'), 1, j - 1);
	free(tmp);
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*str[OPEN_MAX];

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	if (BUFFER_SIZE < 1 || fd == -1 || read(fd, buf, 0) == -1)
	{
		free(buf);
		return (0);
	}
	gnl_read(fd, buf, str);
	return (gnl_process(fd, str));
}
