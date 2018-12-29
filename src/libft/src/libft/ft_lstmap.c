/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:55:59 by myarovoy          #+#    #+#             */
/*   Updated: 2017/11/07 19:56:00 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_lst;
	t_list *tmp;

	tmp = NULL;
	new_lst = f(lst);
	tmp = new_lst;
	if (lst != NULL)
	{
		while (lst->next)
		{
			new_lst->next = f(lst->next);
			new_lst = new_lst->next;
			lst = lst->next;
		}
	}
	return (tmp);
}
