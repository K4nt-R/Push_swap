/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qroyo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:17:45 by qroyo             #+#    #+#             */
/*   Updated: 2023/11/15 10:48:40 by qroyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	get_num(const char *str, size_t i, int minus)
{
	long int	nb;

	nb = 0;
	while (ft_isdigit(str[i]))
	{
		if (((nb * 10) + str[i] - '0') / 10 != nb)
		{
			if (minus == -1)
				return (LONG_MIN);
			else
				return (LONG_MAX);
		}
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (minus * nb);
}

long int	ft_atoi(const char *str)
{
	size_t	i;
	int		minus;

	i = 0;
	minus = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	return (get_num(str, i, minus));
}
