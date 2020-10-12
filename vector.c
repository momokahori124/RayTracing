/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 19:41:03 by mhori             #+#    #+#             */
/*   Updated: 2020/08/23 19:04:25 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	vec_init(double *v)
{
	v[0] = 0;
	v[1] = 0;
	v[2] = 0;
}

void	vec_minus(double *v, double *a, double *b)
{
	int i;

	i = 0;
	while (i < 3)
	{
		v[i] = a[i] - b[i];
		i++;
	}
}

void	unit_vector(double *v)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (vec_norm(v) == 0)
			exit(0);
		v[i] = v[i] / vec_norm(v);
		i++;
	}
}

double	vec_norm(double *v)
{
	return (sqrt(inner_product(v, v)));
}

void	vec_times(double a, double **v)
{
	int k;

	k = 0;
	while (k < 3)
	{
		(*v)[k] = a * (*v)[k];
		k++;
	}
}
