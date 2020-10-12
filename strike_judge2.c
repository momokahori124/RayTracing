/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strike_judge2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:11:13 by mhori             #+#    #+#             */
/*   Updated: 2020/08/25 17:27:34 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	get_base_vector(double **a, double **b, t_objs *objs, int num)
{
	double	x[3];
	double	y[3];
	double	z[3];

	set_base(x, y, z);
	if (objs->sq[num].n[2] != 0)
	{
		*a = cross_product(x, objs->sq[num].n);
		*b = cross_product(y, objs->sq[num].n);
	}
	else if (objs->sq[num].n[0] != 0)
	{
		*a = cross_product(y, objs->sq[num].n);
		*b = cross_product(z, objs->sq[num].n);
	}
	else if (objs->sq[num].n[1] != 0)
	{
		*a = cross_product(z, objs->sq[num].n);
		*b = cross_product(x, objs->sq[num].n);
	}
	unit_vector(*a);
	unit_vector(*b);
}

int		judge_for_sq(double *v, t_objs *objs, int num, double *t)
{
	double		*a;
	double		*b;
	double		r[3];
	double		u[2];
	double		*tmp[2];

	get_base_vector(&a, &b, objs, num);
	vec_minus(r, objs->c[objs->c_num].p, objs->sq[num].p);
	tmp[0] = cross_product(r, a);
	tmp[1] = cross_product(v, b);
	*t = inner_product(tmp[0], b);
	*t /= inner_product(tmp[1], a);
	u[0] = inner_product(tmp[1], r);
	u[0] /= inner_product(tmp[1], a);
	u[1] = inner_product(tmp[0], v);
	u[1] /= inner_product(tmp[1], a);
	free_ab(tmp[0], tmp[1]);
	vec_times(u[0], &a);
	vec_times(u[1], &b);
	if (*t >= 0 && vec_norm(a) < objs->sq[num].side
		&& vec_norm(b) < objs->sq[num].side)
		return (free_ab(a, b));
	free_ab(a, b);
	return (0);
}

int		strike_judge_sq(t_objs *objs, double *v)
{
	int		ret;
	int		i;
	double	t_tmp;

	i = 0;
	while (i < objs->num[h("sq")])
	{
		if (judge_for_sq(v, objs, i, &t_tmp) > 0)
		{
			ret = 1;
			if (objs->t_min >= t_tmp && t_tmp >= 0)
			{
				objs->near_obj_num = i;
				objs->near_obj = h("sq");
				objs->t_min = t_tmp;
				array_dup(objs->sq[i].rgb, objs->near_color);
			}
		}
		i++;
	}
	return (ret);
}

int		strike_judge(t_objs *objs, double *v)
{
	int		ret;

	objs->t_min = 1.0 / 0.0;
	ret = 0;
	ret = strike_judge_sp(objs, v);
	ret = strike_judge_pl(objs, v);
	ret = strike_judge_cy(objs, v);
	ret = strike_judge_tr(objs, v);
	ret = strike_judge_sq(objs, v);
	return (ret);
}

void	input_t(t_objs *objs, int i, double t_tmp)
{
	objs->near_obj_num = i;
	objs->near_obj = h("sp");
	objs->t_min = t_tmp;
}
