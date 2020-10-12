/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 19:00:10 by mhori             #+#    #+#             */
/*   Updated: 2020/10/12 17:31:41 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include <stdio.h>
# include <math.h>
# include "minilibx_mms_20200219/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include "GNL_success/get_next_line.h"
# include <fcntl.h>
# include "Libft/libft.h"
# include <limits.h>
# include "error.h"
# include "keycode.h"
# include "struct.h"
# include "bmp.h"
# include "cylinder.h"
# define HEADER_SIZE 122
# define PI acos(-1);
# define MAAX(a, b) ((a > b) ? a : b)

int			is_out_of_range(t_objs objs);
double		inner_product(double a[3], double b[3]);
double		*cross_product(double a[3], double b[3]);
void		cross_product2(double ret[3], double a[3], double b[3]);
int			rgb_to_int(int r, int b, int g);
void		input_t(t_objs *objs, int i, double t_tmp);
void		input_error(t_objs objs);
int			get_next_line(int fd, char **line);
int			vec_equal(double a[3], double b[3]);
void		input_r(char *s, t_objs *objs);
void		input_a(char *s, t_objs *objs);
void		input_c(char *s, t_objs *objs);
void		input_l(char *s, t_objs *objs);
void		free_members(t_objs *objs);
void		input_sp(char *s, t_objs *objs);
void		input_pl(char *s, t_objs *objs);
void		input_sq(char *s, t_objs *objs);
void		input_cy(char *s, t_objs *objs);
void		input_tr(char *s, t_objs *objs);
void		input_objs(t_objs *objs, char *s);
void		data_check(t_objs objs);
void		check_vector_norm(double *v);
void		input_data(char *filename, t_objs *objs);
void		input_info(char *s, t_objs *objs);
int			get_coordinate(char **s, double *r);
int			get_double(char **s, double *d);
void		skip_white_space(char **s);
int			ft_isspace(char c);
int			h(char *s);
void		fill_null(t_objs *objs);
void		count_id(t_objs	*objs, char *s);
void		new_get_coordinate(char **s, double *r);
void		nnn(char **s, t_objs *objs);
int			rgb_to_int(int r, int b, int g);
int			start_window(t_objs objs);
void		get_color_sp(t_objs objs, double *v, double *color, double *p);
void		get_color_pl(t_objs objs, double *v, double *color, double *p);
void		get_color_cy(t_objs objs, double *v, double *color, double *p);
void		get_color_tr(t_objs objs, double *v, double *color, double *p);
void		get_color_sq(t_objs objs, double *v, double *color, double *p);
void		get_color(t_objs objs, double *v, double *color);
double		dark(double *lp, double *p, double *cp);
double		mirror(double *lp, double *p, double *n, double *v);
double		dark_pl(double *lp, double *p, double *n);
int			dark_sp(t_objs objs, double *p, double *v);
int			dark_tr(t_objs objs, double *p, double *v);
int			dark_sq(t_objs objs, double *p, double *v);
int			dark_cy(t_objs objs, double *p, double *v);
int			strike_judge_sp(t_objs *objs, double *v);
int			strike_judge(t_objs *objs, double *v);
int			strike_judge_pl(t_objs *objs, double *v);
int			judge_for_pl(double *v, t_objs *objs, int num);
double		*get_inter_for_sq(double *v, t_objs *objs, double *t, int num);
int			strike_judge_tr(t_objs *objs, double *v);
int			judge_for_tr(double *v, t_objs *objs, int num);
int			judge_for_sq_new(double *p, double *v, t_objs *objs, int num);
void		get_base_sq(double **a, double **b, t_objs *objs, int num);
void		set_base(double *x, double *y, double *z);
int			judge_for_tr_new(double *p, double *v, t_objs *objs, int num);
int			strike_judge_pl(t_objs *objs, double *v);
int			judge_for_pl(double *v, t_objs *objs, int num);
int			strike_judge_sp(t_objs *objs, double *v);
int			strike_judge(t_objs *objs, double *v);
int			judge_for_tr(double *v, t_objs *objs, int num);
int			strike_judge_tr(t_objs *objs, double *v);
int			judge_for_tr_new(double *p, double *v, t_objs *objs, int num);
int			judge_for_sq_new(double *p, double *v, t_objs *objs, int num);
int			judge_for_sq(double *v, t_objs *objs, int num, double *t);
void		vec_init(double *v);
void		vec_minus(double *v, double *a, double *b);
double		vec_norm(double *v);
void		vec_times(double a, double **v);
void		invert_vector(double **n, t_objs objs, int l_num, double *p);
void		unit_vector(double *v);
void		set_base_vector(double **x, double **y, double **z);
void		invert_vector(double **n, t_objs objs, int l_num, double *p);
void		count_id(t_objs *objs, char *s);
int			h(char *s);
void		err_exit_sub2(int n);
void		objs_num_init(t_objs *objs);
int			strike_judge_tr(t_objs *objs, double *v);
int			judge_for_tr(double *v, t_objs *objs, int num);
int			judge_for_sq_new(double *p, double *v, t_objs *objs, int num);
void		get_base_sq(double **a, double **b, t_objs *objs, int num);
void		dark_dup(int f, t_objs objs, double *color);
double		d_for_sp(double *v, double *vp, double *cp, double r);
double		*get_inter_for_sp(double *v, double *vp, t_sp sp, double *t);
double		*get_inter_for_sq(double *v, t_objs *objs, double *t, int num);
double		*get_inter_for_pl(double *v, t_objs *objs, double *t_tmp, int num);
double		*get_inter_for_cy(double *v, t_objs *objs, double *t_tmp, int num);
double		*get_inter_for_tr(double *v, t_objs *objs, double *t_tmp, int num);
double		*get_inter_for_tr_new(double *p, double *v,
			t_objs *objs, double *t, int num);
double		*get_inter_for_sq(double *v, t_objs *objs, double *t, int num);
int			judge_for_pl(double *v, t_objs *objs, int num);
int			free_ab(double *a, double *b);
void		get_tr_t(double *t, t_objs *objs, double *v, double *r);
int			dark_from_others(t_objs objs, double *p, int l_num);
void		get_screen(int i, int j, double *screen, t_objs objs);
void		get_tr_t_tmp(double *r, t_objs *objs, double *t_tmp);
double		max(double a, double b);
double		min(double a, double b);
void		set_base(double *x, double *y, double *z);
void		ft_mlx(t_objs *objs, int c_num);
void		objs_num_init(t_objs *objs);
int			strike_judge(t_objs *objs, double *v);
void		get_base_vector(double **a, double **b, t_objs *objs, int num);
int			judge_for_sq(double *v, t_objs *objs, int num, double *t);
int			strike_judge_sq(t_objs *objs, double *v);
int			strike_judge(t_objs *objs, double *v);
void		invert_vector(double **n, t_objs objs, int l_num, double *p);
void		ft_putstr(char *s);
void		my_mlx_pixel_put(t_objs *objs, int x, int y, int color);
void		get_color_sq(t_objs objs, double *v, double *color, double *p);
void		get_color_tr(t_objs objs, double *v, double *color, double *p);
void		get_sq_n(double **n, t_objs objs, int l_num, double *p);
void		get_tr_n(double **n, t_objs objs, int l_num, double *p);
void		get_color_cy(t_objs objs, double *v, double *color, double *p);
void		get_cy_cos(t_objs *objs, int i, double *v, double *c);
void		get_cy_cap_top_cos(t_objs *objs, double *v, int i);
void		get_cy_cap_bot_cos(t_objs *objs, int i, double *v);
void		get_cy_body_cos(t_objs *objs, int i, double *c, double *v);
void		get_center_cy(t_objs objs, double *p, double *c);
void		get_color_pl(t_objs objs, double *v, double *color, double *p);
void		get_color_sub(t_objs objs, double *color, int i);
void		get_pl_n(double **n, t_objs objs, int l_num, double *p);
void		get_color_sp(t_objs objs, double *v, double *color, double *p);
void		get_color_objs(t_objs *objs,
			double *obj_p, double *obj_rgb, double *color);

#endif
