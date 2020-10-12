/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 15:46:49 by mhori             #+#    #+#             */
/*   Updated: 2020/10/12 18:41:53 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		err_invalid_file(void)
{
	ft_putstr(ERR_INVALID_FILE);
	return (0);
}

int		err_few_argument(void)
{
	ft_putstr(ERR_WRONG_NUMBER_ARGUMENT);
	return (0);
}

void	err_exit_sub(int n)
{
	if (n == ERR_INVALID_FILE_N)
		ft_putstr(ERR_INVALID_FILE);
	if (n == ERR_N)
		ft_putstr(ERR);
	if (n == CANT_OPEN_N)
		ft_putstr(CANT_OPEN);
	if (n == ERR_MALLOC_N)
		ft_putstr(ERR_MALLOC);
	if (n == ERR_R_N)
		ft_putstr(ERR_R);
	if (n == ERR_A_N)
		ft_putstr(ERR_A);
	if (n == ERR_C_N)
		ft_putstr(ERR_C);
	if (n == ERR_CY_N)
		ft_putstr(ERR_CY);
	if (n == ERR_L_N)
		ft_putstr(ERR_L);
	if (n == ERR_OUT_OF_RANGE_N)
		ft_putstr(ERR_OUT_OF_RANGE);
}

void	err_exit(int n)
{
	if (n == ERR_KEY_N)
		ft_putstr(ERR_KEY);
	if (n == FINISH_N)
		ft_putstr(FINISH);
	if (n == ERR_RAC_N)
		ft_putstr(ERR_RAC);
	if (n == ERR_WRONG_INPUT_N)
		ft_putstr(ERR_WRONG_INPUT);
	if (n == ERR_WRONG_OPTION_N)
		ft_putstr(ERR_WRONG_OPTION);
	if (n == ERR_WRONG_NUMBER_ARGUMENT_N)
		ft_putstr(ERR_WRONG_NUMBER_ARGUMENT);
	if (n == ERR_NO_CAMERA_N)
		ft_putstr(ERR_NO_CAMERA);
	if (n == ERR_VECTOR_N)
		ft_putstr(ERR_VECTOR);
	if (n == ERR_OVER_MAX_N)
		ft_putstr(ERR_OVER_MAX);
	err_exit_sub(n);
	err_exit_sub2(n);
	exit(n);
}
