/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:34:56 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/21 11:16:33 by tsofien-         ###   ########.fr       */
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
	if (!list_args)
		printf("list_args null");
	ft_stack_init(list_args, &error);
	if (list_args != argv && list_args)
		ft_free_args(list_args);
	if (error != 0)
		return (write(1, "Error\n", 6));
	return (0);
}
