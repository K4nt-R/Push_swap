/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qroyo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:32:33 by qroyo             #+#    #+#             */
/*   Updated: 2023/12/15 10:57:16 by qroyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <libft.h>
/*
static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
*/
static int	ft_check_base(char *base, int len)
{
	int	i;
	int	j;

	i = 0;
	if (len <= 1)
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| base[i] == '\f' || base[i] == '\t' || base[i] == '\n'
			|| base[i] == '\r' || base[i] == '\v')
			return (0);
		while (j < len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_str(char str)
{
	if (str == '\f' || str == '\t' || str == '\n' || str == '\r'
		|| str == '\v' || str == ' ')
		return (1);
	else if (str == '-' || str == '+')
		return (2);
	else
		return (0);
}

static int	check_in_base(char str, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (str == base[i])
			return (i);
		i++;
	}
	return (-1);
}

uint32_t	ft_atoi_base(char *str, char *base)
{
	int			i;
	uint32_t	nb;
	int			count_minus;
	int			len_base;

	nb = 0;
	i = 0;
	count_minus = 1;
	len_base = ft_strlen(base);
	if (ft_check_base(base, len_base) == 0)
		return (0);
	while (check_str(ft_tolower(str[i])) == 1)
		i++;
	while (check_str(ft_tolower(str[i])) == 2)
	{
		if (str[i] == '-')
			count_minus *= -1;
		i++;
	}
	while (check_in_base(ft_tolower(str[i]), base) >= 0)
	{
		nb = nb * len_base + check_in_base(ft_tolower(str[i]), base);
		i++;
	}
	return (count_minus * nb);
}
