/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:34:56 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/17 21:35:49 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int main(int argc, char **argv)
{
	char	**list_args;
	int		error;
	int		i;
	// t_pile	*first_node;
	// t_pile	*new;

	list_args = NULL;
	error = ft_sanitize_args(argc, argv, list_args);
	if (error != 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	i = 0;
	while (list_args[i])
	{
	printf("index : %d || content : %s\n", i, list_args[i]);
	}
	
	// ft_free_args(list_args);
	return (0);
}





















	// content = ft_atoi(argv[i++]);
	// first_node = ft_lstnew(content);
	// if (!first_node)
	// 	return (1);
	// while (i < argc)
	// {
	// 	content = ft_atoi(argv[i++]);
	// 	new = ft_lstnew(content);
	// 	if (!new)
	// 		printf("memory allocation fail\n");
	// 	error = ft_lstadd_back(&first_node, new);
	// 	if (error == -1)
	// 		printf("fail add back\n");
	// }
	// display_stack(first_node);
	// ft_lstclear(&first_node, NULL);