/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:58:30 by tsofien-          #+#    #+#             */
/*   Updated: 2024/03/12 19:32:00 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int	ft_check_args(int argc, char **argv, char **args)
{
	if (argc != 2)
		return (1);
	args = ft_split(*argv, 32);
	if (!args)
		return (1);
	return (0);
}

int	ft_sanitize_args(int argc, char **argv, char **list_args)
{
	int	i;
	int	check_error;
	int	content;

	content = 0;
	check_error = 0;
	i = 1;
	if (argc == 2)
		if (ft_check_args(argc, *argv, *list_args) == 1)
			return (check_error += 1);
	while (list_args[i])
	{
		content = ft_atoi(list_args[i++]);
		if (ft_sanitize(content) < 0)
			return (check_error =+ 1);
	}
	return (check_error);
}
