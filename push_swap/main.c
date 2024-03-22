/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:34:56 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/22 20:04:31 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int main(int argc, char **argv)
{
	char	**list_args;
	int		error;
	t_pile	*stack_a;
	t_pile	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	error = 0;
	list_args = NULL;
	list_args = ft_sanitize_args(argc, argv, &error);
	if (!list_args)
		return (write(1, "Error\n", 6));
	push_swap(stack_a, stack_b, &error, list_args);
	if (list_args != argv && list_args)
		ft_free_args(list_args);
	if (error != 0)
		return (write(1, "Error\n", 6));
	return (0);
}

int push_swap(t_pile *stack_a, t_pile *stack_b, int *error, char **list_args)
{

	*error = ft_stack_init(list_args, error, &stack_a);
	if (stack_a == NULL)
		printf("la stack a est nulle trou duc\n dans le doute la valeur d'error : %d\n", *error);
	if (*error == 0)
		ft_isduplicate(stack_a, error);
	if (!stack_b)
		printf("stack_b vide\n");
	return (*error);
}
