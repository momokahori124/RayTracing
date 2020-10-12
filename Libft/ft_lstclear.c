/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 20:22:54 by mhori             #+#    #+#             */
/*   Updated: 2020/07/02 18:36:42 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*save;
	t_list	*move;

	if (!(lst) || !(*lst))
		return ;
	move = *lst;
	while (move)
	{
		save = move;
		move = move->next;
		ft_lstdelone(save, del);
	}
	*lst = NULL;
}
