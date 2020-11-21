/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 14:41:18 by mhori             #+#    #+#             */
/*   Updated: 2020/08/22 14:59:44 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		free_ab(double *a, double *b)
{
	free(a);
	free(b);
	return (1);
}

void	get_tr_t_tmp(double *r, t_objs *objs, double *t_tmp)
{
	double	*tmp0;
	double	*tmp1;

	tmp0 = cross_product(r, objs->tr_e1);
	tmp1 = cross_product(objs->v, objs->tr_e2);
	*t_tmp = inner_product(tmp0, objs->tr_e2) /
		inner_product(tmp1, objs->tr_e1);
	free(tmp0);
	free(tmp1);
}

void	get_tr_t(double *t, t_objs *objs, double *v, double *r)
{
	double	*tmp0;
	double	*tmp1;

	tmp0 = cross_product(r, objs->tr_e1);
	tmp1 = cross_product(v, objs->tr_e2);
	t[0] = inner_product(tmp0, objs->tr_e2);
	t[0] /= inner_product(tmp1, objs->tr_e1);
	free(tmp0);
	free(tmp1);
	tmp0 = cross_product(v, objs->tr_e2);
	tmp1 = cross_product(v, objs->tr_e2);
	t[1] = inner_product(tmp0, r);
	t[1] /= inner_product(tmp1, objs->tr_e1);
	free(tmp0);
	free(tmp1);
	tmp0 = cross_product(r, objs->tr_e1);
	tmp1 = cross_product(v, objs->tr_e2);
	t[2] = inner_product(tmp0, v);
	t[2] /= inner_product(tmp1, objs->tr_e1);
	free(tmp0);
	free(tmp1);
}
