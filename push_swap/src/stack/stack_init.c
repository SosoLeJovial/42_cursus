/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:51:31 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/22 20:05:20 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int ft_stack_init(char **list_arg, int *error, t_pile **stack_a)
{
	t_pile	*new;
	int		content;
	int		i;

	i = 0;
	if (!list_arg)
		return (*error += 1);
	content = ft_atoi(list_arg[i++]);
	*stack_a = ft_lstnew(content);
	if (!*stack_a)
		return (1);
	while (list_arg[i])
	{
		content = ft_atoi(list_arg[i++]);
		new = ft_lstnew(content);
		if (!new)
			return (*error -= 1);
		*error = ft_lstadd_back(stack_a, new);
		if (*error == -1)
			return (*error);
	}
	display_stack(stack_a);
	return (*error);
}

int	ft_isduplicate(t_pile *stack, int *error)
{
	int		content;
	t_pile	*tmp;
	t_pile	*tmp_node;

	tmp_node = stack;
	while (tmp_node)
	{
		content = tmp_node->value;
		tmp_node = tmp_node->next;
		tmp = stack;
		while (tmp)
		{
			if (content == tmp->value)
			{
				printf("hahaha duplicate found \n");
				return (*error += 1);
			}
			tmp = tmp->next;
		}
	}
	return (*error);
}
