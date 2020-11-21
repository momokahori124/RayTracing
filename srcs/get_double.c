/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 19:14:46 by mhori             #+#    #+#             */
/*   Updated: 2020/08/22 22:06:19 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		get_number(char **s, double *d, int *g)
{
	int ret;

	ret = 0;
	while ('0' <= **s && **s <= '9')
	{
		*d = *d * 10 + **s - '0';
		(*s)++;
		ret = 1;
	}
	if (**s == '.')
		(*s)++;
	while ('0' <= **s && **s <= '9')
	{
		*d = *d * 10 + **s - '0';
		(*s)++;
		(*g)++;
	}
	return (ret);
}

int		get_double(char **s, double *d)
{
	int		g;
	double	flag;
	int		ret;

	*d = 0;
	g = 0;
	ret = 0;
	flag = 1;
	if (**s == '-')
	{
		flag = -1;
		(*s)++;
	}
	ret = get_number(s, d, &g);
	*d = *d / pow(10, g);
	*d *= flag;
	return (ret);
}

int		get_coordinate(char **s, double *r)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (i < 3)
	{
		ret += get_double(s, &r[i]);
		while (**s == ',' || ft_isspace(**s))
			(*s)++;
		i++;
	}
	return (ret);
}

int		ft_isspace(char c)
{
	if (c == '\n' || c == '\t' || c == '\v')
		return (1);
	if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

void	skip_white_space(char **s)
{
	while (ft_isspace(**s))
		(*s)++;
}
