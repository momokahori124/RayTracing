/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 15:36:11 by mhori             #+#    #+#             */
/*   Updated: 2020/09/13 15:36:13 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void			get_color_cy(t_objs objs, double *v, double *color, double *p)
{
	double		max[3];
	double		c[3];
	int			is_dark;
	int			i;

	is_dark = 0;
	get_center_cy(objs, p, c);
	vec_init(max);
	vec_init(color);
	i = -1;
	while (++i < 3)
		color[i] += objs.a.ratio * objs.a.rgb[i];
	i = -1;
	while (++i < objs.num[h("l")])
	{
		is_dark = dark_from_others(objs, p, i);
		if (is_dark == 0)
		{
			array_dup(p, (&objs)->p);
			get_cy_cos(&objs, i, v, c);
			get_color_sub(objs, color, i);
		}
	}
}

void			get_tr_n(double **n, t_objs objs, int l_num, double *p)
{
	double	u[3];
	double	v[3];

	vec_minus(u, objs.tr[objs.near_obj_num].b, objs.tr[objs.near_obj_num].a);
	vec_minus(v, objs.tr[objs.near_obj_num].a, objs.tr[objs.near_obj_num].c);
	*n = cross_product(u, v);
	invert_vector(n, objs, l_num, p);
}

void			get_sq_n(double **n, t_objs objs, int l_num, double *p)
{
	*n = objs.sq[objs.near_obj_num].n;
	invert_vector(n, objs, l_num, p);
}

void			get_color_tr(t_objs objs, double *v, double *color, double *p)
{
	double	max[3];
	double	*n;
	int		is_dark;
	int		i;

	vec_init(max);
	vec_init(color);
	i = -1;
	while (++i < 3)
		color[i] += objs.a.ratio * objs.a.rgb[i];
	is_dark = 0;
	i = -1;
	while (++i < objs.num[h("l")])
	{
		is_dark = dark_from_others(objs, p, i);
		if (is_dark == 0)
		{
			get_tr_n(&n, objs, i, p);
			objs.cosa = dark_pl(objs.l[i].p, p, n);
			objs.cosg = mirror(objs.l[i].p, p, n, v);
			free(n);
			get_color_sub(objs, color, i);
		}
	}
}

void			get_color_sq(t_objs objs, double *v, double *color, double *p)
{
	double	max[3];
	double	*n;
	int		is_dark;
	int		i;

	vec_init(max);
	vec_init(color);
	is_dark = 0;
	i = -1;
	while (++i < 3)
		color[i] += objs.a.ratio * objs.a.rgb[i];
	i = -1;
	while (++i < objs.num[h("l")])
	{
		is_dark = dark_from_others(objs, p, i);
		if (is_dark == 0)
		{
			get_sq_n(&n, objs, i, p);
			objs.cosa = dark_pl(objs.l[i].p, p, n);
			objs.cosg = mirror(objs.l[i].p, p, n, v);
			get_color_sub(objs, color, i);
		}
	}
}
