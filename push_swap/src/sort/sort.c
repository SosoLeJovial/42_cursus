/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:25:41 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/26 16:05:15 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sort.h"
#include "../../includes/tester.h"

void	which_sort(size_t stack_length, t_pile **stack_a, t_pile **stack_b)
{
	if (stack_length < 2)
		return ;
	else if (stack_length == 2)
		sort_two(stack_a);
	else if (stack_length == 3)
		sort_three(stack_a);
	else if (stack_length == 5)
		sort_five(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

void	sort_two(t_pile **stack)
{
	if ((*stack)->value > (*stack)->next->value)
		which_swap('a', stack, NULL);
}

static void	sa_ra_ra(t_pile **stack_a)
{
	which_swap('a', stack_a, NULL);
	which_rotate('a', stack_a, NULL);
	which_rotate('a', stack_a, NULL);
}

void	sort_three(t_pile **stack)
{
	if (((*stack)->value < (*stack)->next->value))
	{
		if ((*stack)->value > (*stack)->next->next->value)
		{
			which_rotate('a', stack, NULL);
			which_rotate('a', stack, NULL);
		}
		else
		{
			which_swap('a', stack, NULL);
			which_rotate('a', stack, NULL);
		}
	}
	else
	{
		if ((*stack)->next->next->value > (*stack)->value)
			which_swap('a', stack, NULL);
		else
		{
			if ((*stack)->next->value > (*stack)->next->next->value)
				sa_ra_ra(stack);
			else
				which_rotate('a', stack, NULL);
		}
	}
}

void	sort_five(t_pile **stack_a, t_pile **stack_b)
{
	push_small_b(stack_a, stack_b);
	add_index(stack_a);
	push_small_b(stack_a, stack_b);
	sort_three(stack_a);
	which_push('a', stack_a, stack_b);
	which_push('a', stack_a, stack_b);
}
