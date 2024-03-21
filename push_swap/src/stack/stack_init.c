/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:51:31 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/21 11:18:16 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int ft_stack_init(char **list_arg, int *error)
{
	t_pile	*first_node;
	t_pile	*new;
	int		content;
	int		i;

	i = 0;
	content = ft_atoi(list_arg[i++]);
	first_node = ft_lstnew(content);
	if (!first_node)
		return (1);
	while (list_arg[i])
	{
		content = ft_atoi(list_arg[i++]);
		new = ft_lstnew(content);
		if (!new)
			printf("memory allocation fail\n");
		*error = ft_lstadd_back(&first_node, new);
		if (*error == -1)
			printf("fail add back\n");
	}
	display_stack(first_node);
	ft_lstclear(&first_node, NULL);
	return (*error);
}
