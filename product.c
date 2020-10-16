/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   product.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 18:48:22 by mhori             #+#    #+#             */
/*   Updated: 2020/08/23 19:07:47 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

double		inner_product(double a[3], double b[3])
{
	return (a[0] * b[0] + a[1] * b[1] + a[2] * b[2]);
}

double		*cross_product(double a[3], double b[3])
{
	double	*ret;
	t_objs	objs;

	objs = (t_objs){0};
	ret = (double *)malloc(sizeof(double) * 3);
	if (!ret)
		err_exit(ERR_MALLOC_N, &objs);
	ret[0] = a[1] * b[2] - a[2] * b[1];
	ret[1] = a[2] * b[0] - a[0] * b[2];
	ret[2] = a[0] * b[1] - a[1] * b[0];
	return (ret);
}
