/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qroyo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:19:13 by qroyo             #+#    #+#             */
/*   Updated: 2023/11/09 13:16:28 by qroyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	to_find_len;

	i = 0;
	if (!little[0])
		return ((char *) big);
	while (big[i] != '\0' && i < len)
	{
		to_find_len = 0;
		j = 0;
		while (little[j] != '\0' && big[i + j] != '\0')
		{
			if (little[j] == big[i + j])
				to_find_len++;
			j++;
		}
		if (to_find_len == ft_strlen(little) && i + ft_strlen(little) <= len)
			return ((char *) &big[i]);
		i++;
	}
	return (0);
}
