/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 09:35:49 by mhori             #+#    #+#             */
/*   Updated: 2020/08/22 14:31:42 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

double		d_for_sp(double *v, double *vp, double *cp, double r)
{
	double	a[4];
	double	vcp[3];

	vec_minus(vcp, vp, cp);
	a[0] = inner_product(v, v);
	a[1] = inner_product(vcp, v);
	a[2] = inner_product(vcp, vcp) - r * r;
	a[3] = a[1] * a[1] - a[0] * a[2];
	return (a[3]);
}

void		get_ret(double *ret, double *vp, double *v, double *t)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		ret[i] = vp[i] + v[i] * (*t);
		i++;
	}
}

double		*get_inter_for_sp(double *v, double *vp, t_sp sp, double *t)
{
	double	a[3];
	double	vcp[3];
	double	*ret;

	ret = (double *)malloc(sizeof(double) * 3);
	a[2] = d_for_sp(v, vp, sp.p, sp.r);
	if (a[2] < 0)
	{
		*t = -1;
		return (ret);
	}
	vec_minus(vcp, vp, sp.p);
	a[0] = inner_product(v, v);
	a[1] = inner_product(vcp, v);
	*t = (-a[1] - sqrt(a[2])) / a[0];
	vec_init(ret);
	if (*t >= 0)
		get_ret(ret, vp, v, t);
	return (ret);
}

int			dark_from_others(t_objs objs, double *p, int l_num)
{
	double	v[3];
	int		is_dark;

	is_dark = 0;
	vec_minus(v, objs.l[l_num].p, p);
	is_dark = max(is_dark, dark_sp(objs, p, v));
	is_dark = max(is_dark, dark_sq(objs, p, v));
	is_dark = max(is_dark, dark_cy(objs, p, v));
	is_dark = max(is_dark, dark_tr(objs, p, v));
	return (is_dark);
}
