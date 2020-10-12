/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:28:17 by mhori             #+#    #+#             */
/*   Updated: 2020/09/12 18:51:27 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	invert_vec(double **y)
{
	int k;

	k = 0;
	while (k < 3)
	{
		(*y)[k] = (-1) * (*y)[k];
		k++;
	}
}

void	get_screen_base(double **x, double **y, double *v)
{
	double	nx[3];
	double	ny[3];
	double	nz[3];

	set_base(nx, ny, nz);
	vec_times(-1, &v);
	if (v[2] != 0)
	{
		*x = cross_product(ny, v);
		*y = cross_product(v, *x);
	}
	else if (v[1] != 0)
	{
		*x = cross_product(nz, v);
		*y = cross_product(v, *x);
	}
	else if (v[0] != 0)
	{
		*x = cross_product(ny, v);
		*y = cross_product(v, *x);
	}
	unit_vector(*x);
	unit_vector(*y);
	invert_vec(y);
}

void	get_screen_center(double *p, t_objs objs)
{
	int	k;

	k = 0;
	while (k < 3)
	{
		p[k] = objs.c[objs.c_num].p[k] + objs.c[objs.c_num].n[k] * 1;
		k++;
	}
}

void	get_screen_start(double *p0, double *p, t_objs objs, double fov)
{
	int	k;

	k = 0;
	while (k < 3)
	{
		p0[k] = p[k] - 1 * tan(fov / 2) * objs.base_x[k]
			+ (double)objs.r.y / objs.r.x * 1 * tan(fov / 2) * objs.base_y[k];
		k++;
	}
}

void	get_screen(int i, int j, double *screen, t_objs objs)
{
	double	fov;
	double	p[3];
	double	v[3];
	double	p0[3];
	int		k;

	fov = objs.c[objs.c_num].degree * acos(-1) / 180;
	get_screen_center(p, objs);
	vec_minus(v, objs.c[objs.c_num].p, p);
	get_screen_base(&(objs.base_x), &(objs.base_y), v);
	get_screen_start(p0, p, objs, fov);
	k = 0;
	while (k < 3)
	{
		screen[k] = p0[k] + 2 * tan(fov / 2) / objs.r.x * i * (objs.base_x)[k]
			- 2 * tan(fov / 2) / objs.r.x * j * (objs.base_y)[k];
		k++;
	}
	free(objs.base_x);
	free(objs.base_y);
}
