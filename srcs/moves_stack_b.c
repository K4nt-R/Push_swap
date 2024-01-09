/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_stack_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qroyo <qroyo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:50:41 by qroyo             #+#    #+#             */
/*   Updated: 2024/01/09 12:47:44 by qroyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_b(t_list *data)
{
	size_t	i;
	int		temp;

	i = data->size_b - 1;
	temp = data->arr_a[0];
	while (i < data->size_b)
	{
		data->arr_b[i + 1] = data->arr_b[i];
		i--;
	}
	data->size_b = data->size_b + 1;
	data->arr_b[0] = temp;
	i = -1;
	while (++i < data->size_a - 1)
		data->arr_a[i] = data->arr_a[i + 1];
	data->size_a = data->size_a - 1;
	if (data->status == 's')
		data->count += 1;
	else if (write(1, "pb\n", 3) < 0)
		clean_exit(data);
}

void	ft_swap_b(t_list *data)
{
	int	temp;

	if (data->size_b < 2)
		return ;
	else
	{
		temp = data->arr_b[0];
		data->arr_b[0] = data->arr_b[1];
		data->arr_b[1] = temp;
	}
	if (data->status == 's')
		data->count += 1;
	else if (write(1, "sb\n", 3) < 0)
		clean_exit(data);
}

void	ft_reverse_rotate_b(t_list *data)
{
	int		temp;
	size_t	i;

	i = data->size_b - 1;
	temp = data->arr_b[data->size_b - 1];
	while (i > 0)
	{
		data->arr_b[i] = data->arr_b[i - 1];
		i--;
	}
	data->arr_b[0] = temp;
	if (data->status == 's')
		data->count += 1;
	else if (write(1, "rrb\n", 4) < 0)
		clean_exit(data);
}

void	ft_rotate_b(t_list *data)
{
	int		temp;
	size_t	i;

	i = 0;
	temp = data->arr_b[0];
	while (i < data->size_b - 1)
	{
		data->arr_b[i] = data->arr_b[i + 1];
		i++;
	}
	data->arr_b[data->size_b - 1] = temp;
	if (data->status == 's')
		data->count += 1;
	else if (write(1, "rb\n", 3) < 0)
		clean_exit(data);
}
