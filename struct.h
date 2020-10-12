/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:53:28 by mhori             #+#    #+#             */
/*   Updated: 2020/09/12 18:29:38 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# define MAX 25

typedef struct	s_r
{
	int	x;
	int	y;
}				t_r;
typedef struct	s_a
{
	double	ratio;
	double	rgb[3];
}				t_a;
typedef struct	s_c
{
	int		num;
	double	p[3];
	double	n[3];
	double	degree;
}				t_c;
typedef struct	s_l
{
	int		num;
	double	p[3];
	double	ratio;
	double	rgb[3];
}				t_l;
typedef struct	s_sp
{
	int		num;
	double	p[3];
	double	r;
	double	rgb[3];
}				t_sp;
typedef struct	s_pl
{
	int		num;
	double	p[3];
	double	n[3];
	double	rgb[3];
}				t_pl;
typedef struct	s_sq
{
	int		num;
	double	p[3];
	double	n[3];
	double	side;
	double	rgb[3];
	double	*a;
	double	*b;
}				t_sq;
typedef struct	s_cy
{
	int		num;
	double	p[3];
	double	n[3];
	double	r;
	double	h;
	double	rgb[3];
}				t_cy;
typedef struct	s_tr
{
	int			num;
	double		a[3];
	double		b[3];
	double		c[3];
	double		rgb[3];
}				t_tr;
typedef struct	s_objs
{
	int			near_obj;
	int			near_obj_num;
	void		*mlx;
	void		*mlx_win;
	void		*img[MAX];
	char		*addr;
	int			bpp;
	int			line;
	int			endian;
	int			c_num;
	int			num[7];
	int			error;
	int			rac;
	int			dark_from_others_flag;
	double		t_min;
	double		screen[3];
	double		color[3];
	double		near_color[3];
	double		v[3];
	double		p[3];
	double		inter[3];
	double		n[3];
	double		ofs[3];
	double		*base_x;
	double		*base_y;
	double		cosa;
	double		cosg;
	double		rgb[3];
	double		tr_e1[3];
	double		tr_e2[3];
	int			flag;
	int			err_num;
	t_r			r;
	t_a			a;
	t_c			c[MAX];
	t_l			l[MAX];
	t_sp		sp[MAX];
	t_pl		pl[MAX];
	t_sq		sq[MAX];
	t_cy		cy[MAX];
	t_tr		tr[MAX];
}				t_objs;
#endif
