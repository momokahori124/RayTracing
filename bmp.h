/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:56:45 by mhori             #+#    #+#             */
/*   Updated: 2020/10/12 17:38:39 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

int		start_bmp(t_objs objs);
int		mlx_bmp(t_objs objs);
void	insert_data(char *data, t_objs objs);
void	insert_header(char *data, int width, int height);
void	set_name(char **name);
void	my_mlx_put_to_bmp(char *name, t_objs objs);
int		exit_program(t_objs *objs);
int		handle_key(int keycode, t_objs *objs);

#endif
