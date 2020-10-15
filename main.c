/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 15:58:43 by mhori             #+#    #+#             */
/*   Updated: 2020/10/12 18:28:48 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int			check_file_name(char *s)
{
	char *tmp;

	tmp = ft_substr(s, ft_strlen(s) - 3, 3);
	if (ft_strncmp(tmp, ".rt", 3) == 0)
	{
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}

void		check_vector_norm(double *v)
{
	if (vec_norm(v) == 0)
		err_exit(ERR_VECTOR_N);
}

void		create_images(t_objs *objs)
{
	int i;

	objs->mlx = mlx_init();
	objs->mlx_win =
		mlx_new_window(objs->mlx, objs->r.x, objs->r.y, "window");
	i = 0;
	objs->addr = NULL;
	while (i < objs->num[h("C")])
	{
		objs->img[i] =
			mlx_new_image(objs->mlx, objs->r.x, objs->r.y);
		objs->addr =
			mlx_get_data_addr(objs->img[i], &objs->bpp, \
			&objs->line, &objs->endian);
		objs->c_num = i;
		ft_mlx(objs, i);
		i++;
	}
}

void		free_members(t_objs *objs)
{
	int i;

	mlx_destroy_window(objs->mlx, objs->mlx_win);
	i = -1;
	while (++i < objs->num[h("C")])
		mlx_destroy_image(objs->mlx, objs->img[i]);
}

int			main(int argc, char *argv[])
{
	t_objs		objs;

	objs = (t_objs){0};
	if (argc < 2 || argc > 3)
		err_exit(ERR_WRONG_NUMBER_ARGUMENT_N);
	if (check_file_name(argv[1]) == 0)
		err_exit(ERR_INVALID_FILE_N);
	if (argc == 3 && (ft_strncmp(argv[2], "--save", 6) != 0
		|| ft_strlen(argv[2]) != 6))
		err_exit(ERR_WRONG_OPTION_N);
	input_data(argv[1], &objs);
	input_error(objs);
	create_images(&objs);
	if (argc == 2)
		start_window(objs);
	if (argc == 3)
		start_bmp(objs);
	free_members(&objs);
	while (1);
	return (0);
}
