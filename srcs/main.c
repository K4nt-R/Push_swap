/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qroyo <qroyo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:43:50 by qroyo             #+#    #+#             */
/*   Updated: 2024/01/09 13:01:21 by qroyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algo_search(t_list *data, int argc, char **argv)
{
	ft_parse(data, argc, argv);
	data->size_a = argc - 1;
	data->size_b = 0;
	ft_median(data);
	ft_algo_push_b(data);
	ft_algo_push_a(data);
	if (data->key_nbr == 1)
		data->last_count = data->count;
	else if (data->count < data->last_count
		&& ft_arr_sorted(data->arr_a, data->size_a) == 0)
	{
		data->last_count = data->count;
		data->final_key = data->key_nbr;
	}
	data->count = 0;
	data->key_nbr += 1;
}

t_list	*ft_init_data(int argc)
{
	t_list	*data_init;

	data_init = malloc(sizeof(t_list));
	if (data_init == NULL)
		return (NULL);
	data_init->arr_a = ft_calloc((argc - 1), sizeof(int));
	if (!(data_init->arr_a))
		return (free(data_init), NULL);
	data_init->arr_b = ft_calloc((argc - 1), sizeof(int));
	if (!(data_init->arr_b))
		return (free(data_init->arr_a), free(data_init), NULL);
	data_init->sorted_tab = ft_calloc((argc - 1), sizeof(int));
	if (!(data_init->sorted_tab))
		return (free(data_init->arr_a), free(data_init->arr_b), \
				free(data_init), NULL);
	data_init->median = ft_calloc((argc - 1), sizeof(int));
	if (!(data_init->sorted_tab))
		return (free(data_init->arr_a), free(data_init->arr_b), \
			free(data_init->sorted_tab), free(data_init), NULL);
	data_init->status = 's';
	data_init->key_nbr = 1;
	data_init->final_key = 1;
	data_init->count = 0;
	return (data_init);
}

void	ft_algo_found(t_list *data, int argc, char **argv)
{
	data->key_nbr = data->final_key;
	data->status = 'f';
	ft_parse(data, argc, argv);
	data->size_a = argc - 1;
	data->size_b = 0;
	data->write = 'o';
	ft_median(data);
	ft_algo_push_b(data);
	ft_algo_push_a(data);
}

void	ft_free_data(t_list *data)
{
	free(data->arr_a);
	free(data->arr_b);
	free(data->sorted_tab);
	free(data->median);
	free(data);
}

int	main(int argc, char **argv)
{
	t_list	*data;

	if (argc < 2)
		return (2);
	else
	{
		data = ft_init_data(argc);
		if (data == NULL)
			return (1);
		if (ft_check_arg(argc, argv) == 1 || ft_check_arg2(argc, argv) == 1)
			return (ft_free_data(data), write(2, "Error\n", 6), 1);
		ft_parse(data, argc, argv);
		if (ft_arr_sorted(data->arr_a, argc - 1) == 0)
			return (ft_free_data(data), 0);
		else if (ft_arr_sorted(data->arr_a, argc - 1) == -1 && argc == 3)
			return (ft_free_data(data), write(1, "sa\n", 3), 0);
		if (argc == 4)
			return (ft_simple_sort(data, data->arr_a), ft_free_data(data), 1);
		while (data->key_nbr < (size_t)(argc - 1) && data->key_nbr < 30)
			ft_algo_search(data, argc, argv);
		ft_algo_found(data, argc, argv);
		return (ft_free_data(data), 0);
	}
}

//proteger les writes
//supprimer ft_print arr
//supprimer stdio.h
//header proximity