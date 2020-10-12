/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 15:06:17 by mhori             #+#    #+#             */
/*   Updated: 2020/08/25 22:17:08 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void		get_view_vector(t_objs *objs, double *v, int c_num)
{
	v[0] = objs->screen[0] - objs->c[c_num].p[0];
	v[1] = objs->screen[1] - objs->c[c_num].p[1];
	v[2] = objs->screen[2] - objs->c[c_num].p[2];
}

void		put_color(t_objs *objs, int ret, int i, int j)
{
	if (ret == 1)
	{
		get_color(*objs, objs->v, objs->color);
		my_mlx_pixel_put(objs, i, j, \
			rgb_to_int(objs->color[0], objs->color[1], objs->color[2]));
	}
	else
		my_mlx_pixel_put(objs, i, j, rgb_to_int(50, 50, 50));
}

void		ft_mlx(t_objs *objs, int c_num)
{
	int		i;
	int		j;
	int		ret;

	i = 0;
	while (i < objs->r.x)
	{
		j = 0;
		while (j < objs->r.y)
		{
			vec_init(objs->color);
			get_screen(i, j, objs->screen, *objs);
			get_view_vector(objs, objs->v, c_num);
			ret = 0;
			ret = strike_judge(objs, objs->v);
			put_color(objs, ret, i, j);
			j++;
		}
		i++;
	}
}
