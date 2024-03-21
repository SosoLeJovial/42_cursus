/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:05:22 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/21 11:31:53 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tester.h"

void	display_stack(t_pile *stack)
{
	t_pile	*tmp;
	int		node;

	node = 1;
	tmp = stack;
	while (tmp)
	{
		printf("|------------------------------|\n");
		printf("| node n'%d ------ value : %d  |\n",node, tmp->value);
		printf("| prev      ------ adress : %p |\n", tmp->prev);
		printf("| &         ------ adress : %p |\n", (void*)tmp);
		printf("| next      ------ adress : %p |\n", tmp->next);
		printf("|------------------------------|\n");
		tmp = tmp->next;
		node++;
	}
}
