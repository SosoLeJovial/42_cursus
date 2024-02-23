/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:34:56 by tsofien-          #+#    #+#             */
/*   Updated: 2024/02/23 16:00:54 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	int		content;
	t_pile	*first_node;
	t_pile	**tmp;
	t_pile	*new;

	tmp = NULL;
	i = 1;
	if (argc < 1)
		return (0);
	content = ft_atoi(argv[i++]);
	first_node = ft_lstnew(content);
	*tmp = first_node;
	while (argv[i])
	{
		content = ft_atoi(argv[i++]);
		new = ft_lstnew(content);
		ft_lstadd_back(tmp, new);
		*tmp = new;
	}
	display_stack(first_node);
	return (0);
}
