/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_objs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 19:16:25 by mhori             #+#    #+#             */
/*   Updated: 2020/10/16 13:24:48 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	input_r(char *s, t_objs *objs)
{
	int	f[2];

	s++;
	ft_bzero(f, sizeof(int) * 2);
	skip_white_space(&s);
	objs->r.x = 0;
	objs->r.y = 0;
	while ('0' <= *s && *s <= '9')
	{
		f[0] = 1;
		objs->r.x = objs->r.x * 10 + *s - '0';
		s++;
	}
	skip_white_space(&s);
	while ('0' <= *s && *s <= '9')
	{
		f[1] = 1;
		objs->r.y = objs->r.y * 10 + *s - '0';
		s++;
	}
	if (!(f[0] && f[1]) || *s)
	{
		objs->err_num = ERR_R_N;
		objs->flag = 1;
	}
}

void	input_a(char *s, t_objs *objs)
{
	int	f;

	f = 0;
	s++;
	skip_white_space(&s);
	f += get_double(&s, &(objs->a.ratio));
	skip_white_space(&s);
	f += get_coordinate(&s, objs->a.rgb);
	skip_white_space(&s);
	if (f != 4 || *s)
	{
		objs->err_num = ERR_A_N;
		objs->flag = 1;
	}
}

void	input_cy(char *s, t_objs *objs)
{
	static int	i;
	int			f;

	f = 0;
	objs->cy[i].num = objs->num[h("cy")];
	s += 2;
	skip_white_space(&s);
	f += get_coordinate(&s, objs->cy[i].p);
	skip_white_space(&s);
	f += get_coordinate(&s, objs->cy[i].n);
	check_vector_norm(objs->cy[i].n);
	skip_white_space(&s);
	f += get_double(&s, &(objs->cy[i].r));
	skip_white_space(&s);
	f += get_double(&s, &(objs->cy[i].h));
	skip_white_space(&s);
	f += get_coordinate(&s, objs->cy[i].rgb);
	i++;
	skip_white_space(&s);
	if (f != 11 || *s)
	{
		objs->err_num = ERR_CY_N;
		objs->flag = 1;
	}
}

void	input_c(char *s, t_objs *objs)
{
	static int	i;
	int			f;

	objs->c[i].num = objs->num[h("C")];
	s += 1;
	f = 0;
	skip_white_space(&s);
	f += get_coordinate(&s, objs->c[i].p);
	skip_white_space(&s);
	f += get_coordinate(&s, objs->c[i].n);
	check_vector_norm(objs->c[i].n);
	skip_white_space(&s);
	f += get_double(&s, &(objs->c[i].degree));
	i++;
	skip_white_space(&s);
	if (f != 7 || *s)
	{
		objs->err_num = ERR_C_N;
		objs->flag = 1;
	}
}

void	input_l(char *s, t_objs *objs)
{
	static int	i;
	int			f;

	f = 0;
	objs->l[i].num = objs->num[h("l")];
	s++;
	skip_white_space(&s);
	f += get_coordinate(&s, objs->l[i].p);
	skip_white_space(&s);
	f += get_double(&s, &(objs->l[i].ratio));
	skip_white_space(&s);
	f += get_coordinate(&s, objs->l[i].rgb);
	i++;
	skip_white_space(&s);
	if (f != 7 || *s)
	{
		objs->err_num = ERR_L_N;
		objs->flag = 1;
	}
}
