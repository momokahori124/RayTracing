/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_out_of_range.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 01:06:43 by mhori             #+#    #+#             */
/*   Updated: 2020/09/23 17:36:17 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		is_out_of_range(t_objs objs)
{
	int		i;
	int		j;

	if (objs.r.x < 0 || objs.r.y < 0)
		return (1);
	i = 0;
	while (i < objs.num[h("C")])
	{
		j = 0;
		while (j < 3)
		{
			if (objs.c[i].n[j] > 1 || objs.c[i].n[j] < -1)
				return (1);
			if (objs.c[i].degree >= 180 || objs.c[i].degree <= 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
