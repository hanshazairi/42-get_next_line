/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 01:10:17 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/07/03 21:09:28 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
	{
		if (*s == 0)
			return (0);
		++s;
	}
	return ((char *)s);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ret;
	char	*src;
	size_t	i;

	ret = malloc(len + 1);
	if (!ret)
		return (0);
	src = (char *)s + start;
	i = 0;
	while (*src && i < len)
		ret[i++] = *src++;
	ret[i] = 0;
	return (ret);
}

size_t	ft_strlen(const char *s)
{
	size_t	ret;

	ret = 0;
	while (*s++)
		++ret;
	return (ret);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = malloc(len + 1);
	if (!ret)
		return (0);
	i = 0;
	while (*s1)
		ret[i++] = *s1++;
	while (*s2)
		ret[i++] = *s2++;
	ret[i] = 0;
	return (ret);
}
