/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:22:17 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/26 16:06:21 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/operations.h"

void	which_swap(char c, t_pile **stack_a, t_pile **stack_b)
{
	if (c == 'a')
	{
		if (*stack_a && (*stack_a)->next)
		{
			swap(stack_a);
			write(1, "sa\n", 3);
		}
	}
	else if (c == 'b')
	{
		if (*stack_b && (*stack_b)->next)
		{
			swap(stack_b);
			write(1, "sb\n", 3);
		}
	}
}

void	swap(t_pile **stack)
{
	t_pile	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = tmp->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	tmp->prev = *stack;
	if (tmp->next)
		tmp->next->prev = tmp;
}
