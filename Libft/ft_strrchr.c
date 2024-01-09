/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qroyo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:33:14 by qroyo             #+#    #+#             */
/*   Updated: 2023/11/13 08:31:53 by qroyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	int		temp;

	i = 0;
	temp = -1;
	while (((char *)s)[i])
	{
		if (((char *)s)[i] == (char)c)
			temp = (int) i;
		i++;
	}
	if ((char)c == ((char *)s)[i])
		return ((char *)s + i);
	else if (temp == -1)
		return (NULL);
	else
		return ((char *)s + temp);
}
