/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qroyo <qroyo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:08:04 by qroyo             #+#    #+#             */
/*   Updated: 2024/01/09 13:10:40 by qroyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <errno.h>
# include <stdlib.h>

typedef struct s_list
{
	int		*arr_a;
	int		*arr_b;
	size_t	size_a;
	size_t	size_b;
	int		*sorted_tab;
	int		*median;
	size_t	key_nbr;
	size_t	count;
	size_t	last_count;
	size_t	final_key;
	char	status;
}	t_list;

void	ft_parse(t_list *data, int argc, char **argv);
void	ft_push_a(t_list *data);
void	ft_push_b(t_list *data);
void	ft_swap_a(t_list *data);
void	ft_swap_b(t_list *data_init);
void	ft_rotate_a(t_list *data);
void	ft_rotate_b(t_list *data);
void	ft_reverse_rotate_a(t_list *data);
void	ft_reverse_rotate_b(t_list *data);
int		ft_search_max(int *arr, size_t size);
void	ft_sort_in_tab(t_list *data);
void	ft_median(t_list *data_init);
void	ft_algo_push_b(t_list *data_init);
void	ft_proximity_a(t_list *data, int value);
void	ft_proximity_b(t_list *data, int value);
int		ft_search_min(int *arr, size_t size);
void	ft_algo_push_a(t_list *data);
size_t	ft_search_index(int *arr, size_t size, int value);
void	ft_print_arr(int *arr, size_t size);
void	ft_tab_copy(t_list *data);
int		ft_arr_sorted(int *arr_a, size_t size_a);
int		ft_is_sorted(int x1, int x2, int x3);
void	ft_simple_sort(t_list *data, int *arr);
int		ft_search_second_max(int *arr, size_t size);
int		ft_check_arg(int argc, char **argv);
int		ft_check_arg2(int argc, char **argv);
void	ft_free_data(t_list *data);
void	clean_exit(t_list *data);
#endif
