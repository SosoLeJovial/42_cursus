/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:25:49 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/26 18:00:06 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sort.h"

static size_t	index_node(int node_value, t_pile **a)
{
	t_pile	*tmp;

	tmp = *a;
	while (tmp->value != node_value)
		tmp = tmp->next;
	return (tmp->index);
}

void	push_small_b(t_pile **a, t_pile **b)
{
	int		node_value;
	size_t	node_index;
	size_t	stack_length;
	t_pile	*tmp;

	tmp = *a;
	stack_length = ft_lst_lengt(tmp);
	node_value = find_smallest(a);
	node_index = index_node(node_value, a);
	while (tmp->value != node_value)
	{
		if (stack_length == 4)
			if (node_index < 3)
				which_rotate('a', a, NULL);
			else
				which_reverse_rotate('a', a, NULL);
		else 
			if (node_index < 2)
				which_rotate('a', a, NULL);
			else
				which_reverse_rotate('a', a, NULL);
		tmp = *a;
	}
	which_push('b', a, b);
}

int	find_smallest(t_pile **stack)
{
	int		node_value;
	t_pile	*tmp;

	tmp = *stack;
	node_value = tmp->value;
	while (tmp)
	{
		if (tmp->value < node_value)
			node_value = tmp->value;
		tmp = tmp->next;
	}
	return (node_value);
}
