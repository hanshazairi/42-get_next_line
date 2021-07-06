/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:46:56 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/07/07 03:34:55 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_read(int fd, char *buf, char **factory)
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
				*factory = ft_substr(buf, 0, i);
			else
			{
				tmp = *factory;
				*factory = ft_strjoin(*factory, buf);
				free(tmp);
			}
			if (ft_strchr(buf, '\n'))
				break ;
			i = read(fd, buf, BUFFER_SIZE);
		}
	}
	free(buf);
}

static char	*ft_process(char **factory)
{
	int		i;
	int		j;
	char	*ret;
	char	*tmp;

	if (!*factory)
		return (0);
	if (!ft_strchr(*factory, '\n'))
	{
		ret = ft_substr(*factory, 0, ft_strlen(*factory));
		free(*factory);
		*factory = 0;
		return (ret);
	}
	i = ft_strlen(*factory);
	j = ft_strlen(ft_strchr(*factory, '\n'));
	ret = ft_substr(*factory, 0, i - j + 1);
	tmp = *factory;
	*factory = ft_substr(ft_strchr(*factory, '\n'), 1, j);
	free(tmp);
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*factory;

	buf = malloc(BUFFER_SIZE + 1);
	if (BUFFER_SIZE < 1 || fd == -1 || !buf || read(fd, buf, 0) == -1)
	{
		free(buf);
		return (0);
	}
	ft_read(fd, buf, &factory);
	return (ft_process(&factory));
}
