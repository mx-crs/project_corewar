/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:52:32 by myarovoy          #+#    #+#             */
/*   Updated: 2017/11/08 16:52:33 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_lst;
	void	*content_cpy;

	new_lst = (t_list*)malloc(sizeof(t_list));
	if (content)
	{
		content_cpy = malloc(sizeof(content_size));
		if (!content_cpy)
			return (NULL);
		ft_memcpy(content_cpy, content, content_size);
		new_lst->content = content_cpy;
		new_lst->content_size = content_size;
	}
	else
	{
		new_lst->content = NULL;
		new_lst->content_size = 0;
	}
	new_lst->next = NULL;
	return (new_lst);
}
