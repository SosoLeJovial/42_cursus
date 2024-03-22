/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:34:56 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/22 19:11:46 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int main(int argc, char **argv)
{
	char	**list_args;
	int		error;
	t_pile	*stack_a;
	// t_pile	*stack_b;

	stack_a = NULL;
	// stack_b = NULL;
	error = 0;
	list_args = NULL;
	list_args = ft_sanitize_args(argc, argv, &error);
	if (!list_args)
		return (write(1, "Error\n", 6));
	ft_stack_init(list_args, &error, stack_a);
	if (list_args != argv && list_args)
		ft_free_args(list_args);
	if (error != 0)
		return (write(1, "Error\n", 6));
	return (0);
}

// int push_swap(t_pile *stack_a, t_pile *stack_b, int *error)
// {

// 	return (0);
// }
