/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qroyo <qroyo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:34:39 by qroyo             #+#    #+#             */
/*   Updated: 2024/01/09 09:37:38 by qroyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_search_max(int *arr, size_t size)
{
	size_t	i;
	int		max;

	i = 0;
	max = arr[0];
	while (i < size)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}

int	ft_search_second_max(int *arr, size_t size)
{
	int		max;
	int		second_max;
	size_t	i;

	max = ft_search_max(arr, size);
	i = 0;
	if (max != arr[0])
		second_max = arr[0];
	else
		second_max = arr[1];
	while (i < size)
	{
		if (arr[i] > second_max && arr[i] != max)
			second_max = arr[i];
		i++;
	}
	return (second_max);
}

int	ft_search_min(int *arr, size_t size)
{
	size_t	i;
	int		min;

	i = 0;
	min = arr[0];
	while (i < size)
	{
		if (arr[i] < min)
			min = arr[i];
		i++;
	}
	return (min);
}

size_t	ft_search_index(int *arr, size_t size, int value)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			break ;
		i++;
	}
	return (i);
}
