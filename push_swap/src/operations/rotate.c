/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:22:01 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/23 16:42:30 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/operations.h"

void	which_rotate(char c, t_pile **stack_a, t_pile **stack_b)
{
	if (c == 'a')
	{
		if (*stack_a)
		{
			rotate(stack_a);
            write(1, "ra\n", 3);
		}
	}
	else if (c == 'b')
	{
		if (*stack_b)
		{
			rotate(stack_b);
            write(1, "rb\n", 3);
		}
	}
}

void	rotate(t_pile **stack)
{
	t_pile	*tmp;
	t_pile	*last;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = tmp->next;
	tmp->next = NULL;
	last->next = tmp;
	tmp->prev = last;
}
