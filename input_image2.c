/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_image2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 18:17:37 by mhori             #+#    #+#             */
/*   Updated: 2020/08/23 18:34:39 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

double		mirror(double *lp, double *p, double *n, double *v)
{
	double		cosg;
	double		vr[3];
	double		w;
	double		vl[3];
	int			k;

	vec_minus(vl, p, lp);
	w = -inner_product(vl, n) / inner_product(n, n);
	k = 0;
	while (k < 3)
	{
		vr[k] = 2 * w * n[k] + vl[k];
		k++;
	}
	cosg = -inner_product(vr, v) /
		sqrt(inner_product(vr, vr) * inner_product(v, v));
	if (cosg < 0)
		cosg = 0;
	cosg = pow(cosg, 10);
	return (cosg);
}

double		*get_inter_for_pl(double *v, t_objs *objs, double *t_tmp, int num)
{
	double	*ret;
	int		i;
	double	vv[3];

	ret = malloc(sizeof(double) * 3);
	if (!ret)
		err_exit(ERR_MALLOC_N);
	vec_minus(vv, objs->pl[num].p, objs->c[objs->c_num].p);
	*t_tmp = inner_product(objs->pl[num].n, vv) /
	inner_product(v, objs->pl[num].n);
	i = 0;
	while (i < 3)
	{
		ret[i] = objs->c[objs->c_num].p[i] + *t_tmp * v[i];
		i++;
	}
	return (ret);
}

void		get_p(double **p, t_objs objs, double *v)
{
	double	t;

	t = 0;
	if (objs.near_obj == h("sp"))
		*p = get_inter_for_sp(v, objs.c[objs.c_num].p,
			objs.sp[objs.near_obj_num], &t);
	else if (objs.near_obj == h("pl"))
		*p = get_inter_for_pl(v, &objs, &t, objs.near_obj_num);
	else if (objs.near_obj == h("cy"))
	{
		*p = get_inter_for_cy(v, &objs, &t, objs.near_obj_num);
	}
	else if (objs.near_obj == h("tr"))
		*p = get_inter_for_tr(v, &objs, &t, objs.near_obj_num);
	else if (objs.near_obj == h("sq"))
		*p = get_inter_for_sq(v, &objs, &t, objs.near_obj_num);
}

void		get_color(t_objs objs, double *v, double *color)
{
	double	*p;

	get_p(&p, objs, v);
	if (objs.near_obj == h("sp"))
		get_color_sp(objs, v, color, p);
	else if (objs.near_obj == h("pl"))
		get_color_pl(objs, v, color, p);
	else if (objs.near_obj == h("cy"))
		get_color_cy(objs, v, color, p);
	else if (objs.near_obj == h("tr"))
		get_color_tr(objs, v, color, p);
	else if (objs.near_obj == h("sq"))
		get_color_sq(objs, v, color, p);
	free(p);
}
