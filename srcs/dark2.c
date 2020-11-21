/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dark2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 18:04:16 by mhori             #+#    #+#             */
/*   Updated: 2020/08/25 17:19:49 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int			dark_sp(t_objs objs, double *p, double *v)
{
	int		ret;
	int		i;
	double	t;
	double	*tmp;

	ret = 0;
	i = 0;
	t = 0;
	while (i < objs.num[h("sp")])
	{
		if (!(h("sp") == objs.near_obj && i == objs.near_obj_num))
		{
			tmp = get_inter_for_sp(v, p, objs.sp[i], &t);
			free(tmp);
			if (t > 0)
				ret = 1;
		}
		i++;
	}
	return (ret);
}

int			dark_tr(t_objs objs, double *p, double *v)
{
	int ret;
	int i;

	ret = 0;
	i = 0;
	while (i < objs.num[h("tr")])
	{
		if (!(h("tr") == objs.near_obj && i == objs.near_obj_num))
		{
			ret = max(ret, judge_for_tr_new(p, v, &objs, i));
		}
		i++;
	}
	return (ret);
}

int			dark_sq(t_objs objs, double *p, double *v)
{
	int ret;
	int i;

	ret = 0;
	i = 0;
	while (i < objs.num[h("sq")])
	{
		if (!(h("sq") == objs.near_obj && i == objs.near_obj_num))
		{
			ret = max(ret, judge_for_sq_new(p, v, &objs, i));
		}
		i++;
	}
	return (ret);
}

int			dark_cy(t_objs objs, double *p, double *v)
{
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	while (i < objs.num[h("cy")])
	{
		if (!(h("cy") == objs.near_obj && i == objs.near_obj_num))
		{
			ret = max(ret, judge_for_cy_new(p, v, &objs, i));
		}
		i++;
	}
	return (ret);
}
