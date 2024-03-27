/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:34:56 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/27 18:00:41 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"
#include "./includes/tester.h"

int	main(int argc, char **argv)
{
	char	**list_args;
	int		error;
	t_pile	*stack_a;
	t_pile	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	error = 0;
	list_args = NULL;
	if (argc < 2)
		return (0);
	list_args = ft_sanitize_args(argc, argv, &error);
	if (list_args && error == 0)
		error = push_swap(stack_a, stack_b, list_args, argv);
	if (list_args != argv && list_args)
		ft_free_args(list_args);
	if (error != 0)
		return (write(2, "Error\n", 6));
	return (0);
}

int	push_swap(t_pile *stack_a, t_pile *stack_b, char **list_args, char **argv)
{
	int	error;

	error = 0;
	error = ft_stack_init(list_args, &error, &stack_a, argv);
	if (error == 0)
	{
		if (ft_isduplicate(stack_a, &error))
			return (clean_stack(stack_a, stack_b), error);
	}
	else
		return (clean_stack(stack_a, stack_b), error);
	if (stack_is_sorted(stack_a))
		return (clean_stack(stack_a, stack_b), 0);
	add_index(&stack_a);
	rank_stack(&stack_a);
	which_sort(ft_lst_lengt(stack_a), &stack_a, &stack_b);
	clean_stack(stack_a, stack_b);
	return (error);
}
