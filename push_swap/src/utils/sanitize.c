/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:58:30 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/17 21:14:18 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int	ft_check_args(int argc, char **argv, char ***list_args)
{
	int	i;

	i = -1;
	if (argc < 2)
		return (1);
	if (argc == 2)
	{
		while (argv[1][++i] && argv[1][i] != '\0')
			if (ft_isdigit(argv[1][i]) == 0 && argv[1][i] != 32)
				return (1);
		*list_args = ft_split(argv[1], 32);
		if (!list_args || !list_args[1])
			return (1);
	}
	if (argc > 2)
	{
		*list_args = argv;
		return (-1);
	}
	return (0);
}

int	ft_sanitize_args(int argc, char **argv, char **list_args)
{
	int	i;
	int	check_error;
	int	content;

	content = 0;
	i = 0;
	check_error = ft_check_args(argc, argv, &list_args);
	if (check_error == 1)
		return (check_error);
	if (check_error == -1)
	{
		i += 1;
		check_error += 1;
	}
	while (list_args[i])
	{
		content = ft_atoi(list_args[i++]);
		if (ft_sanitize(content) > 0)
			return (check_error += 1);
		printf("content : %d\n", content);
	}
	return (check_error);
}
