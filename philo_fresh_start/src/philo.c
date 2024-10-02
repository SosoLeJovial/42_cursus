/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsofien- <tsofien-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 06:26:46 by tsofien-          #+#    #+#             */
/*   Updated: 2024/10/02 11:42:25 by tsofien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init_env(t_philo **philo, t_table **table, char **av);

int	main(int ac, char **av)
{
	t_table	*table;
	t_philo	*philo;

	table = NULL;
	philo = NULL;
	if (ac < 5 || !ft_check_args(ac, av))
		return (ft_msg(2, "Error table!\n"), 1);
	if (!init_env(&philo, &table, av))
		return (ft_msg(2, "Error init program!\n"), 1);
	free_table(&table);
	return (0);
}

static bool	init_env(t_philo **philo, t_table **table, char **av)
{
	*table = init_table(av);
	if (!*table)
		return (false);
	if (!mutex_init(*table))
		return (free(*table), false);
	*philo = init_philo(*table, (*table)->forks);
	if (!philo)
		return (false);
	(*table)->philo = philo;
	return (true);
}
