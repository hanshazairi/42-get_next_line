/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:46:56 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/05/20 01:33:46 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int		size;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	if (fd == -1 || !line || BUFFER_SIZE < 1 || read(fd, buf, 0) == -1)
		return (-1);
	size = read(fd, buf, BUFFER_SIZE);
	while (size > 0)
	{
	}
	return (0);
}
