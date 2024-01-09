/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qroyo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:39:10 by qroyo             #+#    #+#             */
/*   Updated: 2023/11/15 08:36:54 by qroyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_trim_left(char const *s1, char const *set)
{
	size_t	start;
	size_t	j;

	start = 0;
	j = 0;
	while (set[j])
	{
		if (set[j] == s1[start])
		{
			start++;
			j = 0;
		}
		else
			j++;
	}
	return (start);
}

static int	ft_trim_right(char const *s1, char const *set)
{
	size_t	end;
	size_t	j;

	end = ft_strlen(s1) - 1;
	j = 0;
	while (set[j])
	{
		if (set[j] == s1[end])
		{
			end--;
			j = 0;
		}
		else
			j++;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	int		diff;

	if (ft_strlen(set) == 0 || ft_strlen(s1) == 0)
		return (ft_strdup(s1));
	start = ft_trim_left(s1, set);
	end = ft_trim_right(s1, set);
	diff = end - start;
	if (diff < 0)
		return (ft_calloc(1, sizeof(char)));
	return (ft_substr(s1, start, end - start + 1));
}
