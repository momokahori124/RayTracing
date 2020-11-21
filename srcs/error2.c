/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 15:36:02 by mhori             #+#    #+#             */
/*   Updated: 2020/09/13 15:36:05 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void	err_exit_sub2(int n)
{
	if (n == ERR_SP_N)
		ft_putstr(ERR_SP);
	if (n == ERR_SQ_N)
		ft_putstr(ERR_SQ);
	if (n == ERR_TR_N)
		ft_putstr(ERR_TR);
	if (n == ERR_PL_N)
		ft_putstr(ERR_PL);
}
