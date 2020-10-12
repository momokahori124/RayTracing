/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:58:40 by mhori             #+#    #+#             */
/*   Updated: 2020/08/22 15:47:03 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

double		*get_inter_for_cy(double *v, t_objs *objs, double *t, int num);
void		offset(double *ofs, t_objs *objs, int num);
int			set_inner_products(double *a, double *v, t_objs *objs, int num);
int			get_cy_t(double *v, t_objs *objs, int num, double *t);
int			cy_body(double *v, t_objs *objs, int num, double *t);
int			cy_cap_bot(double *v, t_objs *objs, int num, double *t);
void		get_top_coordinate(t_objs *objs, int num, double *top);
int			cy_cap_top(double *v, t_objs *objs, int num, double *t);
int			judge_for_cy(double *v, t_objs *objs, int num, double *t);
int			strike_judge_cy(t_objs *objs, double *v);
void		offset_new(double *ofs, t_objs *objs, int num, double *p);
int			get_cy_new_t(double *v, t_objs *objs, int num, double *t);
int			cy_body_new(double *v, t_objs *objs, int num, double *t);
int			cy_cap_bot_new(double *v, t_objs *objs, int num, double *t);
int			cy_cap_top_new(double *v, t_objs *objs, int num, double *t);
void		array_dup(double *src, double *dest);
int			judge_for_cy_new(double *p, double *v, t_objs *objs, int num);

#endif
