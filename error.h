/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:48:33 by mhori             #+#    #+#             */
/*   Updated: 2020/10/16 12:54:38 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "struct.h"

void	err_exit(int n, t_objs *objs);
# define ERR_INVALID_FILE "Error : Invalid file.\n"
# define ERR_WRONG_NUMBER_ARGUMENT "Error : Wrong number of arguments.\n"
# define ERR "Error : Something happened.\n"
# define ERR_WRONG_OPTION "Error : Wrong option.\n"
# define ERR_WRONG_INPUT "Error : Wrong input.\n"
# define ERR_RAC "Error : You have Wrong number of Resolution.\n"
# define ERR_KEY "Error : Invalid key\n"
# define FINISH "Finish : No more image.\n"
# define CANT_OPEN "Error : Can't open file.\n"
# define ERR_MALLOC "Error : Can't allocate memory.\n"
# define ERR_R "Error : Something wrong with information of R.\n"
# define ERR_A "Error : Something wrong with information of A.\n"
# define ERR_C "Error : Something wrong with information of C.\n"
# define ERR_CY "Error : Something wrong with information of cy.\n"
# define ERR_L "Error : Something wrong with information of l.\n"
# define ERR_SP "Error : Something wrong with information of sp.\n"
# define ERR_SQ "Error : Something wrong with information of sq.\n"
# define ERR_TR "Error : Something wrong with information of tr.\n"
# define ERR_PL "Error : Something wrong with information of pl.\n"
# define ERR_NO_CAMERA "Error : No camera.\n"
# define ERR_VECTOR "Error : Vector norm is zero.\n"
# define ERR_OUT_OF_RANGE "Error : Some variable is out of range.\n"
# define ERR_OVER_MAX "Error : Some objects are over MAX.\n"
# define ERR_INVALID_FILE_N -1
# define ERR_WRONG_NUMBER_ARGUMENT_N -2
# define ERR_N -3
# define ERR_WRONG_OPTION_N -4
# define ERR_WRONG_INPUT_N -5
# define ERR_RAC_N -6
# define ERR_KEY_N -7
# define FINISH_N -8
# define CANT_OPEN_N -9
# define ERR_MALLOC_N -10
# define ERR_R_N -11
# define ERR_A_N -12
# define ERR_C_N -13
# define ERR_CY_N -14
# define ERR_L_N -15
# define ERR_SP_N -16
# define ERR_SQ_N -17
# define ERR_TR_N -18
# define ERR_PL_N -19
# define ERR_NO_CAMERA_N -20
# define ERR_VECTOR_N -21
# define ERR_OUT_OF_RANGE_N -22
# define ERR_OVER_MAX_N -23

#endif
