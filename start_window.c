/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 13:21:34 by mhori             #+#    #+#             */
/*   Updated: 2020/10/12 17:39:04 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void		my_mlx_pixel_put(t_objs *objs, int x, int y, int color)
{
	char	*dst;

	dst = objs->addr + (y * objs->line + x * (objs->bpp / 8));
	*(unsigned int*)dst = color;
}

int			handle_key(int k, t_objs *objs)
{
	static int i;

	if (k == 53)
		return (exit_program(objs));
	if (k == KEYCODE_RIGHT)
		i++;
	if (!(k == 53 || k == KEYCODE_RIGHT))
		err_exit(ERR_KEY_N, objs);
	if (i < objs->num[h("C")])
	{
		mlx_clear_window(objs->mlx, objs->mlx_win);
		mlx_put_image_to_window(objs->mlx, objs->mlx_win, objs->img[i], 0, 0);
	}
	else
		err_exit(FINISH_N, objs);
	return (0);
}

int			exit_program(t_objs *objs)
{
	free_members(objs);
	exit(0);
	return (0);
}

void		mlx_main(t_objs objs)
{
	int num;

	num = 0;
	mlx_clear_window(objs.mlx, objs.mlx_win);
	mlx_put_image_to_window(objs.mlx, objs.mlx_win, objs.img[num], 0, 0);
	mlx_hook(objs.mlx_win, 2, 1L << 0, handle_key, &objs);
	mlx_hook(objs.mlx_win, 17, 1L << 17, exit_program, &objs);
	mlx_loop(objs.mlx);
}

int			start_window(t_objs objs)
{
	objs.mlx_win =
		mlx_new_window(objs.mlx, objs.r.x, objs.r.y, "window");
	if (objs.error == 1)
		err_exit(ERR_WRONG_INPUT_N, &objs);
	mlx_main(objs);
	return (1);
}
