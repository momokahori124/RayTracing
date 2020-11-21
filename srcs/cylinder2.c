/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:47:44 by mhori             #+#    #+#             */
/*   Updated: 2020/08/19 18:19:51 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int			cy_body_new(double *v, t_objs *objs, int num, double *t)
{
	double		rc[3];
	double		cut;
	double		r[3];
	int			k;

	if (get_cy_new_t(v, objs, num, t) == 0)
		return (0);
	k = 0;
	while (k < 3)
	{
		r[k] = objs->p[k] + *t * v[k];
		k++;
	}
	vec_minus(rc, r, objs->cy[num].p);
	cut = inner_product(objs->cy[num].n, rc);
	cut /= inner_product(objs->cy[num].n, objs->cy[num].n);
	if (*t >= 0)
	{
		if (0 <= cut && cut <= objs->cy[num].h)
			return (1);
		return (0);
	}
	return (0);
}

int			cy_cap_bot_new(double *v, t_objs *objs, int num, double *t)
{
	double	x[3];
	double	pc[3];
	double	dis;
	int		k;

	vec_minus(pc, objs->cy[num].p, objs->p);
	*t = inner_product(pc, objs->cy[num].n);
	if (inner_product(v, objs->cy[num].n) < 0.0f)
		return (0);
	*t /= inner_product(v, objs->cy[num].n);
	k = 0;
	while (k < 3)
	{
		x[k] = (objs->p)[k] + *t * v[k];
		k++;
	}
	vec_minus(pc, x, objs->cy[num].p);
	dis = inner_product(pc, pc);
	if (dis <= objs->cy[num].r * objs->cy[num].r)
		return (1);
	else
		return (0);
}

int			cy_cap_top_new(double *v, t_objs *objs, int num, double *t)
{
	double	x[3];
	double	pc[3];
	double	top[3];
	int		k;
	double	dis;

	get_top_coordinate(objs, num, top);
	vec_minus(pc, top, objs->p);
	*t = inner_product(pc, objs->cy[num].n);
	if (inner_product(v, objs->cy[num].n) == 0.0f)
		return (0);
	*t /= inner_product(v, objs->cy[num].n);
	k = 0;
	while (k < 3)
	{
		x[k] = (objs->p)[k] + *t * v[k];
		k++;
	}
	vec_minus(pc, x, top);
	dis = inner_product(pc, pc);
	if (dis <= objs->cy[num].r * objs->cy[num].r)
		return (1);
	else
		return (0);
}

void		array_dup(double *src, double *dest)
{
	int k;

	k = 0;
	while (k < 3)
	{
		dest[k] = src[k];
		k++;
	}
}

int			judge_for_cy_new(double *p, double *v, t_objs *objs, int num)
{
	double	s[3];
	double	t;

	s[0] = 1.0 / 0.0;
	s[1] = 1.0 / 0.0;
	s[2] = 1.0 / 0.0;
	array_dup(p, objs->p);
	array_dup(v, objs->v);
	if (cy_body_new(v, objs, num, &s[0]) == 1 || \
	cy_cap_top_new(v, objs, num, &s[1]) == 1 || \
	cy_cap_bot_new(v, objs, num, &s[2]) == 1)
	{
		t = min(s[0], min(s[1], s[2]));
		if (t > 0)
			return (1);
		return (0);
	}
	return (0);
}
