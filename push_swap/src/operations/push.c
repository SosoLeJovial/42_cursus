/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:20:37 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/23 16:20:38 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/operations.h"

void which_push(char c, t_pile **stack_a, t_pile **stack_b)
{
	if (c == 'a')
	{
		if (*stack_b)
		{
			push(stack_b, stack_a);
			write(1, "pa\n", 3);
		}
	}
	else if (c == 'b')
	{
		if (*stack_a)
		{
			push(stack_a, stack_b);
			write(1, "pb\n", 3);
		}
	}
}

void push(t_pile **src, t_pile **dst)
{
	t_pile	*tmp;

	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = *dst;
	if (*dst)
		(*dst)->prev = tmp;
	*dst = tmp;
	tmp->prev = NULL;
}
