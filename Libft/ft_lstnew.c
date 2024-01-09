/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qroyo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:21:05 by qroyo             #+#    #+#             */
/*   Updated: 2023/11/10 13:21:40 by qroyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_elt;

	new_elt = malloc(sizeof(t_list));
	if (!new_elt)
		return (NULL);
	new_elt->content = content;
	new_elt->next = 0;
	return (new_elt);
}
