/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:51:43 by mhori             #+#    #+#             */
/*   Updated: 2020/08/22 15:34:36 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int			cy_cap_top(double *v, t_objs *objs, int num, double *t)
{
	double	x[3];
	double	pc[3];
	double	top[3];
	double	dis;
	int		k;

	get_top_coordinate(objs, num, top);
	vec_minus(pc, top, objs->c[objs->c_num].p);
	*t = inner_product(pc, objs->cy[num].n);
	if (inner_product(v, objs->cy[num].n) == 0.0f)
		return (0);
	*t /= inner_product(v, objs->cy[num].n);
	k = 0;
	while (k < 3)
	{
		x[k] = objs->c[objs->c_num].p[k] + *t * v[k];
		k++;
	}
	vec_minus(pc, x, top);
	dis = inner_product(pc, pc);
	if (dis <= objs->cy[num].r * objs->cy[num].r)
		return (1);
	else
		return (0);
}

int			judge_for_cy(double *v, t_objs *objs, int num, double *t)
{
	double s[3];

	s[0] = 1.0 / 0.0;
	s[1] = 1.0 / 0.0;
	s[2] = 1.0 / 0.0;
	if (cy_body(v, objs, num, &s[0]) == 1 || \
	cy_cap_top(v, objs, num, &s[1]) == 1 || \
	cy_cap_bot(v, objs, num, &s[2]) == 1)
	{
		*t = min(s[0], min(s[1], s[2]));
		return (1);
	}
	return (0);
}

int			strike_judge_cy(t_objs *objs, double *v)
{
	int		ret;
	int		i;
	double	t_tmp;

	i = 0;
	while (i < objs->num[h("cy")])
	{
		if (judge_for_cy(v, objs, i, &t_tmp) == 1)
		{
			ret = 1;
			if (objs->t_min >= t_tmp && t_tmp >= 0)
			{
				objs->near_obj_num = i;
				objs->near_obj = h("cy");
				objs->t_min = t_tmp;
				array_dup(objs->cy[i].rgb, objs->near_color);
			}
		}
		i++;
	}
	return (ret);
}

void		offset_new(double *ofs, t_objs *objs, int num, double *p)
{
	int l;

	l = 0;
	while (l < 3)
	{
		ofs[l] = objs->cy[num].p[l] - p[l];
		l++;
	}
}

int			get_cy_new_t(double *v, t_objs *objs, int num, double *t)
{
	double	a[3];
	double	t1;
	double	t2;
	double	s;

	offset_new(objs->ofs, objs, num, objs->p);
	if (set_inner_products(a, v, objs, num) == 0)
		return (0);
	if (a[0] == 0.0f)
		return (0);
	s = a[1] * a[1] - a[0] * a[2];
	if (s < 0.0f)
		return (0);
	s = sqrt(s);
	t1 = (a[1] + s) / a[0];
	t2 = (a[1] - s) / a[0];
	if (t1 > 0)
		*t = t1;
	if (t2 > 0 && t2 < t1)
		*t = t2;
	return (1);
}
