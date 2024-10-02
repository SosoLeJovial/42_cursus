/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:32:40 by tsofien-          #+#    #+#             */
/*   Updated: 2024/10/02 06:24:01 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/* 
	Arguments :
	-> number of philo 👴
	-> time to eat
	-> time to sleep
	-> time to think
	[number of iteration (eating)]
 */

int	ft_check_args(int ac, char**av)
{
	int	i;
	int	j;

	if (ac < 5)
		return (0);
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		if (ft_atoi(av[i]) < 0)
			return (0);
		i++;
	}
	return (1);
}
