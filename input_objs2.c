/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_objs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 13:26:22 by mhori             #+#    #+#             */
/*   Updated: 2020/09/11 17:46:03 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	input_sp(char *s, t_objs *objs)
{
	static int	i;
	int			f;

	f = 0;
	objs->sp[i].num = objs->num[h("sp")];
	s += 2;
	skip_white_space(&s);
	f += get_coordinate(&s, objs->sp[i].p);
	skip_white_space(&s);
	f += get_double(&s, &(objs->sp[i].r));
	objs->sp[i].r /= 2;
	skip_white_space(&s);
	f += get_coordinate(&s, objs->sp[i].rgb);
	i++;
	if (f != 7)
	{
		objs->err_num = ERR_SP_N;
		objs->flag = 1;
	}
}

void	input_sq(char *s, t_objs *objs)
{
	static int	i;
	int			f;

	f = 0;
	objs->sq[i].num = objs->num[h("sq")];
	s += 2;
	skip_white_space(&s);
	f += get_coordinate(&s, objs->sq[i].p);
	skip_white_space(&s);
	f += get_coordinate(&s, objs->sq[i].n);
	check_vector_norm(objs->sq[i].n);
	skip_white_space(&s);
	f += get_double(&s, &(objs->sq[i].side));
	skip_white_space(&s);
	f += get_coordinate(&s, objs->sq[i].rgb);
	i++;
	if (f != 10)
	{
		objs->err_num = ERR_SQ_N;
		objs->flag = 1;
	}
}

void	input_tr(char *s, t_objs *objs)
{
	static int	i;
	int			f;

	f = 0;
	objs->tr[i].num = objs->num[h("tr")];
	s += 2;
	skip_white_space(&s);
	f += get_coordinate(&s, objs->tr[i].a);
	skip_white_space(&s);
	f += get_coordinate(&s, objs->tr[i].b);
	skip_white_space(&s);
	f += get_coordinate(&s, objs->tr[i].c);
	skip_white_space(&s);
	f += get_coordinate(&s, objs->tr[i].rgb);
	i++;
	if (f != 12)
	{
		objs->err_num = ERR_TR_N;
		objs->flag = 1;
	}
}

void	input_pl(char *s, t_objs *objs)
{
	static int	i;
	int			f;

	f = 0;
	objs->pl[i].num = objs->num[h("pl")];
	s += 2;
	skip_white_space(&s);
	f += get_coordinate(&s, objs->pl[i].p);
	skip_white_space(&s);
	f += get_coordinate(&s, objs->pl[i].n);
	skip_white_space(&s);
	f += get_coordinate(&s, objs->pl[i].rgb);
	i++;
	if (f != 9)
	{
		objs->err_num = ERR_PL_N;
		objs->flag = 1;
	}
}
