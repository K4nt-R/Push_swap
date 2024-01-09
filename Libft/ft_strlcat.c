/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qroyo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:31:06 by qroyo             #+#    #+#             */
/*   Updated: 2023/11/10 14:57:44 by qroyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;

	i = 0;
	src_len = 0;
	dest_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	while (dst[dest_len] != '\0' && dest_len < dstsize)
		dest_len++;
	while (src[i] != '\0' && dest_len + i + 1 < dstsize)
	{
		dst[i + dest_len] = src[i];
		i++;
	}
	if (dest_len < dstsize)
		dst[dest_len + i] = '\0';
	return (src_len + dest_len);
}
