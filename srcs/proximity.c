/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qroyo <qroyo@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:19:46 by qroyo             #+#    #+#             */
/*   Updated: 2024/01/09 09:07:10 by qroyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_proximity_a(t_list *data, int value)
{
	size_t	index;
	size_t	proximity;

	proximity = data->size_a / 2;
	index = ft_search_index(data->arr_a, data->size_a, value);
	if (proximity >= index)
	{
		while (ft_search_index(data->arr_a, data->size_a, value) != 0)
			ft_rotate_a(data);
	}
	else
	{
		while (ft_search_index(data->arr_a, data->size_a, value) != 0)
			ft_reverse_rotate_a(data);
	}
	ft_push_b(data);
}

void	ft_prox_rot(t_list *data, int value, int second_max)
{
	ft_rotate_b(data);
	if (ft_search_index(data->arr_b, data->size_b, value) == 1)
		ft_swap_b(data);
	if (ft_search_index(data->arr_b, data->size_b, second_max) == 0)
		ft_push_a(data);
}

void	ft_prox_rev_rot(t_list *data, int value, int second_max)
{
	ft_reverse_rotate_b(data);
	if (ft_search_index(data->arr_b, data->size_b, value) == 1)
		ft_swap_b(data);
	if (ft_search_index(data->arr_b, data->size_b, second_max) == 0)
		ft_push_a(data);
}

void	ft_proximity_b(t_list *data, int value)
{
	size_t	index;
	size_t	proximity;
	int		second_max;

	proximity = data->size_b / 2;
	index = ft_search_index(data->arr_b, data->size_b, value);
	second_max = ft_search_second_max(data->arr_b, data->size_b);
	if (proximity >= index)
	{
		while (ft_search_index(data->arr_b, data->size_b, value) != 0)
		{
			ft_prox_rot(data, value, second_max);
		}
	}
	else
	{
		while (ft_search_index(data->arr_b, data->size_b, value) != 0)
		{
			ft_prox_rev_rot(data, value, second_max);
		}
	}
	ft_push_a(data);
}
