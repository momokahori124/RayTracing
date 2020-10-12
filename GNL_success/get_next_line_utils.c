/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 11:05:26 by mhori             #+#    #+#             */
/*   Updated: 2020/08/23 18:35:21 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*ret;
	int		i;

	len = ft_strlen(s1);
	if (!(ret = malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	char			*save;

	if (!s)
		return (NULL);
	save = (char *)s;
	while (*save)
	{
		if (*save == c)
			return (save);
		save++;
	}
	if (c == '\0')
		return (save);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t count;

	count = 0;
	while (*(s++))
		count++;
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*ret;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(ret = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = '\0';
	return (ret);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	slen;

	if (!s)
		return (NULL);
	if (!(ret = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	slen = ft_strlen(s);
	i = 0;
	if (slen < start + len)
		return (ft_strdup(""));
	while (i < len && s[i + start])
	{
		ret[i] = s[i + start];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
