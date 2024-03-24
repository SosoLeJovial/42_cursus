/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:25:49 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/24 19:26:19 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sort.h"

void push_small_b(t_pile **a, t_pile **b)
{
	int		node_value;
	t_pile	*tmp;


	tmp = *a;
	node_value = find_smallest(a);
	while (tmp)
	{
		if (tmp->value == node_value)
		{
			which_index(tmp, a, b);
			break ;
		}
		tmp = tmp->next;
	}
}

void which_index(t_pile *tmp, t_pile **a, t_pile **b)
{
				if (tmp->index == 0)
				which_push('b', a, b);
			else if (tmp->index == 1)
			{
				which_swap('a', a, b);
				which_push('b', a, b);
			}
			else if (tmp->index == 2)
			{
				which_rotate('a', a, b);
				which_rotate('a', a, b);
				which_push('b', a, b);
			}
			else if (tmp->index == 3)
			{
				which_reverse_rotate('a', a, b);
				which_push('b', a, b);
			}
			else if (tmp->index == 4)
			{
				which_reverse_rotate('a', a, b);
				which_push('b', a, b);
			}
}
int find_smallest(t_pile **stack)
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
