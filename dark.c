/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dark.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 18:18:33 by mhori             #+#    #+#             */
/*   Updated: 2020/09/11 22:16:58 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

double		dark(double *lp, double *p, double *cp)
{
	double		n[3];
	double		vl[3];
	double		cosa;

	vec_minus(n, p, cp);
	vec_minus(vl, p, lp);
	cosa = -inner_product(vl, n);
	cosa /= sqrt(inner_product(vl, vl) * inner_product(n, n));
	return (cosa);
}

double		dark_pl(double *lp, double *p, double *n)
{
	double	cosa;
	double	vl[3];

	vec_minus(vl, p, lp);
	cosa = -inner_product(vl, n);
	cosa /= sqrt(inner_product(vl, vl) * inner_product(n, n));
	return (cosa);
}
