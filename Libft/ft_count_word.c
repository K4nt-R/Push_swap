/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qroyo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:29:18 by qroyo             #+#    #+#             */
/*   Updated: 2023/12/15 16:29:26 by qroyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charset(char s1, char c)
{
	return ((s1 == c || s1 == '\0'));
}

size_t	ft_count_word(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (ft_charset(s[i], c) == 0 && ft_charset(s[i + 1], c) == 1)
			count++;
		i++;
	}
	return (count);
}
