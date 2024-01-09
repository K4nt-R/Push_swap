/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qroyo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:47:15 by qroyo             #+#    #+#             */
/*   Updated: 2023/11/10 16:43:42 by qroyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elt;
	void	*content;

	new_lst = NULL;
	while (lst)
	{
		content = (*f)(lst->content);
		if (!content)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		new_elt = ft_lstnew(content);
		if (!new_elt)
		{
			(*del)(content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elt);
		lst = lst->next;
	}
	return (new_lst);
}
