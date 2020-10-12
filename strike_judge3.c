/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strike_judge3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 14:36:32 by mhori             #+#    #+#             */
/*   Updated: 2020/08/25 17:20:13 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	get_base_sq(double **a, double **b, t_objs *objs, int num)
{
	double	x[3];
	double	y[3];
	double	z[3];

	set_base(x, y, z);
	*a = NULL;
	*b = NULL;
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

int		judge_for_sq_new(double *p, double *v, t_objs *objs, int num)
{
	double		t[5];
	double		*a;
	double		*b;
	double		r[3];
	double		*tmp[2];

	get_base_sq(&a, &b, objs, num);
	vec_minus(r, p, objs->sq[num].p);
	tmp[0] = cross_product(r, a);
	tmp[1] = cross_product(v, b);
	t[0] = inner_product(tmp[0], b);
	t[0] /= inner_product(tmp[1], a);
	t[1] = inner_product(tmp[1], r);
	t[1] /= inner_product(tmp[1], a);
	t[2] = inner_product(tmp[0], v);
	t[2] /= inner_product(tmp[1], a);
	free_ab(tmp[0], tmp[1]);
	vec_times(t[1], &a);
	vec_times(t[2], &b);
	t[3] = vec_norm(a);
	t[4] = vec_norm(b);
	free_ab(a, b);
	if (t[0] >= 0 && t[3] < objs->sq[num].side && t[4] < objs->sq[num].side)
		return (1);
	return (0);
}

int		judge_for_tr(double *v, t_objs *objs, int num)
{
	double		t[3];
	double		r[3];
	double		e1[3];
	double		e2[3];
	double		*tmp[2];

	vec_minus(r, objs->c[objs->c_num].p, objs->tr[num].a);
	vec_minus(e1, objs->tr[num].b, objs->tr[num].a);
	vec_minus(e2, objs->tr[num].c, objs->tr[num].a);
	tmp[0] = cross_product(r, e1);
	tmp[1] = cross_product(v, e2);
	t[0] = inner_product(tmp[0], e2);
	t[0] /= inner_product(tmp[1], e1);
	t[1] = inner_product(tmp[1], r);
	t[1] /= inner_product(tmp[1], e1);
	t[2] = inner_product(tmp[0], v);
	t[2] /= inner_product(tmp[1], e1);
	free_ab(tmp[0], tmp[1]);
	if (t[0] >= 0 && t[1] >= 0 && t[2] >= 0 && t[1] + t[2] <= 1)
		return (1);
	else
		return (0);
}

int		strike_judge_tr(t_objs *objs, double *v)
{
	int			ret;
	int			i;
	double		t_tmp;
	double		*tmp;

	i = 0;
	while (i < objs->num[h("tr")])
	{
		if (judge_for_tr(v, objs, i) > 0)
		{
			ret = 1;
			tmp = get_inter_for_tr(v, objs, &t_tmp, i);
			free(tmp);
			if (objs->t_min >= t_tmp && t_tmp >= 0)
			{
				objs->near_obj_num = i;
				objs->near_obj = h("tr");
				objs->t_min = t_tmp;
				array_dup(objs->tr[i].rgb, objs->near_color);
			}
		}
		i++;
	}
	return (ret);
}

double	*get_inter_for_sq(double *v, t_objs *objs, double *t, int num)
{
	double	*ret;
	int		k;

	ret = malloc(sizeof(double) * 3);
	if (!ret)
		err_exit(ERR_MALLOC_N);
	judge_for_sq(v, objs, num, t);
	k = 0;
	while (k < 3)
	{
		ret[k] = objs->c[objs->c_num].p[k] + *t * v[k];
		k++;
	}
	return (ret);
}
