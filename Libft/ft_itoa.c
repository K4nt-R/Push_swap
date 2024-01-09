/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qroyo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:11:08 by qroyo             #+#    #+#             */
/*   Updated: 2023/11/15 08:26:57 by qroyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_calc_div(long int nbr)
{
	size_t	div;

	if (nbr < 10)
		return (1);
	else
	{
		div = 1;
		while (nbr >= 10)
		{
			nbr = nbr / 10;
			div++;
		}
		return (div);
	}
}

static void	ft_check_minus(int *minus, long int *number)
{
	if (*number < 0)
	{
		*number *= -1;
		*minus = 1;
	}
	else
		*minus = 0;
}

char	*ft_itoa(int n)
{
	size_t		div;
	int			minus;
	char		*str;
	long int	nb;

	nb = (long int) n;
	ft_check_minus(&minus, &nb);
	div = ft_calc_div(nb);
	str = ft_calloc(div + minus + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (minus == 1)
		str[0] = '-';
	while (nb / 10 != 0)
	{
		str[div + minus - 1] = (nb % 10) + '0';
		nb = nb / 10;
		div--;
	}
	str[div + minus - 1] = nb % 10 + '0';
	return (str);
}
