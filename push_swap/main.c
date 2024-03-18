/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:34:56 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/18 22:32:51 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int main(int argc, char **argv)
{
	char	**list_args;
	int		error;

	error = 0;
	list_args = NULL;
	list_args = ft_sanitize_args(argc, argv, &error);
	if (list_args != argv && list_args)
		ft_free_args(list_args);
	if (error != 0)
		return (write(1, "Error\n", 6));
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