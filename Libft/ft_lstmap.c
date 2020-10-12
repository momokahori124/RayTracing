/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 21:20:18 by mhori             #+#    #+#             */
/*   Updated: 2020/07/05 20:05:19 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*ret_save;
	t_list	*move;

	if (!lst)
		return (NULL);
	if (!(ret = (t_list *)malloc(sizeof(t_list) * 1)))
		return (NULL);
	ret_save = ret;
	move = lst;
	while (move->next)
	{
		ret->content = (*f)(move->content);
		if (!(ret->next = (t_list *)malloc(sizeof(t_list) * 1)))
		{
			ft_lstclear(&ret_save, del);
			return (NULL);
		}
		move = move->next;
		ret = ret->next;
	}
	ret->content = (*f)(move->content);
	ret->next = NULL;
	return (ret_save);
}
