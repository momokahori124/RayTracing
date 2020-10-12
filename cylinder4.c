/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:53:01 by mhori             #+#    #+#             */
/*   Updated: 2020/08/23 15:52:14 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int			cy_body(double *v, t_objs *objs, int num, double *t)
{
	double	cut;
	double	r[3];
	int		k;
	double	rc[3];

	if (get_cy_t(v, objs, num, t) == 0)
		return (0);
	k = 0;
	while (k < 3)
	{
		r[k] = objs->c[objs->c_num].p[k] + *t * v[k];
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

int			cy_cap_bot(double *v, t_objs *objs, int num, double *t)
{
	double		x[3];
	double		pc[3];
	int			k;
	double		dis;

	vec_minus(pc, objs->cy[num].p, objs->c[objs->c_num].p);
	*t = inner_product(pc, objs->cy[num].n);
	if (inner_product(v, objs->cy[num].n) < 0.0f)
		return (0);
	*t /= inner_product(v, objs->cy[num].n);
	k = 0;
	while (k < 3)
	{
		x[k] = objs->c[objs->c_num].p[k] + *t * v[k];
		k++;
	}
	vec_minus(pc, x, objs->cy[num].p);
	dis = inner_product(pc, pc);
	if (dis <= objs->cy[num].r * objs->cy[num].r)
		return (1);
	else
		return (0);
}

void		get_top_coordinate(t_objs *objs, int num, double *top)
{
	int k;

	k = 0;
	while (k < 3)
	{
		top[k] = objs->cy[num].p[k] + objs->cy[num].n[k] * objs->cy[num].h;
		k++;
	}
}
