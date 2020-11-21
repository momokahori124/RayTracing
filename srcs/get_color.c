/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 11:54:45 by mhori             #+#    #+#             */
/*   Updated: 2020/10/12 16:33:08 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void			get_color_objs(t_objs *objs, double *obj_p,
	double *obj_rgb, double *color)
{
	int		i;

	if (obj_rgb == NULL)
		return ;
	i = -1;
	while (++i < 3)
		color[i] += objs->a.ratio * objs->a.rgb[i];
	i = -1;
	while (++i < objs->num[h("l")])
	{
		objs->dark_from_others_flag = dark_from_others(*objs, obj_p, i);
		if (objs->dark_from_others_flag == 0)
		{
			objs->cosa = dark(objs->l[i].p, objs->p, obj_p);
			objs->cosg = mirror(objs->l[i].p, objs->p, objs->n, objs->v);
			get_color_sub(*objs, color, i);
		}
	}
}

void			get_color_sp(t_objs objs, double *v, double *color, double *p)
{
	int			k;
	double		n[3];

	k = 0;
	while (k < 3)
	{
		n[k] = p[k] - objs.sp[objs.near_obj_num].p[k];
		k++;
	}
	vec_init(color);
	array_dup(v, objs.v);
	array_dup(n, objs.n);
	array_dup(p, objs.p);
	get_color_objs(&objs, objs.sp[objs.near_obj_num].p,
		objs.sp[objs.near_obj_num].rgb, color);
}

void			get_pl_n(double **n, t_objs objs, int l_num, double *p)
{
	*n = objs.pl[objs.near_obj_num].n;
	invert_vector(n, objs, l_num, p);
}

void			get_color_sub(t_objs objs, double *color, int i)
{
	int		k;

	k = -1;
	while (++k < 3)
	{
		color[k] += objs.near_color[k] * MAAX(0, objs.cosa);
		color[k] += objs.l[i].rgb[k] * objs.cosg * objs.l[i].ratio;
	}
}

void			get_color_pl(t_objs objs, double *v, double *color, double *p)
{
	double	max[3];
	double	*n;
	int		i;
	int		is_dark;

	is_dark = 0;
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
			get_pl_n(&n, objs, i, p);
			objs.cosa = dark_pl(objs.l[i].p, p, n);
			objs.cosg = mirror(objs.l[i].p, p, n, v);
			get_color_sub(objs, color, i);
		}
	}
}
