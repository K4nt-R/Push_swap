/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_case.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qroyo <qroyo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:35:34 by qroyo             #+#    #+#             */
/*   Updated: 2024/01/09 13:07:09 by qroyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(int x1, int x2, int x3)
{
	if (x1 < x2 && x2 < x3)
		return (1);
	else
		return (0);
}

void	clean_exit(t_list *data)
{
	ft_free_data(data);
	exit (1);
}

void	ft_simple_sort(t_list *data, int *arr)
{
	if ((ft_is_sorted(arr[1], arr[0], arr[2]) == 1
			&& write (1, "sa\n", 3) < 0)
		|| (ft_is_sorted(arr[2], arr[1], arr[0]) == 1
			&& write (1, "sa\nrra\n", 7) < 0)
		|| (ft_is_sorted(arr[1], arr[2], arr[0]) == 1
			&& write (1, "ra\n", 3) < 0)
		|| (ft_is_sorted(arr[0], arr[2], arr[1]) == 1
			&& write (1, "sa\nra\n", 6) < 0)
		|| (ft_is_sorted(arr[2], arr[0], arr[1]) == 1
			&& write (1, "rra\n", 4) < 0))
		clean_exit(data);
}
