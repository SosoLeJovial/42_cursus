/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:58:30 by tsofien-          #+#    #+#             */
/*   Updated: 2024/02/29 16:14:21 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int	ft_sanistize_args(int argc, char **argv)
{
	int	i;
	int check_error;
	int content;

	content = 0;
	check_error = 1;
	i = 1;
	while (i < argc)
	{
		content = ft_atoi(argv[i++]);
		if (ft_sanitize(content) < 0)
			return (check_error * -1);
	}
	return (check_error);
}
