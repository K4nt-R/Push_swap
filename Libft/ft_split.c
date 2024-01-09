/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qroyo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 07:51:19 by qroyo             #+#    #+#             */
/*   Updated: 2023/12/15 09:20:50 by qroyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charset(char s1, char c)
{
	return ((s1 == c || s1 == '\0'));
}

static void	ft_fill(const char *s, size_t index, char c, char *str)
{
	size_t	j;

	j = 0;
	while (ft_charset(s[index], c) == 0)
	{
		str[j] = s[index];
		j++;
		index++;
	}
}

char	**ft_free_split(char **str, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**str;
	size_t	index;

	i = -1;
	index = 0;
	j = 0;
	str = malloc((ft_count_word(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (s[++i])
	{
		if (ft_charset(s[i], c) == 1)
			index = i + 1;
		if (ft_charset(s[i], c) == 0 && ft_charset(s[i + 1], c) == 1)
		{
			str[j] = ft_calloc(i - index + 2, sizeof(char));
			if (!str[j])
				return (ft_free_split(str, j));
			ft_fill(s, index, c, str[j++]);
		}
	}
	str[j] = NULL;
	return (str);
}
