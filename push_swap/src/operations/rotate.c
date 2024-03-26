/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:22:01 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/26 16:06:58 by tsofien-         ###   ########.fr       */
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

void	which_reverse_rotate(char c, t_pile **stack_a, t_pile **stack_b)
{
	if (c == 'a')
	{
		if (*stack_a)
		{
			reverse_rotate(stack_a);
			write(1, "rra\n", 4);
		}
	}
	else if (c == 'b')
	{
		if (*stack_b)
		{
			reverse_rotate(stack_b);
			write(1, "rrb\n", 4);
		}
	}
}

void	reverse_rotate(t_pile **stack)
{
	t_pile	*tmp;
	t_pile	*last;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next)
	{
		last = tmp;
		tmp = tmp->next;
	}
	last->next = NULL;
	tmp->next = *stack;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	*stack = tmp;
}
