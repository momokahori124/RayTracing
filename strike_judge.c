/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strike_judge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 13:07:38 by mhori             #+#    #+#             */
/*   Updated: 2020/08/25 17:27:25 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		strike_judge_sp(t_objs *objs, double *v)
{
	int		ret;
	int		i;
	double	t_tmp;
	double	*tmp;

	ret = 0;
	i = 0;
	while (i < objs->num[h("sp")])
	{
		if (d_for_sp(v, objs->c[objs->c_num].p,
						objs->sp[i].p, objs->sp[i].r) >= 0)
		{
			tmp = get_inter_for_sp(v, objs->c[objs->c_num].p, \
			objs->sp[i], &t_tmp);
			free(tmp);
			if (objs->t_min >= t_tmp && t_tmp >= 0)
			{
				input_t(objs, i, t_tmp);
				array_dup(objs->sp[i].rgb, objs->near_color);
			}
			ret = 1;
		}
		i++;
	}
	return (ret);
}

int		judge_for_pl(double *v, t_objs *objs, int num)
{
	double t;
	double vv[3];

	vec_minus(vv, objs->pl[num].p, objs->c[objs->c_num].p);
	if (inner_product(v, objs->pl[num].n) == 0)
		return (0);
	t = inner_product(objs->pl[num].n, vv) / inner_product(v, objs->pl[num].n);
	if (t > 0)
		return (1);
	else
		return (0);
}

int		strike_judge_pl(t_objs *objs, double *v)
{
	int			ret;
	int			i;
	double		t_tmp;
	double		*tmp;

	i = 0;
	while (i < objs->num[h("pl")])
	{
		if (judge_for_pl(v, objs, i) > 0)
		{
			ret = 1;
			tmp = get_inter_for_pl(v, objs, &t_tmp, i);
			free(tmp);
			if (objs->t_min >= t_tmp && t_tmp >= 0)
			{
				objs->near_obj_num = i;
				objs->near_obj = h("pl");
				objs->t_min = t_tmp;
				array_dup(objs->pl[i].rgb, objs->near_color);
			}
		}
		i++;
	}
	return (ret);
}

double	*get_inter_for_tr(double *v, t_objs *objs, double *t_tmp, int num)
{
	double		*ret;
	double		r[3];
	int			k;

	ret = malloc(sizeof(double) * 3);
	if (!ret)
		err_exit(ERR_MALLOC_N);
	vec_minus(r, objs->c[objs->c_num].p, objs->tr[num].a);
	vec_minus(objs->tr_e1, objs->tr[num].b, objs->tr[num].a);
	vec_minus(objs->tr_e2, objs->tr[num].c, objs->tr[num].a);
	array_dup(v, objs->v);
	get_tr_t_tmp(r, objs, t_tmp);
	k = 0;
	while (k < 3)
	{
		ret[k] = objs->c[objs->c_num].p[k] + *t_tmp * v[k];
		k++;
	}
	return (ret);
}

int		judge_for_tr_new(double *p, double *v, t_objs *objs, int num)
{
	double	t[3];
	double	r[3];

	vec_minus(r, p, objs->tr[num].a);
	vec_minus(objs->tr_e1, objs->tr[num].b, objs->tr[num].a);
	vec_minus(objs->tr_e2, objs->tr[num].c, objs->tr[num].a);
	get_tr_t(t, objs, v, r);
	if (t[0] >= 0 && t[1] >= 0 && t[2] >= 0 && t[1] + t[2] <= 1)
		return (1);
	else
		return (0);
}
