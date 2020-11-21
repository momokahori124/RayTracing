/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 22:58:39 by mhori             #+#    #+#             */
/*   Updated: 2020/10/12 18:47:39 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		h(char *s)
{
	if (ft_strncmp(s, "l", 1) == 0)
		return (0);
	else if (ft_strncmp(s, "pl", 2) == 0)
		return (1);
	else if (ft_strncmp(s, "sp", 2) == 0)
		return (2);
	else if (ft_strncmp(s, "sq", 2) == 0)
		return (3);
	else if (ft_strncmp(s, "cy", 2) == 0)
		return (4);
	else if (ft_strncmp(s, "tr", 2) == 0)
		return (5);
	else if (ft_strncmp(s, "C", 1) == 0 || ft_strncmp(s, "c", 1) == 0)
		return (6);
	return (-1);
}

void	objs_num_init(t_objs *objs)
{
	int i;

	i = 0;
	while (i < 7)
	{
		objs->num[i] = 0;
		i++;
	}
}

void	count_id(t_objs *objs, char *s)
{
	objs->num[h(s)] += 1;
	if (ft_strncmp(s, "R", 1) == 0)
		objs->rac++;
}

void	input_error(t_objs objs)
{
	if (is_out_of_range(objs) == 1)
		err_exit(ERR_OUT_OF_RANGE_N, &objs);
	if (objs.rac != 1)
		err_exit(ERR_RAC_N, &objs);
	if (objs.error == 1)
		err_exit(ERR_WRONG_INPUT_N, &objs);
	if (objs.num[h("c")] == 0)
		err_exit(ERR_NO_CAMERA_N, &objs);
}

int		is_over_max(t_objs objs)
{
	if (objs.num[h("c")] >= MAX ||
		objs.num[h("l")] >= MAX ||
		objs.num[h("sp")] >= MAX ||
		objs.num[h("pl")] >= MAX ||
		objs.num[h("sq")] >= MAX ||
		objs.num[h("cy")] >= MAX ||
		objs.num[h("tr")] >= MAX)
		return (1);
	return (0);
}
