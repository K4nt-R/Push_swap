/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qroyo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:27:45 by qroyo             #+#    #+#             */
/*   Updated: 2023/11/13 07:53:51 by qroyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;

	i = 0;
	if (n == 0)
		return (NULL);
	while (((unsigned char *)s)[i] != (unsigned char)c && i < n - 1)
		i++;
	if (((unsigned char *)s)[i] == (unsigned char)c)
		return ((void *)s + i);
	return (NULL);
}
