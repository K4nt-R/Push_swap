/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qroyo <qroyo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:37:52 by qroyo             #+#    #+#             */
/*   Updated: 2024/01/09 09:37:56 by qroyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_tab_copy(t_list *data)
{
	size_t	i;

	i = 0;
	while (i < data->size_a)
	{
		data->sorted_tab[i] = data->arr_a[i];
		i++;
	}
}

void	ft_sort_in_tab(t_list *data)
{
	size_t	i;
	size_t	j;
	int		temp;

	i = 0;
	ft_tab_copy(data);
	while (i < data->size_a)
	{
		j = 0;
		while (j < data->size_a)
		{
			if (data->sorted_tab[j] > data->sorted_tab[i])
			{
				temp = data->sorted_tab[i];
				data->sorted_tab[i] = data->sorted_tab[j];
				data->sorted_tab[j] = temp;
				j = 0;
			}
			j++;
		}
		i++;
	}
}

int	ft_arr_sorted(int *arr_a, size_t size_a)
{
	size_t	i;

	i = 1;
	while (i < size_a)
	{
		if (arr_a[i - 1] > arr_a[i])
			return (-1);
		i++;
	}
	return (0);
}
