/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 11:39:04 by mhori             #+#    #+#             */
/*   Updated: 2020/07/07 21:00:07 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*ret;

	str = (char *)s;
	ret = NULL;
	while (*str)
	{
		if (*str == c)
			ret = str;
		str++;
	}
	if (c == '\0')
		return (str);
	return (ret);
}
