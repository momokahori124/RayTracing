/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 11:49:47 by mhori             #+#    #+#             */
/*   Updated: 2020/08/23 18:34:15 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

double		*get_inter_for_cy(double *v, t_objs *objs, double *t, int num)
{
	double		*ret;
	double		s[3];
	int			k;

	ret = malloc(sizeof(double) * 3);
	if (!ret)
		err_exit(ERR_MALLOC_N);
	s[0] = 1.0 / 0.0;
	s[1] = 1.0 / 0.0;
	s[2] = 1.0 / 0.0;
	if (cy_body(v, objs, num, &s[0]) == 1 || \
	cy_cap_top(v, objs, num, &s[1]) == 1 || \
	cy_cap_bot(v, objs, num, &s[2]) == 1)
		*t = min(s[0], min(s[1], s[2]));
	k = 0;
	while (k < 3)
	{
		ret[k] = objs->c[objs->c_num].p[k] + *t * v[k];
		k++;
	}
	return (ret);
}

void		offset(double *ofs, t_objs *objs, int num)
{
	int l;

	l = 0;
	while (l < 3)
	{
		ofs[l] = objs->cy[num].p[l] - objs->c[objs->c_num].p[l];
		l++;
	}
}

int			set_inner_products(double *a, double *v, t_objs *objs, int num)
{
	double	d[6];

	d[0] = inner_product(v, v);
	d[1] = inner_product(objs->cy[num].n, v);
	d[2] = inner_product(objs->ofs, v);
	d[3] = inner_product(objs->cy[num].n, objs->cy[num].n);
	d[4] = inner_product(objs->ofs, objs->cy[num].n);
	d[5] = inner_product(objs->ofs, objs->ofs);
	if (d[3] == 0.0f)
		return (0);
	a[0] = d[0] - d[1] * d[1] / d[3];
	a[1] = d[2] - d[4] * d[1] / d[3];
	a[2] = d[5] - d[4] * d[4] / d[3] - objs->cy[num].r * objs->cy[num].r;
	return (1);
}

int			get_cy_t(double *v, t_objs *objs, int num, double *t)
{
	double		a[3];
	double		t1;
	double		t2;
	double		s;

	offset(objs->ofs, objs, num);
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
