/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qroyo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:58:23 by qroyo             #+#    #+#             */
/*   Updated: 2023/11/15 08:34:33 by qroyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	len_src;
	char	*dest;

	len_src = 0;
	while (src[len_src] != '\0')
		len_src++;
	dest = malloc(sizeof (char) * (len_src + 1));
	if (!dest)
		return (NULL);
	ft_memcpy(dest, src, len_src + 1);
	return (dest);
}
