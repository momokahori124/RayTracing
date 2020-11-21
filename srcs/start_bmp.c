/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_bmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 18:47:29 by mhori             #+#    #+#             */
/*   Updated: 2020/08/23 18:51:37 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void	my_mlx_put_to_bmp(char *name, t_objs objs)
{
	int				fd;
	unsigned int	size;
	void			*data;

	size = objs.r.x * objs.r.y * 3;
	data = malloc(size + HEADER_SIZE);
	if (!data)
		err_exit(ERR_MALLOC_N, &objs);
	insert_data(data, objs);
	if ((fd = open(name, O_CREAT | O_RDWR, 0644)) < 2)
		err_exit(CANT_OPEN_N, &objs);
	write(fd, data, size + HEADER_SIZE);
	free(data);
	close(fd);
}

int		mlx_bmp(t_objs objs)
{
	char	*name[10];
	int		i;

	set_name(name);
	i = 0;
	while (i < objs.num[h("C")])
	{
		objs.addr =
			mlx_get_data_addr(objs.img[i], &objs.bpp, \
			&objs.line, &objs.endian);
		my_mlx_put_to_bmp(name[i], objs);
		i++;
	}
	return (1);
}

int		start_bmp(t_objs objs)
{
	if (objs.rac != 1)
		return (-1);
	if (objs.error == 1)
		return (0);
	mlx_bmp(objs);
	return (1);
}
