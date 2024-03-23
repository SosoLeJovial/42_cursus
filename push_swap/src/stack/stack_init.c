/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:51:31 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/23 02:02:34 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int ft_stack_init(char **list_arg, int *error, t_pile **stack_a, char **argv)
{
	t_pile	*new;
	int		content;
	int		i;

	i = 1;
	if(!list_arg)
		return(*error += 1);
	if (list_arg != argv)
		i -= 1;
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
		tmp = tmp_node->next;
		while (tmp)
		{
			if (content == tmp->value)
			{
				printf("hahaha duplicate found \n");
				return (*error += 1);
			}
			tmp = tmp->next;
		}
		tmp_node = tmp_node->next;
	}
	return (*error);
}
