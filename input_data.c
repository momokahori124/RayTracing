/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 17:10:50 by mhori             #+#    #+#             */
/*   Updated: 2020/10/12 18:48:56 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	check_data(t_objs *objs)
{
	int	display_size[2];

	if (objs->flag == 1)
		err_exit(objs->err_num, objs);
	mlx_get_screen_size(objs->mlx, &(display_size[0]), &(display_size[1]));
	if (objs->r.x > display_size[0])
		objs->r.x = display_size[0] - 30;
	if (objs->r.y > display_size[1])
		objs->r.y = display_size[1] - 50;
}

void	input_objs(t_objs *objs, char *s)
{
	if (ft_strncmp(s, "R", 1) == 0)
		input_r(s, objs);
	else if (ft_strncmp(s, "A", 1) == 0)
		input_a(s, objs);
	else if (ft_strncmp(s, "cy", 2) == 0)
		input_cy(s, objs);
	else if (ft_strncmp(s, "C", 1) == 0 ||
		ft_strncmp(s, "c", 1) == 0)
		input_c(s, objs);
	else if (ft_strncmp(s, "l", 1) == 0)
		input_l(s, objs);
	else if (ft_strncmp(s, "pl", 2) == 0)
		input_pl(s, objs);
	else if (ft_strncmp(s, "sp", 2) == 0)
		input_sp(s, objs);
	else if (ft_strncmp(s, "sq", 2) == 0)
		input_sq(s, objs);
	else if (ft_strncmp(s, "tr", 2) == 0)
		input_tr(s, objs);
}

void	input_free(t_objs *objs, char **line)
{
	input_objs(objs, *line);
	free(*line);
}

void	count_free(t_objs *objs, char **line)
{
	count_id(objs, *line);
	free(*line);
}

void	input_data(char *filename, t_objs *objs)
{
	int		fd;
	int		ret;
	char	*line;

	objs_num_init(objs);
	if ((fd = open(filename, O_RDONLY)) < 2)
		err_exit(CANT_OPEN_N, objs);
	while ((ret = get_next_line(fd, &line)) > 0)
		count_free(objs, &line);
	count_free(objs, &line);
	if (is_over_max(*objs) == 1)
		err_exit(ERR_OVER_MAX_N, objs);
	close(fd);
	if ((fd = open(filename, O_RDONLY)) < 2)
		err_exit(CANT_OPEN_N, objs);
	while ((ret = get_next_line(fd, &line)) > 0)
		input_free(objs, &line);
	input_free(objs, &line);
	close(fd);
	check_data(objs);
	return ;
}
