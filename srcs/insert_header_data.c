/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_header_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 13:25:16 by mhori             #+#    #+#             */
/*   Updated: 2020/08/23 18:49:40 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void	set_name(char **name)
{
	name[0] = "picture_0.bmp";
	name[1] = "picture_1.bmp";
	name[2] = "picture_2.bmp";
	name[3] = "picture_3.bmp";
	name[4] = "picture_4.bmp";
	name[5] = "picture_5.bmp";
	name[6] = "picture_6.bmp";
	name[7] = "picture_7.bmp";
	name[8] = "picture_8.bmp";
	name[9] = "picture_9.bmp";
}

/*
** Initialize the header of bmp (char *data)
**
** HEADER
** Position | Hex	| Description
** 00		| 00	| TYPE OF BMP FILE
** 02		| 02	| TOTAL SIZE OF FILE
** 06-08	| 06-08	| RESERVED TO SIGN
** 10		| 0A	| HEADER SIZE
** =============================================================================
** HEADER INFOS
** Position | Hex	| Description
** 14		| 0E	| HEADER INFOS SIZE
** 18		| 12	| WIDTH OF IMG (PX)
** 22		| 16	| HEIGHT OF IMG (PX)
** 26		| 1A	| NUMBER OF PLANS
** 28		| 1C	| BITS PER PIXELS (1 - 4 - 8 - 24)
** 30		| 1E	| COMPRESSION TYPE
** 34		| 22	| SIZE OF IMG
** 38		| 26	| RES X PX PER METER
** 42		| 2A	| RES Y PX PER METER
** 46		| 2E	| NB OF USED COLOR (0 = MAX)
** 50		| 32	| NB OF INDEX OF COLOR (0 = ALL)
*/

void	insert_header(char *data, int width, int height)
{
	int		size;

	size = width * height * 3;
	*(unsigned int *)data = *(const unsigned int *)(unsigned long)"BM";
	*(unsigned int *)(data + 2) = (size + HEADER_SIZE);
	*(unsigned int *)(data + 6) = 0;
	*(unsigned int *)(data + 10) = HEADER_SIZE;
	*(unsigned int *)(data + 14) = HEADER_SIZE - 14;
	*(unsigned int *)(data + 18) = width;
	*(unsigned int *)(data + 22) = height;
	*(unsigned int *)(data + 26) = 1;
	*(unsigned int *)(data + 28) = 24;
	*(unsigned int *)(data + 30) = 0;
	*(unsigned int *)(data + 34) = (unsigned int)size;
	*(unsigned int *)(data + 38) = 3780;
	*(unsigned int *)(data + 42) = 3780;
	*(int *)(data + 46) = 0;
	*(int *)(data + 50) = 0;
}

void	insert_data(char *data, t_objs objs)
{
	int		i;
	int		j;
	int		x;
	int		y;
	// int		k;

	insert_header(data, objs.r.x, objs.r.y);
	i = HEADER_SIZE;
	y = objs.r.y;
	while (y--)
	{
		x = -1;
		while (++x < objs.r.x)
		{
			j = ((x * (objs.bpp / 8)) + (y * objs.line));
			*(data + i++) = *(objs.addr + j++);
			*(data + i++) = *(objs.addr + j++);
			*(data + i++) = *(objs.addr + j++);
		}
		// k = 0;
		// while ((k++ + (objs.r.y * 3) % 4) != 0)
		// 	*(data + i++) = 0;
	}
}
