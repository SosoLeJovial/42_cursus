/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:20:04 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/26 16:03:07 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sort.h"

static int	find_max_bits(t_pile **stack)
{
	size_t	max;
	size_t	bits;
	t_pile	*tmp;

	max = 0;
	bits = 0;
	tmp = *stack;
	while (tmp)
	{
		if ((tmp)->rank > max)
			max = tmp->rank;
		tmp = tmp->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_pile **stack_a, t_pile **stack_b)
{
	int	max_bits;
	int	current_bit;
	int	i;
	int	size;
	int	num;

	max_bits = find_max_bits(stack_a);
	size = ft_lst_lengt(*stack_a);
	current_bit = -1;
	while (++current_bit < max_bits)
	{
		i = -1;
		while (++i < size)
		{
			num = (*stack_a)->rank;
			if (((num >> current_bit) & 1) == 1)
				which_rotate('a', stack_a, stack_b);
			else
				which_push('b', stack_a, stack_b);
		}
		while (*stack_b)
			which_push('a', stack_a, stack_b);
	}
}
