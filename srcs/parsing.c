/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qroyo <qroyo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:52:32 by qroyo             #+#    #+#             */
/*   Updated: 2024/01/09 10:27:02 by qroyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parse(t_list *data, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		data->arr_a[i] = (int)(ft_atoi(argv[i + 1]));
		i++;
	}
}

int	ft_check_arg(int argc, char **argv)
{
	size_t	i;
	int		size;

	size = 1;
	while (size < argc)
	{
		i = 0;
		if (ft_strlen(argv[size]) == 0)
			return (1);
		while (i < ft_strlen(argv[size]))
		{
			if (argv[size][i] == '+' || argv[size][i] == '-')
			{
				if (i == 0)
					i++;
				else
					return (1);
			}
			if (ft_isdigit(argv[size][i]) == 0)
				return (1);
			i++;
		}
		size++;
	}
	return (0);
}

int	ft_check_arg2(int argc, char **argv)
{
	int	size;
	int	j;

	size = 1;
	while (size < argc)
	{
		if (ft_atoi(argv[size]) > INT_MAX || ft_atoi(argv[size]) < INT_MIN)
			return (1);
		j = size + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[size]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		size++;
	}
	return (0);
}
