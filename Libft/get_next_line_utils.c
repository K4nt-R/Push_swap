/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qroyo <qroyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:49:39 by qroyo             #+#    #+#             */
/*   Updated: 2023/12/18 14:59:40 by qroyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_buf(char *s1, char *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == NULL)
		len_s1 = 0;
	else
		len_s1 = ft_sch(s1, '\0');
	if (ft_sch(s2, '\n') != ft_sch(s2, '\0'))
		len_s2 = ft_sch(s2, '\n') + 1;
	else
		len_s2 = ft_sch(s2, '\0');
	str = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!str)
	{
		if (s1 != NULL)
			free(s1);
		return (NULL);
	}
	ft_memset(str, 0, len_s1 + len_s2 + 1);
	ft_memcpy(str, s1, len_s1);
	ft_memcpy(str + len_s1, s2, len_s2);
	if (s1 != NULL)
		free(s1);
	return (str);
}

char	*ft_strjoin_last(char *s1, char *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == NULL)
		len_s1 = 0;
	else
		len_s1 = ft_sch(s1, '\0');
	len_s2 = ft_sch(s2, '\0');
	str = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!str)
	{
		if (s2 != NULL)
			free(s2);
		return (NULL);
	}
	ft_memset(str, 0, len_s1 + len_s2 + 1);
	ft_memcpy(str, s1, len_s1);
	ft_memcpy(str + len_s1, s2, len_s2);
	if (s2 != NULL)
		free(s2);
	return (str);
}
