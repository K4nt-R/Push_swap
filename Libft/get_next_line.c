/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qroyo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:58:46 by qroyo             #+#    #+#             */
/*   Updated: 2023/12/15 13:12:09 by qroyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

#include "libft.h"

char	*get_next_line(int fd)
{
	char		*str;
	static char	last[BUFFER_SIZE + 1];

	str = NULL;
	if (read(fd, 0, 0) < 0)
		return (ft_free(str, last));
	if (ft_sch(last, '\n') != ft_sch(last, '\0'))
	{
		str = ft_strjoin_buf(str, last);
		if (!str)
			return (ft_free(str, last));
		ft_strlcpy(last, last + ft_sch(last, '\n') + 1, ft_sch(last, '\0'));
		return (str);
	}
	str = ft_read(last, fd);
	if (!str)
		return (ft_free(str, last));
	return (str);
}

size_t	ft_sch(const char *buf, int c)
{
	size_t	i;

	if (buf == NULL)
		return (0);
	i = 0;
	while (buf[i])
	{
		if (buf[i] == c)
			return (i);
		i++;
	}
	return (i);
}

char	*ft_read(char *last, int fd)
{
	char	*buf;
	char	*str;
	int		r;

	str = NULL;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (ft_free(buf, last));
	ft_memset(buf, 0, BUFFER_SIZE + 1);
	str = ft_line(last, fd, buf, &r);
	if (!str && r == 0 && last[0] != '\0')
	{
		free(str);
		str = NULL;
		str = ft_strjoin_buf(str, last);
		if (!str)
			return (ft_free(str, last));
		ft_memset(last, 0, BUFFER_SIZE + 1);
	}
	else if (!str)
		return (ft_free(str, last));
	return (str);
}

char	*ft_line(char *last, int fd, char *buf, int *r)
{
	char	*str;
	size_t	len;

	str = NULL;
	*r = read(fd, buf, BUFFER_SIZE);
	while (*r > 0)
	{
		str = ft_strjoin_buf(str, buf);
		if (!str)
			return (ft_free(buf, last));
		if (ft_sch(buf, '\n') != BUFFER_SIZE)
		{
			str = ft_strjoin_last(last, str);
			if (!str)
				return (ft_free(buf, last));
			len = BUFFER_SIZE - ft_sch(buf, '\n');
			ft_strlcpy(last, buf + ft_sch(buf, '\n') + 1, len);
			break ;
		}
		ft_memset(buf, 0, BUFFER_SIZE + 1);
		*r = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (str);
}

void	*ft_free(char *s1, char *last)
{
	if (s1 != NULL)
		free(s1);
	ft_memset(last, 0, BUFFER_SIZE + 1);
	return (NULL);
}
