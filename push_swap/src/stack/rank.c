/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 02:02:46 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/23 02:16:23 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void add_index(t_pile **stack)
{
	t_pile	*tmp;
	size_t		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}
void rank(t_pile **stack)
{
	t_pile	*tmp;
	t_pile	*tmp2;
	size_t	i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp2 = *stack;
		while (tmp2)
		{
			if (tmp->value > tmp2->value)
				i++;
			tmp2 = tmp2->next;
		}
		tmp->rank = i;
		i = 0;
		tmp = tmp->next;
	}
}
void rank_stack(t_pile **stack)
{
	add_index(stack);
	rank(stack);
}