/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 18:05:36 by mhori             #+#    #+#             */
/*   Updated: 2020/08/23 18:36:54 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				free_line_tmp(char ***line, char **tmp)
{
	free(**line);
	free(*tmp);
	return (-1);
}

static int		rv_positive(char **save, int fd, char **line)
{
	char	*tmp;
	int		len;

	len = 0;
	while (save[fd][len] != '\n' && save[fd][len] != '\0')
		len++;
	if (save[fd][len] == '\0')
	{
		*line = ft_strdup(save[fd]);
		free(save[fd]);
		if (!*line)
			return (-1);
		save[fd] = NULL;
		return (0);
	}
	else
	{
		*line = ft_substr(save[fd], 0, len);
		tmp = ft_strdup(&save[fd][len + 1]);
		free(save[fd]);
		if (!tmp || !line)
			return (free_line_tmp(&line, &tmp));
		save[fd] = tmp;
		return (1);
	}
}

static int		decide_rv(char **save, int rv, int fd, char **line)
{
	if (rv == 0 && save[fd] == NULL)
	{
		free(save[fd]);
		*line = ft_strdup("");
		if (*line == NULL)
			return (-1);
		return (0);
	}
	else if (rv < 0)
		return (-1);
	else
		return (rv_positive(save, fd, line));
}

int				free_buf(char **buf)
{
	free(*buf);
	return (-1);
}

int				get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*save[FD_MAX];
	char		*tmp;
	int			rv;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (fd < 0 || fd > FD_MAX || line == NULL || buf == NULL)
		return (-1);
	while ((rv = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rv] = '\0';
		if (save[fd] == NULL)
			tmp = ft_strdup(buf);
		else
			tmp = ft_strjoin(save[fd], buf);
		free(save[fd]);
		if (!tmp)
			return (free_buf(&buf));
		save[fd] = tmp;
		if (ft_strchr(save[fd], '\n'))
			break ;
	}
	free(buf);
	return (decide_rv(save, rv, fd, line));
}
