/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:34:56 by tsofien-          #+#    #+#             */
/*   Updated: 2024/02/26 18:55:35 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"
#include "../includes/tester.h"
#include "../includes/stack.h"

int	main(int argc, char **argv)
{
	int		i;
	int		error;
	int		content;
	t_pile	*first_node;
	t_pile	*new;

	i = 1;
	if (argc < 1)
		return (0);
	content = ft_atoi(argv[i++]);
	first_node = ft_lstnew(content);
	if (!first_node)
		return (1);
	while (i < argc)
	{
		content = ft_atoi(argv[i++]);
		new = ft_lstnew(content);
		if (!new)
			printf("memory allocation fail\n");
		error = ft_lstadd_back(&first_node, new);
		if (error == -1)
			printf("fail add back\n");
	}
	display_stack(first_node);
	return (0);
}
