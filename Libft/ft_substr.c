/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qroyo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 07:52:23 by qroyo             #+#    #+#             */
/*   Updated: 2023/11/13 09:57:46 by qroyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	str_len;
	size_t	true_len;

	str_len = ft_strlen(s);
	if (start > str_len)
		return (ft_strdup(""));
	if (len > str_len - start)
		true_len = str_len - start;
	else
		true_len = len;
	str = ft_calloc(true_len + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s + start, true_len);
	return (str);
}
