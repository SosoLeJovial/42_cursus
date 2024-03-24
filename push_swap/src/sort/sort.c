/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:25:41 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/24 01:33:39 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>

void which_sort(size_t stack_length, t_pile **stack_a, t_pile **stack_b)
{
	if (stack_length < 2)
		return ;
	else if (stack_length == 2)
		sort_two(stack_a);
	else if (stack_length == 3)
		sort_three(stack_a);
	else if (stack_length == 4)
		printf("note done yet 4 elements\n");
	else if (stack_length == 5)
		printf("note done yet 5 elements\n");
	else
		printf("note done yet Radix\n");
	if (!stack_b)
	printf("hahaha stack_b\n");
}

void sort_two(t_pile **stack)
{
	if ((*stack)->value > (*stack)->next->value)
		which_swap('a', stack, NULL);
}

void sort_three(t_pile **stack)
{
	if ((*stack)->value > (*stack)->next->value)
	{
		if ((*stack)->value > (*stack)->next->next->value)
		{
			which_rotate('a', stack, NULL);
			which_swap('a', stack, NULL);
		}
		if ((*stack)->value < (*stack)->next->next->value)
			which_swap('a', stack, NULL);
		else
		{
			which_swap('a', stack, NULL);
			which_rotate('a', stack, NULL);
		}
	}
	else if ((*stack)->next->value > (*stack)->next->next->value)
	{
		if ((*stack)->value > (*stack)->next->next->value)
			which_rotate('a', stack, NULL);
		else
			which_rotate('a', stack, NULL);
	}
	else if ((*stack)->value > (*stack)->next->next->value)
		which_rotate('a', stack, NULL);
}

