/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qroyo <qroyo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:43:32 by qroyo             #+#    #+#             */
/*   Updated: 2024/01/09 12:14:36 by qroyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_median(t_list *data)
{
	size_t	i;
	size_t	n;

	i = 1;
	n = 1;
	ft_sort_in_tab(data);
	data->median[0] = data->sorted_tab[0];
	while (n <= data->key_nbr && i < data->key_nbr)
	{
		data->median[i] = data->sorted_tab[n * (data->size_a \
				- 1) / data->key_nbr];
		i++;
		n++;
	}
}

void	ft_chunks(t_list *data, size_t *i, size_t j, size_t k)
{
	if (data->median[k] <= data->arr_a[*i]
		&& data->arr_a[*i] <= data->median[k + 1])
	{
		ft_proximity_a(data, data->arr_a[*i]);
		*i = 0;
	}
	else if (data->median[j - 1] <= data->arr_a[*i]
		&& data->arr_a[*i] <= data->median[j])
	{
		ft_proximity_a(data, data->arr_a[*i]);
		ft_rotate_b(data);
		*i = 0;
	}
	else
		*i = *i + 1;
}

void	ft_algo_push_b(t_list *data)
{
	size_t	i;
	size_t	j;
	size_t	k;

	j = data->key_nbr / 2;
	k = data->key_nbr / 2;
	while (k < data->key_nbr - 1)
	{
		i = 0;
		while (i < data->size_a - 1 && data->size_a > 1)
			ft_chunks(data, &i, j, k);
		k++;
		j--;
	}
}

void	ft_algo_push_a(t_list *data)
{
	while (data->size_a > 2)
	{
		ft_proximity_a(data, ft_search_min(data->arr_a, \
					data->size_a));
	}
	if (data->arr_a[0] > data->arr_a[1])
		ft_swap_a(data);
	while (data->size_b > 1)
	{
		ft_proximity_b(data, ft_search_max(data->arr_b, \
					data->size_b));
		if (data->arr_a[0] > data->arr_a[1])
			ft_swap_a(data);
	}
	ft_push_a(data);
}
