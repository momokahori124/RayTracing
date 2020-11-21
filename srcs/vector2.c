/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 16:58:43 by mhori             #+#    #+#             */
/*   Updated: 2020/09/12 18:59:14 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void			invert_vector(double **n, t_objs objs, int l_num, double *p)
{
	int		k;
	double	pl[3];
	double	v[3];

	vec_minus(v, objs.c[objs.c_num].p, p);
	vec_minus(pl, objs.l[l_num].p, p);
	if (inner_product(*n, v) < 0)
	{
		k = 0;
		while (k < 3)
		{
			(*n)[k] = (-1.0) * (*n)[k];
			k++;
		}
	}
}

double			max(double a, double b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

double			min(double a, double b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

void			dark_dup(int f, t_objs objs, double *color)
{
	int k;

	if (f >= 2)
	{
		k = 0;
		while (k < 3)
		{
			color[k] *= pow(objs.a.ratio, f - 1);
			k++;
		}
	}
}

void			set_base(double *x, double *y, double *z)
{
	x[0] = 1;
	x[1] = 0;
	x[2] = 0;
	y[0] = 0;
	y[1] = 1;
	y[2] = 0;
	z[0] = 0;
	z[1] = 0;
	z[2] = 1;
}
