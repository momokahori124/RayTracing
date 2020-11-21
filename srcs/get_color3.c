/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 15:36:17 by mhori             #+#    #+#             */
/*   Updated: 2020/09/13 15:36:28 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void			get_center_cy(t_objs objs, double *p, double *c)
{
	double	t;
	int		k;
	int		num;

	num = objs.near_obj_num;
	t = inner_product(p, objs.cy[num].n) -
		inner_product(objs.cy[num].p, objs.cy[num].n);
	t /= inner_product(objs.cy[num].n, objs.cy[num].n);
	k = 0;
	while (k < 3)
	{
		c[k] = objs.cy[num].p[k] + t * objs.cy[num].n[k];
		k++;
	}
}

void			get_cy_body_cos(t_objs *objs, int i, double *c, double *v)
{
	int			k;
	double		n[3];

	k = -1;
	while (++k < 3)
		n[k] = (objs->p)[k] - c[k];
	objs->cosa = dark(objs->l[i].p, objs->p, c);
	objs->cosg = mirror(objs->l[i].p, objs->p, n, v);
}

void			get_cy_cap_bot_cos(t_objs *objs, int i, double *v)
{
	double		n[3];
	int			k;

	k = -1;
	while (++k < 3)
		n[k] = objs->cy[objs->near_obj_num].n[k] * -1;
	objs->cosa = dark_pl(objs->l[i].p, objs->p, n);
	objs->cosg = mirror(objs->l[i].p, objs->p, n, v);
}

void			get_cy_cap_top_cos(t_objs *objs, double *v, int i)
{
	objs->cosa = dark_pl(objs->l[i].p, objs->p,
						objs->cy[objs->near_obj_num].n);
	objs->cosg = mirror(objs->l[i].p, objs->p,
						objs->cy[objs->near_obj_num].n, v);
}

void			get_cy_cos(t_objs *objs, int i, double *v, double *c)
{
	double		s[3];

	if (cy_body(v, objs, objs->near_obj_num, &s[0]) == 1)
		get_cy_body_cos(objs, i, c, v);
	else if (cy_cap_top(v, objs, objs->near_obj_num, &s[1]) == 1)
		get_cy_cap_top_cos(objs, v, i);
	else if (cy_cap_bot(v, objs, objs->near_obj_num, &s[2]) == 1)
		get_cy_cap_bot_cos(objs, i, v);
}
